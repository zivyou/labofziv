import sys
import re

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """

        re = []
        re.append(0)
        for i in range(1, n+1):
            minNum = sys.maxint
            j = 1
            while j*j <= i:
                minNum = min(minNum, re[i - j*j])
                j = j+1
            re.append(minNum+1)
        print re
        return re[n]

if __name__ == "__main__":
    s = Solution()
    print s.numSquares(12)

    print re.match("tion", "function")
    print re.search("tion", "function")