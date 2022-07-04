class Solution
{
public:
    int candy(vector<int> &rat)
    {
        int n = rat.size();
        if (n == 1)
            return 1;
        vector<int> arr(rat.size(), 1);
        vector<int> brr(rat.size(), 1);
        for (int i = 1; i < rat.size(); i++)
        {
            if (rat[i] > rat[i - 1])
                arr[i] = arr[i - 1] + 1;
        }

        for (int i = rat.size() - 2; i >= 0; i--)
        {
            if (rat[i] > rat[i + 1])
                brr[i] = brr[i + 1] + 1;
        }
        int ans = 0;

        for (int i = 0; i < rat.size(); i++)
        {
            // cout<<arr[i]<<" "<<brr[i];
            ans += max(brr[i], arr[i]);
        }
        return ans;
    }
};