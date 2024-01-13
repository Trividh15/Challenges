class Solution {
public:
    int minSteps(const string& s, const string& t) {
        if (s.size() != t.size())
        {    
            return -1;
        }

        int charfreqfors[26] = {0};

        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') {
                charfreqfors[ch - 'a']++;
            }
        }

        int charfreqfort[26] = {0};

        for (char ch : t) {
            if ('a' <= ch && ch <= 'z') {
                charfreqfort[ch - 'a']++;
            }
        }

        int steps = 0;

        for (int i = 0; i < 26; i++) {
            steps += abs(charfreqfors[i] - charfreqfort[i]);
        }

        return steps / 2; 
    }
};

