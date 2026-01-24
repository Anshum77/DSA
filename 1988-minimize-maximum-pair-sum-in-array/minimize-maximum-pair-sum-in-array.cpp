class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxSum = 1;
        int r=n-1;
        for(int l=0; l<n; l++){
            maxSum = max(maxSum, nums[l]+nums[r]);
            r--;
        }
        return maxSum;
    }
};