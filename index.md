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

```c++:binary_serch.cpp
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