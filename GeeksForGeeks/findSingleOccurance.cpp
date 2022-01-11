// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int singleElement(int arr[], int N)
    {
        long int sum = 0;
        string s = "";
        for (int i = 0; i < 32; i++)
        {
            sum = 0;
            for (int j = 0; j < N; j++)
            {
                sum += (arr[j] % 2);
                arr[j] = arr[j] >> 1;
            }
            //  cout<<sum<<endl;
            sum = sum % 3;
            s = (sum == 0 ? '0' : '1') + s;
        }
        // cout<<s<<endl;

        return stol(s, 0, 2);
        // return 10;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;
        int arr[N];

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.singleElement(arr, N);
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends