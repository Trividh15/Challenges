class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string word : words){
            if(ispalindrome(word))
            {
                return word;
                break;
            }
        }
        //if no palindrome string is found : )
        return "";
    }
private:
    bool ispalindrome(string word){
        int left = 0;
    int right = word.length() - 1;
    
    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
    }
};
