// bank_branch.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <chrono>
#include <cassert>
#include <fstream>

#include "bank_branch.h"
#include "json_reader.h"
#include "output_writer.h"

//this is base test for functional of bank
void TestBank() {
	using namespace bank;
	using namespace std::chrono_literals;
	Bank bank;
	std::string m = "Vasya";
	std::vector<std::string> vec = { "reception", "deposits" };

	for (int i = 0; i < 4; ++i) {
		bank.AddClient(m, 500ms, 1,vec);
	}

	assert(bank.CountClients() == 4);

	bank.AddDepartment(vec[0], 2);
	bank.AddDepartment(vec[1], 3);

	assert(bank.GetDepartment("reception") != nullptr);
	assert(bank.GetDepartment("deposits") != nullptr);
	
	bank.ProccessingClients();
}

void TestInput() {
	//std::ifstream file("in.json");
	std::fstream file;
	file.open("C:/Users/Александр/Desktop/учеба/Методы программирования/bank_branch/input.txt");
	if (!file.is_open()) {
		std::cerr << "No JSON file" << std::endl;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();

	if (buffer.str().empty()) {
		std::cerr << "No JSON file" << std::endl;
	}
	Reader reader(buffer);
	bank::Bank bank = reader.LoadBank();
	
	assert(bank.GetDepartment("reception") != nullptr);
	assert(bank.GetDepartment("deposits") != nullptr);

	assert(bank.GetDepartment("reception")->GetCountEmployees() == 2);
	assert(bank.CountClients() == 3);
}

int main()
{
	//TestBank();
	//TestInput();
	setlocale(LC_ALL, "RU");
	bank::Bank bank;
	std::string str;
	std::getline(std::cin, str);
	std::fstream file;
	file.open(str);
	if (!file.is_open()) {
		std::cerr << "Can't search file" << std::endl;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();

	if (buffer.str().empty()) {
		std::cerr << "No JSON file" << std::endl;
	}
	Reader reader(buffer);
	
	Write(bank.ProccessingClients());
	
	return 0;
}
