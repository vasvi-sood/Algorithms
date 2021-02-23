/*
Move from 0 to n
Every stair has a max permissible step limit you can take
Input 
n
n itheres 0 to n-1
4
4 2 1 2
from step 0 we can take at max 4 steps
from step 1 we cake at most 2 steps and so on
*/
  #include <iostream>
  #include<vector>
  #include<algorithm>
  #define lli long long int
using namespace std;
lli countpaths(int n,vector<lli> max)
{
   
  vector<lli> steps(n+1);
  for(int i=0;i<n;i++)
  steps[i]=0;

  steps[n]=1;
  for(lli i=n-1;i>=0;i--)
  {
    for(lli j=1;j<=max[i];j++) 
    {
       //cout<< i+j<<endl;
     if(i+j>n)
     break;
     steps[i]+=steps[i+j];
    }
  }
  for(int i=n;i>=0;i--)
 cout<<steps[i]<<" ";
 cout<<endl;

 return steps[0];

}
int main()
{
    lli n;
  cin>>n;

  vector<lli> max(n);
  for (int i = 0; i <n; i++)
  {
    cin>>max[i];
  }
  
  
  lli ct=countpaths(n,max);
  cout<<ct;

}