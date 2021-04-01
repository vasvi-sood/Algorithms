#include<iostream>
#include<vector>
using namespace std;
void Print_prime(int n)
{
    vector<int> prime(n+1,1); //al numbers set to prime in beginning
for(int i=2;i*i<=n;i++)
{
    if(prime[i]) //computes the multiples of prime numbers only
                 // 4 that is not prime has all it's multiples taken care of
    {
    for(int j=i*i;j<=n;j+=i)
    {
      prime[j]=0;
    }
    }
}
for(int tri=2;tri<=n;tri++)
{
    if(prime[tri])
    cout<<tri<<" ";
}
}
int main(){
    int n;
    cin>>n;
    Print_prime(n);
return 0;
}