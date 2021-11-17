class Solution
{
    int func(int amount, int target, vector<int> &arr, vector<int> &mem)
    {
        if (amount > target)
            return 0;
        if (amount == target)
            return 1;
        if (mem[amount] != -1)
            return mem[amount];
        int count = 0;
        for (int num : arr)
            count += func(amount + num, target, arr, mem);
        mem[amount] = count;
        return count;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {

        vector<int> mem(target, -1);
        return func(0, target, nums, mem);
    }
};