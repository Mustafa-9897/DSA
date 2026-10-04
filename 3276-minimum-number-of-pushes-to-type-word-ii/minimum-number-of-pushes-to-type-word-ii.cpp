class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<int>hash(26,0);
        for(int i=0;i<n;i++){
            hash[word[i]-'a']++;
        }
        sort(hash.begin(),hash.end());
        int ans=0;
        int cnt=0;
        for(int i=25;i>=0;i--){
            cnt ++;
            if(cnt<=8){
                ans += hash[i];
            }
            else if(cnt>=9 && cnt<=16){
                ans += 2*hash[i];
            }
            else if(cnt>=17 && cnt<=24){
                ans += 3*hash[i];
            }
            else{
                ans += 4*hash[i];
            }
        }
        return ans;
    }
};