#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <set>
#include <numeric>
#include <map>
// #define ll int long long
typedef long long ll;
using namespace std;

void printvec(vector<ll> &arr);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b, temp;
        cin >> n ; 
        map<ll, vector<ll>> adjl;
        vector<ll> inorder(n, 0);
        for(int i=1; i<n; i++){
            cin >> a >> b;
            adjl[b].push_back(a);
            adjl[a].push_back(b);
            inorder[a-1]++;
            inorder[b-1]++;
        }
        // printvec(inorder);
        ll v1 = distance(inorder.begin(), max_element(inorder.begin(), inorder.end()));
        for(auto v: adjl[v1+1]){
            inorder[v-1]--;
            inorder[v1]--;
        }
        
        // printvec(inorder);
        ll v2 = distance(inorder.begin(), max_element(inorder.begin(), inorder.end()));
        if(inorder[v2])
            for(auto v: adjl[v2+1]){
                if(v-1!=v1){
                    inorder[v-1]--;
                    inorder[v2]--;
                }
            }
        
        // printvec(inorder);
        if(n<3){
            cout << 0 << endl;
            continue;
        }
        ll netinorder = accumulate(inorder.begin(), inorder.end(), 0);
        ll res = n-2-netinorder/2;
        cout << res << endl;
    }


    return 0;
}


void printvec(vector<ll> &arr){
    for(auto &x: arr)
        cout << x << " ";
    cout << endl;
}