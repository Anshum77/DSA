class Solution {
public:
    bool validWindow(unordered_map<char, int>& mpp, unordered_map<char, int>& mpp2){
        for(auto p : mpp){
            char ch = p.first;
            int freq = p.second;
            if(mpp2.find(ch)==mpp2.end() || mpp2[ch]<freq) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m) return "";
        unordered_map<char, int> mpp;

        for(char ch : t) mpp[ch]++;

        int ansi = -1;
        int ansj = -1;
        int l = 0;
        int r = 0;

        unordered_map<char, int> mpp2;

        int minlength = INT_MAX;

        while(r<n && l<n){
            mpp2[s[r]]++;
            while(validWindow(mpp, mpp2)){
                if(minlength > r-l+1){
                    minlength = r-l+1;
                    ansi = l;
                    ansj = r;
                }
                mpp2[s[l]]--;
                if(mpp2[s[l]]==0) mpp2.erase(s[l]);
                l++;
            }
            r++;
        }
        if(ansi==-1 || ansj==-1) return "";
        string ans;
        for(int i=ansi; i<=ansj; i++) ans += s[i];

        return ans;
    }
};