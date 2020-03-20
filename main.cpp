#include<iostream>
#include<fstream>
#include "delCheck.h"

using namespace std;

int main(int argc, char const *argv[]) {

  ifstream userfile;
  string userFile;
  fstream outfile;
  string line;
  int lineCount = 1;

  cout << "Checking syntax to make sure the correct # of delimeters are in code" << endl;
  cout<< "Enter location of your file to be checked" << endl;
  cin >> inFile;

  delCheck match(userFile);
  match.delScan();

  return 0;
}
