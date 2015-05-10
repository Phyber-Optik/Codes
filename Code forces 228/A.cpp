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

    int getGCD(int x, int y)
    {
        while(x!=y)
        {
            if(x>y)x=x-y;
            else y=y-x;
        }
        return(x);
    }

    int main(){
        int N;
        while(scanf("%d", &N)!=EOF){
            int a[N];

            scanf("%d", &a[0]);
            int GCD=a[0];
            for(int i=1; i<N; i++){
                scanf("%d", &a[i]);
                //cout<<GCD<<endl;
                GCD=getGCD(GCD, a[i]);
                //cout<<GCD<<endl;
            }

            printf("%d\n", GCD*N);
        }
        return 0;
    }
