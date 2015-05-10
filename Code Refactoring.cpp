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

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        int N;
        scanf("%d", &N);
        for(int tc=1; tc<=N; tc++){
            int n;
            scanf("%d", &n);
            int sq=(sqrt(n));
            //cout<<sq<<endl;

            int i=2, j;
            while(i<=sq){
                if(n%i==0){
                    j=n/i;
                    break;
                }

                i++;
            }

            sq=sqrt(j);
            int q;
            int p=2;
            while(p<=sq){
                if(j%p==0){
                    p=p*i;
                    q=n/p;
                    break;
                }

                p++;
            }

            printf("Case #%d: %d = %d * %d = %d * %d\n", tc, n, i, j, p, q);
        }
        return 0;
    }
