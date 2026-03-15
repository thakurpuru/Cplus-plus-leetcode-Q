class Fancy {
public:
    int mod=1e9+7;
    vector<long long> vec;
    long long mul=1;
    long long add=0;
    Fancy() {
        
    }
    long long inverse(long long x){
        long long res=1,p=mod-2;
        while(p>0){
            if(p&1) res=(res*x)%mod;
            x=(x*x)%mod;
            p>>=1;
        }
        return res;
    }
    void append(int val) {
        long long v=((val-add+mod)%mod*inverse(mul))%mod;
        vec.push_back(v);
    }
    
    void addAll(int inc) {
        add=(add+inc)%mod;
    }
    
    void multAll(int m) {
        mul=(mul*m)%mod;
        add=(add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=vec.size()) return -1;
        return (vec[idx]*mul+add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */