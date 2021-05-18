public class countPalindrome {

    public static int getCountPalindrome(String str) {
        int len = str.length();
        int N=len;
        int[][] cps = new int[N][N];

        for (int i = 0; i < len; i++) {
            cps[i][i] = 1;
        }

        for (int L = 2; L <= len; L++) {
            for (int i = 0; i <= N - L; i++) {
                int k = L + i - 1;
                if (str.charAt(i) == str.charAt(k)) {
                    cps[i][k] = cps[i][k - 1] + cps[i + 1][k] + 1;
                } else {
                    cps[i][k] = cps[i][k - 1] + cps[i + 1][k] - cps[i + 1][k - 1];
                }
            }
        }

        return cps[0][N-1];
    }

    public static void main(String[] args) {
        String s="abcb";
        System.out.print(getCountPalindrome(s));

    }

}
