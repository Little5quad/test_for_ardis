#pragma once

#include "document.h"
#include "istreamwrapper.h"
#include "error/en.h"
#include "bank_branch.h"
#include <iostream>
#include <fstream>
#include <chrono>

class Reader {
public:
	Reader(const std::stringstream& buffer ) {

		if (buffer.str().empty()) {
			std::cerr << "No JSON file" << std::endl;
		}
		rapidjson::ParseResult doc = document_.Parse(buffer.str().c_str());
		if (!doc) {
			std::cerr << rapidjson::GetParseError_En(doc.Code()) << std::endl;
		}
		
	}

	void FillDepartments(bank::Bank& bank);
	void FillClients(bank::Bank& bank);

	bank::Bank LoadBank();

private:
	rapidjson::Document document_;
};