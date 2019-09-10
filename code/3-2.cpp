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
    while(1){
        lint h,w;
        cin>>w>>h;
        if(h==0&&w==0)break;
        vector<vector<lint>> v(h,vector<lint>(w,0));
        rep(i,h)rep(j,w)cin>>v[i][j];
        lint cnt=0;
        rep(i,h)rep(j,w){
            if(v[i][j]!=1)continue;
            cnt++;
            queue<pair<lint,lint>> que;
            que.push({i,j});
            while(!que.empty()){
                lint y,x;
                tie(y,x)=que.front();
                que.pop();
                rep(k,8){
                    if(y+dy[k]<0||h<=y+dy[k]||x+dx[k]<0||w<=x+dx[k])continue;
                    if(v[y+dy[k]][x+dx[k]]==1){
                        v[y+dy[k]][x+dx[k]]=0;
                        que.emplace(y+dy[k],x+dx[k]);
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
}