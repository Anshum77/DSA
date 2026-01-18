class Solution {
public:
    bool isValid(int i, int j, int len, vector<vector<int>>& grid, vector<vector<int>>& rowPrefix, vector<vector<int>>& colPrefix, vector<vector<int>>& mainDiaPrefix, vector<vector<int>>& antiDiaPrefix){
        int sum = -1;
        int n = grid.size();
        int m = grid[0].size();
        for(int k=i; k<i+len; k++){
            if(j==0){
                if(sum==-1) sum = rowPrefix[k][len-1];
                else{
                    if(sum!=rowPrefix[k][len-1]) return false;
                }
            }
            else{
                if(sum==-1) sum = rowPrefix[k][j+len-1] - rowPrefix[k][j-1];
                else{
                    if(sum!=rowPrefix[k][j+len-1] - rowPrefix[k][j-1]) return false;
                }
            }
        }
        for(int k=j; k<j+len; k++){
            if(i==0){
                if(sum!=colPrefix[len-1][k]) return false;
            }
            else{
                if(sum!=colPrefix[i+len-1][k]-colPrefix[i-1][k]) return false;
            }
        }
        //Main diagonal sum:
        if(i==0 || j==0){
            if(sum!=mainDiaPrefix[i+len-1][j+len-1]) return false;
        }
        else{
            if(sum!=mainDiaPrefix[i+len-1][j+len-1]-mainDiaPrefix[i-1][j-1]) return false;
        }
        //Anti diagonal sum:
        if(i==0 || j+len-1==m-1){
            if(sum!=antiDiaPrefix[i+len-1][j]) return false;
        }
        else{
            if(sum!=antiDiaPrefix[i+len-1][j]-antiDiaPrefix[i-1][j+len]) return false;
        }
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> rowPrefix = grid;
        vector<vector<int>> colPrefix = grid;
        vector<vector<int>> mainDiaPrefix = grid;
        vector<vector<int>> antiDiaPrefix = grid;

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                colPrefix[i][j] += colPrefix[i-1][j];
            }
        }
        for(int j=1; j<m; j++){
            for(int i=0; i<n; i++){
                rowPrefix[i][j] += rowPrefix[i][j-1];
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                mainDiaPrefix[i][j] += mainDiaPrefix[i-1][j-1];
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m-1; j++){
                antiDiaPrefix[i][j] += antiDiaPrefix[i-1][j+1];
            }
        }
        int maxlen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int len=min(n-i, m-j); len>=2; len--){
                    if(isValid(i, j, len, grid, rowPrefix, colPrefix, mainDiaPrefix, antiDiaPrefix)){
                        maxlen = max(maxlen, len);
                        break;
                    }
                }
            }
        }
        return maxlen;
    }
};