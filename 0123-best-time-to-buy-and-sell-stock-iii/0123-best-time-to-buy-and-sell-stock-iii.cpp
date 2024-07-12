class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        int mnbuy=prices[0];
        int mxsell=prices[n-1];
        
        for(int i=1;i<n;i++)
        {
            dp1[i]=max(dp1[i-1],prices[i]-mnbuy);
            mnbuy=min(mnbuy,prices[i]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            dp2[i]=max(dp2[i+1],mxsell-prices[i]);
           mxsell=max(mxsell,prices[i]);
        }
        
        int mxprofit=dp2[0];
        
        for(int i=0;i<n-1;i++)
        {
            mxprofit=max(mxprofit, dp1[i]+dp2[i+1]);
        }
        
        return mxprofit;
        
    }
};