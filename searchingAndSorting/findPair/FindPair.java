import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

public class FindPair {

    static int findPairOfInt(int arr[],int N,int x){
        Set<Integer> hash_Set = new HashSet<Integer>(); 
        for(int a:arr){
            hash_Set.add(a);
        }

        for(int i:arr){
            if(hash_Set.contains(Math.abs(i+x)) || hash_Set.contains(Math.abs(i-x))){
                return 1;
            }
        }

        return -1;

    }

    public static void main(String[] args){
        int n=6;
        int arr[]={5,20,3,2,5,80};
        int x=78;
        System.out.println(findPairOfInt(arr,n,x));


        // System.out.println("hello world");
    }
    
}
