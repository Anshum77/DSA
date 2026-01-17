class Solution {
public:
    // int computesqlen(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    //     if(x3>=x2 || y3>=y2 || x4<=x1 || y4<=y1) return 0;
    //     if(x3>=x1 && x3<=x2 && y3>=y1 && y3<y2){
    //         int x = abs(min(x2, x4) - x3);
    //         int y = abs(min(y2, y4) - y3);
    //         return min(x, y);
    //     }
    //     if(x4>=x1 && x4<=x2 && y3>=y1 && y3<=y2){
    //         int x = abs(max(x3, x1) - x4);
    //         int y = abs(min(y2, y4) - y3);
    //         return min(x, y);
    //     }
    //     if(x4>=x1 && x4<=x2 && y4>=y1 && y4<=y2){
    //         int x = abs(max(x1, x3) - x4);
    //         int y = abs(max(y1, y3) - y4);
    //         return min(x, y);
    //     }
    //     int x = abs(min(x2, x4) - x3);
    //     int y = abs(max(y1, y3) - y4);
    //     return min(x, y);
    // }

    int computesqlen(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
        if(x3>=x2 || y3>=y2 || x4<=x1 || y4<=y1) return 0;
        int x = min(x2, x4) - max(x1, x3);
        int y = min(y2, y4) - max(y1, y3);
        return min(x, y);
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = bottomLeft[i][0]; int y1 = bottomLeft[i][1];
                int x2 = topRight[i][0]; int y2 = topRight[i][1];
                int x3 = bottomLeft[j][0]; int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0]; int y4 = topRight[j][1];
                long long sqlen = computesqlen(x1, y1, x2, y2, x3, y3, x4, y4);
                maxArea = max(maxArea, sqlen*sqlen);
            }
        }
        return maxArea;
    }
};