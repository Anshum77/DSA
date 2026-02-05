class Solution {
public:
    string reverseWords(string s){
        int n = s.size();
        string word =  "";
        string ans;
        for(int i=n-1; i>=0; i--){
            if(s[i]==' ' && word.size()>0){
                reverse(word.begin(), word.end());
                ans += word;
                ans += ' ';
                word = "";
            }
            else if(s[i]!=' ') word += s[i];
        }
        if(word.size()>0){
            reverse(word.begin(), word.end());
            ans += word;
        }
        if(s[0]==' ') ans.pop_back();

        return ans;
    }
};