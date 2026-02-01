class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int mini = 51;
        int indexOfMini = -1;
        int secondMini = 51;

        for(int i=1; i<nums.size(); i++){
            if(mini>nums[i]){
                mini = nums[i];
                indexOfMini = i;
            }

        }
        for(int i=1; i<nums.size(); i++){
            if(indexOfMini!=i) secondMini = min(secondMini, nums[i]);
        }

        return ans + mini + secondMini;
    }
};