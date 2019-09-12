#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace::std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/numeric/interval/io.hpp>
// #include <boost/intrusive/rbtree.hpp>
// #include <boost/geometry.hpp>
// #include <boost/geometry/geometries/linestring.hpp>
// #include <boost/geometry/geometries/polygon.hpp>
// #include <boost/geometry/geometries/point_xy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
using namespace::std;
namespace mp = boost::multiprecision;
typedef mp::number<mp::cpp_dec_float<0>> cdouble;
typedef mp::cpp_int cint;
typedef long long lint;
typedef long long ll;
typedef long double ldouble;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<double> dvec;
typedef vector<vector<double>> dmat;
typedef vector<vector<vector<double>>> dmat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef vector<vector<vector<string>>> smat3;
typedef vector<pair<lint,lint>> pvec;
typedef vector<vector<pair<lint,lint>>> pmat;
typedef vector<vector<vector<pair<lint,lint>>>> pmat3;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define PI 3.141592653589793
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"");if(i>INF/2)cout<<"INF";else cout<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto j:v)output(j);
#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define SUM(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define EPS (1e-10)
#define LINF 9223372036854775807
#define MOD 1000000007
#define endl "\n"
template<typename T=lint> T in(){
    return *istream_iterator<T>(cin);
}
inline lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}
inline lint lcm(lint a,lint b){return a*b/gcd(a,b);}
inline bool chmin(auto& s,const auto& t){bool res=s>t;s=min(s,t);return res;}
inline bool chmax(auto& s,const auto& t){bool res=s<t;s=max(s,t);return res;}
inline lint mex(vector<lint> s){
    lint res=0;
    sort(all(s));
    while(binary_search(all(s),res))res++;
    return res;
}
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};

template<typename T=long long,typename E=T>
struct segment{
    private:
    T et;
    E ee;
    lint n;
    lint size;
    struct node{
        T val;
        E lazy;
        node *lch,*rch;
        node(segment &seg):lch(nullptr),rch(nullptr){val=seg.et;lazy=seg.ee;}
    };
    struct interval{
        segment<T,E>* seg;
        lint l,r;
        interval operator +=(T n){seg->update(l,r,n);return *this;}
        interval operator =(T n){seg->update(l,r,n);return *this;}
        operator T(){return seg->get(l,r);}
    };
    struct iterator{
        lint n;
        segment<T,E>* seg;
        iterator(segment* seg,lint n):n(n),seg(seg){}
        auto operator!=(const iterator& rhs){return n!=rhs.n;}
        auto operator++(){n++;}
        auto operator--(){n--;}
        auto operator+=(lint add){n+=add;}
        auto operator-=(lint sub){n-=sub;}
        auto operator*(){return seg->get(n,n+1);}
    };
    node* root;
    public:
    segment(lint size,T et,E ee):et(et),ee(ee),n(1),size(size){
        while(n<size)n<<=1;
        root=new node(*this);
    }
    segment(T et,E ee):et(et),ee(ee),n((1LL<<61)-1),size(1LL<<60){
        root=new node(*this);
    }
    public:
    //0-indexed [a,b)
    T update(lint a,lint b,E x,lint k=0,lint l=0,lint r=-1,node* t=nullptr){
        if(t==nullptr)t=root;
        if(r<0)r=n;
        eval(t,r-l,k);
        //区間外
        if(r<=a||b<=l)return t->val;
        //全部区間内
        if(a<=l&&r<=b){
            t->lazy=g(t->lazy,x);
            return h(t->val,t->lazy,r-l);
        }
        //一部区間内
        if(t->lch==nullptr)t->lch=new node(*this);
        if(t->rch==nullptr)t->rch=new node(*this);
        return t->val=f(update(a,b,x,2*k+1,l,(l+r)/2,t->lch),update(a,b,x,2*k+2,(l+r)/2,r,t->rch));
    }
    //0-indexed [a,b)
    T get(lint a,lint b,lint k=0,lint l=0,lint r=-1,node* t=nullptr){
        if(t==nullptr)t=root;
        if(r<0)r=n;
        eval(t,r-l,k);
        //区間外
        if(r<=a||b<=l)return et;
        //全部区間内
        if(a<=l&&r<=b)return t->val;
        //一部区間内
        if(t->lch==nullptr)t->lch=new node(*this);
        if(t->rch==nullptr)t->rch=new node(*this);
        return f(get(a,b,2*k+1,l,(l+r)/2,t->lch),get(a,b,2*k+2,(l+r)/2,r,t->rch));
    }
    iterator begin(){
        return iterator(this,0);
    }
    iterator end(){
        return iterator(this,size);
    }
    interval operator ()(lint l,lint r){return interval{this,l,r};}
    interval operator ()(lint n){return interval{this,n,n+1};}
    interval operator [](lint n){return interval{this,n,n+1};}
    private:
    inline void eval(node* t,lint len,lint k){
        if(t->lazy==ee) return;
        if(k*2+1<n*2-1){
            if(t->lch==nullptr)t->lch=new node(*this);
            if(t->rch==nullptr)t->rch=new node(*this);
            t->lch->lazy=g(t->lch->lazy,t->lazy);
            t->rch->lazy=g(t->rch->lazy,t->lazy);
        }
        t->val=h(t->val,t->lazy,len);
        t->lazy=ee;
    }
    T f(T a,T b){
        return a+b;
    }
    T h(T a,E b,lint len){
        return a+b*len;
    }
    E g(E a,E b){
        return a+b;
    }
    auto update(auto a,auto b){return b==ee?a:b;}
};

int main(){
    lint n=in(),q=in();
    segment<> seg(n,0,0);
    rep(i,q){
        if(in()==0){
            lint s=in(),t=in();
            seg[s-1]+=t;
        }else{
            lint s=in(),t=in();
            cout<<seg(s-1,t)<<endl;
        }
    }
}