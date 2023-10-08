#include <iostream>
using namespace std;

class Base
{
   int x;
   public:
  
  Base()
  {
      cout << "Base class default constructor\n"; 
  }
   
  Base(int x) { 
      this->x = x;
      cout<<"Base class parameterized constructor\n";
  }
};

class Derived: public Base
{
    public:
    Derived()
    {
         cout << "Derived lass default constructor\n"; 
    }

    Derived(int x): Base(x)
    {
         cout << "Derived lass parametrised constructor\n"; 
    }
};

int main()
{
    Derived obj;
    Derived obj1(5);
}

// ouput
// Base class default constructor
//Derived lass default constructor
//Base class parameterized constructor
//Derived class parameterized constructor

