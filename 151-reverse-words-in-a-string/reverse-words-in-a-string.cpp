class Solution {
public:
    string reverseWords(string s) {
        // int n=s.size();
        // vector<string>words;
        // string temp="";
        // for(int i=0;i<n;i++){
        //     if(s[i]==' '){
        //         if(!temp.empty()){
        //             words.push_back(temp);
        //             temp.clear();
        //         }
        //     }
        //     else{
        //         temp += s[i];                          //   BRUTE FORCE
        //     }
        // }
        // if(!temp.empty()){
        //     words.push_back(temp);
        // }
        // reverse(words.begin(),words.end());
        // string result="";
        // for(int i=0;i<words.size();i++){
        //     result += words[i];
        //     if(i<words.size()-1){
        //         result += " ";
        //     }
        // }
        // return result;

        string result="";
        int i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]==' '){ // traverse past the white spaces if given at the end
                i--;
            }
            if(i<0) break;
            int end=i;
            while(i>=0 && s[i]!=' '){ // now to traverse to starting to the start of the word
                i--; // this loop will stop at the space before the word
            }
            string word="";
            int j=i+1;   // start the j from the start the word
            while(j<=end){
                word += s[j]; // for the word
                j++;
            }
            if(!result.empty()){
                result += " ";
            }
            result += word;
        }
        return result;
    }
};