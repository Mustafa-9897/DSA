class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>hash(51,0);
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            hash[A[i]]++;
            hash[B[i]]++;
            int cnt=0;
            for(int i=0;i<hash.size();i++){
                if(hash[i]==2){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};