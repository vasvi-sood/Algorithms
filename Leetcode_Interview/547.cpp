class Solution
{
    void dfs(int i, vector<bool> &visit, vector<vector<int>> &arr)
    {
        visit[i] = 1;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 1 && !visit[j])
                dfs(j, visit, arr);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &arr)
    {
        vector<bool> visit(arr.size(), 0);
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!visit[i])
            {
                dfs(i, visit, arr);
                count++;
            }
        }

        return count;
    }
};