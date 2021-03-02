#include<vector>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
       vector<int> arr(amount+1); 
        arr[0]=1;
         for(int j=0;j<coins.size();j++)
        for(int i=1;i<amount+1;i++)
           {
               if(i-coins[j]>=0)
                  arr[i]+=arr[i-coins[j]];
            }
        return arr[amount];
    }
};
