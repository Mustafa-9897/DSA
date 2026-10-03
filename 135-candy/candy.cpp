class Solution {
public:
    int candy(vector<int>& ratings) {
        //  BRUTE
        // int n=ratings.size();
        // vector<int>left(n,1);
        // vector<int>right(n,1);
        // // left neighbors
        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]=left[i-1]+1;
        //     }
        // }
        // // right neighbors
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1]){
        //         right[i]=right[i+1]+1;
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans += max(left[i],right[i]);
        // }
        // return ans;

        // BETTER
        // int n=ratings.size();
        // vector<int>left(n,1);
        // // left neighbors
        // for(int i=1;i<n;i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]=left[i-1]+1;
        //     }
        // }
        // int right=1,curr=1,sum=max(1,left[n-1]);
        // for(int i=n-2;i>=0;i--){
        //     if(ratings[i]>ratings[i+1]){
        //         curr=right+1;
        //         right=curr;
        //     }
        //     else{
        //         curr=1;
        //         right=curr;
        //     }
        //     sum += max(curr,left[i]);
        // }
        // return sum;

        // OPTIMAL
        int i=1,n=ratings.size(),sum=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum += down;
                i++;
                down++;
            }
            if(down>peak){
                sum += down-peak;
            }
        }
        return sum;
    }
};