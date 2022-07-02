class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long int M = 1000000007;
        int mxh = horizontalCuts[0] - 0;

        for (int i = 0; i < horizontalCuts.size() - 1; i++)
        {
            mxh = max(mxh, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        mxh = max(h - horizontalCuts[horizontalCuts.size() - 1], mxh);

        int mxv = verticalCuts[0] - 0;

        for (int i = 0; i < verticalCuts.size() - 1; i++)
        {
            mxv = max(mxv, verticalCuts[i + 1] - verticalCuts[i]);
        }
        mxv = max(w - verticalCuts[verticalCuts.size() - 1], mxv);

        int ans = (mxh % M * mxv % M) % M;
        return ans;
    }
};