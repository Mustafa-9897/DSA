class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //    BRUTE ,,  WILL GIVE TLE
        // int maxlen=0;
        // for(int i=0;i<fruits.size();i++){
        //     unordered_set<int>st;
        //     for(int j=i;j<fruits.size();j++){
        //         st.insert(fruits[j]);
        //         if(st.size()<=2) maxlen=max(maxlen,j-i+1);
        //         else break;
        //     }
        // }
        // return maxlen;


        //    BETTER
        // int l=0,r=0,maxlen=0;
        // unordered_map<int,int>mpp;
        // while(r<fruits.size()){
        //     while(mpp.size()>2){
        //         mpp[fruits[l]]--;
        //         if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
        //         l++;
        //     }
        //     mpp[fruits[r]]++;
        //     if(mpp.size()<=2)
        //         maxlen=max(maxlen,r-l+1);
        //     r++;
        // }
        // return maxlen;


        //   OPTIMAL
        int l=0,r=0,maxlen=0;
        unordered_map<int,int>mpp;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<=2) maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};