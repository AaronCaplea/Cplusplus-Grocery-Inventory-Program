#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
    string name;
    int quantity;
public:
    //Added the default constructor, which initializes the name to an empty string and quantity to 0 for non-parameterized items.
	//This can only be done in the header file, since the default constructor cannot be defined in both the header and cpp file. 
    Item() : name(""), quantity(0) {};
    Item(const string& itemName, const int& itemQuantity);
    string GetName() const;
    int GetQuantity() const;
    void SetQuantity(int newQuantity);
};
