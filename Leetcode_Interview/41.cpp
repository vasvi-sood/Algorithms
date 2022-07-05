class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(0);
        nums.push_back(0);

        for (int &num : nums)
        {
            int no = num;
            while (no >= 1 && no <= n && no != nums[no])
            {
                // cout<<"here"<<endl;
                int temp = nums[no];
                nums[no] = no;
                no = temp;
            }
        }
        for (int i = 1; i <= n + 1; i++)
        {
            if (nums[i] != i)
                return i;
        }

        return INT32_MAX;
    }
};