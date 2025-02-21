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
    ll n, m, x, y;
    cin >> n >> m;
    cin >> x >> y;
    ll k, dx, dy;
    cin >> k;
    ll res = 0, steps;
    // cout << x << " " << y << endl;
    for(int i=0; i<k; i++){
        cin >> dx >> dy;
        steps = INT_MAX;
        if(dx>0){
            steps = (n-x)/dx;
        }
        if(dx<0){
            steps = min(steps, (1-x)/dx);
        }
        if(dy>0){
            steps = min(steps, (m-y)/dy);
        }
        if(dy<0){
            steps = min(steps, (1-y)/dy);
        }
        res += steps;
        x = x + dx*steps;
        y = y + dy*steps;
        // cout << x << " " << y << " with :" << steps << endl;
    }
    cout << res << endl;
    return 0;
}
