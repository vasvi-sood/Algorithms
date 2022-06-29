class Solution
{
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        set<int> st;
        sort(people.begin(), people.end(), compare);
        for (int i = 0; i < people.size(); i++)
        {
            st.insert(i);
        }

        //         for(int i=0;i<people.size();)
        //         {
        //             int idx=i;
        //             vector<int> a;
        //             a.push_back(people[i][1]);
        //             while(i+1<people.size() && people[i][0]==people[i+1][0])
        //             {
        //                 a.push_back(people[i+1][1]);
        //                 i++;
        //             }
        //             sort(a.begin(),a.end(),greater<int>());
        //             int k=0;
        //             for(int j=idx;j<=i;j++)
        //             {
        //                 // cout<<a[k]<<"\n";
        //                 people[j][1]=a[k];
        //                 k++;
        //             }
        //             i++;
        //         }

        // }
        vector<vector<int>> arr(people.size());
        for (int i = 0; i < people.size(); i++)
        {
            int pos = people[i][1];
            auto it = st.begin();
            advance(it, pos);
            int x
                //         for(int i=0;i<people.size();)
                //         {
                //             int idx=i;
                //             vector<int> a;
                //             a.push_back(people[i][1]);
                //             while(i+1<people.size() && people[i][0]==people[i+1][0])
                //             {
                //                 a.push_back(people[i+1][1]);
                //                 i++;
                //             }
                //             sort(a.begin(),a.end(),greater<int>());
                //             int k=0;
                //             for(int j=idx;j<=i;j++)
                //             {
                //                 // cout<<a[k]<<"\n";
                //                 people[j][1]=a[k];
                //                 k++;
                //             }
                //             i++;
                //         }

                // } = *it;
                arr[x] = people[i];
            st.erase(it);
        }

        return arr;
    }
};