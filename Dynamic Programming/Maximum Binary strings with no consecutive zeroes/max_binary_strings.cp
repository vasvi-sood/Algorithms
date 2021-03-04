 #include<vector>
  #include<algorithm>
  #include<iostream>
  #define lli long long int
using namespace std;


pair<int,int> binary(lli n)
{
if(n==1)
{
    return make_pair(2,1);
}
pair<int,int> i=binary(n-1);
return make_pair(i.first+i.second,i.first);
}


int main()
{
  lli n;
    cin>>n;
cout<<binary(n).first;
   
return 0;
}
