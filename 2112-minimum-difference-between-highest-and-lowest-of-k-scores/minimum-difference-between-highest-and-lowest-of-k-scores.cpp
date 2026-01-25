class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        int diff = INT_MAX;
        for(int j=k-1; j<n; j++){
            diff = min(diff, abs(nums[i]-nums[j]));
            i++;
        }

        return diff;
    }
};