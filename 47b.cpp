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

int main(){
    map<char, int> cnts;
    set<pair<int, char>> s;
    string cur;
    cnts['A'] = 0;
    cnts['B'] = 0;
    cnts['C'] = 0;
    for(int i=0; i<3; i++){
        cin >> cur;
        if(cur[1]=='>')
            cnts[cur[0]]++;
        else 
            cnts[cur[2]]++;
    }
    for(auto c: cnts){
        s.insert({c.second, c.first});
        // cout << c.first << " : " << c.second << endl;
    }
    if(s.size()<3){
        cout << "Impossible" << endl;
        return 0;
    }
    string res;
    for(auto i: s)
        res.push_back(i.second);
    cout << res << endl;
    return 0;
}