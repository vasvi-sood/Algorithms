class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(points[0][1] - points[0][0], points[0][0])); //y1-x1
        int mx = INT32_MIN;
        for (int i = 1; i < points.size(); i++)
        {
            int x2 = points[i][0];
            int y2 = points[i][1];
            while ((!pq.empty()))
            {
                int x1 = pq.top().second;
                // cout<<x2<<" "<<x1<<endl;
                if (x2 - x1 > k)
                    pq.pop();
                else
                    break;
            }
            if (!pq.empty())
            {
                // cout<<pq.top().first<<" "<<x2<<" "<<y2<<endl;
                mx = max(mx, pq.top().first + x2 + y2);
            }
            pq.push(make_pair(y2 - x2, x2));
        }
        return mx;
    }
};