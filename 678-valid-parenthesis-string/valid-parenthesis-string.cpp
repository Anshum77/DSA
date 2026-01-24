class Solution {
public:
    bool recursion(int i, int left, string& s, vector<vector<int>>& dp){
        int n = s.size();
        if(i==n) return left==0;
        if(dp[i][left] != -1) return dp[i][left];
        if(s[i]=='(') return dp[i][left] = recursion(i+1, left+1, s, dp);
        if(s[i]==')'){
            if(left==0) return false;
            return dp[i][left] = recursion(i+1, left-1, s, dp);
        }
        else{
            if(left>0){
                return dp[i][left] = recursion(i+1, left+1, s, dp) || recursion(i+1, left, s, dp) || recursion(i+1, left-1, s, dp);
            }
            else return dp[i][left] = recursion(i+1, left+1, s, dp) || recursion(i+1, left, s, dp);
        }
    }
    
    bool checkValidString(string s){
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recursion(0, 0, s, dp);
    }
};