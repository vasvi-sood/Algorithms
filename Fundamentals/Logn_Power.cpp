#include<iostream>
using namespace std;
#define lli long long int
const long long int M=10e9+7;
lli mod(lli a){
    return (a%M+M)%M;
}
lli mod_mul(lli a,lli b){
    return mod(mod(a)*mod(b));
}
lli mod_add(lli a,lli b){
    return (a%M+b%M)%M;
}
int main()
{
    
// to impliment a^b in log b time
lli a,b;
cin>>a>>b;
lli result=1,transfer=a;
int bi;
while(b>0)
{
bi=b%2;
b/=2;
if(bi)
result=mod_mul(result,transfer);
transfer=mod_mul(transfer,transfer);
}
cout<<result;
}


/*
The logic used here is that any number can be broken down into power of two for eg 7=2^0 + 2^1 + 2^2.
  So if we have to find a^b e.g 10^7
  we calculate 10^(2^0) if the binary representation of b(the power) has 1 at that location meaning power contains the term 2^0 multiply that to result
  Then calulate 10^(2^1) whch is simply square of 10^(2^0) check if this power is required, if yes multiply in result
  Continue till we have checked for the last power of two in that b number
*/

/*
Update : the probelm now changes to a^b%m;
we know that (a*b)%m can be written as (a%m*b%m)%m  so at every step of multiplication we will call the mod function to get the desitrd result
*/
