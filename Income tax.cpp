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

    int main(){
        //read(in);
        long long m, x;
        while(scanf("%lld %lld", &m, &x) && (m|x)){
            if(!x || x==100)
                printf("Not found\n");
            else{
                long long p=((m-1)*100)/(100-x);
                //cout<<p<<endl;
                long long cur;
                int f=0;
                while(1){
                    long long tax=(p*x)/100;
                    //cout<<"tax="<<tax<<endl;
                    cur=p-tax;
                    if(cur<m){
                        f=1;
                        break;
                    }
                    p--;
                }

                printf("%lld\n", p);
            }
        }
        return 0;
    }
