class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False

        if num % 2 == 0:
            while num % 2 == 0:
                num = num / 2
            if num == 1:
                return True
        
        if num % 3 == 0:
            while num % 3 == 0:
                num = num / 3
            if num == 1:
                return True

        if num % 5 == 0:
            while num % 5 == 0:
                num = num / 5
            if num == 1:
                return True

        if num == 1:
            return True
        return False


if __name__ == "__main__":
    s = Solution()
    print s.isUgly(6)