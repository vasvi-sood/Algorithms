class Solution
{

public:
    static bool sortindesc(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
    int carFleet(int target, vector<int> &p, vector<int> &s)
    {
        vector<pair<int, int>> arr(p.size());
        for (int i = 0; i < p.size(); i++)
            arr[i] = make_pair(p[i], s[i]);
        sort(arr.begin(), arr.end(), sortindesc);

        // for(int i=0;i<arr.size();i++)
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        int fleet = 1;
        for (int i = 1; i < arr.size(); i++)
        {

            if (arr[i].second == arr[i - 1].second)
            {
                if (arr[i].first != arr[i - 1].first)
                {
                    fleet++;
                }
            }
            else if (arr[i].second < arr[i - 1].second)
            {
                // cout<<arr[i].second<<" less than "<<arr[i-1].second;
                fleet++;
            }
            else
            {
                double a1 = ((double)arr[i - 1].first * arr[i].second);
                double a2 = ((double)arr[i].first * arr[i - 1].second);
                double a3 = a1 - a2;
                double a4 = (double)arr[i].second - arr[i - 1].second;

                double meet = a3 / a4;
                //                 cout<<( (double)arr[i-1].first*arr[i].second)<<" "<<((double)arr[i].first*arr[i-1].second)<<" "<<(double)arr[i].second-arr[i-1].second;

                if (meet > (double)target)
                    fleet++;
                else
                {
                    arr[i].first = arr[i - 1].first;
                    arr[i].second = arr[i - 1].second;
                }
            }
        }
        return fleet;
    }
};