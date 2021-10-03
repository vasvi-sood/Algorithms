class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        map<char, queue<string>> mp;

        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i][0]].push(words[i]);
        }

        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            int num = mp[c].size();
            for (int j = 0; j < num; j++)
            {

                string elem = mp[c].front();
                mp[c].pop();
                if (elem.size() == 1)
                {

                    count++;
                }
                else
                {
                    mp[elem[1]].push(elem.substr(1));
                }
            }
        }

        return count;
    }
};