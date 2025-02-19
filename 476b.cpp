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
#include <iomanip>

using namespace std;

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define sz size()
#define NL cout << "\n";
#define loop(i, a, b) for(int i=a; i<b; i++)
#define loopr(i, a, b) for(int i=a; i>b; i--)
#define geta(A, a, b) for(int i=a; i<b; i++){cin >> A[i];}
#define getv(v, a, b) for(int i=a; i<b; i++){int x; cin >> x; v.push_back(x);}
#define gets(s, a, b) for(int i=a; i<b; i++){int x; cin >> x; s.insert(x);}
#define seea(A, a, b) for(int i=a; i<b; i++){cout << A[i]<<" ";}cout <<"\n";

// template<typename... T> 
// void put(T&... args){
//     cout << a << " ";
// }
template<typename... T>
void get(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}

typedef long long ll;
typedef long double ld;

const ll mod = 1e9+7;
const ll inf = 1LL<<60;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);

map<int, int> sumcnt;
ll expSum=0;

void func(string &rec, int i, int cursum){
    if(i==rec.size()){
        sumcnt[cursum]++;
        return;
    }
    if(rec[i]=='+'){
        func(rec, i+1, cursum+1);
        return;
    }
    if(rec[i]=='-'){
        func(rec, i+1, cursum-1);
        return;
    }
    func(rec, i+1, cursum+1);
    func(rec, i+1, cursum-1);
}

int main(){
    string exp;
    string rec;
    cin >> exp;
    cin >> rec;
    expSum = 0;
    for(auto c: exp){
        if(c=='+')
            expSum++;
        else    
            expSum--;
    }
    func(rec, 0, 0);
    long double totCnt=0;
    for(auto i: sumcnt)
        totCnt += i.second;
    long double res = sumcnt[expSum]*1.0/totCnt;
    cout << fixed << setprecision(9)<<res << endl;
    return 0;
}
