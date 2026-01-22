class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int l=0; int r=0;
        int jump = 0;
        while(l<n && r<n-1){
            int farthestIndex = 0;
            for(; l<=r; l++){
                farthestIndex = max(farthestIndex, l+nums[l]);
            }
            jump++;
            r = farthestIndex;
        }
        return jump;
    }
};