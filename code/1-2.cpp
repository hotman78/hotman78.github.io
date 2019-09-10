#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define all(x) (x).begin(),(x).end()
inline bool search(vector<lint>& v,lint& val){
    lint left = -1;
    lint right =v.size();
    while (right - left > 1) {
        lint mid = left + (right - left) / 2;
        if (v[mid]>=val) right = mid;
        else left = mid;
    }
    return v[right]==val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
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
        if(search(s,t[i]))cnt++;
    }
    cout<<cnt<<endl;
}