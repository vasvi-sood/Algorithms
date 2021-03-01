#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     
        vector<long int> arr(amount+1);
        arr[0]=0;
        for(long long int i=1;i<=amount;i++)
         arr[i]=INT_MAX-1;
         for(long long int i=0;i<coins.size();i++)
         {
             long long int coin=coins[i];
             for(long long int j=coin;j<arr.size();j++)
              arr[j]=min(arr[j-coin]+1,arr[j]);
         }
         if(arr[amount]==INT_MAX-1)
         return -1;
         return arr[amount];
          
            
    }
};
