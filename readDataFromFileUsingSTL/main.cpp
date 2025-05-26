//Compiler used C++ 20
// This program reads data from a file and processes it using STL features.

#include <format>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::format;
using std::string;
using std::vector;

const int MAX_SIZE = 1024;
const char* tab { "\t" };
const char* readFile {"/Users/abdix/myProject/gitRepository/myLearningProjects/readDataFromFileUsingSTL/items.txt"};

class items
{
    int index;
    string type;
    string description;

public:
    items() { reset(); }
    items(int i, const string& t, const string& d) : index(i), type(t), description(d) {};
    items(const items& it); 
    items& operator = (const items& it);
    ~items() { reset(); }
    void reset() { index = 0; type = "unknown"; description = "unknown"; }
    void setIndex(int i);
    int getIndex() const;
    void setType(const string& t);
    string getType() const;
    void setDescription(const string& d);
    string getDescription() const;
};

items::items(const items& it)
{
    index = it.index;
    type = it.type;
    description = it.description;
}

items& items::operator=(const items& it)
{
    if (this != &it)
    {
        index = it.index;
        type = it.type;
        description = it.description;
    }
    return *this;
}

void items::setIndex(int i)
{
    index = i;
}

int items::getIndex() const
{
	return index;
}

void items::setType(const string& t)
{
	type = t;
}

string items::getType() const
{
	return type;
}

void items::setDescription(const string& d)
{
	description = d;
}

string items::getDescription() const
{
	return description;
}

vector<string> splitString(const string& s)
{ 
	vector<string> result;
    size_t start_loc = 0;
	size_t end_loc = s.find(tab, start_loc);
    while (end_loc != string::npos)
    {
        result.push_back(s.substr(start_loc, end_loc - start_loc));
        start_loc = end_loc + 1;
        end_loc = s.find(tab, start_loc);
    }
	result.push_back(s.substr(start_loc));
    return result;
}

int main()
{
    char buff[MAX_SIZE] {};
    std::ifstream rfile(readFile);

    while (rfile.good())
    {
        rfile.getline(buff, MAX_SIZE);
        vector<string> data = splitString(buff);
        if (data.size() < 3) continue;

        items currentItem(stoi(data[0]), data[1], data[2]);
        cout << std::format("Index: {}, Type: {}, Description: {}\n",
            currentItem.getIndex(),
            currentItem.getType(),
            currentItem.getDescription());
    }
    rfile.close();
    return 0;
}