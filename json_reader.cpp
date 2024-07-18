#include "json_reader.h"

void Reader::FillDepartments(bank::Bank& bank) {
	auto dict = document_.FindMember("departments");
	for (const auto& depart : dict->value.GetArray()) {
		std::string name = depart["name"].GetString();
		int empl = depart["employees"].GetInt();
		bank.AddDepartment(name, empl);
	}
}
void Reader::FillClients(bank::Bank& bank) {
	auto dict = document_.FindMember("clients");
	for (const auto& client : dict->value.GetArray()) {
		std::string name = client["name"].GetString();
		std::chrono::milliseconds time = static_cast<std::chrono::milliseconds>(client["time"].GetInt());
		int prior = client["priority"].GetInt();
		std::vector<std::string> vec;
		for (const auto& arr : client.FindMember("departments")->value.GetArray()) {
			vec.push_back(arr.GetString());
		}
		bank.AddClient(name, time, prior, vec);
	}
}

bank::Bank Reader::LoadBank() {
	bank::Bank bank_buf;
	FillDepartments(bank_buf);
	FillClients(bank_buf);

	return bank_buf;
}