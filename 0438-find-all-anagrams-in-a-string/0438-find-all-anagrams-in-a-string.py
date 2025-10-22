class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        freq_p={}
        for c in p:
            freq_p[c]=freq_p.get(c,0)+1
        window={}
        j=0
        ans=[]
        n=len(p)
        for i in range(len(s)):
            if s[i] in freq_p:
                window[s[i]]=window.get(s[i],0)+1
            else:
                window.clear()
                j=i
            if i-j+1==n:
                if window==freq_p:
                    ans.append(j)
                if s[j] in window:
                    window[s[j]]-=1
                    if window[s[j]]==0:
                        del window[s[j]]
                j+=1
        return ans
            
                

        