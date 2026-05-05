/* 137. Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/

int singleNumber(int* nums, int numsSize) {
    /*int ans = 0;
    for(int bit_count = 0 ; bit_count < 32 ; bit_count++)
    {
        int buf = 0;
        for(int count = 0 ; count < numsSize ; count++)
        {
            buf += (nums[count] >> bit_count) & 1;
        }

        if(buf % 3)
            ans |= 1U << bit_count; 
    }

    return ans;
*/
    int one = 0;
    int two = 0;
    for(int count = 0 ; count < numsSize ; count++)
    {
        one = (one ^ nums[count]) & ~two;
        two = (two ^ nums[count]) & ~one;
    }

    return one;
}