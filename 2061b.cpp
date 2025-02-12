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
        ll n, res;
        cin >> n;
        vector<ll> arr(n);
        
        for(ll i=0; i<n; i++){
            cin >> arr[i] ;
        }
        sort(arr.begin(), arr.end());
        vector<ll> dubs;
        bool flag = true;
        for(int i=0; i<n-1; i++){
            if(arr[i]==arr[i+1]){
                dubs.push_back(i);
                i++;
            }
        }
        // cout << "HERE 1\n";
        // cout << dubs.size() << " dub size\n";
        if(dubs.empty()){
            cout << -1 << endl;
            continue;
        } else if(dubs.size()>1){
            cout << arr[dubs[0]] <<" "<< arr[dubs[0]] <<" " << arr[dubs[1]] << " " << arr[dubs[1]] << endl;
            flag = false;
            continue;
        } else{
            ll a = arr[dubs[0]];
            arr.erase(arr.begin()+dubs[0]);
            arr.erase(arr.begin()+dubs[0]);
            for(int i=1; i<arr.size(); i++){
                if(arr[i]-arr[i-1]<2*a){
                    cout << a << " " << a << " " << arr[i] << " " << arr[i-1] << endl;
                    flag = false;
                    break;
                }
            }
            if(flag)
            cout << -1 << endl;
        }
        
        // cout << "HERE 2\n";
    }


    return 0;
}