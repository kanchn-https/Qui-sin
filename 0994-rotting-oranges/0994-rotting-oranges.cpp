class Solution {
public:
    int bfs(vector<vector<int>> &grid,queue<pair<int,int>>& q,int delrow[],int delcol[],int total) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        int count=0;
        while(!q.empty()){
            int k=q.size();
            count+=k;
            while(k--) {
                auto cell=q.front();
                q.pop();
                int row=cell.first;
                int col=cell.second;
                for(int i=0;i<4;i++) {
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol]==1 ) {
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                    }
                }
            }if(!q.empty()) time++;
        }if(total==count) return time;
            return -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int total=0;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++ ) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }return bfs(grid,q,delrow,delcol,total);
    }
};