class Solution {
public:
    vector<int> prefix(vector<int> &arr, int n) {
        vector<int> prefixSum(n);
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++) {
            prefixSum[i]=max(prefixSum[i-1],arr[i]);
        }return prefixSum;
    }
    vector<int> suffix(vector<int> &arr, int n) {
        vector<int> suffixSum(n);
        suffixSum[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) {
            suffixSum[i]=max(suffixSum[i+1],arr[i]);
        }return suffixSum;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        vector<int> leftSum= prefix(height,n);
        vector<int> rightSum= suffix(height,n);
        
        for(int i=0;i<n;i++) {
            if(leftSum[i]>height[i] && rightSum[i]>height[i]) {
                total+=(min(leftSum[i],rightSum[i])-height[i]);
            }
        }return total;
    }
};