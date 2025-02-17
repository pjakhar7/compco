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

ll lowbit(ll n){
    for(int i=0; i<32; i++){
        if((n>>i)&1){
            return (1<<i);
        }
    }
    return 1;
}

int main(){   
    ll sum=0, limit=0;

    cin >> sum >> limit ;
    // cout << sum << "  sum  " << limit << endl;
    vector<ll> res;
    if(sum<=limit){
        for(int i=31; i>=0; i--){
            if((sum>>i)&1){
                res.push_back((1<<i));
            }
        }
    } else {
        ll cursum = 0;
        for(ll i=limit; i>0; i--){
            if(lowbit(i)+cursum<=sum){
                // cout << i<<" X " << lowbit(i) << endl;
                res.push_back(i);
                cursum += lowbit(i);
            }
        }
        if(cursum < sum){
            res.clear();
        }

    }
    if(res.empty()){
        cout << -1 << endl;
    } else {
        cout << res.size() << endl;
        for(auto i: res)
            cout << i << " ";
        cout << endl;

    }
    return 0;
}
