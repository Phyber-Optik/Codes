
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

int main(){
    //read(in);
    //write(out);
    int n;
    string s;
    while(cin>>n){
        vector<int>ans;
        cin>>s;
        int a[27] = {0};
        int cnt = 0;
        for(char i = 'a'; i <= 'z'; i++){
            for(int j = 0; j < s.size(); j++){
                if(s[j] == i && a[(int)i - 'a'] != 0){
                    a[(int)i - 'a'] = j;
                    cnt += 1
                }
            }
        }

        sort(a, a + cnt);
        if(cnt >= n){
            cout<<"YES\n";
            for(int i = 0; i < n; i++){
                for(int j = a[i]; j < s.size(); j++){
                    cout<<s[j];
                }
            }
        }
        else{
            cout<<"NO\n";
        }

        chk.clear();
    }
    return 0;
}
