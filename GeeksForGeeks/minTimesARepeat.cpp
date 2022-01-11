// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    void repeat(string &s, string a, int n)
    {
        for (int i = 0; i < n; i++)
            s += a;
    }

public:
    int minRepeats(string a, string b)
    {
        if (b.size() < a.size())
        {
            if (a.find(b) != string::npos)
                return 0;
            string s = a + a; //repeat a 1 time
            if (s.find(b) != string::npos)
                return 1;
        }
        else
        {
            int n = b.size() / a.size();
            if (b.size() % a.size() != 0)
                n++;

            string s;
            repeat(s, a, n);
            if (s.find(b) != string::npos)
            {
                //  cout<<s.find(b)<<" ";
                return n;
            }
            s += a;
            if (s.find(b) != string::npos)
                return n + 1;
        }
        return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
} // } Driver Code Ends