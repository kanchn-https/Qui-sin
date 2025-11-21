class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low=0,high=0,pro=1,count=0;
        int n=nums.size();
        if(k<=1) return 0;
        while(high<n) {
            pro*=nums[high];
            while(pro>=k) pro/=nums[low++];
            count+=1+(high-low);
            high++;
        }return count;
    }
};