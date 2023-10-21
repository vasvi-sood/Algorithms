class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> visit;
        for(int i=0;i<grid.size();i++)
        {
            vector<int> a(grid[0].size(),0);
            
            visit.push_back(a);
            // cout<<visit[i].size()<<"\n";
        }
        queue<vector<int>> q;
        //travel each node on grid that is rotten
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
               if(grid[i][j]==2)
                   q.push({i,j,0});
            }
        
        // cout<<visit.size()<<" "<<visit[0].size()<<"\n";
        while(!q.empty())
        {
            vector<int> parent=q.front();
            q.pop();
            int i=parent[0],j=parent[1],minutes=parent[2];
            // cout<<i+1<<" "<<j<<"\n";
            // cout<<grid[i+1][j]<<"\n";
            // cout<<visit[i+1][j]<<"\n";
            if(i+1<grid.size() && grid[i+1][j]==1 && visit[i+1][j]==0)
            {
                q.push({i+1,j,minutes+1});
                visit[i+1][j]=minutes+1;
            }
            if(j+1<grid[0].size() && grid[i][j+1]==1 && visit[i][j+1]==0)
            {
                q.push({i,j+1,minutes+1});
                visit[i][j+1]=minutes+1;
            }
            if(i-1>=0 && grid[i-1][j]==1 && visit[i-1][j]==0)
            {
                q.push({i-1,j,minutes+1});
                visit[i-1][j]=minutes+1;
            }
             if(j-1>=0 && grid[i][j-1]==1 && visit[i][j-1]==0)
            {
                q.push({i,j-1,minutes+1});
                visit[i][j-1]=minutes+1;
            }
        }
        
        int mx=0;
         for(int i=0;i<grid.size();i++)
         {
             for(int j=0;j<grid[0].size();j++)
             {
                 if(grid[i][j]==1)
                 {
                     if(visit[i][j]==0)
                     return -1;
                     else
                         mx=max(mx,visit[i][j]);
                 }
                
             }
         }
        
        return mx;
    }
};