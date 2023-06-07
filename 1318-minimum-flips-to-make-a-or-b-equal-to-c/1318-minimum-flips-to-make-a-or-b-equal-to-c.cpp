class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flipCount = 0;

        while (a > 0 || b > 0 || c > 0) {
            int currBitA = a & 1;
            int currBitB = b & 1;
            int currBitC = c & 1;

            if ((currBitA | currBitB) != currBitC) {
                if (currBitC == 1) {
                    flipCount += 1;
                } else {
                    flipCount += currBitA + currBitB;
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flipCount;
    }
};
