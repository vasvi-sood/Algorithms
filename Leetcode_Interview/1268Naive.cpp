class Solution {
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& words, string search) {
        map<string,set<string>> mp;
        sort(words.begin(),words.end());
        for(string word: words)
        {
            string inst="";
            for(char c: word)
            {
                inst+=c;
                if(mp[inst].size()<3)
                mp[inst].insert(word);
            }
        }
        vector<vector<string>> arr;
        string st="";
        for(char c:search)
        {
            st+=c;
            vector<string> st3;
            for(auto elem: mp[st])
            {
                if(st3.size()>=3)
                    break;
                st3.push_back(elem);
            }
            
            arr.push_back(st3);
            
        }
        
        return arr;
    }
};