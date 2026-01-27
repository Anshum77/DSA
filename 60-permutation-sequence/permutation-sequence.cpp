class Solution {
public:
    void generate(int length, int n, int k, string& s, vector<int>& factorial, vector<int>& nums){
        if(n==0) return;
        if(n==1){
            s[length-1] = nums[0] + '0';
            return;
        }
        if(k==0){
            generate(length, n, factorial[n], s, factorial, nums);
            return;
        }

        int totalNums = factorial[n];
        int eachSection = totalNums/n;
        int pos = k/eachSection;
        int remaining = k%eachSection;
        if(remaining!=0) pos++;
        
        s[length-n] = nums[pos-1] + '0';
        nums.erase(nums.begin()+pos-1);
        generate(length, n-1, remaining, s, factorial, nums);
    }

    string getPermutation(int n, int k){
        vector<int> factorial(10, 1);
        for(int i=1; i<10; i++) factorial[i] = i*factorial[i-1];

        vector<int> nums;
        for(int i=1; i<=n; i++) nums.push_back(i);

        string ans(n, '1');
        generate(n, n, k, ans, factorial, nums);
        return ans;
    }
};