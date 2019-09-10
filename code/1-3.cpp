#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define endl "\n"
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
#define MOD 1000000007
#define input 
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto i:v)output(i);
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
int main(){
    lint n,m;
    cin>>n;
    set<lint>s;
    rep(i,n)s.insert(*istream_iterator<lint>(cin));
    cin>>m;
    lint cnt=0;
    rep(i,m)cnt+=s.count(*istream_iterator<lint>(cin));
    cout<<cnt<<endl;
}