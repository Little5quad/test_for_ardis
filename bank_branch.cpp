#include "bank_branch.h"

namespace bank {
	Department::Department(std::string& name, int employees)
		: name_(std::move(name)), employees_(employees) {
	}

	std::string Department::GetName() const {
		return this->name_;
	}

	int Department::GetCountEmployees() const {
		return this->employees_;
	}

	Client::Client(std::string& name
		, std::chrono::milliseconds time
		, short priority
		, std::vector<std::string>& departments)
		: name_(std::move(name)), time_for_work_(time), priority_(priority), departments_(departments) {
		//std::reverse(departments_.begin(), departments_.end());
	}

	std::string Client::GetName() const {
		return this->name_;
	}

	std::chrono::milliseconds Client::GetTime() const {
		return this->time_for_work_;
	}
	std::vector<std::string>& Client::GetDepartments() {
		return this->departments_;
	}

	void Bank::AddDepartment(std::string& name, int employees) {
		all_departments_.push_back({name, employees});
		name_to_department_[all_departments_.back().GetName()] = &all_departments_.back();
	}
	void Bank::AddClient(std::string& name, std::chrono::milliseconds time, short priority, std::vector<std::string>& departments) {
		all_clients_.push_back({name, time, priority, departments});
		for (const auto& depart : departments) {
			q_to_department_[depart].push_back(all_clients_.back());
		}
	}

	const Department* Bank::GetDepartment(const std::string& name) {
		return name_to_department_.at(name);
	}

	size_t Bank::CountClients() {
		return this->all_clients_.size();
	}

	std::string Bank::GetTime() const {
		const auto now = std::chrono::system_clock::now();
		const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
		std::string str(std::ctime(&t_c));
		return str.substr(0, str.size() - 1);
	}

	Bank::log Bank::ProccessingClients() {
		log buff;
		{
			std::string time = "";
			time += "[" + GetTime() + "]:  Bank opened";
			//std::cerr << time << std::endl;
			buff.push_back(time);
		}
		
		while (!q_to_department_.empty()) {
			/*for (auto& [depart, queue] : q_to_department_) {
				int i = this->GetDepartment(depart)->GetCountEmployees();
				if (i > 0) {
					for (size_t j = 0; j < i && j < queue.size(); ++j) {
						{
							std::cerr << queue[j].GetName() << std::endl;
							std::string time = "";
							time += "[" + GetTime() + "]:  Client " + queue[j].GetName() = " came to the department " + depart;
							std::cerr << time << std::endl;
							buff.push_back(time);
						}
						std::this_thread::sleep_for(queue[j].GetTime());
						{
							std::string time = "";
							time += "[" + GetTime() + "]:  Client " + queue[j].GetName() = "is served by the department " + depart;
							std::cerr << time << std::endl;
							buff.push_back(time);
						}
						
					}
					queue.erase(queue.begin(), queue.begin() + i);
				}
				if (queue.empty()) {
					q_to_department_.erase(depart);
				}
			}*/
			std::string time = "";
			time += "[" + GetTime() + "]: Client ";
			std::vector<Client> q = q_to_department_.rbegin()->second;
			for (size_t i = 0; 
				i < GetDepartment(q_to_department_.rbegin()->first)->GetCountEmployees() 
				&& i < q.size(); ++i) {
				time += q[i].GetName() + " came to the department " + q_to_department_.rbegin()->first;
				std::cerr << time << std::endl;
				std::this_thread::sleep_for(q[i].GetTime());
				buff.push_back(time);


			}
			std::vector<Client> buffer_v(q.begin() + GetDepartment(q_to_department_.rbegin()->first)->GetCountEmployees()
				, q.end());
			if (!buffer_v.empty()) {
				q_to_department_.rbegin()->second = buffer_v;
			}
			else {
				q_to_department_.erase(q_to_department_.rbegin()->first);
			}
			
		}
		
		
		{
			std::string time = "";
			time += "[" + GetTime() + "]: Bank closed";
			//std::cerr << time << std::endl;
			buff.push_back(time);
		}

		return buff;
	}
}