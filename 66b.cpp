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


int main(){
    int t;
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++)
        cin >> arr[i] ;
    vector<ll> leftsm(n, 1), rightsm(n, 1);
    for(int i=1; i<n; i++){
        if(arr[i]>=arr[i-1])
            leftsm[i] = leftsm[i-1]+1;
    }
    for(int i=n-2; i>=0; i--){
        if(arr[i]>=arr[i+1])
            rightsm[i] = rightsm[i+1]+1;
    }
    ll res=0;
    for(int i=0; i<n; i++)
        res = max(res, leftsm[i]+rightsm[i]-1);
    cout << res << endl;


    return 0;
}