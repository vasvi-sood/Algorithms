class Solution {
public:
    int minLengthAfterRemovals(vector<int>& arr) {
        int n=arr.size();
        map<int, int> mp;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++; //frequency of numbers
        }
        // cout<<"size before"<<mp.size()<<"\n";
        for(auto elem: mp)
        {
            pq.push(elem.second); //frequency of element pushed in inc order
        }
        
        while(pq.size()>1)
        {
            int top=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            top--;
            second--;
            if(top>0)
            pq.push(top); // store how many elements are still remaining
            if(second>0)
            pq.push(second);
        }
        // cout<<"size"<<pq.size()<<"\n";
        if(pq.size()==0)
            return 0;
        return pq.top();
        
        
      
    }
};