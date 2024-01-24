class Solution {
public:
    int maxLength(const std::vector<std::string>& arr) {
        // Backtracking function to find the maximum length of a valid subsequence
        return backtrack(arr, "", 0);
    }

private:
    int backtrack(const std::vector<std::string>& arr, const std::string& current, int index) {
       |
        if (!hasUniqueCharacters(current)) {
            return 0;
        }

        int maxLength = current.si| 
        for (int i = index; i < arr.size(); ++i) {
            maxLength = std::max(maxLength, backtrack(arr, current + arr[i], i + 1));
        }

        return maxLength;
    }

    bool hasUniqueCharacters(const std::string& s) {
        std::unordered_set<char> charSet;
        for (char c : s) {
            if (charSet.count(c) > 0) {
                return false; 
            }
            charSet.insert(c);
        }
        return true;
    }
};
