#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // For parsing lines
using namespace std;

void parseCSV(const string&);

int main() {
   parseCSV("students.csv");
   
   return 0;
}

void parseCSV(const string&)
{
    ifstream file("students.csv");
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string token;

        while (ss >> token)
        {
            size_t pos = token.find(':');

            string key = token.substr(0, pos);
            string value = token.substr(pos + 1);

            cout << key << " -> " << value << endl;
        }
         cout << endl; // Add a newline after each line of the CSV
    }
   
}
