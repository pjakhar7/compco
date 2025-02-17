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
    ll n, m, k, t;
    cin >> n >> m >> k >> t;
    ll a, b;
    vector<ll> wastes;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        wastes.push_back(m*(a-1)+b-1);
    }
    int cur=0;
    vector<string> crops = {"Waste", "Carrots", "Kiwis", "Grapes"};
    sort(wastes.begin(), wastes.end());
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << field[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while(t--){
        cin >> a >> b;
        ll cur = m*(a-1) + b-1;
        ll pos = lower_bound(wastes.begin(), wastes.end(), cur)-wastes.begin();
        if(wastes[pos] == cur){
            cout << crops[0] << "\n";
        } else{
            cout << crops[(cur-pos)%3+1] << "\n";
        }
    }   
    return 0;
}
