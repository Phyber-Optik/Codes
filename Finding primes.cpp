
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
#define MAX             10000010
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
#define si              10000000
using namespace std;
bool status[MAX];
int cnt[MAX];

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

    cnt[2] = 1;
    FORAB(i, 3, si + 1){
        if(status[i] == 1){
            cnt[i] = cnt[i-1] + 1;
        }
        else cnt[i] = cnt[i - 1];
    }
}
int main(){
    //read(in);
    //write(out);
    go();
    int tc, a;
    scan(tc);
    while(tc--){
        scan(a);
        print(cnt[a] - cnt[a/2]);
        //print(cnt_prime[a] - prime_fact_cnt[a] - 1);
    }
    return 0;
}
