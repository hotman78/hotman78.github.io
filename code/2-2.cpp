#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define all(x) (x).begin(),(x).end()
int main(){
    lint n,q;
    cin>>n;
    vector<lint> a(n);
    rep(i,n)cin>>a[i];
    cin>>q;
    vector<lint> m(q);
    rep(i,q)cin>>m[i];
    set<lint> list;
    rep(i,pow(2,n)){
        lint cnt=0,tmp=i;
        rep(j,n){
            if(tmp%2==1)cnt+=a[j];
            tmp/=2;
        }
        list.insert(cnt);
    }
    rep(i,q){
        if(list.count(m[i]))cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}