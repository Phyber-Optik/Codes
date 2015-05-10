
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

int main(){
    //read(in);
    //write(out);
    int n;
    double temp;
    int a[1010];
    while(scan(n) && n){
        ll sum = 0;
        FORAB(i, 1, n + 1){
            scanf("%lf", &temp);
            temp = round(temp * 100);
            a[i] = temp;
            sum += a[i];
        }

        int ag = sum / n;
        double ans1 = 0, ans2 = 0;
        FORAB(i, 1, n + 1){
            if(a[i] < ag){
                ans1 += (a[i]);
            }
            else ans2 += (a[i]);
        }

        printf("$%.2lf %.2lf\n", ans1 / 100.0,ans2 / 100.0);
    }
    return 0;
}
