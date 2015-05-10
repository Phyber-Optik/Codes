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

        #define si 5010

    int prime[5000];
    bool status[5010];

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
        read(in);
        int N;
        scanf("%d", &N);
        for(int tc=1; tc<=N; tc++){
            sieve();
            int m, n;
            scanf("%d %d", &m, &n);
            int result=100000, flag=1;

            //cout<<prime[1]<<endl;
            for(int i=1; prime[i]<=m; i++){
                int temp=prime[i], num=n;
                int count;
                if(m%temp==0){
                    //cout<<temp<<endl;
                    int c1=0;
                    while(m){
                        if(m%temp==0)
                            c1++;
                        else{
                            break;
                        }
                        m=m/temp;
                    }
                    //cout<<temp<<" "<<"time="<<c1<<endl;
                    count=0;
                    while(num){
                        count+=num/temp;
                        num/=temp;
                    }

                    //cout<<"count="<<count<<endl;

                    if(count<c1){
                        flag=0;
                        break;
                    }

                    else
                        count=count/c1;

                    result=min(result, count);
                }
            }

            if(flag){
                printf("Case %d:\n%d\n", tc, result);
            }

            else{
                printf("Case %d:\nImpossible to divide\n", tc);
            }
        }

        return 0;
    }
