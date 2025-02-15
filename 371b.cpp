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

const ll MP = 1000002;
vector<bool> primes(1000002, true);

vector<ll> getPrimeFactors(ll a){

    ll i=2;
    vector<ll> res;
    if(a< MP &&primes[a]){
        res.push_back(a);
        return res;
    }

    while(a>1  && i<MP){
        while(a%i==0){
            res.push_back(i);
            a /= i;
        }
        i++;
        while(i<MP &&!primes[i])
            i++;
    }
    if(a>1)
        res.push_back(a);
    // cout << a << endl;
    return res;
}   

void showSet(vector<ll> &a){
    for(auto i: a)
        cout << i << " ";
    cout << endl;
}

int main(){
    ll a, b;
    cin >> a >> b;
    primes[1] = false;
    for(ll p=2; p<MP; p++){
        if(primes[p]==true){
            for(ll j=p*p; j<MP; j+=p)
                primes[j] = false;
        }
    }

    
    // for(int i=1; i<=100; i++){
    //     if(primes[i])
    //         cout << i << " ";
    // }
    vector<ll> ap, bp;
    ap = getPrimeFactors(a);
    bp = getPrimeFactors(b);
    vector<ll> diff;
    set_symmetric_difference(ap.begin(), ap.end(), bp.begin(), bp.end(), back_inserter(diff));
    ll res = diff.size();
    for(auto ii: diff){
        if(ii>5){
            res = -1;
            break; 
        }
    }
    cout << res << endl;
    return 0;
}
