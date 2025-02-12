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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr;
    ll a, b;
    vector<pair<ll,ll>> nums;
    
    for(ll i=0; i<m; i++){
        cin >> a >> b;
        nums.push_back({b, a});
    }
    
    sort(nums.begin(), nums.end());
    ll res=0, curcnt=0;
    for(int i=m-1; i>=0 && curcnt<n; i--){
        if(curcnt+nums[i].second<=n){
            res += nums[i].first * nums[i].second;
            curcnt += nums[i].second;
        } else{
            res += nums[i].first * (n-curcnt);
            curcnt += n-curcnt;
        }
    }
    cout << res << endl;

    return 0;
}