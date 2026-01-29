class Solution {
    bool checkIn(vector<int> nums){
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]> nums[i]) return false;
        }return true;
    }
    bool checkDe(vector<int> nums){
        for(int i=1;i<nums.size();i++) {
            if(nums[i-1]< nums[i]) return false;
        }return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(nums[n-1]>nums[0]) return checkIn(nums);
        return checkDe(nums);
    }
};