class Solution {
public:
    bool closeStrings(const string& word1, const string& word2) {
        if (word1.size() != word2.size()) return false;

        int* word1freq = countfreq(word1);
        int* word2freq = countfreq(word2);

        for (int i = 0; i < 26; i++) {
            if ((word1freq[i] == 0 && word2freq[i] > 0) || (word1freq[i] > 0 && word2freq[i] == 0)) {
                delete[] word1freq;  
                delete[] word2freq;  
                return false;
            }
        }

        
        sort(word1freq, word1freq + 26);
        sort(word2freq, word2freq + 26);

        
        bool result = equal(word1freq, word1freq + 26, word2freq);

        
        delete[] word1freq;  
        delete[] word2freq;  

        return result;
    }

private:
    int* countfreq(const string& word) {
        int* freq = new int[26](); 

        for (char ch : word) {
            if ('a' <= ch && ch <= 'z') {
                freq[ch - 'a']++;
            }
        }

        return freq;
    }
};
