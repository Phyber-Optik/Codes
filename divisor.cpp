
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

#define si 100

int prime[100], pos = 1;
bool status[si];
bool mul[10000];
int num_of_d[1000010];

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

    mem(mul, false);
    for(int i = 1; i < pos; i++){
        for(int j = i + 1;j < pos; j++){
            mul[prime[i] * prime[j]] = true;
        }
    }

    int cnt = 0;
    FORAB(i, 1, 1000001){
        if(mul[num_of_d[i]] == true){
            cnt += 1;
            if(cnt % 9 == 0){
                printf("%d\n", i);
            }
        }
    }
    //dbg(num_of_d[999927]);

    return 0;
}
