#pragma once
#include <iostream>
#include <ctime>
#include <deque>
#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include <unordered_map>
#include <map>
#include <thread>
namespace bank {

	class Client {
	public:
		
		Client(std::string& name, std::chrono::milliseconds time, short priority, std::vector<std::string>& departments);

		std::chrono::milliseconds GetTime() const;
		std::vector<std::string>& GetDepartments();
		std::string GetName() const;

	private:
		std::string name_;
		std::chrono::milliseconds time_for_work_;
		short priority_;
		std::vector<std::string> departments_;
	}; 

	class Department {
	public:

		Department(std::string& name, int employees);

		std::string GetName() const;
		int GetCountEmployees() const;

	private:
		std::string name_ = "";
		int employees_ = 0;
	};

	class Bank {
	public:

		using log = std::vector<std::string>;

		void AddDepartment(std::string& name, int employees);
		void AddClient(std::string& name, std::chrono::milliseconds time, short priority, std::vector<std::string>& employees);

		const Department* GetDepartment(const std::string& name);

		size_t CountClients();

		log ProccessingClients();

	private:

		std::string GetTime() const;

		std::deque<Department> all_departments_;
		std::deque<Client> all_clients_;
		// For more speed search deparment 
		std::unordered_map<std::string, const Department*> name_to_department_;
		std::map<std::string, std::vector<Client>> q_to_department_;
	};

}