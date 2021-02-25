 /*
 Find the shortest path to travel from stair 0 to n 
 so that from every step at max ai steps can be travelled
 */
 #include <iostream>
  #include<vector>
  #include<algorithm>
  #define lli long long int
using namespace std;
int main()
{
long int n;
cin>>n;
vector<lli> maxstep(n); 
for( lli i=0;i<n;i++)
 {
cin>>maxstep[i];
  } 
  vector<lli> arr(n+1); 
  for( lli i=0;i<n;i++)
 {
 arr[i]=n+1;
  }
  arr[n]=0;
   for( lli i=n-1;i>=0;i--)
 {
     for(lli j=1;j<=maxstep[i] && i+j<=n;j++)
     {
        
     arr[i]=min(arr[i],arr[i+j]+1);
     }
    

  }
