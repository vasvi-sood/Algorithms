#include <iostream>
  #include<vector>
  #include<algorithm>
  #define lli long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> values(n+1);
    vector<int> weights(n+1);
    weights.push_back(0);
    values.push_back(0);
    for(int i=1;i<=n;i++)
    cin>>values[i];
    for(int i=1;i<=n;i++)
    cin>>weights[i];
    int capacity;
    cin>>capacity;
    int ** arr=new int*[values.size()+1];
    for(int i=0;i<=n;i++)
    arr[i]=new int[capacity+1];
    for(int i=0;i<=capacity;i++)
    arr[0][i]=0;

    for(int i=1;i<=n;i++)
    {
    for(int j=0;j<weights[i];j++)
    {
      arr[i][j]=arr[i-1][j]; 
       cout<<arr[i][j]<<" "; 
    }
    for(int j=weights[i];j<=capacity;j++)
    {
      arr[i][j]=max(arr[i-1][j],values[i]+arr[i-1][j-weights[i]]);  
      cout<<arr[i][j]<<" "; 
    }
   cout<<endl;
    }
   // cout<<"hello";

    cout<<arr[n][capacity]<<endl;



}
