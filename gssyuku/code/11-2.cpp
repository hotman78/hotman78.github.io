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
template<typename T>struct SEG{
    lint n=1;
    vector<T> node;
    T init;
    SEG(lint size,T _init){
        init=_init;
        while(n<size)n*=2;
        node.resize(n*2-1,init);
    }
    SEG(lint size,vector<T> initVec,T _init){
        init=_init;
        while(n<size)n*=2;
        node.resize(n*2-1,_init);
        rep(i,size)node[i+n-1]=initVec[i];
        rrep(i,n-1)node[i]=f(node[2*i+1],node[2*i+2]);
    }
    void update(lint x,T val){
        x+=(n-1);
        node[x]=val;
        while(x>0){
            x=(x-1)/2;
            node[x]=func(node[x*2+1],node[x*2+2]);
        }
    }
    void add(lint x,T val){
        x+=(n-1);
        node[x]+=val;
        while(x>0){
            x=(x-1)/2;
            node[x]=func(node[x*2+1],node[x*2+2]);
        }
    }
    T get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
        if(r<0)r=n;
        if(r<=a||b<=l)return init;
        if(a<=l&&r<=b)return node[k];
        else{
            lint vl=get(a,b,k*2+1,l,(l+r)/2);
            lint vr=get(a,b,k*2+2,(l+r)/2,r);
            return func(vl,vr);
        }
    }
    T func(T s,T t){
        return s+t;
    }
};
int main(){
    lint n,q;
    cin>>n>>q;
    SEG<lint> seg=SEG<lint>(n,0);
    rep(i,q){
        lint com,x,y;
        cin>>com>>x>>y;
        if(com==0){
            seg.add(x-1,y);
        }else{
            cout<<seg.get(x-1,y)<<endl;
        }
    }
}