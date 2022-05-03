class Solution {
    int findpivot(vector<int>& nums)
    {
    int begin=0;
    int n=nums.size();
    int end=n-1;
        
        int mid=(begin+end)/2;
        while(nums[mid]<nums[mid+1])
        {
            mid=(begin+end)/2;
            if(nums[mid]>nums[0])
            {
                begin=mid;
            }
            else
            {
                end=mid;
            }
        }
        return mid;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums[n-1]>=nums[0])
        {
            if(binary_search(nums.begin(),nums.end(),target))
                  return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            return -1;
         }
        int pvt=findpivot(nums);
        // cout<<pvt<<endl;
          // cout<<*(nums.begin()+pvt+1)<<endl;
   
        if(binary_search(nums.begin(),nums.begin()+pvt+1,target))
        {
               // cout<<"here"<<endl;
                  return lower_bound(nums.begin(),nums.begin()+pvt+1,target)-nums.begin();
        }
         if(binary_search(nums.begin()+pvt+1,nums.end(),target))
                  return lower_bound(nums.begin()+pvt+1,nums.end(),target)-nums.begin();

        return -1;
        
    
    }
};