 #include<vector>
  #include<algorithm>
  #include<iostream>
  #define lli long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> values(n+1);
    vector<int> weights(n+1);
    weights.push_back(0);
    values.push_back(0);
    for(int i=1;i<=n;i++)
    cin>>values[i];
    for(int i=1;i<=n;i++)
    cin>>weights[i];
    int capacity;
    cin>>capacity;

    int * arr=new int[capacity+1];
   
    for(int i=0;i<=capacity;i++)
    arr[i]=0;

    for(int i=1;i<=n;i++)
    for(int j=weights[i];j<=capacity;j++)
    {
        arr[j]=max(values[i]+arr[j-weights[i]],arr[j]);
    }
    cout<<arr[capacity];

}
