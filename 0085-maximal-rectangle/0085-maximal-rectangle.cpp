class Solution {
public:
    int histo(vector<int> &arr) {
        int n=arr.size();
       stack<int> st;
       int ans=0;
       for(int i=0;i<n;i++) {
        while(!st.empty() && arr[st.top()]>=arr[i]) {
            int ind=arr[st.top()];
            st.pop();
            int pse=st.empty()?-1: st.top();
            int nse=i;
            ans=max(ans,ind*(nse-pse-1));
        }st.push(i);
       }
        while(!st.empty()) {
            int ind=arr[st.top()];
            st.pop();
            int pse=st.empty()? -1: st.top();
            int nse=n;
            ans=max(ans,ind*(nse-pse-1));
        }
       return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int  n=matrix.size();
       int m=matrix[0].size();
       vector<int> arr(m,0);
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]=='0') arr[j]=0;
                else arr[j]++;
            }ans=max(ans,histo(arr));
        }return ans;
    }
};