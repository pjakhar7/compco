#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <tuple>
#include <stack>

using namespace std;

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define sz size()
#define NL cout << "\n";
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>b; i--)
#define geta(A, a, b) for(int i=a; i<b; i++){cin >> A[i];}
#define getv(v, a, b) for(int i=a; i<b; i++){int x; cin >> x; v.push_back(x);}
#define gets(s, a, b) for(int i=a; i<b; i++){int x; cin >> x; s.insert(x);}
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i]<<" ";}cout <<"\n";

// template<typename... T> 
// void put(T&... args){
//     cout << a << " ";
// }
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}

typedef long long ll;
typedef long double ld;

const ll mod = 1e9+7;
const ll inf = 1LL<<60;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);


int main(){
    int p,q,l,r, a, b;
    cin >> p >> q >> l >> r;
    vector<pair<int,int>> zsegs, xsegs;
    for(int i=0; i<p; i++){
        cin >> a >> b;
        zsegs.push_back({a,b});
    }
    map<int,bool> zactive;
    for(auto s: zsegs){
        for(int i=s.first; i<=s.second; i++)
            zactive[i] = true;
    }
    for(int i=0; i<q; i++){
        cin >> a >> b;
        xsegs.push_back({a,b});
    }
    set<int> res;
    for(auto ii: xsegs){
        for(int i=ii.first; i<=ii.second; i++){
            for(int t=l; t<=r; t++){
                if(zactive[i+t])
                    res.insert(t);
            }
        }
    }
    cout << res.size() << endl;
    return 0;
}
