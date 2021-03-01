 #include <iostream>
  #include<vector>
  #include<algorithm>
  #define lli long long int
using namespace std;
lli countpaths(int n,vector<int> arr)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(arr[n]!=0)
    return arr[n];
  lli ct= countpaths(n-1,arr)+countpaths(n-2,arr)+countpaths(n-3,arr);
arr[n]=ct;
  return ct;

}
int main()
{
    lli n;
  cin>>n;
  vector<int> arr(n+1);
  for (int i = 1; i < n+1; i++)
  arr[i]=0;
  
  
  lli ct=countpaths(n,arr);
  cout<<ct;

}
