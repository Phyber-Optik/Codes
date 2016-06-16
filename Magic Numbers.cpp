
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
#define MAX             9876543210
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

bool chk(ll n){
    bool f[10] = {false};
    while(n){
        int digit = n % 10;
        if(f[digit] == true) return false;
        f[digit] = true;
        n /= 10;
    }
    return true;
}

int main(){
    //read(in);
    int tc, t = 0;
    ll n;
    scan(tc);
    while(tc--){
        scanf("%lld", &n);
        for(ll i = 1; i * n <= MAX; i++){
            if(chk(i) == false) continue;
            ll nn = i * n;
            bool f = chk(nn);
            if(f) printf("%lld / %lld = %lld\n", nn, i, n);
        }
        if(tc) putchar('\n');
    }
    return 0;
}
