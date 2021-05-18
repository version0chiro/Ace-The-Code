public class kmp {

    static void KmpSearch(String txt, String ptr) {
        int N = txt.length();
        int M = ptr.length();
        int j = 0;
        int[] lps = new int[M];

        computeLPSArray(lps, M, ptr);

        int i = 0;
        while (i < N) {
            if (ptr.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == M) {
                System.out.println("Founr at" + (i - j));

                j = lps[j - 1];
            }

            else if (i < N && ptr.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

    }

    static void computeLPSArray(int[] lps, int M, String ptr) {
        int length = 0;
        int i = length + 1;
        lps[0] = 0;
        while (i < M) {

            if (ptr.charAt(i) == ptr.charAt(length)) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = length;
                    i++;
                }
            }

        }
    }

    public static void main(String[] args) {
        String txt = "Sachin Singh Pooja Wani";
        String ptr = "Pooj";

        KmpSearch(txt, ptr);
    }

}
