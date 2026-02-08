class Solution {
public:
    string RLE(string& s){
        string ans;
        char curr = s[0];
        int currCount = 0;

        for(char ch : s){
            if(ch==curr){
                currCount++;
            }
            else{
                ans += to_string(currCount);
                ans += curr;
                currCount = 1;
                curr = ch;
            }
        }

        ans += to_string(currCount);
        ans += curr;

        return ans;
    }

    string recursion(int n){
        if(n==1) return "1";

        string temp = recursion(n-1);

        return RLE(temp);
    }

    string countAndSay(int n){
        return recursion(n);
    }
};