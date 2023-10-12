class Solution {
    
public:
     void func(vector<int>& arr,vector<vector<int>> &ans,int target,int sum,vector<int> used,int i)
     {
//       cout<<i<<": ";
//          for(int i=0;i<used.size();i++)
//              cout<<used[i]<<" ";
         
//          cout<<"\n";
         
//           if(target==sum)
//          {
           
//              ans.push_back(used);
//              return;
//          }
         
//          if(sum>target || i>=arr.size())
//              return;
        
         
//          func(arr,ans,target,sum,used,i+1);
//          used.push_back(arr[i]);
//          func(arr,ans,target,sum+arr[i],used,i+1);
         
         
         
     }
    
   void func(vector<int>& arr, int target, map<int,vector<vector<int>>> &mp)
    {
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            int num=arr[i];
            sum=arr[i];
            mp[sum].push_back({arr[i]});
            
           
            for(int j=num+2;j<=target;j++)
            {
                 vector<vector<int>> temp;
                int tomake=j;
                 // cout<<j<<"\n";
                for(vector<int> a: mp[tomake-num])
                if(a.size()>0)
                {
                    // cout<<"here"<<"\n";
                    a.push_back(num);
                    temp.push_back(a);
                    // for(int k=0;k<temp.size();k++)
                    //     for(int l=0;l<temp[k].size();l++)
                    //     cout<<temp[k][l]<<" ";
                        
                         // cout<<"\n";
                }
                
                for(int k=0;k<temp.size();k++)
                mp[tomake].push_back(temp[k]);
                
            }
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
    map<int,vector<vector<int>>> mp;
        sort(arr.begin(),arr.end());
        func(arr,target,mp);
        return mp[target];
   
    }
};