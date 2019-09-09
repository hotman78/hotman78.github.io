# hotman's homepage

1日目　探索&DPアルゴリズム編
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B	二分探索
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A	bit全探索
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160		BFS/DFS
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0529		半分全列挙
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A	DP
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B	ナップサックDP

3日目 木とグラフ編
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B	ワーシャルフロイド
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A	ダイクストラ
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C	ベルマンフォード
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A	union-find木
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B	segment木
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D	反転数(BIT+座圧)

1日目　チャレンジ問題
https://atcoder.jp/contests/abc020/tasks/abc020_c
https://atcoder.jp/contests/arc028/tasks/arc028_4

3日目　チャレンジ問題
https://atcoder.jp/contests/abc136/tasks/abc136_f
https://atcoder.jp/contests/arc008/tasks/arc008_4
ボツ
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0030		全探索
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_11_A	bit全探索
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A	最大流
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_5_D	順列列挙

```c++:binary_search-1.cpp
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
```
入力を受け取ってbinary_search(v.begin(),v.end(),val)でソート済み配列vの中にvalがあるかを調べます

```c++:binary_search-2.cpp
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
```
自分で関数を作るならこう

```c++:binary_search-3.cpp
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define endl "\n"
typedef long long lint;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define all(x) (x).begin(),(x).end()
#define INF (1LL<<60)
#define MOD 1000000007
#define input 
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto i:v)output(i);
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
int main(){
    lint n,m;
    cin>>n;
    set<lint>s;
    rep(i,n)s.insert(*istream_iterator<lint>(cin));
    cin>>m;
    lint cnt=0;
    rep(i,m)cnt+=s.count(*istream_iterator<lint>(cin));
    cout<<cnt<<endl;
}
```