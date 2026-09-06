#include<iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sys/stat.h>
#include <ctime>
#include <string>
#include <climits>
#include <mach-o/dyld.h>
using namespace std;
int a[100];
string bbh="00011";
void hx(int a){
    for(int i=0;i<a;i++){
            cout << "—";
    }
}
int main(){
    cout <<"the this is  "<< bbh;
    system("sleep 1");
    cout << "only APPLE can do ";
    for(int i=0;i<30;i++){
        cout << endl;
    }
    hx(30);
    while(1){
        cout << endl;
        for(int i=1;i<150;i++){
            if(a[i]!=0&&rand()%2==1&&a[i-1]==0){
                if(rand()%2==0){
                    cout << 1 ;
                }else{
                    cout << 0 ;
                }
                a[i]=1;
            }else if(a[i]!=0&&rand()%2==1&&a[i-1]==0){
                if(rand()%2==0){
                    cout << 1 ;
                }else{
                    cout << 0 ;
                }
                a[i]=1;
            }else if(rand()%70==1&&a[i-1]==0){
                if(rand()%2==0){
                    cout << 1 ;
                }else{
                    cout << 0 ;
                }
                a[i]=1;
            }else {
                a[i]=0;
                cout << ' ';
            }
        }
        system("sleep 0.2");
    }
}
