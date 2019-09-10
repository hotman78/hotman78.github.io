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
vector<vector<lint>> mul(const vector<vector<lint>>& s,const vector<vector<lint>>& t){
    vector<vector<lint>> res(2,vector<lint>(2,0));
    rep(i,2)rep(j,2)rep(k,2){
        res[i][j]+=s[i][k]*t[k][j];
    }
    return res;
}
vector<vector<lint>> pow(const vector<vector<lint>>& s,const lint& n){
    if(n==0)return {{1,0},{0,1}};
    if(n==1)return s;
    if(n%2==0){
        vector<vector<lint>> tmp=pow(s,n/2);
        return mul(tmp,tmp);
    }else{
        return mul(s,pow(s,n-1));
    }
}
int main(){
    lint n;
    cin>>n;
    cout<<pow({{1,1},{1,0}},n+1)[1][0]<<endl;
}