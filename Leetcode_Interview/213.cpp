class Solution
{
    bool isadjascent(int i, int parent, int n)
    {
        if (i == n - 1 && parent == 0)
        {
            return true;
        }

        return false;
    }
    int helper(vector<int> &nums, int i, vector<int> &dp, int parent)
    {

        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = nums[i];
        int a = helper(nums, i + 2, dp, parent);
        int b = helper(nums, i + 3, dp, parent);
        ans += max(a, b);
        dp[i] = ans;
        return ans;
    }

public:
    int rob(vector<int> &nums)
    {
        /*
          2        7         1        3      9
        1   3     3   9     9  2      2    7   1
        \
        9



    2        7     1     3
      \
   1   3     3

        */

        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size(), -1);

        int ans = max(helper(nums, 2, dp, 2), helper(nums, 1, dp, 1));
        nums.pop_back();
        dp.assign(nums.size(), -1);

        ans = max(ans, helper(nums, 0, dp, 0));
        return ans;
    }
};