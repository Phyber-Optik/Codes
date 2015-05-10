    #include<cstdio>
    #include<iostream>
    #include<cstring>
    #include<cmath>
    #include<cstdlib>
    #include<cctype>
    #include<vector>
    #include<queue>
    #include<fstream>
    #include<sstream>
    #include<set>
    #include<climits>
    #include<map>
    #include<algorithm>

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;

    int main(){
        //read(in);
        vector<int>adjlist[21];
        int e;
        int tc=1;
        while(scanf("%d", &e)!=EOF){
            int n=e, a, b;
            while(e--){
                scanf("%d", &a);
                adjlist[1].pb(a);
                adjlist[a].pb(1);
            }

            for(int i=2; i<=19; i++){
                scanf("%d", &e);
                while(e--){
                    scanf("%d", &a);
                    adjlist[i].pb(a);
                    adjlist[a].pb(i);
                }
            }

            int k;
            scanf("%d", &k);

            queue<int>q;
            bool visit[30];
            int cost[30];

            printf("Test Set #%d\n", tc);
            tc++;

            int z, x;
            while(k--){
                scanf("%d %d", &z, &x);

                memset(visit, false, sizeof visit);
                memset(cost, -1, sizeof cost);

                cost[z]=0;
                visit[z]=true;

                q.push(z);

                while(!q.empty()){
                    int f=q.front();
                    int flag=1;

                    for(int i=0; i<adjlist[f].size(); i++){
                        int v=adjlist[f][i];

                        if(visit[v]==false){
                            cost[v]=cost[f]+1;
                            visit[v]=true;
                            q.push(v);
                        }
                    }

                    q.pop();
                }

                printf("%2d to %2d: %d\n", z, x, cost[x]-cost[z]);
            }
            printf("\n");

            for(int i=1; i<21; i++){
                adjlist[i].clear();
            }
        }
        return 0;
    }
