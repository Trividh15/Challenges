//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        if (s.empty()) return result;
        substrStartPalin(s, 0, currentPartition, result);
        return result;
    }
    
private:
    void substrStartPalin(const string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                currentPartition.push_back(s.substr(start, i - start + 1));
                substrStartPalin(s, i + 1, currentPartition, result);
                currentPartition.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

