class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        std::string a = s.substr(0,n/2);
        std::string b = s.substr(n/2, n);

        int a_vowel = countVowels(a);
        int b_vowel = countVowels(b);

        if(a_vowel == b_vowel)
        {
            return true;
        }

        return false;
        
    }

private:
    int countVowels(const std::string& inputString) {
    int vowelCount = 0;

    for (char ch : inputString) {
        // Convert the character to lowercase for case-insensitive comparison
        char lowerCh = std::tolower(ch);

        // Check if the character is a vowel
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            vowelCount++;
        }
    }

    return vowelCount;
}
};
