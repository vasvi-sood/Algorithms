class Solution
{
    void addforward(vector<string> &arr, int idx, string &s, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (idx < s.size())
            {
                arr[i] += s[idx];
                idx++;
            }
        }
    }
    void addbackward(vector<string> &arr, int idx, string &s, int n)
    {
        // if(n==0)
        //     return;
        for (int i = n - 1; i >= 1; i--)
        {
            if (idx < s.size())
            {
                arr[i] += s[idx];
                idx++;
            }
        }
    }

public:
    string convert(string s, int n)
    {
        if (n == 1)
            return s;
        vector<string> arr(n);
        for (int i = 0; i < s.size();)
        {
            addforward(arr, i, s, n); // arr 0->n
            i += n;
            addbackward(arr, i, s, n - 1);
            i += n - 2;
        }
        string ans = "";

        for (int i = 0; i < n; i++)
            ans += arr[i];

        return ans;
    }
};