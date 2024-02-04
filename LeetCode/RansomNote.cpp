#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomLetters[26];
        int magazineLetters[26];

		// Initialize each letter count to 0
        for (int i = 0; i < 26; i++) {
            ransomLetters[i] = 0;
            magazineLetters[i] = 0;
        }

		// Count the number of letters in ransom string
        for (char c : ransomNote)
            ransomLetters[c - 'a']++;
        
		// Count the number of letters in magazine string
        for (char c : magazine)
            magazineLetters[c - 'a']++;

		// If ransom has more of any letter than magazine, return false
        for (int i = 0; i < 26; i++)
            if (ransomLetters[i] > magazineLetters[i])
                return false;
        
        return true;
    }
};