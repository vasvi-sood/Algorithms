//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int maxLenArea(vector<int> arr, int n)
  {
      stack<int> st1,st2;
      vector<int> ans1,ans2;
      //next smallest left
      for(int i=0;i<n;i++)
      {
          while(!st1.empty() && arr[st1.top()]>=arr[i])
          {
              st1.pop();
          }
          if(st1.empty())
          {
             ans1.push_back(-1);
          }
          else
          {
             ans1.push_back(st1.top()); 
          }
           st1.push(i);
      }
      //next smallest to right
      for(int i=n-1;i>=0;i--)
      {
          while(!st2.empty() && arr[st2.top()]>=arr[i])
          {
              st2.pop();
          }
          if(st2.empty())
          {
             ans2.push_back(n);
          }
          else
          {
             ans2.push_back(st2.top()); 
          }
           st2.push(i);
      }
      reverse(ans2.begin(),ans2.end());
      
      int maxarea=0;
      for(int i=0;i<n;i++)
      {
          int height=arr[i];
          int length=ans2[i]-ans1[i]-1;
          int area=height*length;
        //   if(length==3)
        //   cout<<ans2[i]<<ans1[i]<<" area ";
          maxarea=max(area,maxarea);
          
      }
    //   cout<<"\n";
      
      return maxarea;
      
  }
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
          vector<int> arr(m,0);
          int maxarea=0;
      
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(M[i][j]==0)
              arr[j]=0;
              else
              arr[j]+=1;
          }
          int area=maxLenArea(arr,m);
          
          maxarea=max(area,maxarea);
          
          
        }
        
        return maxarea;
     
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends