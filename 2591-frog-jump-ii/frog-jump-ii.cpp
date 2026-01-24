class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if(n==2) return abs(stones[0]-stones[1]);
        int maxlen = 0;
        for(int i=2; i<n; i=i+2){
            maxlen = max(maxlen, abs(stones[i-2]-stones[i]));
        }
        for(int i=1; i<n; i=i+1){
            if(i+2<n) maxlen = max(maxlen, abs(stones[i+2]-stones[i]));
        }
        return maxlen;
    }
};