#include "Include/header.h" //Include header file for necessary libraries
struct Data
{
    int age;
    std::string name;
    int accnumber;
    int pin;
    int amount;
};


class user_info1
{
public:
    struct Data *d1;
    user_info1() {
        d1 = new Data;
    }
    void Account(){
        std::cout<<"Enter your account number: ";
        std::cin>>d1->accnumber;
    }
    void Pin(){
        std::cout<<"Enter your pin: ";
        std::cin>>d1->pin;
    }
    ~user_info1() {
        delete d1;
    }
};

void user_info(){
    struct Data *d;
    d = new Data;
    std::cout<<"Enter Your name: ";
    std::cin>>d->name;
    std::cout<<"Enter your age: ";
    std::cin>>d->age;
    if (d->age < 18)
    {
        std::cout<<"You're Underage";
    }
    else
    {
        user_info1 user1;
        user1.Account();
    }
    delete d;
}
void total(){
    struct Data *d2;
    d2 = new Data;
    d2->amount = 30000;
    std::cout<<"You have Total "<<d2->amount<<" in your account.";
}

int main(){
    user_info();
    user_info1 u;
    u.Pin();
    total();
    u.d1;
}