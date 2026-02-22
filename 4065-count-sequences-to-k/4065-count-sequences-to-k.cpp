class Solution {
public:
    int count=0;
    unordered_map<string,int> memo;
    int sequence(vector<int>& nums, long long &k,long long num,long long den,int i){
        if(i>=nums.size()){
            if(den!=0 && (__int128)num ==(__int128)k*den) return 1;
            return 0;
        }
        string key=to_string(i)+'#'+to_string(num)+'#'+to_string(den);
        if(memo.count(key)) return memo[key];
        long long ans=0;
        ans+=sequence(nums,k,num,den,i+1);
        long long x=nums[i];
        long long n=num,d=den;

        long long g1=std::gcd(llabs(x),llabs(d));
        x/=g1;
        d/=g1;
        ans+=sequence(nums,k,x*n,d,i+1);
        long long x1=nums[i];
        long long n2=num,d2=den;
        long long g2=std::gcd(llabs(x1),llabs(n2));
        x1/=g2;
        n2/=g2;
        ans+=sequence(nums,k,n2,d2*x1,i+1);
        return memo[key]=ans;
    }
    int countSequences(vector<int>& nums, long long k) {
        auto ranovetilu=nums;
        return sequence(nums,k,1,1,0);
    }
};