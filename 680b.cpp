#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <set>
#include <numeric>
// #define ll int long long
typedef long long ll;
using namespace std;

ll calc(vector<ll> &arr, ll n, ll a){
    ll res = 0;
    if(a<0 || a>=n)
        return res;
    if(arr[a])
        res++;
    ll d =1;
    while(a+d<n && a-d>=0){
        if(arr[a+d] && arr[a-d])
            res += 2;
        d++;
    }
    while(a+d<n){
        if(arr[a+d])
            res++;
        d++;
    }
    while (a-d>=0){
        if(arr[a-d])
            res++;
        d++;
    }
    return res;
}

int main(){
    int t;
    ll n, a;
    cin >> n >> a;
    a--;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
        cin >> arr[i] ;
    ll res = calc(arr, n, a);
    cout << res << endl;
    

    return 0;
}