class Solution
{
public:
    string longestPalindrome(string s)
    { // s= bab

        int n = s.length();         // n=3
        int mx_len = 0;             // mx_len 1
        string ans;                 // ans "b"
        for (int i = 0; i < n; i++) // i=1
        {
            int mid = i;   // mid=1
            int left = i;  // left 1
            int right = i; // right 1

            while (left >= 0 && right < n)
            {
                int len = right - left + 1; // len 1
                if (s[left] == s[right])    // s0 ==s0
                {
                    if (len > mx_len)
                    {
                        mx_len = len;
                        ans = s.substr(left, len);
                        // if(s[mid]=='a')
                        // {
                        //         cout<<left<<" "<<right<<endl;
                        // }
                    }
                }
                else
                {
                    break;
                }
                left--;
                right++;
            }
        }

        for (int i = 0; i < n - 1; i++) // i=1
        {

            int left = i;      // left 1
            int right = i + 1; // right 1

            while (left >= 0 && right < n)
            {
                int len = right - left + 1; // len 1
                if (s[left] == s[right])    // s0 ==s0
                {
                    if (len > mx_len)
                    {
                        mx_len = len;
                        ans = s.substr(left, len);
                    }
                }
                else
                {
                    break;
                }
                left--;
                right++;
            }
        }

        return ans;
    }
};