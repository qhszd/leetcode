// Description
// 1832. Check if the Sentence Is Pangram

// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters,
// return true if sentence is a pangram, or false otherwise.


// Example 1:
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.

// Example 2:
// Input: sentence = "leetcode"
// Output: false


// Constraints:
// 1 <= sentence.length <= 1000
// sentence consists of lowercase English letters.

#include <iostream>
#include <string>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        bool eleTruth[26] = { 0 };
        bool truth = true;
        
        for( auto iterator = sentence.begin(); iterator != sentence.end(); ++iterator ){
            eleTruth[*iterator - 'a'] = true;
        }
        for( int i = 0; i < 26; ++i ){
            truth = truth && eleTruth[i];
        }
        return truth;
    }
};

int main(int argc, char* argv[])
{
    std::string sentence = "leetcode";
    Solution obj = Solution();
    std::cout << obj.checkIfPangram(sentence) << std::endl;
    return 0;
}
