#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
// #define ll int long long
typedef long long ll;
using namespace std;


int main(){
    // int t;
    // cin >> t;
    // while(t--){
        ll n;
        cin >> n;
        vector<ll> arra(n), arrb(n);
        for(ll i=0; i<n; i++)
            cin >> arra[i] >> arrb[i];
        ll res=0;
        for(int i=0; i<n; i++){
            res = arrb[i]-arra[i];
            if(res==0 && arra[i]==1)
                res++;
            cout << res<<endl;
        }        



        
    // }


    return 0;
}