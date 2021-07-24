class Solution {
public:
    map<char,int> h;

    bool checkOrder(string& a,string& b){
        int i=-1;
        while(++i<size(a) && i<size(b)){
            if(h[a[i]]!=h[b[i]]) return h[a[i]]<h[b[i]];
            
        }
        return size(a)<=size(b);
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int i=0;
        for(auto a: order){
            h[a]=i;
            i++;
        }
        
        for(i=0;i<size(words)-1;i++){
            if(!checkOrder(words[i],words[i+1])) return false;
            
        }
        return true;
    }
};