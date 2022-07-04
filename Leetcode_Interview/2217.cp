class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int l) {
        int x=(l+1)/2;
        long long int fst=pow(10,x-1);
        vector<string> ans;
        for(int n: queries)
        {
            string s=to_string(fst+n-1);
            if(s.size()==x)
            ans.push_back(s);
            else
            ans.push_back("-1");   
        }
        int rem=l-x;
        vector<long long> a;
        for(string &num: ans)
        {
            if(num!="-1")
            {
            string scnd=num.substr(0,rem);
            reverse(scnd.begin(),scnd.end());
            num+=scnd;
            a.push_back(stol(num));
            }
            else
                a.push_back(-1);
        }
        
        return a;
    }
};