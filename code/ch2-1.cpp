#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
#define MOD 1000000007
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto i:v)output(i);
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
class mint {
  using u64 = std::uint_fast64_t;
    public:
    u64 a;
    constexpr mint(const u64 x = 0) noexcept : a(x % MOD) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr mint operator+(const mint rhs) const noexcept {
        return mint(*this) += rhs;
    }
    constexpr mint operator-(const mint rhs) const noexcept {
        return mint(*this) -= rhs;
    }
    constexpr mint operator*(const mint rhs) const noexcept {
        return mint(*this) *= rhs;
    }
    constexpr mint operator/(const mint rhs) const noexcept {
        return mint(*this) /= rhs;
    }
    constexpr mint &operator+=(const mint rhs) noexcept {
        a += rhs.a;
        if (a >= MOD) {
            a -= MOD;
        }
        return *this;
    }
    constexpr mint &operator-=(const mint rhs) noexcept {
        if (a < rhs.a) {
            a += MOD;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr mint &operator*=(const mint rhs) noexcept {
        a = a * rhs.a % MOD;
        return *this;
    }
    constexpr mint operator++(int n) const noexcept {
        return mint(*this) +=1;
    }
    constexpr mint operator--(int n) const noexcept {
        return mint(*this) -=1;
    }
    constexpr mint &operator/=(mint rhs) noexcept {
        u64 exp = MOD - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
};
ostream& operator<<(ostream& lhs, const mint& rhs) noexcept {
    lhs << rhs.a;
    return lhs;
}
istream& operator>>(istream& lhs, const mint& rhs) noexcept {
    lhs >> rhs.a;
    return lhs;
}
inline mint pow(mint m,lint n){
    if(n==0)return 1;
    else if(n%2==0){
        mint x=pow(m,n/2);
        return x*x;
    }else{
        return m*pow(m,n-1);
    }
}
inline mint fact(lint a){
    return a?fact(a-1)*a:1;
}
template<typename T>struct Csum{
    lint n;
    vector<T> v;
    Csum(lint n):n(n){
        v.resize(n+1,0);
    }
    Csum(vector<T> init):n(init.size()){
        v.resize(n+1,0);
        rep(i,init.size())update(i,init[i]);
    }
    //0-indexed
    void update(lint x,T val){
        v[x+1]=v[x]+val;
    }
    //0-indexed [a,b) sum
    T get(lint a,lint b){
        return v[b]-v[a];
    }
    T get(lint x){
        return v[x+1]-v[x];
    }
    vector<T> vals(){
        vector<T> res(n);
        rep(i,n)res[i]=v[i+1]-v[i];
        return res;
    }
};
int main(){
    lint n,m,q;
    cin>>n>>m>>q;
    vector<lint> a(n);
    rep(i,n)cin>>a[i];
    vector<Csum<mint>> dp(n+1,Csum<mint>(m+1));
    dp[0].update(0,1);
    rep(i,m)dp[0].update(i+1,0);
    repi(i,1,n+1)rep(j,m+1){
        dp[i].update(j,dp[i-1].get(max(0LL,j-a[i-1]),j+1));
    }
    vector<mint> last=dp[n].vals();
    vector<Csum<mint>>dp2(n,Csum<mint>(m+1));
    rep(i,n)dp2[i].update(0,1);
    rep(i,n)repi(j,1,m+1){
        dp2[i].update(j,last[j]-dp2[i].get(max(0LL,j-a[i]),j));
    }
    rep(i,q){
        lint k,x;
        cin>>k>>x;
        cout<<dp2[k-1].get(m-x)<<endl;
    }
}