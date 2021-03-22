class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        begin = 0
        re = 0
        for k, v in enumerate(citations):
            if v > k:
                re = k+1
                continue
            else:
                break
        return re

if __name__ == "__main__":
    s = Solution()
    print s.hIndex([7,0,6,1, 4, 5,2,4,5,63,2])