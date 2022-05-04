
class Solution
{
    string trim(const std::string &s)
    {
        auto start = s.begin();
        while (start != s.end() && std::isspace(*start))
        {
            start++;
        }

        auto end = s.end();
        do
        {
            end--;
        } while (std::distance(start, end) > 0 && std::isspace(*end));

        return std::string(start, end + 1);
    }

public:
    string reverseWords(string s)
    {
        string ans;
        s = trim(s);
        s = " " + s;
        string word;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (s[i + 1] == ' ')
                    continue;
                else
                {
                    ans += word + " ";
                    word = "";
                }
            }
            else
            {
                word = s[i] + word;
            }
        }

        ans = trim(ans);
        return ans;
    }
};