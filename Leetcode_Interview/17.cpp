class Solution {
  void  inorder(vector<vector<char>> &arr, string &s, int level, vector<string> &ans, string cons )
    {
        if(level>=s.size())
        {
            ans.push_back(cons);
            return;
        }
        int dig=s[level]-'0';
        for(char a: arr[dig])
        {
            string cons2=cons+a;
            inorder(arr,s,level+1,ans,cons2);
        }
    }
public:
    vector<string> letterCombinations(string s) {
       vector<vector<char>> arr(10);
        char j='a';
     
        for(int i=2;i<=6;i++)
        {
            int count=0;
            vector<char> temp(3);
            for(;count<3;j++)
            {
                temp[count]=j;
                count++;
            }
            
            arr[i]=temp;
        }
        
        arr[7]={'p','q','r','s'};
        arr[8]={'t','u','v'};
        arr[9]={'w','x','y','z'};
        
        vector<string> ans;
           if(s=="")
            return ans;
        inorder(arr,s,0,ans,"");
        return ans;
    }
};