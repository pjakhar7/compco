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
#include <iomanip>

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

bool cmp(pair<ld,ll> &a, pair<ld,ll> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first < b.first;
}

int main(){
    ll n, t1, t2, k;
    ld a, b, u, v;
    cin >> n >> t1 >> t2 >> k;
    vector<pair<ld, ll>> heights;
    a = (100.0-k)*t1 / 100;
    b = t2;
    int i=0;
    while(i<n){
        cin >> u >> v;
        heights.push_back({max(1.0*a*v+b*u, 1.0*a*u+b*v), i+1});
        i++;
    }
    sort(heights.begin(), heights.end(), cmp);
    for(auto h=heights.rbegin(); h!=heights.rend(); h++){
        cout << h->second << " " << fixed <<  setprecision(2) << h->first << endl;
    }
    return 0;
}