
#include <iostream>
#include <fstream>

#include "uuid.hpp"
#include "save_data.hpp"

int main()
{
	char file_name[32];
	std::cout << "Enter save file name: ";
	std::cin >> file_name;

	save_data::GameSave save(file_name);
	std::cout << "File size: " << save.GetSize() << std::endl;
	std::cout << "Version: " << save.version << std::endl;
	return 0;
}

