class Solution {
public:
    long long sumation(vector<vector<int>> & arr) {
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                sum+=abs(arr[i][j]);
            }
        }return sum;
    }
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int count=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<0) count++;
            }
        }long long sum=sumation(matrix);
        if(count %2) {
            int mini=INT_MAX;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) mini=min(mini,abs(matrix[i][j]));
            }return sum -(2*mini);
        }return sum;
    }
};