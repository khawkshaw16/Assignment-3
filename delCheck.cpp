#include <iostream>
#include <fstream>
#include "delCheck.h"

using namespace std;

delCheck::delCheck(string fileName) {
  inputFile = fileName;
}

void delCheck::delScan() {
  GenStack<char> delStack(10);
  string line;
  int lineCount = 1;
  nextFile = "first";
//If user wants to do another file
    while(true) {
       if (nextFile == "y") {
        cout << "Enter location of your file to be checked" << endl;
        cout << "If you want to exit input 'x'" << endl;
        cin >> inputFile;

        if(inputFile == 'x') {
          exit(1);
        }
        inFile.open(inputFile);
      }
      inFile.open(inputFile);

    // File is not found or misspelled
    if(!inFile) {
      cout << "Error opening file exiting program" << endl;
      exit(1);
    }

    while (getline(inFile, line)) {
      for (int i = 0; i < line.size(); ++i) {
        // Looking for opening delimiter in file
        if(line[i] == '(') {
          delStack.push('(');
        }
        else if(line[i] == '{') {
          delStack.push('{');
        }
        else if(line[i] == '[') {
          delStack.push('[');
        }
        //Checking ( )
        if (line[i] == ')') {
          if(delStack.isEmpty()) {
            cout << "Error found on line: " << lineCount << endl;
            cout << "Nothing matches with: " << line[i] << endl;
            inFile.close();
            exit(1);
          }

          if(delStack.peek() != '(') {
            cout << "Error found on line: " << lineCount << endl;
            cout << "Wrong one used, should be: " << opposite(line[i]) << endl;
            inFile.close();
            exit(1);
          }
          delStack.pop();
        }
        //Checking { }
        else if (line[i] == '}') {
          if(delStack.isEmpty()) {
            cout << "Error found on line: " << lineCount << endl;
            cout << "Nothing matches with: " << line[i] << endl;
            inFile.close();
            exit(1);
          }

          if(delStack.peek() != '}') {
            cout << "Error found on line: " << lineCount << endl;
            cout << "Wrong one used, should be: " << opposite(line[i]) << endl;
            inFile.close();
            exit(1);
          }
          delStack.pop();
        }
        //Checking [ ]
        else if (line[i] == ']') {
          if(delStack.isEmpty()) {
            cout << "Error found on line: " << lineCount << endl;
            cout << "Nothing matches with: " << line[i] << endl;
            inFile.close();
            exit(1);
          }

          if(delStack.peek() != ']') {
            cout << "Error found on line: " << lineCount << endl;
            cout << "Wrong one used, should be: " << opposite(line[i]) << endl;
            inFile.close();
            exit(1);
          }
          delStack.pop();
        }
      }
      ++lineCount;
    }

    if (delStack.isEmpty()) {
      //No errors found, prompt user for another file
      cout << "No syntax errors in your file :)" << endl;
      cout << "If you want to do another file type 'y' if not 'n'" << endl;
      cin >> nextFile;
      if(nextFile != "y") {
        inFile.close();
        exit(1);
      }
    }
    else {
      //Symbols didn't match
      cout << "There is a problem with syntax." << endl;
      inFile.close();
      cout << "There is an extra: " << matchStack.pop() <<
      cout << "Error found on line: " << lineCount << endl;
      exit(1);
    }
    inFile.close();
  }
}
//Popping opposite character
char delCheck::opposite(GenStack<char> stack) {
  while (stack.getTop() != 0) {
    cout << "Popping character: " << endl;
    stack.pop();
  }
  switch(stack.peek()) {
    case '(':
      return ')';

    case '{':
      return '}';

    case '[':
      return ']';

    default:
      return '\0';
  }
}
//Returns opposite of character inputed
char delCheck::opposite(char c) {
  switch(c) {
    case '(':
      return ')';

    case ')';
      return '(';

    case '{':
      return '}';

    case '}':
      return '{';

    case '[':
      return ']';

    case ']':
      return '[';

    default:
      return '\0';
  }
}

delCheck::~delCheck() {

}
