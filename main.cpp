#include <iostream>
#include <string>
#include <fstream>

#include "Read.h"
#include "Display.h"
#include "Item.h"
#include "CustomStrings.h"
#include "Write.h"

#include <vector>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem; // I created a shorthand for this namespace to use the filesystem library.

int main() {
	Read reader;
	string userFileName;
	Display printer;
	int userInput = 0;
	Item item;

	vector<Item> inventory;
	vector<string> fileNameList;

	cout << "Enter the name of the file to read from the list of files below: " << endl << endl;
	//for each .txt file in the directory, output the filename to the console. This will be done using a for loop and the filesystem library.
	for (const auto& entry : fs::directory_iterator(".")) {
		//if the entry is a regular file and has a .txt extension, output the filename to the console as a part of the list.
		if (entry.is_regular_file() && entry.path().extension() == ".txt") {
			cout << entry.path().filename() << endl << endl;
			fileNameList.push_back(entry.path().filename().string());
		}
	}
	// Initialize boolean variable to track if the file is found
	bool validFile = false;

	while (validFile == false) {
		cin >> userFileName;
		// For each available file name, check if it matches the user input
		for (const string& availableFile : fileNameList) {
			if (userFileName == availableFile) {
				validFile = true;
				// A match was found, so break out of the loop
				break;
			}
		}
		if (!validFile) {
			// If the file is not valid, output an error message.
			cout << "Error: '" << userFileName << "' is not a valid file selection."
				<< endl << "Please enter a valid file name from the list above (make sure to add '.txt'):" << endl;
		}
	}
	
	//define local vector as returned from the ReadFile function.
	vector<string> lines = reader.ReadFile(userFileName);

	//if there was an error reading the file in function ReadFile() OR if it is .bad() and the function outputted an empty vector, return 1.
	if (lines.empty()) {
		return 1;
	}
	else {
		for (const string& line : lines) {
			// Clean up any trailing/leading whitespace from the line
			stringstream ss(line);
			string name;
			if (ss >> name) {
				//initialized a boolean variable to check if the item already exists in the inventory vector.
				bool alreadyExists = false;

				// Check if this item is already in the inventory vector. Increment its quantity.
				for (Item& existingItem : inventory) {
					if (existingItem.GetName() == name) {

						alreadyExists = true;
						existingItem.SetQuantity(existingItem.GetQuantity() + 1);
						break;
					}
				}

				// If it's a new item, initialize its associated item with a quantity of 1 and add it to the inventory vector.
				if (!alreadyExists) {
					inventory.push_back(Item(name, 1));
				}
			}
		}

		Write writer;
		writer.writeToFile("frequency.dat", inventory);
		//-----------------------------------------------------------------------------------------------------------
		//Main loop:
		
		//while user does not exit the program, output results based on user input and loop back to menu.
		while (true) {
			//I made sure to display the menu and get user input at the beginning of the while loop.
			cout << endl;
			printer.DisplayMenu();
			cin >> userInput;
			cout << endl;

			//If Statements:
			if (userInput == 1) {

				cin.get();

				// prompt the user to input item name and search for it in the vector of lines read from the file.
				cout << "Enter the name of the item to search for: ";
				string itemName;

				getline(cin, itemName);

				CustomStrings loweredString;
				string loweredItemName = loweredString.toLowerString(itemName);

				bool found = false;
				for (const Item& item : inventory) {
					if (loweredString.toLowerString(item.GetName()) == loweredItemName){
						found = true;
						cout << "Item found: " << item.GetName() << ", Quantity: " << item.GetQuantity() << endl;
						break;
					}
				}
				if (!found) {
					cout << "Item not found." << endl;
				}

			}
			else if (userInput == 2) {
				// print a list of all items and their quantities in the inventory vector.
				cout << "Items in Inventory:" << endl;
				for (const Item& item : inventory) {
					cout << "- " << item.GetName() << ": " << item.GetQuantity() << endl;
				}
			}
			else if (userInput == 3) {
				// Print a list of all items and their quantities in the form of a histogram, with each item name followed by a number of asterisks equal to its quantity.
				cout << "Inventory Histogram:" << endl;
				for (const Item& item : inventory) {
					cout << "- " << item.GetName() << " ";
					//Nested for loop to print asterisks equal to the quantity of the item.
					for (int i = 0; i < item.GetQuantity(); i++) {
						cout << "*";
					}
					cout << endl;
				}
			}
			else if (userInput == 4) {
				// Exit the program and print a message indicating that the inventory has been saved to frequency.dat.
				cout << "Successfully saved inventory to frequency.dat" << endl;
				break;
			}
			else {
				cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			}
		}
	}

	return 0;
}