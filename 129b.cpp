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
    ll n, m;
    cin >> n >> m;
    vector<int> indegree(n+1, 0);
    map<int, vector<int>> graph;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[b].push_back(a);
        graph[a].push_back(b);
        indegree[a]++;
        indegree[b]++;
    }
    bool flag = true;
    int res = 0;
    while(flag){
        // seea(indegree, 0, n+1);
        flag = false;
        vector<int> group;
        for(int i=1; i<=n; i++){
            if(indegree[i]==1){
                group.push_back(i);
                flag = true;
            }
        }
        for(auto i: group){
            indegree[i]--;
            for(auto v: graph[i]){
                indegree[v]--;
            }
                
        }
        if(flag)
            res++;
    }
    cout << res << endl;
    return 0;
}
