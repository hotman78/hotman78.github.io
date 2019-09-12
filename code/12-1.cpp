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
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
struct BIT{
    vector<lint> bit;
    lint n;
    BIT(lint n):n(n){
        bit.resize(n+1,0);
    }
    //1-indexed [1,x]-sum
    lint sum(lint x){
        lint res=0;
        for(lint i=x;i>0;i-=i&-i)res+=bit[i];
        return res;
    }
    //1-indexed [x,y]-sum
    lint sum(lint x,lint y){
        return sum(y)-sum(x-1);
    }
    //1-indexed
    void add(lint x,lint val){
        if(x>n)return;
        for(lint i=x;i<=n;i+=i&-i)bit[i]+=val;
    }
};
int main(){
    lint n;
    cin>>n;
    vector<lint> a(n),b;
    rep(i,n)cin>>a[i];
    b=a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    rep(i,n)a[i]=lower_bound(all(b),a[i])-b.begin()+1;
    BIT bit=BIT(n);
    lint cnt=0;
    rep(i,n){
        cnt+=bit.sum(a[i],n);
        bit.add(a[i],1);
    }
    cout<<cnt<<endl;
}
