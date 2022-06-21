class Solution
{
    int furthestBuilding(int i, vector<int> &heights, int b, int l)
    {
        // cout<<i<<" "<<heights[i]<<" "<<b<<" "<<l<<endl;
        if (i == heights.size() - 1)
        {
            // cout<<i<<endl;
            return i;
        }
        if (heights[i] >= heights[i + 1])
            return furthestBuilding(i + 1, heights, b, l);
        int bricks = heights[i + 1] - heights[i];
        if (bricks > b && l == 0)
        {
            // cout<<i<<" no resources"<<endl;
            return i;
        }
        int build = i, build2 = i;
        if (bricks <= b)
            build = furthestBuilding(i + 1, heights, b - bricks, l);
        if (l > 0)
            build2 = furthestBuilding(i + 1, heights, b, l - 1);
        // cout<<max(build,build2)<<" best ans"<<endl;
        return max(build, build2);
    }

public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        return furthestBuilding(0, heights, bricks, ladders);
    }
};