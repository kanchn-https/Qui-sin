class Solution {
public:
    string minWindow(string s, string t) {
        int minlen=INT_MAX;
         int ind=-1;
         int hash[256]={0};
         for(char n: t) hash[n]++;
         int count=0,l=0,r=0;
         while(r<s.size()) {
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
            while(count==t.size() ) {
                if(r-l+1<minlen) {
                    minlen=r-l+1;
                    ind=l;
                }hash[s[l]]++;
                if(hash[s[l]]>0) count--;
                l++;
            }r++;
         }return (ind==-1)? "":s.substr(ind,minlen);

    }
};