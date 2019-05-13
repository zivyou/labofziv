class Solution(object):
    def raw_min(self, a, b):
        if a > b:
            return b
        else:
            return a
    def min(self, a, b, c):
        return self.raw_min(a, self.raw_min(b, c))

    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        re = []
        index = 0
        re.append(1)
        current2 = 0
        current3 = 0
        current5 = 0

        while index < n: 
            i = current2
            while i < index:
                if re[i]*2 <= re[index]:
                    i = i+1
                else:
                    break
            current2 = i
            i = current3
            while i < index:
                if re[i]*3 <= re[index]:
                    i = i+1
                else:
                    break
            current3 = i
            i = current5
            while i < index:
                if re[i]*5 <= re[index]:
                    i = i+1
                else:
                    break
            current5 = i
            re.append(min(2*re[current2], 3*re[current3], 5*re[current5]))
            index = index+1   
        #print re
        return re[n-1]
if __name__ == "__main__":
    s = Solution()
    print s.nthUglyNumber(456)
            