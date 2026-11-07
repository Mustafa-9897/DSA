class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n=responses.size();
        unordered_map<string,int>mpp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            unordered_set<string>st;
            for(int j=0;j<responses[i].size();j++){
                if(st.count(responses[i][j])==0){
                    mpp[responses[i][j]]++;
                } 
                st.insert(responses[i][j]);
            }
        }
        vector<string>temp;
        for(auto it:mpp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        for(auto it:mpp){
            if(it.second==maxi){
                temp.push_back(it.first);
            }
        }
        sort(temp.begin(),temp.end());
        return temp[0];
    }
};