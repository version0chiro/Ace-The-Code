class Solution {
public:
    //97
    string freqAlphabets(string s) {
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                string temp = string(1,s[i-2]);
                temp+=s[i-1];
                int tempInt=stoi(temp)+96;
                cout<<tempInt<<" ";;
                char tempChar = tempInt;
                cout<<tempChar<<" ";
                ans+=tempChar;
                i=i-2;
            }else{
                int tempInt=stoi(string(1,s[i]))+96;
                char tempChar = tempInt;
                ans+=tempChar;
            }
        }
        reverse(ans.begin(),ans.end());
        // cout<<a;
        return ans;
    }
};