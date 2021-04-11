#include<iostream>
using namespace std;
int main()
{
   int arr[3][3]={{1,2,3},{1,2,3},{4,5,6}};
   int dp[4][4];

for(int i=0;i<4;i++)
{
dp[i][0]=0;
dp[0][i]=0;
}

   
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
    dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+arr[i][j];
   
    }
    
}
cout<<"the sum of matrix:\n";
   for(int i=1;i<=3;i++)
   {
   for(int j=1;j<=3;j++)
   {
   cout<<dp[i][j]<<" ";
   }
   cout<<endl;
   }
   return 0; 
}