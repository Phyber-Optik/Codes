
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
vector<string>one, ten, zzz;
int main(){
    //read(in);
    //write(out);
    int n;
    one.pb("one");
    one.pb("two");
    one.pb("three");
    one.pb("four");
    one.pb("five");
    one.pb("six");
    one.pb("seven");
    one.pb("eight");
    one.pb("nine");
    one.pb("ten");

    ten.pb("eleven");
    ten.pb("twelve");
    ten.pb("thirteen");
    ten.pb("fourteen");
    ten.pb("fifteen");
    ten.pb("sixteen");
    ten.pb("seventeen");
    ten.pb("eighteen");
    ten.pb("nineteen");

    zzz.pb("twenty");
    zzz.pb("thirty");
    zzz.pb("forty");
    zzz.pb("fifty");
    zzz.pb("sixty");
    zzz.pb("seventy");
    zzz.pb("eighty");
    zzz.pb("ninety");
    while(cin>>n){
        if(n == 0){
            cout<<"zero\n";
        }
        else if(n <= 10){
            cout<<one[n-1]<<endl;
        }
        else if(n > 10 && n < 20){
            cout<<ten[n % 10 - 1]<<endl;
        }

        else{
            cout<<zzz[n/10-2];
            if(n % 10)cout<<"-"<<one[n % 10 - 1]<<endl;
            else cout<<endl;
        }
    }
    return 0;
}
