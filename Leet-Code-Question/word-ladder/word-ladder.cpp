class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        int level=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                            auto temp = q.front();
            q.pop();
            if(temp==endWord){
                return level;
            }
            st.erase(temp);
            for(int i=0;i<temp.size();i++){
                char ch = temp[i];
                for(int k=0;k<26;k++){
                    temp[i] = k+'a';
                    if(st.count(temp)){
                        q.push(temp);
                    }

                }
                temp[i]=ch;
            }

                
            }
            level++;
        }
        
        return 0;
    }
};