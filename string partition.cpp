
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
string lim, s;
string::size_type sz;
ll dp[201];
int n;
bool t[201];

ll go(int pos){
    if(pos >= n) return 0;
    if(t[pos] == true) return dp[pos];
    t[pos] = true;

    ll ret1 = 0, ret2 = 0;
    for(int i = pos; i < n && (i - pos + 1) <= 10; i++){
        string tmp = s.substr(pos, i - pos + 1);
        ll tmpnum = stoll(tmp, &sz, 0);
        if(tmpnum <= INT_MAX) ret1 = max(ret1, tmpnum + go(i + 1));
    }

    return dp[pos] = ret1;
}
int main(){
    //read(in);
    //write(out);
    lim = SSTR(INT_MAX);
    int tc;
    scan(tc);
    while(tc--){
        cin>>s;
        mem(t, false);
        n = s.size();
        printf("%lld\n", go(0));
    }
    return 0;
}
