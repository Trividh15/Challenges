#include<bits/stdc++.h>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq; // This map maps each element to its corresponding frequency
        int n = nums.size();
        
        for (int num : nums) {
            freq[num]++;
        }
         
        for (auto it : freq) {
            if (it.second > n / 2) {
                return it.first;
            }
        }
               
        return -1;
    }
};

