#include<iostream>
#include<fstream>
#include "GenStack.h"

using namespace std;

class delCheck {
  public:
    string userFile;
    ifstream infile;
    string nextFile;

    delCheck(string fileName);
    ~delCheck();
    void delScan();
    char opposite(GenStack<char> stack);
    char opposite(char c);
};
