class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        vector<int> bal(n,0);
        unordered_map<int,int> first;
        int ans=0;
        for(int i=n-1;i>=0;i--) {
            int x=nums[i];
            auto it=first.find(x);
            if(it!=first.end()) bal[it->second]=0;
            first[x]=i;
            bal[i]=((x&1)==0)? 1:-1;
            int s=0;
            for(int j=i;j<n;j++) {
                s+=bal[j];
                if(s==0) ans=max(ans,j-i+1);
            }
        }return ans;
    }
};