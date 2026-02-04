class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1]<=nums[n-2]) return false;

        int q = n-2;
        while(nums[q-1]<=nums[q]){
            q--;
            if(nums[q+1]==nums[q]) return false;
            if(q==0) return false;
        }

        int p = q;
        while(nums[p-1]>=nums[p]){
            p--;
            if(nums[p+1]==nums[p]) return false;
            if(p==0) return false;
        }

        for(int i=0; i<p; i++){
            if(nums[i+1]<=nums[i]) return false;
        }

        cout<<p<<" "<<q<<endl;

        return true;
    }
};