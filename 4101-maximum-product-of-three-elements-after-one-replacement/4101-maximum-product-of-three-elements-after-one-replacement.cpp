class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long a=nums[n-1],b=nums[n-2],c=nums[n-3];
        if(n>3){
            for(int i=0;i<3;i++){
                if(abs(nums[i])>abs(c)){
                    c=nums[i];
                }else if(abs(nums[i])>abs(b)){
                    b=nums[i];
                }else if(abs(nums[i])>abs(a)){
                    a=nums[i];
                }
            }
            
        }
        long long d=min(abs(a),abs(min(abs(b),abs(c))));
        if(abs(d)==abs(a)){
            ans=b*c;
        }else if(abs(d)==abs(b)){
            ans=a*c;
        }else{
            ans=a*b;
        }
        
        if(ans<0) return -ans*pow(10,5);
        return ans*pow(10,5);
    }
};