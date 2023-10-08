#include <iostream>
#include <string>
using namespace std;

 class Hello 
{
    string name;
   
    // public:
  public:  
   
   struct abc{
        int a;
        string b;

    } structabc;
  
  Hello(string name){
this->name=name;
    }

 void sayhello()
    {
        cout<<"Hello "+name;
    }
   


};

int main()
{
    Hello obj("VASVI");
    obj.sayhello();
    
    return 0;
}