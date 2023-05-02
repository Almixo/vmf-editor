#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <format>
#include <algorithm>

// _CRT_NO_SECURE something something...
#pragma warning( disable : 4996 )

int main(int argc, char* argv[])
{
	std::vector<std::string>everything;

	std::ifstream file(argv[1]);
	std::string line;

	std::string lookup = std::format("\"{}\"", argv[2]);
	std::string oldvalue = std::format("\"{}\"", argv[3]);
	std::string newvalue = std::format("\"{}\"", argv[4]);

	std::cout << " ============ VMF PARSER/EDITOR, WRITTEN BY ALMIX, DATE " << __TIME__ << " ============ " << std::endl;
	std::cout << " ========== Format the lines like \"everything\", no \"\"nothing\"\" !!! ========== " << std::endl;

	std::cout << "key to change: " << lookup << std::endl;
	std::cout << "value to change: " << oldvalue << std::endl;
	std::cout << "new value: " << newvalue << std::endl;


	//copy it to our temporary vector
	while (std::getline(file, line))
		everything.push_back(line);
	file.close();


	//write backup just in case
	std::ofstream file_backup(std::format("{}_backup", argv[1]));
	for (auto& line_backup : everything)
		file_backup << line_backup << std::endl;
	file_backup.close();


	//parse our vector and edit the corresponding lines
	for (auto& var : everything)
	{
		if (strstr(var.c_str(), lookup.c_str()))
		{
			if (strstr(var.c_str(), oldvalue.c_str()))
			{
				std::string temp = var.c_str();

				temp.replace(temp.length() - oldvalue.length(), newvalue.length(), newvalue);

				//we don't have them line numbers... too bad I guess :p
				//no line number print then!
				std::cout << "Line edited!" << std::endl;
				
				var.clear();
				var.append(temp);
			}
		}
	}


	//write it back to the file
	std::ofstream file_new(argv[1]);
	for (auto& line_new : everything)
		file_new << line_new << std::endl;
	file_new.close();


	return 0;
}