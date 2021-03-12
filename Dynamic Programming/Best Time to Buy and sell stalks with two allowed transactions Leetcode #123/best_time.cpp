#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> arr1(prices.size());
        vector<int> arr2(prices.size());
        arr1[0]=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<mini)
            {
                mini=prices[i];
            }
          arr1[i]=max(arr1[i-1],prices[i]-mini);
        }
        int maxi=prices[prices.size()-1];
        arr2[prices.size()-1]=0;
        for(int i=prices.size()-2;i>=0;i--)
        {
            if(prices[i]>maxi)
            {
                maxi=prices[i];
            }
          arr2[i]=max(arr2[i+1],maxi-prices[i]);
        }
         
        maxi=0;
        for(int i=0;i<prices.size();i++)
        {
            if(arr1[i]+arr2[i]>maxi)
                maxi=arr1[i]+arr2[i];
            
    }
        return maxi;
    }
};
