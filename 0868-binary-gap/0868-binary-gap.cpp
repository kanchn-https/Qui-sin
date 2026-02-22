class Solution {
public:
    int binaryGap(int n) {
        int maxi=0,curr=0;
        bool flag=false;
        while(n>0) {
            if(n%2==1) {
                if(flag) maxi=max(maxi,curr);
                curr=1;
                flag=true;
            }else {
                if(flag) curr++;
            }n/=2;
        }return maxi;
    }
};