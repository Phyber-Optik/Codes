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
    #define si 1200

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
        //sieve();
        int n, b;
        while(scanf("%d %d", &n, &b)!=EOF){
            int j=b;
            int r=n;
            for(int i=2; i<=j; i++){
                if(j%i==0){
                    int count=0;
                    while(j){
                        if(j%i==0){
                            count++;
                            j=j/i;
                        }

                        else{
                            break;
                        }
                    }

                    int c=0;
                    int f=n;
                    while(f){
                        c+=f/i;
                        f=f/i;
                    }

                    r=min(r, c/count);
                }
            }

            double ans=0;
            for(int i=1; i<=n; i++){
                ans+=log(i);
            }

            ans/=log(b);
            ans+=1.0;
            ans=floor(ans);
            printf("%d %d\n", r, (int)ans);
        }
        return 0;
    }
