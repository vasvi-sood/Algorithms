//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
      stack<pair<long long,int>> st1;
      stack<pair<long long,int>> st2;
    
      vector<int> index1;
      vector<int> index2;
      
   for(int i=0;i<n;i++)
   {
       while(!st1.empty() &&  st1.top().first>=arr[i])
       {
           st1.pop();
       }
       
    
       
       if(st1.empty())
       {
           index1.push_back(-1);
       }
       else
       {
           index1.push_back(st1.top().second);
       }
          st1.push({arr[i],i});
   }
   
      for(int i=n-1;i>=0;i--)
   {
       while(!st2.empty() &&  st2.top().first>=arr[i])
       {
           st2.pop();
       }
       
    
       
       if(st2.empty())
       {
           index2.push_back(n);
       }
       else
       {
          index2.push_back(st2.top().second);
       }
          st2.push({arr[i],i});
   }
   
   reverse(index2.begin(),index2.end());
      
    
    
    long long maxarea=0;
    for(int i=0;i<n;i++)
    {
        long long height=arr[i];
        long long base= index2[i]-index1[i]-1;
        long long area=base*height;
        maxarea=max(area,maxarea);
    }
    
    
    return maxarea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends