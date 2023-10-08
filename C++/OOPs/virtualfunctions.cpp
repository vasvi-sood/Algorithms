#include <iostream>  
using namespace std;  
class Base  
{  
   
    public:  
    virtual void show() 
    {
        
    }


     protected:
     virtual void Hello()=0; // pure virtual functions
    
   
};  
class Derived : public Base  
{  
    public:  
    void show()  
    {  
        std::cout << "Derived class is derived from the base class." << std::endl; 
   
    }  
};  
int main()  
{  
 
    
    Derived d; 
  
      Base *bptr= &d;  
    bptr->show();  
    
    
}  