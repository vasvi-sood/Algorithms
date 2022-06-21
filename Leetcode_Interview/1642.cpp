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
    int furthestBuilding(vector<int> &heights, int bricks, int ladder)
    {
        // return furthestBuilding(0, heights, bricks, ladders);
        vector<int> arr;
        vector<int> building;
        // difference array;
        for (int i = 0; i < heights.size() - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
            {
                arr.push_back(diff);
                building.push_back(i); // i->i+1 diff req
            }
        }

        // for(int i=0;i<arr.size();i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<arr.size();i++)
        //     cout<<building[i]<<" ";
        // if(arr.size()==0)
        //     return heights.size()-1;
        /*
        Id diff is less than bricks

Bricks-diff

Keep diff in a list (pq)

   1. Else

   2. if ladder is present

  3. replace largest elem with ladder (pq.top)

Bricks+=largest element
laders--

If(ladder is not present )

Return curr building



        */

        int sum = 0;
        priority_queue<int> pq;
        int ans = heights.size() - 1;
        for (int i = 0; i < arr.size(); i++)
        {
            int diff = arr[i];
            if (diff <= bricks)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else
            {
                if (ladder > 0)
                {
                    bricks -= diff;
                    pq.push(diff);
                    int elem = pq.top();
                    // cout<<"\n"<<elem;
                    pq.pop();
                    bricks += elem;
                    ladder--;
                }
                else
                {
                    ans = building[i];
                    break;
                }
            }

            // cout<<"\n"<<bricks<<" "<<ladder;
        }

        return ans;
    }
};