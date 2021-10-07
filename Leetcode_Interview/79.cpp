class Solution
{
    bool sol(int len, vector<vector<char>> &arr, int pos, int i, int j, string &word, vector<vector<bool>> &visit)
    {

        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size())
            return false;
        char c = word[pos];

        if (len <= 1) //len of strig to be found
            return true;

        visit[i][j] = true;
        bool ans = false;
        if (i + 1 < arr.size() && !visit[i + 1][j] && arr[i + 1][j] == word[pos + 1])
            ans = ans || sol(len - 1, arr, pos + 1, i + 1, j, word, visit);

        if (j + 1 < arr[0].size() && !visit[i][j + 1] && arr[i][j + 1] == word[pos + 1])
            ans = ans || sol(len - 1, arr, pos + 1, i, j + 1, word, visit);

        if (i - 1 >= 0 && !visit[i - 1][j] && arr[i - 1][j] == word[pos + 1])
            ans = ans || sol(len - 1, arr, pos + 1, i - 1, j, word, visit);

        if (j - 1 >= 0 && !visit[i][j - 1] && arr[i][j - 1] == word[pos + 1])
            ans = ans || sol(len - 1, arr, pos + 1, i, j - 1, word, visit);

        visit[i][j] = false;
        return ans;
    }

public:
    bool exist(vector<vector<char>> &arr, string word)
    {
        vector<vector<bool>> visit(arr.size(), vector<bool>(arr[0].size(), false));

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                bool ans = false;
                if (arr[i][j] == word[0])
                {
                    ans = sol(word.size(), arr, 0, i, j, word, visit);
                    if (ans)
                        return true;
                }
            }
        }
        return false;
    }
};