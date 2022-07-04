class Solution {
public:
    int minDeletions(string s) {
       vector<int> arr(26,0);
        for(char c:s)
        {
           arr[c-'a']++;
        }
        int del=0;
      sort(arr.begin(),arr.end(),greater<int>());
       
        int mxfreq=s.size();
        for(int i=0;i<26;i++)
        {
            if(arr[i]>mxfreq)
            {
                del+=arr[i]-mxfreq;
                arr[i]=mxfreq;
            }
            mxfreq=max(arr[i]-1,0);
                
            
        }
        
 
        
        return del;
    }
};