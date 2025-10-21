class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        
        n=len(s1)
        if n==1:
            return s1 in s2
        freq_s1={}
        for c in s1:
            freq_s1[c]=freq_s1.get(c,0)+1
        j=0
        window={}
        for i in range(len(s2)):
            if s2[i] in freq_s1:
                window[s2[i]]=window.get(s2[i],0)+1
            else:
                window.clear()
                j=i
            if i-j+1==n:
                if window==freq_s1:
                    return True
                if s2[j] in window:
                    window[s2[j]] -= 1
                    if window[s2[j]]==0:
                        del window[s2[j]]
                j+=1
        return False
        