class Solution {
public:
    string frequencySort(string s){
        unordered_map<char, int> mpp;
        for(char c : s) mpp[c]++;

        priority_queue<pair<int, char>> heap;
        for(auto p : mpp) heap.push({p.second, p.first});

        string ans;
        while(!heap.empty()){
            for(int i=0; i<heap.top().first; i++) ans += heap.top().second;
            heap.pop();
        }

        return ans;
    }
};