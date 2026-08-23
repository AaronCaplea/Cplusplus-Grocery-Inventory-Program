#include "Write.h"
#include "Item.h"

Write::Write() {}
Write::~Write() {}

void Write::writeToFile(const std::string& filename, std::vector<Item>& data)
{
    std::ofstream outFS(filename);        
    if (!outFS) return;
    for (const Item& item : data) {
        outFS << item.GetName() << ' ' << item.GetQuantity() << endl;
	}
    outFS.close();
}
