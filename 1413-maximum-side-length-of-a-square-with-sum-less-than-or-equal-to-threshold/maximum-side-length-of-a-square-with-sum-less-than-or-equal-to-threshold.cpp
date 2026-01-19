class Solution {
public:
    bool isValid(int i, int j, int len, vector<vector<int>>& mat, vector<vector<int>>& prefixSum, int threshold){
        if(i==0 && j==0){
            return prefixSum[i+len-1][j+len-1]<=threshold;
        }
        if(i==0){
            int sum = prefixSum[i+len-1][j+len-1] - prefixSum[i+len-1][j-1];
            return sum<=threshold;
        }
        if(j==0){
            int sum = prefixSum[i+len-1][j+len-1] - prefixSum[i-1][j+len-1];
            return sum<=threshold;
        }
        int sum = prefixSum[i+len-1][j+len-1] - prefixSum[i-1][j+len-1] - prefixSum[i+len-1][j-1] + prefixSum[i-1][j-1];
        return sum<=threshold;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> prefixSum = mat;
        for(int i=0; i<n; i++){
            int rowSum = 0;
            for(int j=0; j<m; j++){
                rowSum += prefixSum[i][j];
                if(i==0){
                    if(j!=0) prefixSum[i][j] += prefixSum[i][j-1];
                }
                else{
                    prefixSum[i][j] = prefixSum[i-1][j] + rowSum;
                }
            }
        }
        int maxlen = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int len=min(n-i, m-j); len>=1; len--){
                    if(len<=maxlen) break;
                    if(isValid(i, j, len, mat, prefixSum, threshold)) maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};