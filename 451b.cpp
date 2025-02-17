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
    int n;
    cin >> n;
    vector<ll> arr(n);
    geta(arr, 0, n);
    arr.insert(arr.begin(), 0);
    arr.push_back(INT_MAX);
    ll resi=-1, resj=-1, res=0, i=1, j=1;
    // seea(arr, 0, n+2);
    while(i<= n){
        while(i<=n && arr[i]<arr[i+1]){
            i++;
            j++;
        }
        while(j<=n && arr[j]>arr[j+1]){
            j++;
        }
        // cout << i << " " << j << endl;
        if(j<=n && arr[i]<=arr[j+1] && arr[j]>=arr[i-1]){
            if(resi>0){
                resi = -1;
                resj = -1;
            }
            resi = i;
            resj = j;
        }
        i = j;
    }
    bool isSorted = true;
    for(int i=1; i<n; i++){
        if(arr[i]>arr[i+1])
            isSorted = false;
    }
    if(isSorted){
        resi = 1; resj = 1;
    }

    if(resi==-1){
        cout << "no\n";
    } else {
        cout << "yes\n";
        cout << resi << " " << resj << endl;
    } 
    return 0;
}
