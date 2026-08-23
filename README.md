# Cplusplus-Grocery-Inventory-Program

This project involved creating and designing a program in C++ that reads a grocery store transaction sheet (.txt) and supplies the user with a menu for
1. Searching items by name and outputting the quantity of that item sold for that day,
2. Printing all items and their quantities,
3. Printing all items and their quantities in the form of a histogram,    and
4. Exiting

The program loops until the user chooses to exit, where the items and quantities are then saved to a file 'frequency.dat'.

This project allowed me to get more hands-on practice with the OOP methodologies. Establishing an 'Item' class for the sole purpose of getting the item name and quantity was more strategic. I was also able to incorporate an additional layer of functionality: the program scans the current directory for .txt files and displays the list of files before the user inputs any command. I added some layers of input validation as well as validation for reading/writing files. I am most proud of my ability to create properly-derived sub/base classes that function well with the main() function.

The most challenging portion of the project was dealing with keeping track of the various data types within various classes. For example, most functions use const pointers, but some do not require this. I was able to look up proper techniques in the class textbook as well as https://www.tutorialspoint.com/cplusplus/cpp_array_of_pointers.htm if I needed quick answers. Otherwise, I tried to solve the problems manually.

The reading and writing to files will come in handy as I transition much of my focus to Data Analysis projects. Programmers can use C++ to create the secure backend engine for pipelines while keeping the interface lightweight with Python, VS Code, SQL, and Jupyter.

The program is maintainable because it features frequent comments for easy navigation of the code
It is readable due to the separate derived classes (the main() function is not overly cluttered)
It is adaptable since OOP methodologies are embedded into the very structure of the files, and since the data types were thought through.
