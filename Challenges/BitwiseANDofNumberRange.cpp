class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left!=right){
            left>>=1;Q
            right>>=1;
            count++;
        }
        return(left<<count);
    }
};
