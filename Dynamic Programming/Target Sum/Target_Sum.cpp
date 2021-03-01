#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr= new int[n+1];
    arr[0]=0;
    for(int i=1;i<=n;i++)
    cin>>arr[i];
    int target=0;
    cin>>target;
    int** dp = new int*[n+1];
for(int i = 0; i < n+1; ++i)
    dp[i] = new int[target+1];
    
    
    
    for(int i=0;i<=n;i++)
    {
    for(int j=0;j<=target;j++) 
    dp[i][j]=0;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=0;j<=target;j++) 
    {
        if(dp[i-1][j])
        dp[i][j]=1;
        else if(j-arr[i]>=0)
        {
            if(dp[i-1][j-arr[i]])  
            dp[i][j]=1;
        }
    }
 if(dp[n][target])
 cout<<"YES"<<endl;
 else
 cout<<"NO"<<endl;
 for(int i=0;i<=n;i++)
 {
    for(int j=0;j<=target;j++) 
    {
    cout<<dp[i][j]<<" ";
    }
    cout<<endl;
 }

}
