class Solution {
public:
    int addDigits(int num) {
    int result=0,temp;
    if(num/10==0){
        return num;
    }else{
    
    while(num!=0){
        temp=num%10;
        result+=temp;
        num=num/10;
    }
    return addDigits(result);
    }
}
};