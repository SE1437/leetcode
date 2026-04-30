/* 125. Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <string.h>

#define ALPHANUM(c) (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c <= '9') && (c >= '0')))

#define LOWERCASE(c) ((c >= 'A') && (c <= 'Z') ? (c + 0x20) : c)

bool isPalindrome(char* s) {
    
    int len = strlen(s);
    int left = 0, right = len;

    while(left < right)
    {
        if(!ALPHANUM(s[left]))
        {
            left++;
        }
        else if(!ALPHANUM(s[right]))
        {
            right--;
        }
        else
        {
            if(LOWERCASE(s[left]) == LOWERCASE(s[right]))
            {
                left++;
                right--;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}