class Solution
{
public:
    int subarraySum(vector<int> &arr, int k)
    {
        map<int, int> sum;
        sum[0] = 1;
        int sm = 0;
        int count = 0;
        for (int i = 1; i <= arr.size(); i++)
        {
            sm += arr[i - 1];
            int req = sm - k;
            // cout<<req<<" ";
            if (sum.find(req) != sum.end())
            {
                // cout<<sum[req]<<endl;
                count += sum[req];
            }

            sum[sm]++;
        }

        return count;
    }
};