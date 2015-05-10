
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

int num_of_d[1000010];
int main(){
    //read(in);
    //write(out);

    for(int i = 1; i <= 1000000; i++){
        num_of_d[i] = 1;
        num_of_d[i] += !(i & 1);
    }

    int sq = sqrt(1000001);
    FORAB(i, 3, 1000001){
        for(int j = i; j <= 1000000; j += i){
            num_of_d[j] += 1;
        }
    }

    bool f[1000010];
    mem(f, true);
    for(int i = 2; i <= 1000000; i++){
        for(int j = i; j <= 1000010; j += i){
            if(num_of_d[j] > 3){
                if(num_of_d[j] % num_of_d[i] != 0){
                    f[j] = false;
                }
            }
            else f[j] = false;
        }
    }

    int cnt = 0;
    FORAB(i, 3, 1000000){
        if(f[i] == true){
            cnt += 1;
            if(cnt % 108 == 0){
                printf("%d\n", i);
            }
        }
    }

    return 0;
}
