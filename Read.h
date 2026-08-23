#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Read
{
private:
    string fileName;
public:
    vector<string> ReadFile(string filename);
};

