class Solution {
    unordered_map<string,int>mpp;
    string b;
    vector<vector<string>>ans;
private:
    void dfs(string word,vector<string>&seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int level=mpp[word];
        int size=word.size();
        for(int i=0;i<size;i++){
            char og=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]==level-1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=og;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        q.push(beginWord);
        mpp[beginWord]=1;
        st.erase(beginWord);
        int size=beginWord.size();
        b=beginWord;

        while(!q.empty()){
            string word=q.front();
            q.pop();
            int level=mpp[word];
            if(word==endWord) break;

            for(int i=0;i<size;i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push(word);
                        mpp[word]=level+1;
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};