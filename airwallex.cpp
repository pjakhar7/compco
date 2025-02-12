#include <bits/stdc++.h>
#include <stdexcept>

// Say we have a number of bank accounts with name and balance. ie. ( name, balance )

// At the end of each day we want to transfer money between accounts to ensure that each account
// has at least 100 dollars in it. 

// Write a program to determine the transfers required to satisfy the requirement. Each transfer 
// should be presented as ( from_account_name, to_account_name, amount ).

// For example:

// bank_accounts = [("a", 80), ("b", 180)]
// transfers = determine_transfers(bank_accounts)

// # expected result
// # transfers = [("b", "a", 20)]

// Ie. you are expected to implement the function:
//   List<Transfer> determine_transfers(List<BankAccount> bank_accounts)
  
  using namespace std;



class BankAccount{
    public:
    string name;
    int balance;
    vector<int> list;

    BankAccount(int balance, string name){
        this->name = name;
        this->balance = balance;
    }
    
};

class Transfer{
    string fromAccount;
    string toAccount;
    int amount;
};

bool comp(BankAccount b1, BankAccount b2){return b1.balance < b2.balance;}

vector<pair< pair < string, string>, int>> determine_transfers(vector<BankAccount> balances){
    sort(balances.begin(), balances.end(), comp);
    int i=0, j=balances.size()-1, n = balances.size();
    long long totalBalance=0;
    for(auto t: balances){
        totalBalance += t.balance;
    }
    vector<pair< pair < string, string>, int>> transfers;
    if(totalBalance < n*100){
        throw invalid_argument("Not Possible for these balances");                            
    }
    while(i<j && balances[i].balance < 100){
        int required = (100-balances[i].balance);
        if(balances[j].balance>100+required){
            balances[j].balance = balances[j].balance - required;
            balances[i].balance = balances[i].balance + required;
            transfers.push_back({{balances[j].name, balances[i].name}, required});
            i++;
        } else {
            int available = balances[j].balance - 100;
            balances[j].balance = balances[j].balance - available;
            balances[i].balance = balances[i].balance + available;
            transfers.push_back({{balances[j].name, balances[i].name}, available});
            j--;
        }
    }
    return transfers;
}



bool validateBalances(vector<pair<int, string>> balances, vector<pair<pair<string,string>, int>> &transfers){
    for(auto bal: balances){
        if(bal.first <100)
            return false;
    }
    return true;
}

int main(){

    vector<pair<int, string>> balances, balances2, balances3;
    vector<pair<pair<string,string>, int>> transfers;
    vector<BankAccount> bankAccounts;
    balances.push_back({180, "b"});
    balances.push_back({80, "a"});
    balances.push_back({50, "c"});
    balances.push_back({230, "d"});
    balances.push_back({10, "e"});
    
    balances2.push_back({10, "a"});
    balances2.push_back({180, "c"});

    balances3.push_back({120, "a1"});
    balances3.push_back({130, "b1"});
    balances3.push_back({160, "c1"});
    bankAccounts.push_back(BankAccount(180, "B"));
    bankAccounts.push_back(BankAccount(80, "A"));
    transfers = determine_transfers(bankAccounts);
    
    cout << "Balances Valid : " << validateBalances(balances2, transfers) << endl;

    for(auto tr: transfers){
        cout << tr.first.first << " " << tr.first.second << " " << tr.second << endl;
    }


    return 0;
  }