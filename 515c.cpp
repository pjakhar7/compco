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

string calc(string a){
    string res;
    vector<int> nums;
    for(auto c: a){
        int cur = c-'0';
        if(cur>1){
            if(cur==4){
                nums.push_back(2);
                nums.push_back(2);
                nums.push_back(3);
            }
            else if(cur==6){
                nums.push_back(3);
                nums.push_back(5);
            }
            else if(cur==8){
                nums.push_back(2);
                nums.push_back(2);
                nums.push_back(2);
                nums.push_back(7);
            }
            else if(cur==9){
                nums.push_back(2);
                nums.push_back(3);
                nums.push_back(3);
                nums.push_back(7);
            } else{
                nums.push_back(cur);
            }
        }
    }
    sort(nums.begin(), nums.end(), greater<int>());
    for(auto i: nums){
        // cout << i << " ";

        res += char('0'+i);
    }
    return res;
}

int main(){
    int t;
    ll n;
    string a;
    cin >> n;
    cin >> a;
    string res = calc(a);
    cout << res << endl;
    

    return 0;
}