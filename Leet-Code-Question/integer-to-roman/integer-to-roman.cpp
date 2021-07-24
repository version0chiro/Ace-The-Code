class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int numbers[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int s = 12;
        while(num>0){
            int div = num/numbers[s];
            num = num%numbers[s];
            while(div){
                ans+=symbol[s];
                div--;
            }
            s--;
        }
        
        return ans;
    }
};