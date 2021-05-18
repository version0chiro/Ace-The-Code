public class Numberpad {

    static void numPad(String s){
        String[] numberPad={
            "2","22","222",
            "3","33","333",
            "4","44","444",
            "5","55","555",
            "6","66","666",
            "7","77","777","7777",
            "8","88","888",
            "9","99","999","9999"
        };
        for(char c : s.toCharArray()){
            if(c == ' '){
                System.out.println("0");
            }
            else{
                int pointer= c - 'a';
                System.out.print(numberPad[pointer]);
            }
        }
    }

    public static void main(String[] args){
        String name= "sachin";

        numPad(name.toLowerCase());

    }
}
