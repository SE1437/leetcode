/* 191. Number of 1 Bits
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

 

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.

Example 3:

Input: n = 2147483645

Output: 30

Explanation:

The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

 

Constraints:

1 <= n <= 231 - 1
 

Follow up: If this function is called many times, how would you optimize it?
*/

int hammingWeight(int n) {
    int hw_answer = 0;
    unsigned int count = 0;
    unsigned int buf = 0;

    while(buf < n)
    {
        buf = (1U << count);
        
        if((n & buf) == buf)
        {
            hw_answer++;
        }

        count++;

    }

    return hw_answer;
}


