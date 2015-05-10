
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
#define MAX             10000010

using namespace std;

ll a, primesqr[MAX];
int pos = 1;
bool status[MAX];
void go(){
    for(ll i = 2; i < MAX; i++){
        if(!status[i]){
            for(ll j = i * i; j < MAX; j += i){
                status[j] = true;
            }
            primesqr[pos++] = i * i;
        }
    }
}

ll f(int i, ll r){
    ll ans;
    for(ans = 0; i < pos && (primesqr[i] <= a / r); i++){
        ans += a / (r * primesqr[i]);
        ans -= f(i + 1, r * primesqr[i]);
    }
    return ans;
}
int main(){
    //read(in);
    //write(out);
    go();
    int tc;
    scan(tc);
    while(tc--){
        scanf("%lld", &a);
        ll ans = a - f(1, 1);
        printf("%lld\n", ans);
    }
    return 0;
}
