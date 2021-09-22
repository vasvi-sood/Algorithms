class Solution
{
    int connectedBfs(vector<vector<bool>> &visit, vector<vector<int>> &arr, int i, int j)
    {
        int connected = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visit[i][j] = true;
        while (!q.empty())
        {
            auto parent = q.front();
            q.pop();
            connected++;
            int i = parent.first;
            int j = parent.second;
            if (i + 1 < arr.size() && arr[i + 1][j] == 1 && !visit[i + 1][j])
            {
                q.push(make_pair(i + 1, j));
                visit[i + 1][j] = true;
            }
            if (i - 1 >= 0 && arr[i - 1][j] == 1 && !visit[i - 1][j])
            {
                q.push(make_pair(i - 1, j));
                visit[i - 1][j] = true;
            }
            if (j + 1 < arr[0].size() && arr[i][j + 1] == 1 && !visit[i][j + 1])
            {
                q.push(make_pair(i, j + 1));
                visit[i][j + 1] = true;
            }

            if (j - 1 >= 0 && arr[i][j - 1] == 1 && !visit[i][j - 1])
            {
                q.push(make_pair(i, j - 1));
                visit[i][j - 1] = true;
            }
        }

        return connected;
    }

    int connectedDfs(vector<vector<bool>> &visit, vector<vector<int>> &arr, int i, int j)
    {
        int connected = 0;
        if (i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size() || arr[i][j] == 0)
            return connected;

        if (!visit[i][j])
        {
            visit[i][j] = true;
            connected = 1;
            connected += connectedDfs(visit, arr, i + 1, j);
            connected += connectedDfs(visit, arr, i - 1, j);
            connected += connectedDfs(visit, arr, i, j + 1);
            connected += connectedDfs(visit, arr, i, j - 1);
        }
        return connected;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && !visit[i][j])
                {

                    int connected = connectedDfs(visit, grid, i, j);
                    ans = max(ans, connected);
                }
            }
        return ans;
    }
};