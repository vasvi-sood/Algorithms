class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> mxprofonsell(n);
         vector<int> mxprofon1buy(n);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                mxprofon1buy[0]=-prices[0];
                mxprofonsell[0]=0;
                continue;
            }
            
            mxprofon1buy[i]=max(mxprofon1buy[i-1],mxprofonsell[i-1]-prices[i]);
            mxprofonsell[i]=max(mxprofonsell[i-1],mxprofon1buy[i-1]+prices[i]-fee);
            
        }
        
        return mxprofonsell[n-1];
    }
};