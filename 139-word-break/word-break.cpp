class Solution{
private:
    bool recursion(int idx, string s, unordered_map<string, int>& mpp, vector<int>& dp){
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];

        string temp = "";
        for(int i=idx; i<s.size(); i++){
            temp += s[i];
            if(mpp.find(temp)!=mpp.end()){
                if(recursion(i+1, s, mpp, dp)){
                    return dp[idx]=1;
                }
            }
        }
        return dp[idx] = 0;
    }


public:
    bool wordBreak(string s, vector<string>& wordDict){
        unordered_map<string, int> mpp;
        int n = s.size();
        vector<int> dp(n, -1);
        for(string it : wordDict) mpp[it] = 1;
        if(recursion(0, s, mpp, dp)) return true;

        return false;
    }
};