public class boyerMoore {

    static void findBoyer(String txt, String ptr) {
        int txtLength = txt.length();
        int ptrLength = ptr.length();

        int txtPointer = ptrLength - 1;
        int ptrPointer = ptrLength - 1;

        int foundLength = 0;

        while (txtPointer < txtLength) {
            while (ptrPointer >= 0 && txt.charAt(txtPointer) == ptr.charAt(ptrPointer) ) {
                ptrPointer--;
                txtPointer--;
                foundLength++;
            }
            if (foundLength == ptrLength) {
                System.out.println("Found at");
                System.out.println(txtPointer+1);
                txtPointer = txtPointer + ptrLength+1;
                ptrPointer = ptrLength-1;
                foundLength=0;
            } else {
                while (ptrPointer >= 0 && txt.charAt(txtPointer) != ptr.charAt(ptrPointer)) {
                    ptrPointer--;
                    foundLength --;
                }
                if (ptrPointer < 0) {
                    // System.out.println("Found at");
                    // System.out.println(txtPointer);
                    txtPointer = txtPointer + ptrLength+1;
                    ptrPointer = ptrLength-1;
                    
                }
            }

        }
    }

    public static void main(String[] args) {
        String txt = "AABAACAADAABAABA";
        String ptr = "AABA";
        findBoyer(txt, ptr);

    }
}
