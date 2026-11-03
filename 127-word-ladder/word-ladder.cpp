class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.count(endWord)==0) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int level=q.front().second;
            q.pop();

            for(int i=0;i<word.size();i++){
                string dummyword=word;
                for(char ch='a';ch<='z';ch++){
                    dummyword[i]=ch;
                    if(dummyword==endWord) return level+1;
                    if(st.count(dummyword)==1){
                        q.push({dummyword,level+1});
                        st.erase(dummyword);
                    }
                }
            }
        }
        return 0;
    }
};