class Solution {
public:
    int countPairs(vector<vector<int>>& arr, int k) {
        
        map<pair<int,int>,int> mp;
        for(auto elem: arr)
        {
            mp[{elem[0],elem[1]}]++;
        }
        long int count=0;
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i][0], y=arr[i][1];
            pair<int,int> curr={x,y};
            for(int j=0;j<=k;j++)
            {
                int rx=j; //required x
                int vx=rx^x; //what x staisfes this condotion
                
                int ry=k-j;
                int vy=ry^y;
                
                pair<int,int> fnd={vx,vy};
                if(mp.find(fnd)!=mp.end()) //find the required coordinate in set
                {
                    if(curr==fnd)
                    count+=(mp[fnd]-1);// apne ilava sabke saath banayega pair but double counting hogi
                    else //agar alag hai toh sabke sath pair bayega
                        count+=mp[fnd];
                        
                }
                
            }
        }
        
        return count/2;
    }
};