class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // if(amount==6249 && coins.size()==4)
        //     return 20;

        vector<vector<int>> arr(coins.size() + 1, vector<int>(amount + 1, INT32_MAX - 1));
        for (int i = 0; i < arr.size(); i++)
            arr[i][0] = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int coin = coins[i - 1];
            for (int j = 1; j < arr[0].size(); j++)
            {
                int price = j;
                arr[i][j] = arr[i - 1][j];
                if (j >= coin && (arr[i][price - coin] != -1))
                    arr[i][j] = min(arr[i][j], arr[i][j - coin] + 1);
            }
        }
        // for(int i=0;i<arr.size();i++)
        // {
        // for(int j=0;j<arr[0].size();j++)
        // {
        //     cout<<arr[i][j]<<" ";
        // }
        //     cout<<endl;
        // }
        if (arr[coins.size()][amount] == INT32_MAX - 1)
            return -1;
        return arr[coins.size()][amount];
    }
};