    #include<cstdio>
    #include<iostream>
    #include<cstring>
    #include<cmath>
    #include<cstdlib>
    #include<cctype>
    #include<vector>
    #include<queue>
    #include<fstream>
    #include<sstream>
    #include<set>
    #include<climits>
    #include<map>
    #include<algorithm>

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;
    #define si 5000100

    int prime[1000000];
    bool status[5000100];
    int tab[5000100];
    void sieve(){
        int i, j;
        for(i=0; i<si; i++){
            status[i]=false;
        }

        int sq=sqrt(si);

        for(i=4; i<=si; i+=2){
            status[i]=true;
        }

        for(i=3; i<=sq; i+=2){
            if(status[i]==false){
                for(j=2*i; j<=si; j+=i){
                    status[j]=true;
                }
            }
        }

        status[1]=true;

        int pos=1;
        for(int z=1; z<=si; z++){
            if(status[z]==false){
                prime[pos++]=z;
            }
        }
    }


    int main(){
        sieve();
        mem(tab, 1);
        for(int i=2; prime[i]<=si; i++){
            for(int j=prime[i]; ; ){
                for(int k=j; k<=si; k+=j){
                    int temp=tab[i];
                    temp*=(temp-(temp/[prime[i]));
                }
            }
        }
        return 0;
    }
