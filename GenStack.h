#include <iostream>
#include <exception>

using namespace std;

template <class T>

class GenStack {
  public:
    GenStack(); //constructor
    GenStack(int maxSize);//overload constructor
    ~GenStack(); //destructor

    void push(T d);
    T pop(); //delete last inserted element
    T peek(); //top of stack
    bool isFull(); //check if isFull
    bool isEmpty(); // check if isEmpty
    int getSize();
    int getTop();

  private:
    int size;
    int top;
    T *myArray;
    int a;

};

    template <class T>
    GenStack<T>::GenStack() {
      myArray = new T[10];
      size = 10;
      top = -1;
    }

    template <class T>
    GenStack<T>::GenStack(int maxSize) {
      myArray = new T[maxSize];
      size = maxSize;
      top = -1;
    }

    template <class T>
    GenStack<T>::~GenStack() {
      delete[] myArray;
    }

    template <class T>
    T GenStack<T>::pop() {
      int a = -1;
      try
      {
        if (isEmpty())
        {
          throw a;
        }
        return myArray[top--];
      }
      catch (int a) {
        cout << "The stack is empty, exiting the program" << endl;
        exit(1);
      }
    }

    template <typename T>
    void GenStack<T>::push(T d) {
      int a = -1;
        if (isFull()) {
          T *temp = new T[size*2];
          for (int i = 0; i < size; i++) {
            temp[i] = myArray[i];
          }
          delete[] myArray;
          size *=2;
          myArray = temp;
        }
        myArray[++top] = d; //adds to myArray stack
    }

    template <class T>
    T GenStack<T>::peek() {
      try {
        if (isEmpty()) {
          throw a;
        }
        return myArray[top];
      }
      catch (int a) {
        cout << "The stack is empty, exiting the program" << endl;
        exit(1);
      }
    }

    template <class T>
    bool GenStack<T>::isEmpty() {
      return (top == -1);
    }

    template <class T>
    bool GenStack<T>::isFull() {
      return (top == size-1);
    }

    template <class T>
    int GenStack<T>::getSize() {
      try {
        if (isEmpty()) {
          throw a;
        }
        return size;
      }
      catch (int a) {
        cout << "The stack is empty, exiting the program" << endl;
        exit(1);
      }
    }

    template <class T>
    int GenStack<T>::getTop() {
      try {
        if (isEmpty()) {
          throw a;
        }
        return top;
      }
      catch (int a) {
        cout << "The stack is empty, exiting the program" << endl;
        exit(1);
      }
    }
