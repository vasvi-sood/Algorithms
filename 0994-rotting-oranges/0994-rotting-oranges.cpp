class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visit;
        for(int i=0;i<grid.size();i++)
        {
            vector<bool> a(grid[0].size(),0);
            
            visit.push_back(a);
            // cout<<visit[i].size()<<"\n";
        }
        queue<vector<int>> q;
        //travel each node on grid that is rotten
        int cntfresh=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
               if(grid[i][j]==2)
               {
                   q.push({i,j,0});
                   visit[i][j]=1;
               }
              else  if(grid[i][j]==1)
                  cntfresh++;
            }
         int mx=0;
        // cout<<visit.size()<<" "<<visit[0].size()<<"\n";
        int cnt=0;
        while(!q.empty())
        {
            vector<int> parent=q.front();
            q.pop();
            int i=parent[0],j=parent[1],minutes=parent[2];
            mx=minutes;
            // cout<<i+1<<" "<<j<<"\n";
            // cout<<grid[i+1][j]<<"\n";
            // cout<<visit[i+1][j]<<"\n";
            if(i+1<grid.size() && grid[i+1][j]==1 && visit[i+1][j]==0)
            {
                q.push({i+1,j,minutes+1});
                visit[i+1][j]=1;
                cnt++;
            }
            if(j+1<grid[0].size() && grid[i][j+1]==1 && visit[i][j+1]==0)
            {
                q.push({i,j+1,minutes+1});
                visit[i][j+1]=1;
                cnt++;
            }
            if(i-1>=0 && grid[i-1][j]==1 && visit[i-1][j]==0)
            {
                q.push({i-1,j,minutes+1});
                visit[i-1][j]=1;
                cnt++;
            }
             if(j-1>=0 && grid[i][j-1]==1 && visit[i][j-1]==0)
            {
                q.push({i,j-1,minutes+1});
                visit[i][j-1]=1;
                 cnt++;
            }
        }
        
       
       if(cnt!=cntfresh)
                     return -1;
                     
              
        
        return mx;
    }
};