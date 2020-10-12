# Problem Link: https://leetcode.com/problems/maximum-subarray/
'''
	Function to find the maximum sum of any contiguous subarray
	
	Function Arguments: nums (the input array)
	Return Type: maximum sum 

'''
def maxSubArray(nums):

    if len(nums)==0:
        return None

    cur_max = nums[0] # maximum sum so far
    sum_ending = nums[0] # max sum of subarray ending at index i

    for i in range(1,len(nums)):

        sum_ending = max(sum_ending + nums[i], nums[i])
        cur_max = max(cur_max, sum_ending)

    return cur_max