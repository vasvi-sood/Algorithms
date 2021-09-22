class Solution
{
    void twoSum(vector<int> &arr, int start, int first, int target, vector<vector<int>> &ans)
    {
        int st = start;

        int end = arr.size() - 1;
        while (start < end)
        {
            int sum = arr[start] + arr[end];

            if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                if (arr[start] == arr[start - 1] && start != st)
                {

                    start++;
                }
                else if (arr[end] == arr[end - 1] && end - 1 != start)
                {
                    end--;
                }

                else
                {
                    vector<int> b(3);
                    b[0] = first;
                    b[1] = arr[start];
                    b[2] = arr[end];
                    ans.push_back(b);
                    start++;
                    end--;
                }
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {

        vector<vector<int>> ans;
        // if(arr.size()<3)
        //     return ans;
        sort(arr.begin(), arr.end());
        int k = arr.size();
        for (int i = 0; i < (k - 2); i++)
        {

            if (i == 0 || arr[i] != arr[i - 1])
            {
                int first = arr[i];
                twoSum(arr, i + 1, first, -first, ans);
            }
        }
        // for(int i=0;i<(arr.size()-2);i++)
        // {
        //     cout<<"hey"<<endl;
        // }

        return ans;
    }
};