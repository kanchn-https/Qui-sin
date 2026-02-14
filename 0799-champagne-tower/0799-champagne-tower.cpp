class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> arr;
        for(int i=1;i<=100;i++) {
            vector<double> b(i,0.0);
            arr.push_back(b);
        }arr[0][0]=poured;
        for(int i=0;i<query_row;i++) {
            for(int j=0;j<=i;j++) {
                if(arr[i][j]>1.0) {
                    double div=(arr[i][j]-1)/2;
                    arr[i+1][j]+=div;
                    arr[i+1][j+1]+=div;
                    arr[i][j]=1.0;
                }
            }
        }return min(1.0,arr[query_row][query_glass]);
    }
};