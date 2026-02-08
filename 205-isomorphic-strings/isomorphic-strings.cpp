class Solution {
public:
    bool isIsomorphic(string s, string t){
        int n = s.size();
        if(n!=t.size()) return false;
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        for(int i=0; i<n; i++){
            if(mpp1.count(s[i]) && mpp1[s[i]]!=t[i]) return false;
            else if(mpp2.count(t[i]) && mpp2[t[i]]!=s[i]) return false;
            mpp1[s[i]] = t[i];
            mpp2[t[i]] = s[i];
        }

        return true;
    }
};