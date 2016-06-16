
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
int F[1000100], M, N, cnt;

void go(){
    int len = 0, i = 1;
    F[0] = 0;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            F[i++] = len;
        }
        else{
            if(len) len = F[len - 1];
            else F[i++] = 0;
        }
    }
}

void KMP(){
    M = strlen(pat);
    N = strlen(txt);
    go();
    int i = 0, j = 0;
    while(i < N){
        if(pat[j] == txt[i]){
            i++, j++;
        }
        if(j == M){
            cnt++;
            j = F[j-1];
        }
        else if(i < N && pat[j] != txt[i]){
            if(j != 0) j = F[j-1];
            else i++;
        }
    }
}

int main(){
    //read(in);
    //write(out);
    int tc, t = 1;
    scan(tc);
    getchar();
    while(tc--){
        scanf("%s %s", txt, pat);
        cnt = 0;
        KMP();
        printf("Case %d: %d\n", t++, cnt);
    }
    return 0;
}
