// naive
// mlog n
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = -1;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][n - 1] >= target)
            {
                row = i;
                break;
            }
        }

        if (row == -1)
            return false;

        return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};

// consider the input set as a bst
// starting from (0,m-1)^th cell and left or down are it's children then it's a bst
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int column = n - 1;
        while (row < m && column >= 0)
        {
            if (matrix[row][column] == target)
            {
                return true;
            }
            else if (matrix[row][column] < target)
            {
                row++;
            }
            else
            {
                column--;
            }
        }

        return false;
    }
};