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
    char pres;
    cin >> n >> m >> pres;
    vector<string> seats;
    string temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        seats.push_back(temp);
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << seats[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    set<char> deputies;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(seats[i][j] == pres){
                if(i+1<n)
                    deputies.insert(seats[i+1][j]);
                if(i>0)
                    deputies.insert(seats[i-1][j]);
                if(j+1<m)
                    deputies.insert(seats[i][j+1]);
                if(j>0)
                    deputies.insert(seats[i][j-1]);
            }
        }
    }
    deputies.erase(pres);
    deputies.erase('.');
    cout << deputies.size() << endl;
    return 0;
}
