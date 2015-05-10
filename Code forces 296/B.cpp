
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
    string a, b;
    map<char, char>non;
    vector< pair<char, int> >G[150];
    int pos[150], q;

    while(cin>>q){
        cin>>a>>b;
        int cnt = 0;
        int p1 = -1, p2 = -1;
        bool flag = false, f = false;


        FORAB(i, 0, a.size()){
            if(a[i] != b[i]){
                cnt += 1;

                if(G[(int)a[i]].size() > 0 && flag == false){
                    //cout<<"poop\n";
                    FORAB(j, 0, G[(int)a[i]].size()){
                        if(G[(int)a[i]][j].first == b[i]){
                            cnt -= 1;
                            flag = true;
                            p2 = i;
                            p1 = G[(int)a[i]][j].second;
                            break;
                        }
                    }

                    f = true;
                    if(flag == false){
                        p2 = i;
                        p1 = G[(int)a[i]][0].second;
                    }
                }

                else{
                    G[(int)b[i]].pb(make_pair(a[i], i));
                }
            }
        }

        if(flag || f){
            cout<<cnt - 1<<endl;
            cout<<p1 + 1<<" "<<p2 + 1<<endl;
        }

        else{
            cout<<cnt<<endl;
            cout<<"-1 -1"<<endl;
        }

        FORAB(i, 1, 150){
            G[i].clear();
        }
    }
    return 0;
}
