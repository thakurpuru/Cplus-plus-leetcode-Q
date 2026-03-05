class TrieNode{
    public:
    TrieNode *child[2];
    TrieNode(){
        this->child[0]=NULL;
        this->child[1]=NULL;
    }
};
class Solution {
public:
    TrieNode *root=new TrieNode();
    void insert(int x){
        TrieNode *curr=root;
        bitset<32> bs(x);
        for(int i=31;i>=0;i--){
            if(curr->child[bs[i]]==NULL){
                curr->child[bs[i]]=new TrieNode();
            }
            curr=curr->child[bs[i]];
        }
    }
    int maxXor(int n){
        TrieNode *curr=root;
        int ans=0;
        bitset<32> bs(n);
        for(int i=31;i>=0;i--){
            if(curr->child[!bs[i]]!=NULL){
                ans+=(1<<i);
                curr=curr->child[!bs[i]];
            }else{
                curr=curr->child[bs[i]];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int max_Xor=0;
    
        for(int i=0;i<nums.size();i++){
            insert(nums[i]);
        }
        for(int n:nums){
            max_Xor=max(max_Xor,maxXor(n));
        }
        return max_Xor;
    }
};