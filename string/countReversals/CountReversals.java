import java.util.Stack;

public class CountReversals {
    
    static int getCount(String s){

        
        int length = s.length();
        
        if(length%2!=0){
            return -1;
        }
        
        Stack<Character> paranStack = new Stack<Character>();


        for(char a:s.toCharArray()){
            if(a=='}'){
                if(!paranStack.empty() && paranStack.peek()=='{'){
                    paranStack.pop();
                }else{
                    paranStack.push(a);
                }
            }else{
                paranStack.push(a);
            }
        }

        int renLength = paranStack.size();

        int n=0;
        while(!paranStack.empty() && paranStack.peek()=='{'){
            n++;
            paranStack.pop();
        }
        
        return (renLength/2 + n%2);
    }

    public static void main(String[] args){
        String s="{}{}{}{{";
        System.out.println(getCount(s));


    }
}
