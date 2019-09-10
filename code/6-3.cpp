#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
//----------------------------------------TLEします-------------------------------------------------------
int main(){
    lint n,W;
    cin>>n>>W;
    vector<lint> v(n),w(n),sv(n,0),sw(n,0);
    vector<pair<lint,lint>>p(n);
    rep(i,n)cin>>p[i].first>>p[i].second;
    lint ans=0;
    sort(all(p),[](const auto& s,const auto& t){return s.first*t.second>s.second*t.first;});
    rep(i,n)v[i]=p[i].first;
    rep(i,n)w[i]=p[i].second;
    sw[0]=w[0];
    sv[0]=v[0];
    rep(i,n-1)sv[i+1]=sv[i]+v[i+1];
    rep(i,n-1)sw[i+1]=sw[i]+w[i+1];
    function<void (lint,lint,lint)> f = [&](lint i,lint cur_v,lint cur_w) {
        if (W<cur_w) return;
        if (i == n) {
            ans=max(ans,cur_v);
            return;
        }
        lint lr_v = cur_v;
        lint lr_w = cur_w;
        auto itr=upper_bound(sw.begin(),sw.end(),W-cur_w+(i?sw[i-1]:0));
        lint j=itr-sw.begin();
        lr_w+=sw[j-1]-(i?sw[i-1]:0);
        lr_v+=sv[j-1]-(i?sv[i-1]:0);
        if (lr_w==W||j==n) {
            ans=max(ans,lr_v);
            return;
        }
        double lr_ans=lr_v+v[j]*(W-lr_w)/(double)w[j];
        if(lr_ans<=ans)return;
        if(W>=cur_w+w[i])f(i+1,cur_v+v[i],cur_w+w[i]);
        f(i+1,cur_v,cur_w);
    };
    f(0, 0, 0);
    cout<<ans<<endl;
}