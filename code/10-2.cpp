#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
#define MOD 1000000007
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
struct UF{
    vector<lint> par,rank;
    UF(lint n){
        par.resize(n);
        rank.resize(n,0);
        iota(all(par),0);
    }
    lint root(lint x){
        if(x==par[x])return x;
        else return par[x]=root(par[x]);
    }
    bool unite(lint x,lint y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if (rank[x]<rank[y])swap(x,y);
        if (rank[x]==rank[y])rank[x]++;
        par[y]=x;
        return true;
    }
    bool same(lint x,lint y){
        return root(x)==root(y);
    }
};
int main(){
    lint n,q;
    cin>>n>>q;
    UF uf=UF(n);
    rep(i,q){
        lint com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            uf.unite(x,y);
        }else{
            if(uf.same(x,y))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}