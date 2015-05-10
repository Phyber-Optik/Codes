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

    int p[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
    47, 53, 59, 61, 67, 71, 73,
    79, 83, 89, 97, 101};

    int main(){
        int n, d;
        vector<int>factor;
        vector<int>power;

        while(scanf("%d %d", &n, &d) && (n|d)){
            if(d<0)
                d=-d;
            for(int i=0; p[i]<=n; i++){
                int temp=p[i];
                //cout<<temp<<endl;
                factor.pb(temp);
                int count=0, N=n;
                while(N){
                    count+=N/temp;
                    N=N/temp;
                }
                //cout<<temp<<" "<<count<<endl;
                power.pb(count);
            }

            for(int i=0; i<factor.size(); i++){
                int temp=factor[i];
                if(d%temp==0){
                    while(1){
                        if(d%temp==0){
                            d=d/temp;
                            power[i]--;
                        }
                        else{
                            break;
                        }
                    }
                }
            }

            int flag=1;
            for(int i=0; i<power.size(); i++){
                if(power[i]<0){
                    flag=0;
                    break;
                }
            }
            if(flag==0 || d>1){
                printf("0\n");
            }

            else{
                long long result=1;
                for(int i=0; i<factor.size(); i++){
                    //cout<<factor[i]<<endl;
                    result*=(power[i]+1);
                }
                printf("%lld\n", result);
            }

            factor.clear();
            power.clear();
        }
        return 0;
    }
