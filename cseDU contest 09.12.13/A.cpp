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
    #define si 1200

    using namespace std;
    long long a[12000][15];


    int prime[1200];
    bool status[1200];

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
            if(status[i]=false){
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
        int n, k, pos=1;
        mem(a, 0);

        for(int z=prime[pos]; z<20; z=prime[pos]){
            //cout<<z<<endl;
            int c=pos+1, e=1;
            long long s=z;
            a[s][e]++;
            long long q=z;
            for(int y=prime[c]; y<20; y=prime[c]){
                cout<<y<<endl;
                int d=2, p=c+1;
                q+=y;
                a[q][d]++;
                long long sum1=s+y, sum2=s+y;
                for(int x=prime[p]; x<20; x=prime[p]){
                    //cout<<sum<<"d="<<d<<" ";
                    a[sum2+x][3]++;
                    sum2+=x;
                    d++;
                    p++;
                }
                cout<<endl;
                c++;
                //sum=z;
            }

            pos++;
        }
        while(scanf("%d %d", &n, &k) && (n||k)){
            printf("%lld\n", a[n][k]);
        }
        return 0;
    }

