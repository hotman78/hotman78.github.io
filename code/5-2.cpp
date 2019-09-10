#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
#define MOD 1000000007
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};

int main(){
    lint n;
    cin>>n;
    lint dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=dp[1]=1;
    function<lint(lint)> f=[&](lint i){
        if(dp[i]!=-1)return dp[i];
        else return dp[i]=f(i-1)+f(i-2);
    };
    cout<<f(n)<<endl;
}
