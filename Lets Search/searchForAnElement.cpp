
#include <iostream> 
#include <vector> 
#include<algorithm>
using namespace std;
 /*   Using the binary_search and lower_bound function of algorithms*/

int main()
{
        int num;
    vector<int> arr={5,4,3,2,1};
    //array must be sorted to perform binary search
    sort(arr.begin(),arr.end());
    cin>>num;
   bool result=binary_search(arr.begin(),arr.end(),num);
   if(!result)
   {
       cout<<"not present"<<endl;
   }
   else
   {
       //lower_bound return the pointer to thefirst  element if
       //it is present, else it return pointer to the next higher element
       //so never use lower_bound to check if a number is there or not
     int pos=lower_bound(arr.begin(),arr.end(),num)-arr.begin();
     cout<<"present at "<<pos<<endl;
   }
    return 0;
}
