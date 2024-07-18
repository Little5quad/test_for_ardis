#include "output_writer.h"

void Write(const std::vector<std::string>& logs) {
	for (const auto& log : logs) {
		std::cout << log << std::endl;
	}
}