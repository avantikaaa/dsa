class Solution(object):
    def check(self, l, c):
        for word in l:
            if c not in word:
                return False
        return True
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        l = []
        for word in A:
            l.append([i for i in word])
        l2 = [i for i in l[0]]
        out = []
        for c in l2:
            if(self.check(l, c)):
                for word in l:
                    word.remove(c)
                out.append(c)
        return out
l = ["bella","label","roller"]
s = Solution()
print s.commonChars(l)
l=["cool","lock","cook"]
print s.commonChars(l)
