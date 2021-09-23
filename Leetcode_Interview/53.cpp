class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mx = INT32_MIN;
        int sum = mx;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (sum < 0)
                sum = 0;
            sum += nums[j];
            mx = max(mx, sum);
        }
        return mx;
    }
};