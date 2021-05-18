// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            
            String s = read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.lps(s));
        }
    }
}// } Driver Code Ends


//User function Template for Java

class Solution {
    int lps(String s) {
        
        // code here
        int i=0;
        int j=i+1;

        int M = s.length();
        int lps[] = new int[M];
        lps[0]=0;

        while(j<M){
            if(s.charAt(j)==s.charAt(i)){
                lps[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i!=0){
                    i=lps[i-1];
                }
                else{
                    lps[j]=i;
                    j++;
                }
            }
        }

        return lps[lps.length-1];
    }


}