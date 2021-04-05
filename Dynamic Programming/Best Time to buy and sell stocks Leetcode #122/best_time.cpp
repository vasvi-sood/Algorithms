#include <algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int prev=prices[0];
        int b=0,s=0;
      int max_profit=0;
        for(int i=0;i<prices.size();i++)
        {
            
           if(prices[i]>=prev)
           {
              // cout<<" s = "<<s<<endl;
               s=i;
               
               
           }
           if(prices[i]<prev)
            {
                max_profit+=prices[s]-prices[b];
               // cout<<" s = "<<s<<" b = "<<b<<" maxprofit "<<max_profit<<endl;
                s=i;b=s;
                
              
            }
            
            prev=prices[i];
          
        }
         max_profit+=prices[s]-prices[b];
        return max_profit;
    }
};
