class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        int n=sentence.size();
        int i=0;
        string ans="";
        while(i<n){
            string word="";
            while(i<n && sentence[i]!=' '){
                word += sentence[i];
                i++;
            }
            string prefix="";
            bool found=false;
            for(char c : word){
                prefix += c;
                if(st.count(prefix)){
                    found=true;
                    break;
                }
            }
            if(found){
                ans += prefix;
            }
            else{
                ans += word;
            }
            if(i<n){
                ans += ' ';
                i++;
            }
        }
        return ans;
    }
};