#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      long long int min=prices[0],maxprofit=0;
        for(long long int i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
                min=prices[i];
            else
            {
                maxprofit=max(maxprofit,prices[i]-min);
            }
        }
        return maxprofit;
    }
};
