class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++)
        {
            string word=strs[i];
            sort(word.begin(),word.end());
            mp[word].push_back(i);
        }
          vector<vector<string>> ans;
        for(auto me: mp)
        {
            string word=me.first;
            vector<string> a;
            for(int i=0;i<mp[word].size();i++)
            {
              a.push_back(strs[mp[word][i]]);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};