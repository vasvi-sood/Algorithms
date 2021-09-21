class Solution
{
    vector<vector<int>> find_nums_adding_to(vector<int> &arr, int elem)
    {
        int fst = -elem;
        vector<vector<int>> a;
        set<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            if (st.find(arr[i]) == st.end())
            {
                //           if(elem==-3 || elem==-4)
                // {
                //     cout<<elem<<": "<<arr[i]<<" "<<elem-arr[i]<<endl;
                // }
                if (elem - arr[i] == arr[i])
                {
                    if (count(arr.begin(), arr.end(), arr[i]) > 1)
                    {
                        vector<int> b(3);
                        b[0] = fst;
                        b[1] = arr[i];
                        b[2] = elem - arr[i];
                        st.insert(arr[i]);
                        a.push_back(b);
                    }
                }
                else if (binary_search(arr.begin(), arr.end(), elem - arr[i]))
                {

                    vector<int> b(3);
                    b[0] = fst;
                    b[1] = arr[i];
                    b[2] = elem - arr[i];
                    st.insert(arr[i]);
                    st.insert(elem - arr[i]);
                    a.push_back(b);
                }
            }
        }

        return a;
    }

public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        vector<vector<int>> ans;
        if (arr.size() < 3)
            return ans;

        set<int> set_positive;
        vector<int> arr_positive;
        set<int> set_negative;
        vector<int> arr_negative;
        vector<int> arr_0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] < 0)
            {
                set_negative.insert(arr[i]);
                arr_negative.push_back(arr[i]);
            }
            else if (arr[i] > 0)
            {
                set_positive.insert(arr[i]);
                arr_positive.push_back(arr[i]);
            }
            else
            {
                arr_0.push_back(arr[i]);
            }
        }
        sort(arr_negative.begin(), arr_negative.end());
        sort(arr_positive.begin(), arr_positive.end());
        for (int elem : set_negative)
        {
            vector<vector<int>> a = find_nums_adding_to(arr_positive, abs(elem));
            for (auto i : a)
            {
                ans.push_back(i);
            }
        }
        for (int elem : set_positive)
        {
            vector<vector<int>> a = find_nums_adding_to(arr_negative, -elem);
            for (auto i : a)
            {
                ans.push_back(i);
            }
        }

        if (arr_0.size() != 0)
        {
            for (auto elem : set_negative)
            {
                if (set_positive.find(abs(elem)) != set_positive.end())
                {
                    vector<int> a;
                    a.push_back(elem);
                    a.push_back(0);
                    a.push_back(-elem);
                    ans.push_back(a);
                }
            }
        }
        if (arr_0.size() >= 3)
        {

            vector<int> b(3);
            b[0] = 0;
            b[1] = 0;
            b[2] = 0;
            ans.push_back(b);
        }
        return ans;
    }
};