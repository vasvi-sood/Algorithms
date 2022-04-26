class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int mx=(right-left)*min(height[left],height[right]);
        while(left<right)
        {
            mx=max(mx,(right-left)*min(height[left],height[right]));
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        
        return mx;
    }
};