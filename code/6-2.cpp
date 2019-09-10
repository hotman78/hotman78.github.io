#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
int main(){
    lint n,W;
    cin>>n>>W;
    vector<lint> v(n),w(n);
    rep(i,n)cin>>v[i]>>w[i];
    lint mx=accumulate(all(v),0LL);
    vector<vector<lint>> dp(n+1,vector<lint>(mx+1,INF));
    rep(i,n+1)dp[i][0]=0;
    lint ans=0;
    repi(i,1,n+1)repi(j,1,mx+1){
        dp[i][j]=dp[i-1][j];
        if(j-v[i-1]>=0)dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i-1]]+w[i-1]);
        if(dp[i][j]<=W)ans=max(ans,j);
    }
    cout<<ans<<endl;
}
