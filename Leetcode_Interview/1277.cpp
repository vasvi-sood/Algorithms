class Solution
{
    //returns the number of total squares if arr[i][j] is the top left corner
    int squares(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &mem)
    {
        if (i >= arr.size() || j >= arr[0].size())
            return 0;
        if (arr[i][j] == 0)
            return 0;
        if (mem[i][j] != 0)
            return mem[i][j];
        int a = squares(i + 1, j, arr, mem);
        int b = squares(i, j + 1, arr, mem);
        int c = squares(i + 1, j + 1, arr, mem);
        mem[i][j] = 1 + min(a, min(b, c));
        return mem[i][j];
    }

public:
    int countSquares(vector<vector<int>> &arr)
    {
        vector<vector<int>> mem(arr.size(), vector<int>(arr[0].size(), 0));
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
            for (int j = 0; j < arr[0].size(); j++)
                count += squares(i, j, arr, mem);

        return count;
    }
};