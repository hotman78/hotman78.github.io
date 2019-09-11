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
lint binary_search(function<bool(lint)> func) {
    lint left = -1;
    lint right =INF;
    while (right - left > 1) {
        lint mid = left + (right - left) / 2;
        if (func(mid)) right = mid;
        else left = mid;
    }
    return right;
}
int main(){
    lint h,w,t;
    cin>>h>>w>>t;
    vector<vector<lint>> s(h,vector<lint>(w,0));
    lint sy=0,sx=0,gy=0,gx=0;
    rep(i,h){
        string a;
        cin>>a;
        rep(j,w){
            if(a[j]=='S'){
                sy=i;sx=j;
            }
            if(a[j]=='G'){
                gy=i;gx=j;
            }
            if(a[j]=='#')s[i][j]=1;
        }
    }
    cout<<binary_search([=](lint val){
        vector<vector<lint>> diff(h,vector<lint>(w,INF));
        diff[sy][sx]=0;
        priority_queue<tuple<lint,lint,lint>,vector<tuple<lint,lint,lint>>,greater<tuple<lint,lint,lint>>> que;
        que.emplace(0,sy,sx);
        while(!que.empty()){
            lint y,x;
            tie(ignore,y,x)=que.top();
            que.pop();
            if(y==gy&&x==gx)break;
            rep(i,4){
                if(y+dy[i]<0||h<=y+dy[i]||x+dx[i]<0||w<=x+dx[i])continue;
                if(chmin(diff[y+dy[i]][x+dx[i]],diff[y][x]+(s[y+dy[i]][x+dx[i]]?val:1))){
                    que.emplace(diff[y+dy[i]][x+dx[i]],y+dy[i],x+dx[i]);
                }
            }
        }
        return diff[gy][gx]>t;
    })-1<<endl;
}