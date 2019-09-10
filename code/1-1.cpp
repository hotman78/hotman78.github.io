#include<bits/stdc++.h>
using namespace::std;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define all(x) (x).begin(),(x).end()
int main(){
    lint n,q;
    cin>>n;
    vector<lint> s(n);
    rep(i,n)cin>>s[i];
    cin>>q;
    vector<lint> t(q);
    rep(i,q)cin>>t[i];
    sort(all(s));
    lint cnt=0;
    rep(i,q){
        if(binary_search(all(s),t[i]))cnt++;
    }
    cout<<cnt<<endl;
}