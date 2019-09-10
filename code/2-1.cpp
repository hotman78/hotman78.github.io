#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define all(x) (x).begin(),(x).end()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    lint n,q;
    cin>>n;
    vector<lint> a(n);
    rep(i,n)cin>>a[i];
    cin>>q;
    vector<lint> m(q);
    rep(i,q)cin>>m[i];
    set<lint> list;
    rep(i,1<<n){
        lint cnt=0;
        rep(j,n){
            if(i&1<<j)cnt+=a[j];
        }
        list.insert(cnt);
    }
    rep(i,q){
        if(list.count(m[i]))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}