#include <iostream>
#include <string>
using namespace std;

class Main{
     friend class Friend;
    private:
int x;
 
    public:
  
    Main()
    {
      x=99;
    }
} obj;

class Friend{
public:
void showMainVar(Main &obj)
{
cout<<obj.x;
}
};

int main()
{

    Friend obj2;
    obj2.showMainVar(obj);
}