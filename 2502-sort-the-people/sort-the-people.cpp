class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<string>ans;
        map<int,string>mpp;
        for(int i=0;i<n;i++){
            mpp[heights[i]]=names[i];
        }
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};