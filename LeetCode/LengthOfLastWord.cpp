#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastI = s.length() - 1;
        int count = 0;
        
        // Move lastI to last index of last word
        while (s[lastI] == ' ')
            lastI--;
        
        // Move firstI to space right before last word
        while (lastI >= 0 && s[lastI] != ' ') {
            lastI--;
            count++;
        }
        
        return count;
    }
};