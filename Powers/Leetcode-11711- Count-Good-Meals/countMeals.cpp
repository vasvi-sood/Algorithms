class Solution {
public:
   
    int countPairs(vector<int>& arr) {
        int M=1000000007;
        long int count=0;
        map<int,int> map;
        
        for(int i=0;i<arr.size();i++)
        {
           map[arr[i]]++; 
        }
        
        for (auto del : map)
        {
             int num=del.first;
        // cout << del.first << "   " << del.second 
        //      << endl; 
              int i=0;
            if(num!=0)
             i=ceil(log2(del.first));
              for(;i<=21;i++)
              {
                 
                   int req=pow(2,i)-del.first;
                if(req==num)
                {
                    count=(count%M+((long int)(del.second)*(long int)(del.second-1)/2)%M)%M;
                }
                 else
                 
                     if(req>num && map.find(req)!=map.end())
                     {
                       
                    count=(count%M+(del.second*map[req])%M)%M;
                 }
                    

     
              }
        }
        
        
       
        return count;
    }
   
};
