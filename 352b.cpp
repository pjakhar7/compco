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
    
    int n, k, a, b, d;
    cin >> n;
    vector<ll> nums(n, 0);
    map<int, vector<int>> xs;
    
    for(int i=0; i<n; i++){
        cin >> a;
        xs[a].push_back(i);
    }
    set<pair<int,int>> res;
    // for(auto x: xs){
    //     cout << x.first << "  --  ";
    //     for(auto i: x.second)
    //         cout << i << " ";
    //     cout << endl;
    // }
    for(auto ii: xs){
        int curx = ii.first;
        int curpx = 0;
        if(ii.second.size()==1){
            res.insert({curx, curpx});
        } else {
            curpx = ii.second[1] - ii.second[0];
            bool flag = true;
            for(int i=2; i<ii.second.size(); i++){
                if(ii.second[i]-ii.second[i-1] != curpx){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.insert({curx, curpx});
            }
        }
    }
    cout << res.size() << endl;
    for(auto i: res){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
