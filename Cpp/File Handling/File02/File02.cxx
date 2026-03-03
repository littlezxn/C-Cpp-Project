#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream fout("sample.txt");
    fout<<"Enter whatever you want.";
    fout.close();

    string text;
    ifstream fin("sample.txt");
    getline(fin , text);
    cout<<text<<endl;
    fin.close();
    return 0;
}