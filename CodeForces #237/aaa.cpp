#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
int main(){
    freopen("Lab2.txt", "w", stdout);

    int n=50;
    cout<<50<<endl;
    while(n--){
        int a=rand()%4;
        if(a==0){
            a=4;
        }

        cout<<a<<" ";
        if(a==4){
            int b=rand()%100;
            int c=rand()%100;

            cout<<b<<" "<<c<<endl;
        }

        else{
            cout<<rand()%100<<endl;;
        }
    }
}
