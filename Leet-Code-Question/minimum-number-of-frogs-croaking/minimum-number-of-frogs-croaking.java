class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        if(croakOfFrogs.charAt(0)!='c'){
            return -1;
        }
        int frogYell =0;
        int sumFrog=0;
        int maxFrog = 0;
        
        for(int i=0;i<croakOfFrogs.length();i++){
            char c = croakOfFrogs.charAt(i);
            if(c=='c'){
                frogYell++;
                sumFrog+=1;
            }else if(c=='r'){
                sumFrog+=2;
            }else if(c=='o'){
                sumFrog+=3;
            }else if(c=='a'){
                sumFrog+=4;
            }else if(c=='k'){
                sumFrog+=5;
                maxFrog = Math.max(frogYell,maxFrog);
                frogYell--;
                sumFrog = sumFrog-15;
                if(sumFrog<0){
                    return -1;
                }
            }
            else{
                return -1;
            }
        }
        
        if(sumFrog==0 && frogYell==0){
            return maxFrog;
        }else{
            return -1;
        }
    }
}