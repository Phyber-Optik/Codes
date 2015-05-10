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
    #define si 10000100

    int prime[1000000];
    bool status[si];

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
        int n;
        while(scanf("%d", &n)!=EOF){
            int flag=0, c, d;
            if(n<8){
                printf("Impossible.\n");
            }

            else{
                if(n%2==0){
                    printf("2 2");
                    n=n-4;
                }

                else{
                    printf("2 3");
                    n=n-5;
                }

                for(int i=1; prime[i]<=n/2; i++){
                    int temp=prime[i];
                    if(status[n-temp]==false){
                        printf(" %d %d\n", temp, n-temp);
                        break;
                    }
                }
            }
        }
        return 0;
    }
