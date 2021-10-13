class Solution
{
    bool ispresent(string s, int pos, string source)
    {
        string str = s.substr(pos, source.size());
        if (str == source)
            return true;
        return false;
    }

public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &source, vector<string> &target)
    {
        map<int, string> mp1;
        map<int, string> mp2;
        for (int i = 0; i < indices.size(); i++)
        {
            int pos = indices[i];
            if (ispresent(s, pos, source[i]))
            {
                // cout<<"yup ";
                mp1[pos] = target[i];
                mp2[pos] = source[i];
            }
        }

        string str;
        int i = 0;
        while (i < s.size())
        {
            if (mp1.find(i) != mp1.end())
            {
                str += mp1[i];
                i += mp2[i].size();
            }
            else
            {
                str += s[i];
                ++i;
            }
        }

        return str;
    }
};