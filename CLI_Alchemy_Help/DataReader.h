#pragma once
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class DataReader
{
public:
	DataReader() = default;

	//for getting the file
	json& getData();
	//for loding from file
	bool loadFromFile(const std::string& filename);

private:
	json data;

};

