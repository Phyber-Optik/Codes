
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

int number_factor[MAX], prime[MAX], ans[MAX], freq[MAX][1328];
bool st[MAX];

void clc(){
    for(int i = 1; i < MAX; i++){
        number_factor[i] = 1;
    }
    int r = 0;
    for(int i = 1; i <= 100000; i++){
        int temp = i;
        for(int j = 1; prime[j] <= sqrt(temp); j++){
            int cnt = 0;
            if(temp % prime[j] == 0){
                while(temp % prime[j] == 0){
                    cnt += 1;
                    temp /= prime[j];
                }
            }
            number_factor[i] *= (2 * cnt + 1);
        }
        if(temp > 1){
            number_factor[i] *= 3;
        }
        r = max(r, number_factor[i]);
    }

    mem(freq, 0);
    for(int i = 1; i <= 100000; i++){
        freq[i][number_factor[i]]++;
    }
    FORAB(i, 2, 100001){
        for(int j = 1; j <= 1323; j += 2){
            freq[i][j] = freq[i][j] + freq[i-1][j];
        }
    }
}

void f(){
    mem(st, true);
    st[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++){
        if(st[i] == true){
            for(int j = i * 2; j < MAX; j += i){
                st[j] = false;
            }
        }
    }

    int pos = 1;
    for(int i = 2; i < MAX; i++){
        if(st[i] == true){
            prime[pos++] = i;
        }
    }
}

int main(){
    //read(in);
    //write(out);
    f();
    clc();
    //return 0;
    int tc;
    ll a, b, k;
    scan(tc);
    while(tc--){
        scanf("%lld %lld %lld", &k, &a, &b);
        if(k > 1323) print(0);
        else{
            if(a == 0) a = 1;
            a -= 1;
            printf("%d\n", freq[(int)sqrt(b)][k] - freq[(int)sqrt(a)][k]);
        }
    }
    return 0;
}
