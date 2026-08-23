#include "Read.h"

vector<string> Read::ReadFile(string filename) {
	vector<string> lines;

	string fileName = filename;
	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		cout << "Error opening file: " << fileName << endl;
		return lines;
	}
	else if (inputFile.bad()) {
		cout << "I/O Error reading file: " << fileName << endl;
		return lines;
	}

	// Get the file content and store it in the vector 'lines'.
	string line;
	while (getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();
	return lines;
}
