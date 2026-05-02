#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 宏定義，判斷是否為英數字
#define ALPHANUM(c) (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c <= '9') && (c >= '0')))

// 宏定義，轉換為小寫
#define LOWERCASE(c) ((c >= 'A') && (c <= 'Z') ? (c + 0x20) : c)

bool isPalindrome(char* s) {
    int len = strlen(s);
    int left = 0, right = len - 1; // 修正為 len - 1，指向最後一個字元

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

void run_test(int id, char* s, bool expected) {
    bool result = isPalindrome(s);
    printf("Test Case %d:\n", id);
    printf("  Input:    \"%s\"\n", s);
    printf("  Expected: %s\n", expected ? "true" : "false");
    printf("  Result:   %s\n", result ? "true" : "false");
    if (result == expected) {
        printf("  Status:   [PASS]\n\n");
    } else {
        printf("  Status:   [FAIL]\n\n");
    }
}

int main() {
    printf("--- LeetCode #125 Valid Palindrome Testing ---\n\n");

    run_test(1, "A man, a plan, a canal: Panama", true);
    run_test(2, "race a car", false);
    run_test(3, " ", true);
    run_test(4, "0P", false); // 額外的測試案例，包含數字和字母

    return 0;
}
