class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missingnum = -1;
        vector<int> temp_array(nums.size() + 1, -1); 
        for(int num : nums){
            temp_array[num] = 0;
        }

        for(int i = 0; i < temp_array.size(); i++){ 
            if(temp_array[i] != 0){ 
                missingnum = i;
                break;
            }
        }
        return missingnum;
    }
};

