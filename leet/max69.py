class Solution(object):
    def maximum69Number (self, num):
        """
        :type num: int
        :rtype: int
        """
        n = str(num)
        n = [i for i in n]
        for i in range (len(n)):
            if(n[i]=='6'):
                n[i] = '9'
                break
        s = ""
        for i in n:
        	s+=i
        return int(s)
s = Solution()
print s.maximum69Number(9669)
