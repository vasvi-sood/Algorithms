
class Solution
{
    int dp[1001][1001];
    int maximumScore(int i, int curr, vector<int> &nums, vector<int> &muls)
    {
        // cout<<dp[curr][i]<<endl;
        int j = nums.size() - (curr - i) - 1;

        if (curr >= muls.size())
        {
            return 0;
        }

        if (dp[curr][i] != INT32_MAX)
        {

            return dp[curr][i];
        }

        int sum1 = muls[curr] * nums[i] + maximumScore(i + 1, curr + 1, nums, muls);
        int sum2 = muls[curr] * nums[j] + maximumScore(i, curr + 1, nums, muls);
        dp[curr][i] = max(sum1, sum2);
        return dp[curr][i];
    }

public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int num = INT32_MAX;
        // memset(dp,num,sizeof dp);
        for (int i = 0; i < 1001; i++)
            for (int j = 0; j < 1001; j++)
                dp[i][j] = num;

        // cout<<dp[0][0]<<endl;
        return maximumScore(0, 0, nums, multipliers);
    }
};