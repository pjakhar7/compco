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


int main(){
    ll n, k, t;
    cin >> n >> k;
    ll res = 0, smallestpos=INT_MAX;
    vector<ll> negs;
    for(int i=0; i<n; i++){
        cin >> t;
        if(t<=0)
            negs.push_back(t);
        else{
            res += t;
            smallestpos = min(smallestpos, t);
        }
    }
    int i=0;
    for(; k>0 && i<negs.size(); i++, k--){
        res += negs[i]*(-1);
    }
    for(; i<negs.size(); i++){
        res += negs[i];
    }
    if(!negs.empty())
        smallestpos = min(smallestpos, abs(negs[negs.size()-1]));
    if(k%2){
        res -= 2*smallestpos;
    }
    // seea(negs, 0, negs.size());
    cout << res << endl;
    
    return 0;
}
