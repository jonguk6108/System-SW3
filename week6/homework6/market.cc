#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Market{
    public:
        Market(string name_, int num_, int price_, int margin_);
        void change(int num_, int price_, int margin_);
        string return_name();
        int return_sellprice();
        int return_num();
        void sell(int num_);

    private:
        string name;
        int num;
        int price;
        int margin;
};

int main(){
    string oper;
    string name;
    int num, price, margin, balance, money;
    int first = 0, i;

    cin >> balance;
    money = balance;
    vector<Market> markets;

    while(1) {
        cin >> oper;
        if(oper == "exit") {
            if(first != 0) cout << " ";
            first = 1;
            cout << balance - money;
            break;
        }
        if(oper == "buy") {
            cin >> name >> num >> price >> margin;
            if(balance < num*price) {
                if(first != 0) cout << " ";
                first = 1;
                cout << "can't buy";
                continue;
            }
            for(i = 0; i < markets.size(); i++)
                if(markets[i].return_name() == name)
                    break;
            balance = balance - num * price;
            if(i == markets.size()) {
                Market market(name, num, price, margin);
                markets.push_back(market);
            }
            else
                markets[i].change(num, price, margin);
        }
        else if(oper == "balance") {
            if(first != 0) cout << " ";
            first = 1;
            cout << balance;
        }
        else if(oper == "sell") {
            cin >> name >> num;
            for(i = 0; i < markets.size(); i++)
                if(markets[i].return_name() == name)
                    break;
            if(i == markets.size()) {
                if(first != 0) cout << " ";
                first = 1;
                cout << "not exist";
                continue;
            }
            if(markets[i].return_num() < num) {
                if(first != 0) cout << " ";
                first = 1;
                cout << "can't sell";
                continue;
            }
            balance = balance + num * markets[i].return_sellprice();
            markets[i].sell(num);
        }
        else if(oper == "check") {
            cin >> name;
            for(i = 0; i < markets.size(); i++)
                if(markets[i].return_name() == name)
                    break;
            if(i == markets.size() ) {
                if(first != 0) cout << " ";
                first = 1;
                cout << "not exist";
                continue;
            }
            if(markets[i].return_num() <= 0) {
                if(first != 0) cout << " ";
                first = 1;
                cout << "not exist";
                continue;
            }
            if(first != 0) cout << " ";
            first = 1;
            cout << markets[i].return_num() << " " << markets[i].return_sellprice();
        }
    }
}

Market::Market(string name_, int num_, int price_, int margin_) {
    name = name_;
    num = num_;
    price = price_;
    margin = margin_;
}
void Market::change(int num_, int price_, int margin_) {num += num_; price = price_; margin = margin_;}
string Market::return_name() { return name; }
int Market::return_sellprice() { return price + margin; }
int Market::return_num() { return num; }
void Market::sell(int num_) { num = num - num_; }
