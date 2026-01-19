class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> pre(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }int l=0,r=min(n,m),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            bool ok=false;
            for(int i=0;i+mid<=n && !ok;i++)
                for(int j=0;j+mid<=m;j++){
                    int s=pre[i+mid][j+mid]-pre[i][j+mid]-pre[i+mid][j]+pre[i][j];
                    if(s<=threshold){ok=true;break;}
                }
            if(ok) ans=mid,l=mid+1;
            else r=mid-1;
        }return ans;
    }
};