class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        cout<<digits.back();
        if(digits.back()+1>9){
            int p=digits.size()-1;
            while(p>=0 && digits.at(p)+1>9){
                digits.at(p)=0;
                p--;
            }
            if(p>=0)
                digits.at(p)++;
            else
                 digits.insert(digits.begin(), 1);
            
        }
        else{
            digits.back()=digits.back()+1;

        }
        return digits;
        
    }
};