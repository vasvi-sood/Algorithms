#include <string>
#include <iostream>
using namespace std;
class Main;
class Friendfunctionclass
{
  
public:
 void func(Main &obj);

};

class Main{
    private:
   int private_var=10;
  public:
 
  friend void Friendfunctionclass::func(Main &obj);  //friend variable

};


void Friendfunctionclass:: func(Main &obj)
{
cout<<obj.private_var;
}

int main()
{
    Main obj;
    Friendfunctionclass fobj;
    fobj.func(obj);

}