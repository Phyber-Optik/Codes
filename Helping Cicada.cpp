
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
int a[20], m;
ll n;
vector<ll>fact;

ll GCD(ll u, ll v) {
    while ( v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}

void f(int i, int k, ll r){
    if(k < 1){
        fact.pb(r);
        return;
    }
    if(i > m){
        return;
    }

    f(i + 1, k - 1, r * a[i] / GCD(r, a[i]));
    f(i + 1, k, r);
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1;
    scan(tc);

    while(tc--){
        scanf("%lld %d", &n, &m);
        FORAB(i, 1, m + 1){
            scan(a[i]);
        }

        ll ans = n;
        for(int i = 1; i <= m; i++){
            fact.clear();
            f(1, i, 1);
            ll cnt = 0;

            FORAB(j, 0, fact.size()){
                cnt += (n / fact[j]);
            }

            if(i&1){
                ans -= cnt;
            }
            else ans += cnt;
        }
        printf("Case %d: %lld\n", t++, ans);
    }
    return 0;
}
