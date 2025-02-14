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

class Trie{
    public:
    vector<Trie*> children;
    bool isWord;

    Trie(){
        children.assign(26, NULL);
        isWord = false;
    }

    void addWord(string word){
        if(word.size()==0){
            this->isWord = true;
            return;
        }
        int curpos = int(word[0]-'a');
        if(children[curpos]==NULL){
            Trie *tr = new Trie();
            this->children[curpos] = tr;
        }
        this->children[curpos]->addWord(word.substr(1));
    }

    bool find(string word){
        if(word.size()==0)
            return isWord;
        int curpos = int(word[0]-'a');
        if(children[curpos]==NULL)
            return false;
        return children[curpos]->find(word.substr(1));
    }

};

bool isConcatHelper(Trie* root, Trie *cur, string word){
    // cout << word << endl;
    if(word.size()==0)
        return cur->isWord;
    int curpos = int(word[0]-'a');
    if(!cur || cur->children[curpos]==NULL)
        return false;
    if(cur->children[curpos]->isWord){
        if(isConcatHelper(root, root, word.substr(1)))
            return true;   
    }
    return isConcatHelper(root, cur->children[curpos], word.substr(1));
}


bool isConcat(Trie* root, Trie *cur, string word){
    if(!cur || word.size()==0)
        return false;
    int curpos = int(word[0]-'a');
    if(cur->children[curpos]->isWord){
        // cout << word << endl;
        if(isConcatHelper(root, root, word.substr(1)))
            return true;   
    }
    return isConcat(root, cur->children[curpos], word.substr(1));
}



vector<string> findWords(vector<string> inp){
    vector<string> res;
    Trie *myTrie = new Trie();
    for(auto s: inp){
        myTrie->addWord(s);
    }
    
    // cout << isConcat(myTrie, myTrie, "dogcatsdog") << endl;
    for(auto s: inp){
        if(isConcat(myTrie, myTrie, s))
            res.push_back(s);
    }
    return res;
}


int main(){
    vector<string> inp = {"cat","cats","catsdogcats", "dog", "dogcatsdog", "hippopotamases","rat","ratcatdogcat"};
    vector<string> out = findWords(inp);
    for(auto s: out)
        cout << s << endl;
    return 0;
}
