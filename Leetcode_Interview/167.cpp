class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        vector<int> a(2);
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum == target)
            {
                a[0] = i + 1;
                a[1] = j + 1;
                return a;
            }
            else if (sum < target)
                i++;
            else
                j--;
        }

        return a;
    }
};