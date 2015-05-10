
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
#define INF             1000000000
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

int d[17][17], dp[1<<16][16], cnt;

int Set(int N, int pos) { return N = N | (1 << pos); }
int reSet(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }

struct point{
    int x, y;
    point(){

    }

    point(int a, int b){
        x = a;
        y = b;
    }
}p[17];

int dis(point a, point b){
    //int sqr = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    int x = abs(a.x - b.x);
    int y = abs(a.y - b.y);

    if(x < y) swap(x, y);

    return y + (x - y);
}

int go(int mask, int cur){
    if(mask == (1 << (cnt + 1)) - 1) {
        return d[cur][0];
    }
    if(dp[mask][cur] != -1) return dp[mask][cur];

    int ret = INF;
    for(int i = 1; i <= cnt; i++){
        if(check(mask, i) == false){
            ret = min(ret, d[cur][i] + go(Set(mask, i), i));
        }
    }

    return dp[mask][cur] = ret;
}

int main(){
    //read(in);
    //write(out);
    int R, C, tc, t = 1;
    char ch[21];
    scan(tc);
    while(tc--){
        scanf("%d%d", &R, &C);

        cnt = 0;
        FORAB(i, 0, R){
            scanf("%s", ch);
            FORAB(j, 0, strlen(ch)){
                if(ch[j] == 'x') p[0] = point(i, j);
                else if(ch[j] == 'g') p[++cnt] = point(i, j);
            }
        }

        FORAB(i, 0, cnt){
            FORAB(j, i + 1, cnt + 1){
                d[i][j] = d[j][i] = dis(p[i], p[j]);
            }
        }

//        FORAB(i, 0, cnt + 1){
//            FORAB(j, 0, cnt + 1){
//                cout<<d[i][j]<<" ";
//            }
//            cout<<endl;
//        }

        mem(dp, -1);
        int ans = go(1, 0);
        printf("Case %d: %d\n", t++, ans);
    }

    return 0;
}
