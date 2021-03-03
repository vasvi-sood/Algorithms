#include <iostream>
  #include<vector>
  #include<algorithm>
  #define lli long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> values(n);
    vector<int> weights(n);
    for(int i=0;i<n;i++)
    cin>>values[i];
    for(int i=0;i<n;i++)
    cin>>weights[i];
    int capacity;
    cin>>capacity;
    int maxval=0;
    vector<pair<int,int>> arr;
    for(int i=0;i<weights.size();i++)
    {
       int wt=weights[i];
        arr.push_back(make_pair(wt,values[i]));
          cout<<wt<<" "<<values[i]<<endl;
         maxval=max(maxval,values[i]);
         int q=arr.size();
        for(int j=0;j<q-1;j++)
        {
            if(arr[j].first+wt<=capacity)
            {
         arr.push_back(make_pair(arr[j].first+wt,arr[j].second+values[i]));
         cout<<arr[j].first+wt<<" "<<arr[j].second+values[i]<<endl;
         maxval=max(maxval,arr[j].second+values[i]);
            }
        }
        
    }
    cout<<maxval;
}
