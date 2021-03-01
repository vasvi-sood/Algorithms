 #include <iostream>
  #include<vector>
  #include<algorithm>
  #define lli long long int
using namespace std;
lli countpaths(int n)
{
   
   vector<lli> paths(n+1);
   if(n==0 || n==1 || n==2)
   return n;
   paths[0]=1;
   paths[1]=1;
   paths[2]=2;
   for(int i=3;i<=n;i++)
   paths[i]=paths[i-1]+paths[i-2]+paths[i-3];

   return paths[n];


}
int main()
{
    lli n;
  cin>>n;

  
  
  lli ct=countpaths(n);
  cout<<ct;

}
