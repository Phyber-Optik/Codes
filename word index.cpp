
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

map<string, int>M;
int cnt = 0;
void go(int pos, char pre, string s){
    if(pos == 5){
        if(M[s] == false) M[s] = cnt++;
        return;
    }

    go(pos + 1, pre, s);
    for(char x = pre + 1; x <= 'z'; x++){
        string tmp = s;
        tmp.pb(x);
        go(pos + 1, x, tmp);
    }
}

int main(){
    //read(in);
    //write(out);
    go(0, (char)96, "");
    char a[6];
    while(gets(a)){
        if(M[a]){
            print(M[a]);
        }
        else print(0);
    }
    return 0;
}
