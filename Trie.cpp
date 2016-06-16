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
#define ff              first
#define ss              second
#define read(in)        freopen("in.txt", "r", stdin)
#define write(out)      freopen("out.txt", "w", stdout)
#define INF             1<<30
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
#define MOD             1000000007
#define MAX             100007

using namespace std;
typedef struct data{
    bool e;             // endmark
    data *next[27];     // pointer to next node, false if this is the last ndoe
    data(){
        e = false;
        FORAB(i, 0, 26) next[i] = NULL;
    }
}node;

node *root;

void insert(char *str, int len){
    node *cur = root;
    FORAB(i, 0, len){
        int id = str[i] - 'a';
        if(cur->next[id] == NULL){
            cur->next[id] = new node();
        }
        cur = cur->next[id];
    }
    cur->e = true;
}

bool search(char *str, int len){
    node *cur = root;
    FORAB(i, 0, len){
        int id = str[i] - 'a';
        if(cur->next[id] == NULL){
            return false;           // doesn't match the character in position i of str
        }
        cur = cur->next[id];
    }

    return cur->e;
}

void del(node *cur){
    FORAB(i, 0, 26){
        if(cur->next[i]){
            del(cur->next[i]);
        }
    }
    delete(cur);
}

int main(){
    //read(in);
    //write(out);
	int tc, cs = 1;
	char str[51];
    scan(tc);
	while(tc--){

		printf("Case %d: \n", cs++);
	}
    return 0;
}
