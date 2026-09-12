class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        def fact(n1):
            if(n1==0 or n1==1):
                return 1
            return n1*fact(n1-1)
        a=fact(n)
        return fact(2*n)/(((n+1)*a)*a)

        