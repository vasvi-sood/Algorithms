class Solution
{
public:
    int singleNumber(vector<int> &arr)
    {
        int ans = 0;
        int val = 1;
        for (int i = 0; i < 32; i++)
        {
            int stbits = 0;
            for (int j = 0; j < arr.size(); j++)
            {

                stbits += arr[j] % 2;
                arr[j] = arr[j] >> 1;
            }

            if (stbits % 3 != 0)
                ans += val;

            if (i != 31)
                val = val << 1;
        }

        return ans;
    }
};