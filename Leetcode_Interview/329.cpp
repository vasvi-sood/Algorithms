class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &visit, vector<vector<int>> &mem)
    {

        if (visit[i][j] == true)
            return 0;

        if (mem[i][j] != 0)
            return mem[i][j];

        int mx = 1;
        int count = 1;
        if (i + 1 < arr.size() && arr[i + 1][j] > arr[i][j])
        {
            count = 1 + dfs(i + 1, j, arr, visit, mem);
            mx = max(mx, count);
        }
        if (i - 1 >= 0 && arr[i - 1][j] > arr[i][j])
        {
            count = 1 + dfs(i - 1, j, arr, visit, mem);
            mx = max(mx, count);
        }
        if (j + 1 < arr[0].size() && arr[i][j + 1] > arr[i][j])
        {
            count = 1 + dfs(i, j + 1, arr, visit, mem);
            mx = max(mx, count);
        }
        if (j - 1 >= 0 && arr[i][j - 1] > arr[i][j])
        {
            count = 1 + dfs(i, j - 1, arr, visit, mem);
            mx = max(mx, count);
        }

        // visit[i][j]=false;
        mem[i][j] = mx;
        return mx;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_route = 1;
        vector<vector<bool>> visit(matrix.size(), vector<bool>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                int path = dfs(i, j, matrix, visit, mem);
                max_route = max(max_route, path);
            }
        }
        return max_route;
    }
};