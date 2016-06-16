
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
#define lim             32000
using namespace std;
char txt[1000100], pat[1000100];
int M, N, pi, F[1000100];

void go(){
    M = strlen(txt);
    FORAB(i, 0, M){
        pat[i] = txt[M - i - 1];
    }

    int i = 1, j = 0;
    F[0] = 0;

    while(i < M){
        if(pat[i] == pat[j]){
            F[i++] = ++j;
        }
        else{
            if(j != 0) j = F[j-1];
            else F[i++] = 0;
        }
    }
}

int KMP(){
    int i = 0, j = 0;
    while(i < M){
        if(pat[j] == txt[i]){
            i++, j++;
        }
        else{
            if(j != 0) j = F[j-1];
            else i++;
        }
    }

    return j;
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1;
    scan(tc);
    getchar();
    while(tc--){
        scanf("%s", txt);
        pi = strlen(txt) - 1;
        go();
        int p = KMP();

        printf("Case %d: %d\n", t++, 2 * M - p);
    }
    return 0;
}
