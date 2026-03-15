class Fancy {
public:
    int mod=1e9+7;
    vector<long long> vec;
    long long mul=1;
    long long add=0;
    Fancy() {
        
    }
    long long inverse(long long x){
        long long r1=mod,r2=x,t1=0,t2=1;
        while(r2>0){
            long long r=r1%r2,q=r1/r2;
            long long t=(t1-q*t2)%mod;
            r1=r2;r2=r;t1=t2;t2=t;
        }
        return (t1+mod)%mod;
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