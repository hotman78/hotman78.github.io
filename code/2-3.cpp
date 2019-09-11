#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
typedef long long lint;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;

int main(){
    bitset<40001>b;
    lint n,q;
    cin>>n;
    vector<lint>a(n);
    rep(i,n)cin>>a[i];
    cin>>q;
    vector<lint>m(q);
    rep(i,q)cin>>m[i];
    b[0]=1;
    rep(i,n)b|=b<<a[i];
    rep(i,q){
        if(b[m[i]])cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}