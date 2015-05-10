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
        read(in);
        int N, i, j;
        scanf("%d", &N);
        getchar();
        int tc=0;
        while(N--){
            if(tc)
                printf("\n");
            tc++;

            char ch, com;
            int team, prob, time;
            while(scanf("%d %d %d", &team, &prob, &time) && getchar(com)){
                ch=getchar();
                if(ch=='\n')
                {
                    cout<<1<<endl;
                    break;
                }
            }
        }
        return 0;
    }
