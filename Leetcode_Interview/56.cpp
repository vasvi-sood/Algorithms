class Solution
{

    void mrge(int i, int j, vector<vector<int>> &intervals)
    {
        intervals[i][0] = min(intervals[i][0], intervals[j][0]);
        intervals[i][1] = max(intervals[i][1], intervals[j][1]);
        intervals.erase(intervals.begin() + j);
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        stack<vector<int>> s;
        s.push(intervals[0]);

        for (auto i : intervals)
        {
            if (i[0] <= s.top()[1])
            {
                auto j = s.top();
                s.pop();
                int a = min(j[0], i[0]);
                int b = max(j[1], i[1]);
                s.push({a, b});
            }
            else
            {
                s.push(i);
            }
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};