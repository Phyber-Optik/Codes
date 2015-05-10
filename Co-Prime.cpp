
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
#define chkwhere        cout<<"LOL\n"

using namespace std;

#define si 31700

int prime[200000];
bool status[si];

void sieve(){
    int i, j;
    for(i = 0; i < si; i++){
        status[i]=false;
    }

    int sq=sqrt(si);

    for(i = 4; i <= si; i += 2){
        status[i]=true;
    }

    for(i = 3; i <= sq; i += 2){
        if(status[i] == false){
            for(j = 2*i; j <= si; j+=i){
                status[j]=true;
            }
        }
    }

    status[1] = true;

    int pos = 1;
    for(int z=1; z <= si; z++){
        if(status[z] == false){
            prime[pos++]=z;
        }
    }
}

vector<int>fact;
vector<ll>d;

vector<int> factorize(int n){
    vector<int>pf;
    pf.clear();
    for(int i = 1; prime[i] <= sqrt(n); i++){
        int p = prime[i];
        if(n % p == 0){
            while(n % p == 0){
                n /= p;
            }
            pf.pb(p);
        }
    }

    if(n > 1){
        //dbg(n);
        pf.push_back(n);
    }
    return pf;
}
void f(vector<int>pf, int i, int n, ll r){
    if(n < 1){
        d.pb(r);
        return;
    }
    if(i >= pf.size()) return;
    f(pf, i + 1, n - 1, r * pf[i]);
    f(pf, i + 1, n, r);
}

ll clc(ll a, ll n){
    vector<int>pf = factorize(n);
    ll ans = a;
    for(int i = 1; i <= pf.size(); i++){
        d.clear();
        f(pf, 0, i, 1);
        ll cnt = 0;
        for(int j = 0; j < d.size(); j++){
            cnt += (a / d[j]);
        }

        if(i & 1){
            ans -= cnt;
        }
        else ans += cnt;
    }

    return ans;
}

int main(){
    //read(in);
    //write(out);
    sieve();
    int tc, t = 1;
    ll a, b, n;
    scan(tc);
    while(tc--){
        scanf("%lld%lld%lld", &a, &b, &n);
        ll ans = clc(b, n) - clc(a - 1, n);
        //ll ans = 0;
        printf("Case #%d: %lld\n", t++, ans);
    }
    return 0;
}
