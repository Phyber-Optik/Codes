
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
#define INF             1000000000
#define eps             1e-9
#define FORN(i, n)      for(int i = 0; i < n; i++)
#define FORAB(i, x, n)  for(int i = x; i < n; i++)
#define FORD(i, x, n)   for(int i= n - 1; i >= x; i--)
#define scan(n)         scanf("%d", &n)
#define print(n)        printf("%d\n", n)
#define tor             vector
#define dbg(x)          cout<<#x<<" : "<<x<<endl
#define chkwhere        cout<<"LOL\n"
#define pii             pair<int, int>
#define ff              first
#define ss              second
#define MAX             1000010
#define MOD             1000000000 + 7
using namespace std;

int f[1000000], a[1000000];
map<int, int>M;
int main(){
    //read(in);
    //write(out);
    mem(f, 0);
    int tmp, cnt = 1;
    while(scanf("%d", &tmp) == 1){
        if(M[tmp] == false){
            a[cnt] = tmp;
            //dbg(cnt);
            M[tmp] = cnt++;
        }
        f[M[tmp]]++;
    }
    map<int, int>::iterator it;
    for(int i = 1; i < cnt; i++){
        printf("%d %d\n", a[i], f[M[a[i]]]);
    }
    return 0;
}
