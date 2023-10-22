class Solution {
    
    bool isneighbour(string a, string b)
    {
        if(a==b)
            return false;
        bool flag=false;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                if(!flag)
                flag=true;
                else
                    return false;
            }
        }
        
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& arr) {
        map<string,vector<string>> adj;
        //add neigbours together
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(isneighbour(arr[i],arr[j]))
                {
                    adj[arr[i]].push_back(arr[j]);
                    adj[arr[j]].push_back(arr[i]);
                }
            }
        }
        
        queue<pair<string,int>> q; //name and level
        
        map<string,bool> visit;
        //if beginword in not in adj list
        if(adj.find(beginWord)==adj.end())
        {
         for(int i=0;i<arr.size();i++)
         {
             if(isneighbour(arr[i],beginWord))
                {
                    adj[arr[i]].push_back(beginWord);
                    adj[beginWord].push_back(arr[i]);
                }
         }
                 
        }
        
        q.push({beginWord,1});
        while(!q.empty())
        {
            string word=q.front().first;
            int level=q.front().second;
            q.pop();
            for(int i=0;i<adj[word].size();i++)
            {
                if(!visit[adj[word][i]])
                {
                    visit[adj[word][i]]=1;
                    q.push({adj[word][i],level+1});
                    if(adj[word][i]==endWord)
                    {
                        return level+1;
                    }
                }
           }
            
        }
        
        
        return 0;
        
    }
};