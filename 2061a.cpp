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
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll oddcnt=0, evencnt=0, res=0;
        for(ll i=0; i<n; i++){
            ll x;
            cin >> x;
            if(x%2)
                oddcnt++;
            else 
                evencnt++;
        }
        if(evencnt)
            res = 1 + oddcnt;
        else 
            res = oddcnt -1;
        cout << res << endl;     
    }


    return 0;
}