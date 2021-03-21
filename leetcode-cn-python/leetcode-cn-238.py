class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        leftList = [] # [0*1*...*i]
        rightList = [] # [n*n-1*...*i]

        tmp = 1
        for i in range(0, len(nums)):
            leftList.append(tmp*nums[i])
            tmp = leftList[i]

        print leftList
        tmp = 1
        for i in range(len(nums)-1, -1, -1):
            rightList.append(tmp*nums[i])
            tmp = tmp*nums[i]
        rightList.reverse()

        print rightList
        re = []
        for i in range(len(nums)):
            if i-1 >= 0:
                left = leftList[i-1]
            else:
                left = 1
            if i+1 <= len(nums)-1:
                right = rightList[i+1]
            else:
                right = 1
            re.append(left*right)

        return re

if __name__ == "__main__":
    s = Solution()
    nums = [13,5,1,5,25,3]
    re = s.productExceptSelf(nums)
    print re