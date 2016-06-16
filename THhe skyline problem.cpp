
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

int H[10010];
int main(){
    //read(in);
    //write(out);
    int x, y, z;
    mem(H, 0);
    int st = 10000, ed = 0;
    while(scanf("%d%d%d", &x, &y, &z) == 3){
        st = min(x, st);
        ed = max(z, ed);
        for(int i = x; i < z; i++){
            H[i] = max(H[i], y);
        }
    }

    printf("%d %d", st, H[st]);
    int pre = H[st];
    FORAB(i, st + 1, ed + 1){
        //cout<<i<<" "<<H[i]<<endl;
        if(pre != H[i]){
            if(H[i] < pre) printf(" %d %d", i, H[i]);
            else printf(" %d %d", i, H[i]);
            pre = H[i];
        }
    }
    printf("\n");
    //printf(" %d %d\n", ed, 0);
    return 0;
}
