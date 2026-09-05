#include<iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;// /Users/macmini/Desktop/table/xcode-c++/A/A/main.cpp
string bbh="00011";
void mian();
int main(){
    cout << bbh;
    for(int i=0;i<10;i++)cout << endl << endl << endl;
    mian();
}
void fgf(int a,int b){
    for(int i=0;i<a;i++){
        if(b==1)
        cout << '-';
        if(b==0)
        cout <<"_";
    }
}
void mian(){
    cout <<"源码地址：https://github.com/edulcni/edulcni"<<endl;
    fgf(30,0);
    cout  <<endl<< "=        '课堂积分系统'        ="<<endl<<'|';
    fgf(28,1);cout << '|';
    cout <<endl<< '|'<<"   A.++  |  B.--  |  c.==   "<<'|'<<endl;
    cout <<'|';fgf(28,1);cout << '|';
    cout << endl << "|   please cin A,B or C; "<<"    |"<<endl;
    fgf(30,1);cout << endl;
    cout <<"-请不要修改任何数据，建议小写字母使用-"<<endl;
    for(int i=0;i<17;i++){
        cout << endl;
    }
    fgf(10,0);cout << endl;
    cout <<"cin to//";
    char abc;
    cin >> abc;
    if(abc!='A'&&abc!='b'&&abc!='C'&&abc!='a'&&abc!='b'&&abc!='c'){
        cout << "|输入不合法,将会重定向|";
        return mian();
    }
}
