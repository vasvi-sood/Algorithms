//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& interval) {
         sort(interval.begin(),interval.end());
         vector<vector<int>> ans(1,interval[0]);
         int j=0;
         for(int i=1;i<interval.size();i++)
         {
             if(max(ans[j][0],interval[i][0])<=min(ans[j][1],interval[i][1]))
             {
                 //ans[j][0] same
                 ans[j][1]=max(ans[j][1],interval[i][1]);
             }
             else
             {
                 ans.push_back(interval[i]);
                 j++;
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends