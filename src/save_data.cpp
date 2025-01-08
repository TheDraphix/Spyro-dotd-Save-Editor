#include "save_data.hpp"

save_data::GameSave::GameSave(const char *file_name)
{
	std::fstream fs(file_name);
  if (fs.fail())
  	std::cout << "error opening file :(" << std::endl;
  	
  fs.seekg(0, std::ios::end);
  this->size = fs.tellg(); 
  fs.seekg(0, std::ios::beg);
  
  this->data = new char[this->size];
  fs.read(this->data, this->size);
  if (fs.fail())
  	std::cout << "error reading file :(" << std::endl;
  	
  this->DetermineVersion();
}

void save_data::GameSave::DetermineVersion()
{
	this->version = save_data::PS2; // temporary hack
}
