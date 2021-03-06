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
int main(){
    lint v,e,r;
    cin>>v>>e>>r;
    vector<lint> s(e),t(e),d(e);
    rep(i,e)cin>>s[i]>>t[i]>>d[i];
    vector<lint> diff(v,INF);
    diff[r]=0;
    rep(k,v-1)rep(i,e){
        if(diff[s[i]]!=INF)diff[t[i]]=min(diff[t[i]],diff[s[i]]+d[i]);
    }
    vector<lint> ans=diff;
    rep(i,e){
        if(diff[s[i]]!=INF)diff[t[i]]=min(diff[t[i]],diff[s[i]]+d[i]);
    }
    if(ans==diff){
        rep(i,v){
            if(diff[i]>=INF/2)cout<<"INF"<<endl;
            else cout<<diff[i]<<endl;
        }
    }else{
        cout<<"NEGATIVE CYCLE"<<endl;
    }
}