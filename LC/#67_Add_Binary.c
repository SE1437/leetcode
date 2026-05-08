/* 67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
#if 0
#include "string.h"

char* addBinary(char* a, char* b) {
    int len_a =  strlen(a);
    int len_b =  strlen(b);
    int max_len;
    int carry = 0;
    (len_a > len_b) ? (max_len = len_a) : (max_len = len_b);
    
    int digit_count = max_len;

    char* answer = (char*)malloc(max_len + 2);
    answer[max_len+1] = 0x00;

    len_a--;//index maximum = strlen - 1, since strlen include none 0x00 cut off charactor 
    len_b--;
    while((len_a > 0) || (len_b > 0) || (carry > 0))
    {
        int sum = carry;
        if(len_a > 0)
        {
            sum += a[len_a] - '0';
            len_a--;
        }

        if(len_b > 0)
        {
            sum += b[len_b] - '0';
            len_b--;
        }

        if(digit_count >= 0)
            answer[digit_count--] = (sum & 1) + '0';
        
        carry = sum >> 1;

    }

    return &answer[digit_count +1];
}
#endif

#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = (len_a > len_b ? len_a : len_b);
    
    // 預留進位與結束字元空間
    char* res = (char*)malloc(max_len + 2);
    res[max_len + 1] = '\0';
    
    // 指標初始化：指向字串的最末端 (LSB)
    char *pa = a + len_a - 1;
    char *pb = b + len_b - 1;
    char *pr = res + max_len; // 從結果字串的最後一個位置開始填
    
    int carry = 0;
    
    // 指標算術：只要指標還沒指到起始位址之前，或還有進位就繼續
    while (pa >= a || pb >= b || carry) {
        int sum = carry;
        if (pa >= a) sum += (*pa--) - '0'; // 取值後指標往前移
        if (pb >= b) sum += (*pb--) - '0';
        
        *pr-- = (sum & 1) + '0';
        carry = sum >> 1;
    }
    
    // 如果最後沒有最高位進位，pr 會停在一個沒填到的位置
    return pr + 1;
}