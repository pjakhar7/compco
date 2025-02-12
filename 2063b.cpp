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
        int n, l, r, temp;
        cin >> n >> l >> r; 
        vector<ll> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        ll res=0;
        vector<ll> arr, brr;
        arr = nums;
        brr = nums;
        sort(arr.begin(), arr.begin()+r, greater<ll>());
        sort(brr.begin()+l-1, brr.end());
        // for(auto i: nums)
        //     cout << i << " ";
        // cout << endl;
        
        // for(auto i: arr)
        //     cout << i << " ";
        // cout << endl;
        // for(auto i: brr)
        //     cout << i << " ";
        // cout << endl;
        res = min(accumulate(arr.begin()+l-1, arr.begin()+r, 0ll), accumulate(brr.begin()+l-1, brr.begin()+r, 0ll));
        
        cout << res << endl;

        
    }


    return 0;
}