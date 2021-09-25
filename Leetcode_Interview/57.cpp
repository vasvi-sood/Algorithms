class Solution
{
    bool check_merge(vector<int> a, vector<int> neww)
    {
        int i = a[0];
        int j = a[1];
        if (j < neww[0] || i > neww[1])
            return false;
        return true;
    }

public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &nw)
    {
        if (intervals.size() <= 0)
            return {nw};

        vector<vector<int>> ans;
        int a = -1, b = -1;
        for (int i = 0; i < intervals.size(); i++)
        {
            bool z = check_merge(intervals[i], nw);
            if (z)
            {
                a = i;
                break;
            }
        }
        int k = intervals.size();
        for (int i = k - 1; i >= 0; i--)
        {
            bool z = check_merge(intervals[i], nw);
            if (z)
            {
                b = i;
                break;
            }
        }
        int pos = -1;
        if (a == -1 && b == -1)
        {
            if (nw[1] < intervals[0][0])
            {
                pos = 0;
            }
            else if (nw[0] > intervals[intervals.size() - 1][1])
                pos = 1;

            if (pos == 0)
            {
                intervals.insert(intervals.begin(), nw);
                return intervals;
            }
            else if (pos == 1)
            {
                intervals.push_back(nw);
                return intervals;
            }
            else
            {
                for (int i = 0; i + 1 < intervals.size(); i++)
                {
                    if (nw[0] > intervals[i][1] && nw[1] < intervals[i + 1][0])
                    {
                        intervals.insert(intervals.begin() + i + 1, nw);
                        return intervals;
                    }
                }
            }
        }
        // cout<<a<<" "<<b<<endl;
        for (int i = 0; i < a; i++)
        {
            ans.push_back(intervals[i]);
        }
        int r = min(intervals[a][0], nw[0]);
        int y = max(intervals[b][1], nw[1]);
        ans.push_back({r, y});
        for (int i = b + 1; i < intervals.size(); i++)
        {
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};