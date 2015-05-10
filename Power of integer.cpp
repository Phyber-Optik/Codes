
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

typedef long long unsigned LLU;
using namespace std;

LLU p[100];
int h;

LLU go(LLU a){
    for(int i = 0; i < 64; i++){
        p[i] = 0;
    }

    p[1] = a - 1;
    for(int i = 2; i < 62; i++){
        double x;
        x = powl(a, 1.0/i);
        LLU temp = (LLU)x;
        if(powl(temp, i) > a){
            while(true){
                if(powl(temp, i) <= a){
                    break;
                }
                temp -= 1;
            }
        }
        if(temp < 2){
            h = i - 1;
            break;
        }

        p[i] = (temp - 1) * i;
        //cout<<i<<" "<<p[i]<<endl;
    }

    LLU sum = 0;
    for(int i = h; i >= 2; i--){
        LLU k = p[i] / i;
        FORAB(j, 1, i){
            if(i % j == 0){
                p[j] -= (k * j);
            }
        }
    }

    for(int i = 1; i <= h; i++){
        sum += p[i];
    }

    return sum;
}

int main(){
    //read(in);
    LLU a, b;

    while(scanf("%llu %llu", &a, &b) && (a || b)){
        cout<<go(b) - go(a - 1)<<endl;
    }
    return 0;
}
