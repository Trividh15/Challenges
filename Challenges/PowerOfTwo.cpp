class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;

        double temp = log2(n);
        return floor(temp) == temp;   
    }
};
