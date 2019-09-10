#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define all(x) (x).begin(),(x).end()
int main(){
    lint n,W;
    cin>>n>>W;
    vector<lint> v(n),w(n);
    rep(i,n)cin>>v[i]>>w[i];
    lint dp[n+1][W+1]={};
    repi(i,1,n+1)repi(j,1,W+1){
        dp[i][j]=dp[i-1][j];
        if(j-w[i-1]>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
    }
    cout<<dp[n][W]<<endl;
}