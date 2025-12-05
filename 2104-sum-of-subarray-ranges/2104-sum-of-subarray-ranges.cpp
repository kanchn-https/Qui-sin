class Solution {
public:
    vector<int> findnext(vector<int> & arr) {
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            ans[i]=!st.empty()? st.top(): n;
            st.push(i);
        }return ans;
    }
    vector<int> findnextG(vector<int> & arr) {
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            ans[i]=!st.empty()? st.top():n;
            st.push(i);
        }return ans;
    }
    vector<int> findprev(vector<int> & arr) {
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            ans[i]=!st.empty()? st.top(): -1;
            st.push(i);
        }return ans;
    }vector<int> findprevG(vector<int> &arr) {
        int n=arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            ans[i]=!st.empty()? st.top():-1;
            st.push(i);
        }return ans;
    }
    long long submin(vector<int> &arr){
        vector<int> nse=findnext(arr);
        vector<int> psee=findprev(arr);
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++) {
            int left=i-psee[i];
            int right=nse[i]-i;
            long long freq=left*right*1LL;
            long long val=(freq*arr[i]*1LL);
            sum+=val;
        }return sum;
    }
    long long submax(vector<int> &arr) {
        vector<int> nge=findnextG(arr);
        vector<int> pgee=findprevG(arr);
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<n;i++) {
            int left=i-pgee[i];
            int right=nge[i]-i;
            long long freq=left*right*1LL;
            long long val=(freq*arr[i]*1LL);
            sum+=val;
        }return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return submax(nums)-submin(nums);
    }
};