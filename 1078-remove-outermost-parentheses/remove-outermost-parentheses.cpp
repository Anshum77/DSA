class Solution {
public:
    string removeOuterParentheses(string s) {
        unordered_set<int> st;
        st.insert(0);
        int count = 1;

        for(int i=1; i<s.size(); i++){
            if(s[i]=='(') count++;
            else count--;
            if(count==0){
                st.insert(i);
                st.insert(i+1);
            }
        }

        for(int i : st) cout<<i<<endl;

        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(st.find(i)==st.end()) ans += s[i];
        }
        return ans;
    }
};