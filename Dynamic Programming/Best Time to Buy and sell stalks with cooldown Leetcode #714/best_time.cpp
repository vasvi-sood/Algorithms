
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
     
int buy=-prices[0];
int sell=0;
        for(int i=1;i<prices.size();i++)
        {
            buy=max(buy,sell-prices[i]);
            sell=max(sell,buy+prices[i]-fee);
        }
        
        return sell;
        
        
   
       
           
           
     
    }
};
