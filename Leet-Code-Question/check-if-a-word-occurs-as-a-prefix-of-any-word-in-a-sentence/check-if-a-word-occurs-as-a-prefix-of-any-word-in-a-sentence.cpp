class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int j=0;
        int wordCount=1;
        for(int i=0;i<sentence.length();i++){
            cout<<sentence[i]<<" \n";
            if(sentence[i]!=searchWord[0]){
                cout<<"\n shiftin ahead \n";
                wordCount++;
                while(i<sentence.length() && sentence[i]!=' '){
                    i++;
                }
                // i++;
                
            }else{
                while(j<searchWord.length() && sentence[i]==searchWord[j]){
                    cout<<" || "<<sentence[i]<<" "<<searchWord[j]<<" || ";
                    j++;
                    i++;
                }
                cout<<"\n";
                if(j==searchWord.length()){
                    return wordCount;
                }else{
                    if(sentence[i]==' '){
                     wordCount++;   
                    }
                    // cout<<"last element "<<sentence[i]<<" \n";
                    j=0;
                    // wordCount++;
                }
            }
        }
        return -1;
    }
};