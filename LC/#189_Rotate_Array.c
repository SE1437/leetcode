/* 189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/



void reverse(int* nums, int start, int end)
{
    int temp = 0;
    while(start < end)
    {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {

    if(numsSize < 1) return;
    //if(k >= numsSize) return;

    // 關鍵修正：讓 k 永遠落在 0 到 numsSize-1 之間
    k %= numsSize; 
    
    // 如果 k 剛好是 numsSize 的倍數，代表不用轉，直接 return
    if (k == 0) return;

    reverse(nums, 0, numsSize - 1);
    reverse(nums, k, numsSize - 1);
    reverse(nums, 0, k - 1);
}

//hint: malloc 生出 dynamic buffer, then memcpy... 浪費 memory, reverse all then reverse each other, or move each other util go back to start
