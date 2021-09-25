class Solution
{

    int sol(vector<vector<int>> &arr, int y)
    {
        int count = 0;
        for (int i = 0; i + y <= arr.size(); i++)
            for (int j = 0; j + y <= arr[0].size(); j++)
            {
                int flag = 0;
                for (int k = i; k < i + y; k++)
                {
                    for (int l = j; l < j + y; l++)
                    {
                        if (arr[k][l] == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1)
                        break;
                }
                if (flag == 0)
                    count++;
            }
        return count;
    }

public:
    int countSquares(vector<vector<int>> &arr)
    {
        int squares = min(arr.size(), arr[0].size());
        int count = 0;
        for (int i = 1; i <= squares; i++)
            count += sol(arr, i);
        return count;
    }
};