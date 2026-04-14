#include <iostream> //header file for input and output
using namespace std;
struct Data
{
    string name;
    int amount;
    float num;
};

class userdata // Taking data from the user
{
public:
    void user_data()
    {
        Data u, u1;
        cout << "Enter your name: ";
        cin >> u.name;
        cout << "Enter your father name: ";
        cin >> u1.name;
    }
};
class Accountdetails // account details of user (Fake)
{
public:
    void midprocess()
    {
        Data p;
        cout << "Enter Your account number: ";
        cin >> p.amount;
    }
};

class credentials // class for credentials (temp credential)
{
public:
    void pass()
    {
        Data c;
        cout << "Enter Your Pin: ";
        cin >> c.amount;
    }
};
class AmountExisted : public Accountdetails, public credentials, public userdata // for better workflow we add everthing in this class
{
private:
    float amountbalance;

public:
    AmountExisted(float accamount)
    {
        amountbalance = accamount;
    }
    void amountinwallet()
    {
        Data acc;
        cout << "account balance checker: \n";
        user_data();
        midprocess();
        pass();
        cout << "you have " << amountbalance << " in your account." << endl;
    }
};

class final : public AmountExisted // final class so that we can understand everything easily
{
public:
    final(float amountinacc) : AmountExisted(amountinacc) {}
    void output()
    {
        amountinwallet();
    }
};
int main() // main fuction
{
    final a(30000.03); // it will give the class amountExisted a temporary amount
    a.output(); // output of final fuction
    return 0;
}
// END of the program
// output
/*
account balance checker: Enter your name: KKKK
Enter your father name: KKKKK
Enter Your account number: 1481515
Enter Your Pin: 001100
you have 30000 in your account.
*/