class Solution {
    int n1,n2;
    vector<vector<int>> dp;
public:
    int helper(int x, int y, string& w1, string& w2){
        if(x==n1 || y==n2)return 0;
        if(dp[x][y]!=INT_MAX) return dp[x][y];     
        int sum;
        if (w1[x]==w2[y]) sum=w1[x]+helper(x+1,y+1,w1,w2);
        else sum=max(helper(x+1,y,w1,w2),helper(x,y+1,w1,w2));
        return dp[x][y]=sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        n1=s1.size();
        n2=s2.size();
        dp.assign(n1,vector<int>(n2,INT_MAX));
        int sum=0;
        for(char ch:s1) sum+=ch;
        for(char ch:s2) sum+=ch;
        return sum-2*helper(0, 0, s1, s2);
    }
};