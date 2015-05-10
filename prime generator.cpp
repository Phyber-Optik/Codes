
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

#define si 100000

int prime[100009];
bool status[si];

void sieve(){
    int i, j;
    for(i = 0; i < si; i++){
        status[i]=false;
    }

    int sq=sqrt(si);

    for(i = 4; i <= si; i += 2){
        status[i]=true;
    }

    for(i = 3; i <= sq; i += 2){
        if(status[i] == false){
            for(j = 2*i; j <= si; j+=i){
                status[j]=true;
            }
        }
    }

    status[1] = true;

    int pos = 1;
    for(int z=1; z <= si; z++){
        if(status[z] == false){
            prime[pos++]=z;
        }
    }
}


int main(){
    //read(in);
    //write(out);
    sieve();
    int tc, a, b;
    scan(tc);
    bool nl = false;
    while(tc--){
        scanf("%d%d", &a, &b);
        if(a == 1) a = 2;
        bool f;
        if(nl) printf("\n");
        nl = true;

        for(int i = a; i <= b; i++){
            f = true;
            for(int j = 1; prime[j] <= sqrt(i); j++){
                if(i % prime[j] == 0){
                    f = false;
                    break;
                }
            }
            if(f) print(i);
        }
    }
    return 0;
}
