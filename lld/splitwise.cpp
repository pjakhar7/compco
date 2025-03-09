#include <bits/stdc++.h>

using namespace std;

static int uidCnt=0;

class User{
    public:
    int uid;
    string name;
    string email;
    string phoneNumber;
    map<int, double> balances;

    User(){
        this->uid = ++uidCnt;
    }

    User(string name){
        this->name = name;
        User();
    }
};

struct Share{
    int uid;
    double amount;

    Share (int uid, double amount){
        this->uid = uid;
        this->amount = amount;
    }
};

class Expense{
    public:
    double amount;
    string title;
    int uidPaid;

    Expense(){}

    Expense(double amount, string title, int uidPaid){
        this->amount = amount;
        this->title = title;
        this->uidPaid = uidPaid;
    }
};

class EqualExpense: public Expense{
    public:
    vector<int> uidOwes;
    EqualExpense(double amount, string title, int uidPaid, vector<int> uidOwes): Expense(amount, title, uidPaid){
        this->uidOwes = uidOwes;
    }
};

class ExactExpense: public Expense{
    public:
    vector<int> uidOwes;
    vector<double> shares;
    ExactExpense(double amount, string title, int uidPaid, vector<int> uidOwes, vector<double> shares): Expense(amount, title, uidPaid){
        this->uidOwes = uidOwes;
        this->shares = shares;
    }
};

class PercentageExpense: public Expense{
    public:
    vector<int> uidOwes;
    vector<double> percentages;

    PercentageExpense(double amount, string title, int uidPaid, vector<int> uidOwes, vector<double> percentages): Expense(amount, title, uidPaid){
        this->uidOwes = uidOwes;
        this->percentages = percentages;
    }
};


class Splitwise{
    Splitwise(){}
    static Splitwise* instance;
    public:
    map<int, User*> users;
    vector<Expense*> expenseLog;

    static Splitwise* getInstance(){
        if(instance==NULL){
            instance = new Splitwise();
        }
        return instance;
    }

    void addUser(User *user){
        users[user->uid] = user;
    }

    void addEqualExpense(string title, int uidPaid, double amount, vector<int> uidOwes){
        int n = uidOwes.size();
        for(auto uid: uidOwes){
            users[uid]->balances[uidPaid] += amount/n;
            users[uidPaid]->balances[uid] += -amount/n;
        }
        Expense *expense = new EqualExpense(amount, title, uidPaid, uidOwes);
        expenseLog.push_back(expense);
    }

    void addExactExpense(string title, int uidPaid, double amount, vector<int> uidOwes, vector<double> shares){
        validateShares(amount, shares);
        for(int i=0; i<uidOwes.size(); i++){
            users[uidOwes[i]]->balances[uidPaid] += shares[i];
            users[uidPaid]->balances[uidOwes[i]] += -shares[i];
        }
        Expense *expense = new ExactExpense(amount, title, uidPaid, uidOwes, shares);
        expenseLog.push_back(expense);
    }

    void addPercentageExpense(string title, int uidPaid, double amount, vector<int> uidOwes, vector<double> percentages){
        validatePercentages(percentages);
        for(int i=0; i<uidOwes.size(); i++){
            users[uidOwes[i]]->balances[uidPaid] += percentages[i]*amount/100;
            users[uidPaid]->balances[uidOwes[i]] += -percentages[i]*amount/100;
        }
        Expense *expense = new PercentageExpense(amount, title, uidPaid, uidOwes, percentages);
        expenseLog.push_back(expense);
    }

    bool validateShares(double &amount, vector<double> &shares){
        double sum=0;
        for(auto s: shares)
            sum += s;
        if(amount!=sum)
            throw invalid_argument("Shares are not valid");
        return true;
    }

    bool validatePercentages(vector<double> &percentages){
        double sum=0;
        for(auto s: percentages)
            sum += s;
        if(100.00!=sum)
            throw invalid_argument("Percentages are not valid");
        return true;
    }

    void showBalances(int uid){
        for(auto b: users[uid]->balances){
            if(b.second>0){
                cout << "User" << uid << " owes User" << b.first << " " << b.second << endl;
            }
            if(b.second<0){
                cout << "User" << b.first << " owes User" << uid << " " << (-1*b.second) << endl;
            }
        }
        cout << endl;
    }

    void showExpenseLogs(){
        for(auto e: expenseLog)
            cout << e->title << " " << e->amount << endl;
    }
};

Splitwise* Splitwise::instance = NULL;

int main(){

    Splitwise *app = Splitwise::getInstance();
    User *user1 = new User();
    User *user2 = new User();
    User *user3 = new User();
    User *user4 = new User();
    app->addUser(user1);
    app->addUser(user2);
    app->addUser(user3);
    app->addUser(user4);
    int u1=user1->uid, u2=user2->uid, u3=user3->uid, u4=user4->uid;
    app->addEqualExpense("Electricity Bill", u1, 1000.00, {u1, u2, u3});
    app->showBalances(u1);
    app->addExactExpense("BBD Sale", u1, 1250.00, {u2, u3}, {370, 880});
    app->showBalances(u1);
    app->addPercentageExpense("Movie", u4, 1200.00, {u1, u2, u3, u4}, {40, 20, 20, 20} );
    app->showBalances(u1);
    app->showExpenseLogs();
    return 0;
}