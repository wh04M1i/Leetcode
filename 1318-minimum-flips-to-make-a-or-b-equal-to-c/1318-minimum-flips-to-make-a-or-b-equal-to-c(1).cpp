class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = a | b;
        if (result == c) {
            return 0;
        }

        int flipCount = 0;

        for (int i = 0; i < 32; ++i) {
            int currBitResult = (result >> i) & 1;
            int currBitC = (c >> i) & 1;

            if (currBitResult != currBitC) {
                if (currBitC == 1) {
                    flipCount += 1;
                } else {
                    flipCount += ((a >> i) & 1) + ((b >> i) & 1);
                }
            }
        }

        return flipCount;
    }
};
