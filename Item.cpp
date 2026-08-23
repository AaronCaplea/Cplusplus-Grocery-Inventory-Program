#include "Item.h"

Item::Item(const string& itemName, const int& itemQuantity) {
	this->name = itemName;
	this->quantity = itemQuantity;
}

string Item::GetName() const {
	return name;
}

int Item::GetQuantity() const {
	return quantity;
}

void Item::SetQuantity(int newQuantity) {
	quantity = newQuantity;
}