class Solution {
public:
    int countOnes(int num) {
        int count = 0;
        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int countOnesNum2 = countOnes(num2);
        int result = 0;

        for (int i = 31; i >= 0 && countOnesNum2 > 0; --i) {
            if (num1 & (1 << i)) {
                result |= (1 << i);
                --countOnesNum2;
            }
        }

        for (int i = 0; i < 32 && countOnesNum2 > 0; ++i) {
            if (!(result & (1 << i))) {
                result |= (1 << i);
                --countOnesNum2;
            }
        }

        return result;
    }
};


