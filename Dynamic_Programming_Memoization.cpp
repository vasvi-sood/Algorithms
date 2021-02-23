/*
Given a stair case of  n steps we can take 1,2 or 3 steps at a time, calculate the number of ways for reaching from n to 0th level
eg n=4
possible paths 1,1,1,1... 2,2... 2,1,1... 1,1,2 , 3,1 etc
*/
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