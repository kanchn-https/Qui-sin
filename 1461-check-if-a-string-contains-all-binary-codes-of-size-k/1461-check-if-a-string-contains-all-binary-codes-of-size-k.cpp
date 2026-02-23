class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string> st;
        for(int i=0;i+k<=n;i++) {
            st.insert(s.substr(i,k));
        }
        if(st.size()==pow(2,k)) return true;
        return false;
    }
};