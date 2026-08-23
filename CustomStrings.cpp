#include "CustomStrings.h"

string CustomStrings::toLowerString(string str) {
    for (char& c : str) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return str;
}