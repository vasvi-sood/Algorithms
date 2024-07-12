class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
        vector<int> buyone(n);
        vector<int> sellone(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
               buyone[0]=-prices[i];
                sellone[0]=0;
            }
            else
                if(i==1)
                {
                    buyone[1]=max(buyone[0],-prices[1]);
                    sellone[1]=max(sellone[0],prices[i]+buyone[i-1]);
                }
            else
            {
                //cooldown price is sellone[i-1]
                buyone[i]=max(buyone[i-1],sellone[i-2]-prices[i]);
                sellone[i]=max(sellone[i-1],buyone[i-1]+prices[i]);
            }
        }
        
        
        return sellone[n-1];
    }
};