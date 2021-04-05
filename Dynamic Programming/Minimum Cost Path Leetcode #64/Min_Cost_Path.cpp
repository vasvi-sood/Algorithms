#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
      
       vector<vector<int>> arr(grid.size());
       arr[0].push_back(grid[0][0]);
        for(int i=1;i<grid.size();i++)
        arr[i].push_back(grid[i][0]+arr[i-1][0]) ; 
         for(int i=1;i<grid[0].size();i++)
         arr[0].push_back(grid[0][i]+arr[0][i-1]);
          for(int i=1;i<grid.size();i++)
         for(int j=1;j<grid[0].size();j++)
           arr[i].push_back(min(arr[i-1][j],arr[i][j-1])+grid[i][j]);

           return arr[grid.size()-1][grid[0].size()-1];


        }
};
