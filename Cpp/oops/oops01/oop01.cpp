#include<iostream> //headerfile for input or output.
using namespace std;
class Data 
{
public:
    int age;
    string name;

    void Bark(){
        cout<<name<<" Bark "<<endl;
    }
};
int main(){
    Data d;
    d.name = "lie";
    d.Bark();
    return 0;
}
//end of the program,
//the output will be ,
/*
lie Bark
 */