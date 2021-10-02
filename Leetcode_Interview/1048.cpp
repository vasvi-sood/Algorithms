class Solution
{
    bool isneighbour(string w1, string w2) //w2>w1
    {
        int i = 0;
        for (int j = 0; j < w2.size(); j++)
        {
            if (w1[i] == w2[j])
                i++;
            else
            {
                if (i != j)
                    return false;
            }
        }
        return true;
    }

    int dfs(map<int, vector<string>> &mp, int node, string nodeword, map<string, int> &len)
    {
        if (len[nodeword] != 0)
            return len[nodeword];
        int path = 0;
        for (string word : mp[node + 1])
        {
            if (isneighbour(nodeword, word))
                path = max(path, dfs(mp, node + 1, word, len));
        }
        // cout<<1+path<<endl;
        len[nodeword] = 1 + path;
        return 1 + path;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        map<string, int> length;
        map<int, vector<string>> mp;
        for (string word : words)
            mp[word.size()].push_back(word);

        int pathlen = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            pathlen = max(pathlen, dfs(mp, word.size(), word, length));
            // cout<<pathlen<<endl;
        }
        return pathlen;
    }
};