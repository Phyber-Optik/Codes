
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
#define MAX             10010
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
#define si              10000
using namespace std;

bool status[MAX];
int primes[MAX], f[MAX][105];

void go(){
    int sq = sqrt(si);
    mem(status, true);

    status[1] = false;
    for(int i = 2; i <= sq; i++){
        if(status[i] == true){
            for(int j = 2 * i; j <= si; j += i){
                status[j] = false;
            }
        }
    }

    FORAB(i, 2, si + 1){
        if(status[i] == true){
            primes[pos++] = i;
        }
    }
}

void process(int n){

}

ll nChoosek( ll n, ll k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    ll result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n -i + 1);
        result /= i;
    }
    return result;
}

int main(){
    //read(in);
    //write(out);
    go();
    int tc, t = 1, n;
    scan(tc);
    while(tc--){
        scan(n);


        FORAB(i, 1, n + 1){
            scan(a[i]);
        }

        bhalo_number = n - kharap_number;
        dbg(bhalo_number);
        ll ans = 0;

        printf("Case %d: %lld\n", t++, ans);
    }
    return 0;
}
