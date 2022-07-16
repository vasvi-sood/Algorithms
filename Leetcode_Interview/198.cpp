class Solution
{

    int helper(vector<int> &nums, int i, vector<int> &dp)
    {
        /*
        2,7,9,3,1,5
                  2
        7         9    3         1    5
        3  1 5   1 5   5
        5
        */
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = nums[i];
        ans += max(helper(nums, i + 2, dp), helper(nums, i + 3, dp));
        dp[i] = ans;
        return ans;
    }

public:
    int rob(vector<int> &nums)
    {
        /*
        2,7,9,3,1,5
                  2
        7         9    3         1    5
        3  1 5   1 5   5
        5
        */
        vector<int> dp(nums.size(), -1);
        return max(helper(nums, 0, dp), helper(nums, 1, dp));
         
    }
};