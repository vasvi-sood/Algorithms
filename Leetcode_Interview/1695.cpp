class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &arr)
    {
        set<int> st;
        int n = arr.size();
        int mx = 0;
        map<int, int> mp;
        int j = 0;
        vector<int> sum(n);
        sum[0] = arr[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + arr[i];
        for (int i = 0; i < n;)
        {

            // for(int j=i;j<n;j++)
            // {
            //     if(st.find(arr[j])==st.end())
            //     {
            //         st.insert(arr[j]);
            //         sum+=arr[j];
            //         mx=max(sum,mx);
            //     }
            //     else
            //     {
            //      break;
            //     }
            // }

            int l;
            int repeat = 0;
            for (l = j; l < n; l++)
            {
                if (mp.find(arr[l]) == mp.end() || mp[arr[l]] < i)
                {
                    mp[arr[l]] = l;
                    int s = sum[l] - (i - 1 >= 0 ? sum[i - 1] : 0);
                    mx = max(s, mx);
                }
                else
                {
                    repeat = arr[l];
                    break;
                }
            }

            if (l == n)
                break;

            int idx = mp[repeat];
            i = idx + 1;
            j = l;

            // cout<<i<<" "<<l<<" "<<j<<endl;
        }

        return mx;
    }
};