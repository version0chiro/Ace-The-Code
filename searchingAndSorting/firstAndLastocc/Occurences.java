import java.util.ArrayList;

public class Occurences {

    public static ArrayList<Long> find(long arr[],int n,int x){
        int start=0;
        int end=n-1;

        ArrayList<Long> answer = new ArrayList<Long>();

        int startOccurence = 0;
        int lastOccurence = 0;


        for(int i=0; i<n; i++){
            if(arr[i]==x){
                answer.add(0, Long.valueOf(i));
                while(arr[i]==x){
                    
                    i++;
                    // System.out.println(i);

                }
                answer.add(1, Long.valueOf(i-1));;
                break;
            }

        }

        
        return answer;

    }

    public static void main(String[] args) {

        long arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125 };

        int x= 5;

        int n = arr.length;

        ArrayList<Long> ans=find(arr,n,x);

        System.out.println(ans.get(0)+" "+ans.get(1));


    }
    
}
