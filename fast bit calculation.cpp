
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
string s;
ll dp[32][2][2];
int sz;
string to_binary(int n){
    s.clear();
    while(n){
        s.pb(n % 2 + '0');
        n /= 2;
    }

    return s;
}

ll calc(int indi, int state) {
    ll total=0;
    if (state == 1) {
        total = 1 << (indi);
    }
    else {
        for(int i = 0; i < indi; ++i) {
            if (s[i] == '1') {
                total += (1<<(i));
            }
        }
        total += 1;
    }
    return total;
}

ll go(int id, bool pre, bool impre){
    if(id < 0) return 0;
    if(dp[id][pre][impre] != -1) return dp[id][pre][impre];
    ll &ret = dp[id][pre][impre];

    ret = 0LL;
    int pos = s[id] - '0';
    if(pre == 1) pos = 1;
    for(int i = 0; i <= pos; i++){
        if(i == 0){
            ret += go(id - 1, pre | i < pos, 0);
        }
        else{
            ll a = (impre == 1 ? calc(id, pre | i < pos) : 0) + go(id - 1, pre | i < pos, 1);
            ret += a;
        }
    }

    return ret;
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1, n;
    scan(tc);
    while(tc--){
        scan(n);
        string s = to_binary(n);
        //dbg(s);
        sz = s.size();
        mem(dp, -1);
        ll ans = go(sz - 1, 0, 0);
        printf("Case %d: %lld\n", t++, ans);
    }
    return 0;
}
