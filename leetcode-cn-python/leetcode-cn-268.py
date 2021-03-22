class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        re = len(nums)
        for k, v in enumerate(nums):
            re = re ^ k
            re = re ^ v
        return re


if __name__ == "__main__":
    s = Solution()
    nums = [0, 5, 2, 3, 4, 6]
    
    print s.missingNumber(nums)