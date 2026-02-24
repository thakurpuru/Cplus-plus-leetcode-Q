class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        int count=0;    
        for(int j=2;j*j<=n;j++){
            for(int i=2*j;i<=n;i+=j)
            prime[i]=false;
        }
        for(int i=0;i<n;i++){
            if(prime[i]) count++;
        }
            
        return count;
    }
};