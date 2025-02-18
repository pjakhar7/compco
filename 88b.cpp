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


ll n, m, x;
vector<string> keyboard;
map<char, int> keys;

void dfs(int i, int j, int curi, int curj, vector<vector<int>> &visited){
    double dist = (i-curi)*(i-curi) + (j-curj)*(j-curj);
    // cout << curi <<" X " << curj << "   " << keyboard[curi][curj] << visited[curi][curj] << endl;
    visited[curi][curj] = 1;
    // cout << curi <<" - " << curj << "   " << keyboard[curi][curj] << endl;
    // cout << dist << " dist  "  << x*x << endl;
    double diff = x*x - dist ;
    // cout << " diff - " << diff << endl;
    if(dist>x*x)
        return ;
    if(dist<=x*x && keyboard[curi][curj]!='S'){
        keys[char(keyboard[curi][curj]-32)] = 1;
    }
    if(curi+1<n && !visited[curi+1][curj])
        dfs(i, j, curi+1, curj, visited);
    if(curj+1<m && !visited[curi][curj+1])
        dfs(i, j, curi, curj+1, visited);
    if(curi>0 && !visited[curi-1][curj])
        dfs(i, j, curi-1, curj, visited);
    if(curj>0 && !visited[curi][curj-1])  
        dfs(i, j, curi, curj-1, visited);
}

int main(){
    cin >> n >> m >> x;
    string temp, text;
    for(int i=0; i<n; i++){
        cin >> temp;
        keyboard.push_back(temp);
    }
    ll sn;
    cin >> sn;
    cin >> text;
    bool shiftPresent = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(keyboard[i][j]=='S'){
                shiftPresent = true;
                vector<vector<int>> visited(n, vector<int> (m, 0));
                dfs(i, j, i, j, visited);
            } else {
                keys[keyboard[i][j]] = 1;
            }
        }
    }
    if(shiftPresent){
        for(auto i: keys){
            if(keys.count(toupper(i.first)) == 0){
                keys[toupper(i.first)] = 2;
            }
        }
    }
    // for(auto i: keys){
    //     cout << i.first << " " << i.second << endl;
    // }
    ll res = 0;
    for(auto c: text){
        if(keys.count(c)==0){
            res = -1;
            break;
        }
        res += (keys[c]-1);
    }
    cout << res << endl;
    return 0;
}
