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
    #define si 1000100

    vector<int>prime;
    bool status[1000100];

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

        for(int z=1; z<=si; z++){
            if(status[z]==false){
                prime.pb(z);
            }
        }
    }

    int main(){
        //read(in);
        sieve();
        int jump[80000][2];
        mem(jump, 0);
        int i;

        jump[0][0]=2;
        jump[0][1]=0;

        for(i=1; i<prime.size(); i++){
            jump[i][0]=prime[i];
            jump[i][1]=prime[i]-prime[i-1];
        }

        //jump[i][0]=prime[i];

        int N;
        scanf("%d", &N);
        while(N--){
            int m, n;
            scanf("%d %d", &m, &n);

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

            int ara[120], j;
            mem(ara, 0);
            for(j=low+1; ; j++){
                //cout<<jump[j][1]<<endl;
                //cout<<prime[j]<<" "<<jump[j][0]<<endl;
                if(jump[j][0]>n){
                    break;
                }

                ara[jump[j][1]]++;
            }

            //cout<<"lower="<<prime[low]<<" "<<prime[j]<<endl;
            int index, sum=0, ma=0;
            for(int i=0; i<120; i++){
                //cout<<i<<" "<<ara[i]<<endl;
                sum+=ara[i];
                if(ara[i]>ma){
                    index=i;
                    ma=ara[i];
                }
            }

            //cout<<"sum="<<sum<<endl;

            int cnt=0;
            for(int i=0; i<120; i++){
                if(ma==ara[i]){
                    cnt++;
                }

                if(cnt>1){
                    break;
                }
            }

            if(sum<1 || cnt>1){
                printf("No jumping champion\n");
            }

            else
                printf("The jumping champion is %d\n", index);
            //cout<<ma<<endl;
        }
        return 0;
    }
