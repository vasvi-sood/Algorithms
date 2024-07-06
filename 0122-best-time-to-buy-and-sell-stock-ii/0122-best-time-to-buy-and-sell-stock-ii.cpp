class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int buy=0,sell=0;
        int profit=0;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
                sell++;
            else
            {
                profit+=arr[sell]-arr[buy];
                buy=i;
                sell=i;
            }
        }
        if(arr[sell]>arr[buy])
        profit+=arr[sell]-arr[buy];
        
        return profit;
    }
};