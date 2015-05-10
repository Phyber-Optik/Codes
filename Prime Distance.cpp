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
    #define si 2147483350

    vector<int>prime;
    bool status[214748335];
    int jump[214748335][2];

    void sieve(){
        read(in);
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

        for(int z=1; z<=si; z++){
            if(status[z]==false){
                prime.pb(z);
            }
        }
    }

    int main(){
        //read(in);
        sieve();
        //int jump[214748335][2];
        mem(jump, 0);
        int i;

        jump[0][0]=2;
        jump[0][1]=0;

        for(i=1; i<prime.size(); i++){
            jump[i][0]=prime[i];
            jump[i][1]=prime[i]-prime[i-1];
        }

        //jump[i][0]=prime[i];
        int m, n;

        while(scanf("%d %d", &m, &n)!=EOF){

            int high, low;
            for(int i=0; ; i++){
                if(jump[i][0]>=m){
                    low=i;
                    break;
                }
                //low=i;
            }

            //if(prime[low]==n){
            //    if(prime[low-1]<=m){
            //        low--;
            //    }
            //}

            int ara[120], j, c ,d;
            mem(ara, 0);
            int min=1111, max=0, num=1;
            for(j=low+1; ; j++){
                if(jump[j][0]>n){
                    break;
                }
                num++;
                if(jump[j][1]<min){
                    min=jump[j][1];
                    c=j;
                }

                if(jump[j][1]>max){
                    max=jump[j][1];
                    d=j;
                }
            }


            if(num<2){
                printf("There are no adjacent primes.\n");
            }

            else
                printf("%d,%d are closest, %d,%d are most distant.\n", prime[c-1], prime[c], prime[d-1], prime[d]);
            //cout<<ma<<endl;
        }
        return 0;
    }
