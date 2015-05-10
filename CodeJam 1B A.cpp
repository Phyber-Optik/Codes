
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

using namespace std;

int clc[1000010];
int main(){
    read(in);
    write(out);
    mem(clc, -1);
    FORAB(i, 1, 21){
        clc[i] = i;
    }

    clc[21] = clc[12] + 1;
    int pre = 21;
    FORAB(i, 21, 1000001){
        if(clc[i] != -1) continue;
        string x = SSTR(i);
        reverse(all(x));
        int re = atoi(x.c_str());
        if(i%10 == 0) clc[i] = clc[i-9] + 9;
        else if(i % 10 == 1 && clc[re] == -1){
            //cout<<i<<endl;
            clc[i] = clc[i-10] + 10;
        }
        else if(i % 10 == 1){
            clc[i] = clc[re] + 1;
        }
        else{
            clc[i] = clc[i-(i%10) + 1] + (i%10 - 1);
        }
    }

    ll tc, n, t = 1;
    cin>>tc;
    while(tc--){
        cin>>n;


        printf("Case #%lld: %d\n", t++, clc[n]);
    }
    return 0;
}
