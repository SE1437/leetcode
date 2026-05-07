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
        one = (one ^ nums[count]) & ~two; //不是已出現過一次的, 若出現兩次的就會被消掉, 進入一次 buf
        two = (two ^ nums[count]) & ~one; //不是已出現過兩次的, 若出現一次的就被消掉, 進入兩次 buf
    }

    return one;
}

//新值 in nums 與出現過一次buf 不一樣先記起來, 又檢查 出現過兩次的 不一樣才記起來到 只出現一次buf