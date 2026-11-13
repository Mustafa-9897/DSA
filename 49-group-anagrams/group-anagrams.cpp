class Solution {
public:
    // bool isanagram(string s,string t){
    //     unordered_map<char,int>mpp;
    //     for(int i=0;i<s.size();i++){
    //         mpp[s[i]]++;
    //     }
    //     for(int i=0;i<t.size();i++){
    //         if(mpp.find(t[i])==mpp.end()) return false;
    //         mpp[t[i]]--;
    //         if(mpp[t[i]]==0) mpp.erase(t[i]);
    //     }
    //     return mpp.size()==0;
    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //   WILL GIVE TLE
        // int n=strs.size();
        // vector<int>vis(n,0);
        // vector<vector<string>>ans;
        // for(int i=0;i<n;i++){
        //     if(vis[i]==1) continue;
        //     vis[i]=1;
        //     vector<string>temp;
        //     temp.push_back(strs[i]);
        //     for(int j=i+1;j<n;j++){
        //         if(isanagram(strs[i],strs[j])){
        //             vis[j]=1;
        //             temp.push_back(strs[j]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;

        int n=strs.size();
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mpp[s].push_back(strs[i]);
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;

        
    }
};