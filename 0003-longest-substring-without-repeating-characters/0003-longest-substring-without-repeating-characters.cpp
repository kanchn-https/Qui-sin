class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
        int haslen=256;
        int hash[haslen];
        for(int i=0;i<haslen;i++) hash[i]=-1;
        int l=0,r=0,maxlen=0;
        while(r<n) {
            if(hash[s[r]]!=-1) l=max(hash[s[r]]+1,l) ; 
            maxlen=max(r-l+1,maxlen);
            hash[s[r]]=r;
            r++;      
        }return maxlen;
    }
};