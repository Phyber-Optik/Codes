
/*  Towhidul Islam
    University Of Dhaka
    Problem Name :
    Algorithm Used :
*/

#include<bits/stdc++.h>

typedef long long ll;

#define SSTR(x)         dynamic_cast< ostringstream & >( \
                        (ostringstream() << dec << x )).str()
#define pb              push_back
#define mem(a, x)       memset(a, x, sizeof a)
#define PI              acos(-1)
#define all(a)          a.begin(), a.end()
#define MAX             100010
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             10000000
#define eps             1e-9
#define arraysz(a)      sizeof (a)/sizeof(a[0])
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>

using namespace std;
int R, C, G[101][101], dp[101][101][2], chk[101][101];

int go(int i, int j, bool out){
    if(out == false) {
        if(i == R && j == C) return 0;
    }

    if(dp[i][j][out] != -1) return dp[i][j][out];

    int ret = 0, ret1 = 0, ret2 = 0;
    if(out == true){
        ret1 = 0, ret2 = 0;
        if(i + 1 <= R && chk[i+1][j] == false){
            if(i + 1 == R && j == C) out = false;
            chk[i+1][j] = true;
            ret1 = G[i+1][j] + go(i + 1, j, out);
        }
        if(j + 1 <= C && chk[i][j+1] == false){
            if(i == R && j + 1 == C) out = false;
            chk[i][j+1] = true;
            ret2 = G[i][j+1] + go(i, j + 1, out);
        }

        ret += max(ret1, ret2);
    }

    /*else{
        ret1 = 0, ret2 = 0;
        if(i - 1 >= 1 && chk[i-1][j] == false){
            chk[i-1][j] = true;
            ret1 = G[i-1][j] + go(i - 1, j, out);
        }
        if(j - 1 >= 1 && chk[i][j-1] == false){
            chk[i][j-1] = true;
            ret2 = G[i][j-1] + go(i, j - 1, out);
        }

        ret += max(ret1, ret2);
    }*/

    dbg(ret);
    return dp[i][j][out] = ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1;
    scan(tc);
    while(tc--){
        scanf("%d%d", &R, &C);
        FORAB(i, 1, R + 1){
            FORAB(j, 1, C + 1){
                scan(G[i][j]);
            }
        }

        mem(dp, -1);
        mem(chk, false);
        int ans = go(1, 1, true);
        printf("Case %d: %d\n", t++, ans);
    }
    return 0;
}
