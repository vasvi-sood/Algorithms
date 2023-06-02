//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>> st;
       vector<int> ans;
     
       for(int i=0;i<n;i++)
       {
          
               int consec=1;
               while(!st.empty() && price[i]>=st.top().first)
               {
                   consec+=st.top().second;
                   st.pop();
               }
               
            //  cout<<st.size()<<endl;
               st.push({price[i],consec});
               ans.push_back(consec);
           
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends