class Solution {
public:
    string largestOddNumber(string num) {
        string odds;
        int i;
        for(i=num.size()-1;i>=0;i--){
            if(num[i]-'0' & 1)
                break;
        }
        cout<<i<<"\n";
        cout<<num.substr(0,i+1)<<"\n";
        // if(maxE==INT_MIN) return "";
        return num.substr(0,i+1);
    }
};