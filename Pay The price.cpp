
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
ll dp[301][301];

int Idx, Sum, L1, L2;
ll toInt(string s){
    ll r = 0 ;
    istringstream sin(s); sin>>r;
    return r;
}

vector<string>Split(string s ){
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}
char Str[100];

void Init(){
    vector<string>ret = Split(Str);
    Idx = ret.size() ;
    if( Idx == 1 ){
        Sum = toInt( ret[0] );
    }
    else if( Idx == 2 ){
         Sum = toInt( ret[0] );
         L1  = toInt( ret[1] );

    } else {
         Sum = toInt( ret[0] );
         L1  = toInt( ret[1] );
         L2  = toInt( ret[2] );
    }
}

ll go(int made, int i){
    if(made == 0) return 1;
    if(made < 0 || i < 1) return 0;
    if(dp[made][i] != -1) return dp[made][i];

    ll ret = 0;
    ret = go(made - i, i) + go(made, i - 1);
    return dp[made][i] = ret;
}

int main(){
    //read(in);
    mem(dp, -1);
    while( gets(Str) ){
        Init();
        //dbg(Sum);
        if( Idx == 1 ) printf("%lld\n", go(Sum, Sum));
        else if( Idx == 2 ){
            L1 = min(L1,300);
            printf("%lld\n", go(Sum, L1));
        }
        else {
            L1 = min(L1,300);
            L2 = min(L2,300);
            if(L1 == 0) printf("%lld\n", go(Sum, L2));
            else printf("%lld\n",go(Sum, L2) - go(Sum, L1-1));
        }
    }
}
