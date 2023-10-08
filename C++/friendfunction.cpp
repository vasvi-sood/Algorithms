#include <string>
#include <iostream>
using namespace std;

class Main{
    private:
   int private_var=10;
  public:
 
  friend void func(Main &obj);  //friend variable

};

void func(Main &obj)
{
cout<<obj.private_var;
}


int main()
{
    Main obj;
    func(obj);

}