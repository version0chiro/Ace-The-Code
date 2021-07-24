class Solution {
public:
    int numDifferentIntegers(string word) {
        int count=0;
        
        int i=0;
        bool intVis=false;
        string tempS="";
        
        set<string> se;
        while(i<word.length()){
            while(isalpha(word[i])){
                // cout<<word[i]<<" <=skipped ";
                i++;
            }
            while(isdigit(word[i])){
                intVis=true;
                if(word[i]=='0' && tempS==""){
                    i++;
                }else{
                    tempS+=word[i];
                    i++;
                }
            }
            if(intVis){
                
            if(tempS!=""){
                se.insert(tempS);
                tempS="";
            }else{
                se.insert("0");
                tempS="";
            }
            intVis=false;
            }
            // cout<<temp<<"\n";
            // temp=-1;
        }        
        return se.size();
    }
};