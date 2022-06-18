class WordFilter
{
    unordered_map<string, int> mp;

public:
    WordFilter(vector<string> &words)
    {
        int idx = 0;
        for (string word : words)
        {
            string prefix = "";
            string suffx = "";
            for (int i = 0; i < 10 && i < word.size(); i++)
            {
                prefix += word[i];
                string suffix = "";
                int l = word.size() - 10;
                int len = max((l), 0);
                for (int j = word.size() - 1; j >= len; j--)
                {
                    suffix = word[j] + suffix;
                    mp[prefix + "." + suffix] = idx;
                }
            }

            idx++;
        }
    }

    int f(string prefix, string suffix)
    {
        string str = prefix + "." + suffix;
        if (mp.find(str) != mp.end())
            return mp[str];
        else
            return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */