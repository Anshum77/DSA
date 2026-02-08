class Solution {
public:
    int checkpossible(int i, string& a, string& b){
        int j = 0;
        int n = a.size();
        int m = b.size();
        int count = 1;

        while(a[i]==b[j]){
            if(i+1<n) i++;
            else if(j+1<m){
                i=0;
                count++;
            }
            j++;
            if(j==m) return count;
        }
        return -1;
    }

    int repeatedStringMatch(string a, string b){
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = 0;
        
        for(int i=0; i<n; i++){
            if(a[i]==b[0]){
                int count = checkpossible(i, a, b);
                if(count!=-1) return count;
            }
        }

        return -1;
    }
};