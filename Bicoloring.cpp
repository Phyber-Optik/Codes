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
        int N, n, e;
        while(scanf("%d", &N) && N){
            vector<int>adjlist[201];
            map<int, int>graph;

            scanf("%d", &e);
            n=e;
            int a, b, tot=1;
            while(n--){
                scanf("%d %d", &a, &b);
                if(graph[a]==0){
                    graph[a]=tot++;
                }

                if(graph[b]==0){
                    graph[b]=tot++;
                }

                int x=graph[a], z=graph[b];

                adjlist[x].pb(z);
                adjlist[z].pb(x);
            }

            queue<int>q;
            bool visit[201];

            memset(visit, false, sizeof visit);
            //memset(cost, -1, sizeof cost);

            //cost[graph[source]]=0;
            map<int, int>::iterator it=graph.begin();
            int source=(*it).first;

            visit[graph[source]]=true;

            q.push(graph[source]);


            int ff=1;
            while(!q.empty()){
                int f=q.front();

                int flag=1;
                for(int i=0; i<adjlist[f].size(); i++){
                    int v=adjlist[f][i];

                    if(visit[v]==false){
                        if(visit[f]==false)
                            visit[v]=true;
                        else
                            visit[v]=false;
                        q.push(v);
                    }

                    if(visit[v]==visit[f]){
                        flag=0;
                        break;
                    }
                }
                if(flag==0){
                    ff=0;
                    break;
                }

                q.pop();
            }

            if(ff){
                printf("BICOLORABLE.\n");
            }

            else
                printf("NOT BICOLORABLE.\n");

            for(int i=0; i<e; i++){
                adjlist[i].clear();
            }
        }
        return 0;
    }
