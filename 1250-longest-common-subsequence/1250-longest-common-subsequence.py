class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        n=len(text1)
        m=len(text2)
        dp=[[-1]*m for _ in range(n)]
        def subsequence(i,j):
            if i>=n or j>=m:
                return 0
            if dp[i][j]!=-1:
                return dp[i][j]
            ans=0
            if text1[i]==text2[j]:
                ans=1+subsequence(i+1,j+1)
            else:
                ans=max(subsequence(i+1,j),subsequence(i,j+1))
            dp[i][j]=ans
            return ans
        return subsequence(0,0)
            
        