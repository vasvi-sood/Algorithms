class Solution {
void create_perm(vector<int>& nums,set<int> &used,vector<vector<int>> &ans, vector<int> &present)
                 {
                     if(used.size()==nums.size())
                     {
                         ans.push_back(present);
                         return;
                     }
                     
                     for(int j=0;j<nums.size();j++)
                     { 
                         int i=nums[j];
                         if(used.find(i)==used.end())
                         {
                             used.insert(i);
                             present.push_back(i);
                             create_perm(nums,used,ans,present);
                             used.erase(i);
                             present.pop_back();
                         }
                         
                     }
                 }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        set<int> used;
        vector<int> present;
        create_perm(nums,used,ans,present);
        return ans;
    }
};