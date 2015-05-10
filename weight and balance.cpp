
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
#define pii             pair<int, int>

using namespace std;

vector<int>G[5610];
int dp[5610];

int go( int u ){
    if(G[u].size() == 0) return 0;
    if(dp[u] != -1) return dp[u];

    int ret = 0;
    for(int i = 0; i < G[u].size(); i++){
        ret = max(ret, 1 + go(G[u][i]));
    }

    return dp[u] = ret;
}

int main(){
    //read(in);
    //write(out);
    int w[5610][2];
    int cnt = 1;
    while(scanf("%d%d", &w[cnt][0], &w[cnt][1]) == 2){
        cnt++;
    }

    FORAB(i, 1, cnt){
        FORAB(j, i + 1, cnt){
            if(w[i][1] >= w[i][0] + w[j][0]){
                G[i].pb(j);
            }
        }
    }

    mem(dp, -1);
    int r = go(1);
    print(r);

    return 0;
}
