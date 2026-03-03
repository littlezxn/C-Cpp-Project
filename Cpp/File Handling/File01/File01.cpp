#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream fout("sample.txt");
    fout<<"Hello World";
    fout.close();
    return 0;
}