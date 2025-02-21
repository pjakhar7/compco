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
    ll a, b;
    cin >> a >> b;
    ll ia=a, ib=b;
    vector<ll> periods;
    if(ia==ib){
        cout << "Equal\n";
        return 0;
    }    
    while(ia!=ib){
        if(ia<ib){
            periods.push_back(ia);
            ia += a;
        } else {
            periods.push_back(ib);
            ib += b;
        }
    }
    periods.push_back(ia);
    ll dasha=0, masha=0, lasti=0;
    // for(auto i: periods)
    //     cout << i << " ";
    // cout << endl;
    for(int i=0; i<periods.size()-1; i++){
        if(periods[i]%a==0){
            dasha += periods[i] - lasti;
        } else {
            masha += periods[i] - lasti;
        }
        lasti = periods[i];
    }
    if(a>b){
        dasha += periods[periods.size()-1] - lasti;
    } else {
        masha += periods[periods.size()-1] - lasti;
    }
    // cout << dasha << " " << masha << endl;
    if(dasha>masha)
        cout << "Dasha\n";
    else if(masha>dasha)
        cout << "Masha\n";
    else 
        cout << "Equal\n";
    return 0;
}