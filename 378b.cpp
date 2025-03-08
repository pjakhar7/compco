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
    ll n;
    cin >> n;
    vector<vector<ll>> times(n, vector<ll> (2,0));
    map<ll, pair<int,int>> pos;
    for(int i=0; i<n; i++){
        cin >> times[i][0] >> times[i][1];
        pos[times[i][0]] = {i,0};
        pos[times[i][1]] = {i,1};
    }
    vector<vector<char>> sem(n, vector<char> (2,'0'));
    for(int i=0; i<n/2; i++){
        sem[i][0] = '1';
        sem[i][1] = '1';
    }
    int rank = 0;
    for(auto pi=pos.begin(); rank<n ; pi++){
        // cout << pi->first << " " << pi->second.first << " " << pi->second.second << endl;
        rank++;
        sem[pi->second.first][pi->second.second] = '1';
    }
    for(int i=0; i<n; i++)
        cout << sem[i][0] ;
    cout << endl;
    for(int i=0; i<n; i++)
        cout << sem[i][1] ;
    cout << endl;
    return 0;
}