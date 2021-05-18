public class AdjacentDiffer {

    static void search(int arr[],int x,int k){
        int i=0;
        while(i<arr.length){
            if(arr[i]==x){
                System.out.println(i);
                break;
            }
            else{
                if(Math.abs(arr[i]-x)/k>0)
                i=i+Math.abs(arr[i]-x)/k;
                else
                i++;
            }
        }

    }
    public static void main(String[] args){
        int arr[] = {20, 40, 50, 70, 70, 60}  ;
        int x = 60;
        int k=20;

        search(arr,x,k);

    }
    
}
