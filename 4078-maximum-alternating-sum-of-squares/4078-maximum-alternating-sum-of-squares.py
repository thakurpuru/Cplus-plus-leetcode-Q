class Solution(object):
    def maxAlternatingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort(key=abs, reverse=True)
        i=0
        n=len(nums)
        a=n//2
        if n%2!=0:
            a+=1

        total_sum=0
        for i in range(n):
            if i<a:
                total_sum+=(nums[i]*nums[i])
            else:
                total_sum-=(nums[i]*nums[i])

        return total_sum
        