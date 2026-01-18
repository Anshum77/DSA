class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid, int len){
        int n = grid.size();
        int m = grid[0].size();
        if(i+len>n || j+len>m) return false;
        int sum = 0;
        for(int k=j; k<j+len; k++){
            sum += grid[i][k];
        }
        for(int k=i; k<i+len; k++){
            int rowsum = 0;
            for(int l=j; l<j+len; l++){
                rowsum += grid[k][l];
            }
            if(sum!=rowsum) return false;
        }
        for(int k=j; k<j+len; k++){
            int colsum = 0;
            for(int l=i; l<i+len; l++){
                colsum += grid[l][k];
            }
            if(sum!=colsum) return false;
        }
        int k=i; int l=j;
        int diasum = 0;
        while(k<i+len && l<j+len){
            diasum += grid[k][l];
            k++; l++;
        }
        if(diasum!=sum) return false;
        diasum = 0;
        k=i; l=j+len-1;
        while(k<i+len && l>=j){
            diasum += grid[k][l];
            k++; l--;
        }
        if(diasum!=sum) return false;
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxlen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int len=2; len<=min(m,n); len++){
                    if(isValid(i, j, grid, len)) maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};