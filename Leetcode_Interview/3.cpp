class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        long mx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            set<char> st;
            long count = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (st.find(s[j]) == st.end()) //not fount
                {
                    count++;
                    st.insert(s[j]);
                }
                else
                    break;
            }
            mx = max(mx, count);
        }
        return (int)mx;
    }
};