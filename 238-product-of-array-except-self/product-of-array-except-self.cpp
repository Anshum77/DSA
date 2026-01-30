class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n, 1);

        for(int i=1; i<n; i++) ans[i] = ans[i-1]*nums[i-1];

        int suffixProduct = 1;

        int i=n-1;
        while(i>=0){
            int prefixProduct = ans[i];
            ans[i] = prefixProduct*suffixProduct;
            suffixProduct *= nums[i--];
        }

        return ans;
    }
};