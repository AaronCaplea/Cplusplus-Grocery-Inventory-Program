#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

class Write
{
private:

public:
	Write();
	~Write();
	void writeToFile(const string& filename, vector<Item>& data);
};

