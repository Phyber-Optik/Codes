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
        int a, b;
        while(scanf("%d %d", &a, &b)!=EOF){
            int awin=0, draw=0, bwin=0;
            for(int x=1; x<=6; x++){
                if(abs(a-x)<abs(b-x))
                    awin++;
                else if(abs(a-x)==abs(b-x))
                    draw++;
                else if(abs(a-x)>abs(b-x))
                    bwin++;
            }

            printf("%d %d %d\n", awin, draw, bwin);
        }
        return 0;
    }
