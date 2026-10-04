class Solution {
public:
    vector<int> partitionLabels(string s) {
        //Start a partition and keep extending its ending position until every character inside that partition has its last occurrence within the partition.

        vector<int>last(26,-1);
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        int start=0;
        int end=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            end=max(end,last[s[i]-'a']);
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};