
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
#define lim             32000
using namespace std;
double C[22];
double dp[22][101];
int Q[22], n;
bool taken[22][101];

double go(int i, int k){
    if(k <= 0) return 0.0;
    if(i > n) return (double)INF;
    if(taken[i][k] == true) return dp[i][k];

    taken[i][k] = true;
    double ret = 0.0;
    ret = min(C[i] + go(i, k - Q[i]), go(i + 1, k));
    return dp[i][k] = ret;
}

int q[102], cnt;
void in(char a[]){
    int len = strlen(a);
    int temp = 0;
    for(int i = 0; i < len; i++){
        if(a[i] == ' '){
            q[cnt++] = temp;
            temp = 0;
            continue;
        }
        temp = (int)(a[i] - '0') + temp * 10;
    }
    q[cnt++] = temp;
}

int main(){
    //read(in);
    //write(out);
    double p;
    char s[10000];
    int t = 1;
    while(scanf("%lf", &p) == 1){
        scanf("%d", &n);
        Q[0] = 1;
        C[0] = p;
        for(int i = 1; i <= n; i++){
            scanf("%d%lf", &Q[i], &p);
            //cout<<(p*100.0)<<endl;
            C[i] = (p);
        }

        cnt = 0;
        getchar();
        gets(s);
        in(s);
        mem(taken, false);
        printf("Case %d:\n", t++);
        for(int i = 0; i < cnt; i++){
            double ret = go(0, q[i]);
            printf("Buy %d for $%.2lf\n", q[i], ret);
        }
    }
    return 0;
}
