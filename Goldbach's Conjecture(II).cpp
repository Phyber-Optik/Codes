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
    #define si 33800

    bool status[33800];

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
    }

    int main(){
        sieve();
        int n;
        while(scanf("%d", &n) && n){
            int cnt=0;
            for(int i=2; i<=n/2; i++){
                if(status[i]==false && status[n-i]==false){
                    //cout<<status[i]<<" "<<n-i<<endl;
                    cnt++;
                }
            }

            printf("%d\n", cnt);
        }
        return 0;
    }
