class Solution {
public:
    // int candy(vector<int>& ratings){
    //     int n = ratings.size();
    //     if(n==1) return 1;
    //     vector<int> lower;
    //     vector<int> higher;

    //     int i=1;
    //     if(ratings[0]<ratings[1]) lower.push_back(0);
    //     while(i<n-1){
    //         int l=i;
    //         int r=i;
    //         while(l>0 && ratings[l]==ratings[l-1]) l--;
    //         while(r<n-1 && ratings[r]==ratings[r+1]) r++;

    //         if(l>0 && r<n-1){
    //             if(ratings[l]>ratings[l-1] && ratings[r]>ratings[r+1]){
    //                 for(int k=l; k<=r; k++) higher.push_back(k);
    //             }
    //             else if (ratings[l]<ratings[l-1] && ratings[r]<ratings[r+1]){
    //                 for(int k=l; k<=r; k++) lower.push_back(k);
    //             }
    //         }
    //         else return n;
    //         i = r+1;
    //     }
    // }
    int candy(vector<int>& ratings){
        int n = ratings.size();
        if(n==1) return 1;
        vector<int> lower;

        if(ratings[0]<=ratings[1]) lower.push_back(0);
        for(int i=1; i<n-1; i++){
            if(ratings[i]<=ratings[i-1] && ratings[i]<=ratings[i+1]){
                lower.push_back(i);
            }
        }
        if(ratings[n-1]<=ratings[n-2]) lower.push_back(n-1);

        vector<int> candies(n, 1);
        for(int i=0; i<lower.size(); i++){
            int idx = lower[i]-1;
            int count = 2;
            while(idx>=0 && idx+1<n && ratings[idx]>ratings[idx+1]){
                if(candies[idx]<count) candies[idx] = count;
                count++;
                idx--;
            }
            idx = lower[i]+1;
            count = 2;
            while(idx<n && idx-1>=0 && ratings[idx]>ratings[idx-1]){
                if(candies[idx]<count) candies[idx] = count;
                count++;
                idx++;
            }
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += candies[i];
        }
        return sum;
    }
};