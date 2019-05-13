class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num >= 10:
            n = 0
            while num != 0:
                n = n + num % 10
                num = num / 10
            num = n
            
        return num


if __name__ == "__main__":
    s = Solution()
    print s.addDigits(1)