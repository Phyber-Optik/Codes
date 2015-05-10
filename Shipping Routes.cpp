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

    vector<int>adjlist[31];
    int cost[100];
    bool visit[900];

    bool bfs(int source, int destination){
        queue<int>q;

        memset(visit, false, sizeof visit);
        memset(cost, -1, sizeof cost);

        cost[source]=0;
        visit[source]=true;

        q.push(source);

        bool flag=false;
        while(!q.empty()){
            int f=q.front();
            bool ff=false;

            for(int i=0; i<adjlist[f].size(); i++){
                int v=adjlist[f][i];

                if(visit[v]==false){
                    if(v==destination){
                        ff=true;
                        //break;
                    }
                    cost[v]=cost[f]+1;
                    visit[v]=true;
                    q.push(v);
                }
            }

            if(ff==true){
                flag=true;
                break;
            }

            q.pop();
        }

        return flag;
    }

    int main(){
        //read(in);
        int N;
        map<string, int>graph;
        scanf("%d", &N);
        puts("SHIPPING ROUTES OUTPUT");
        int tc=1;

        while(N--){
            printf("\nDATA SET %2d\n\n", tc);
            tc++;

            int m, n, k;
            scanf("%d %d %d", &m, &n, &k);

            string s;
            int tot=1;
            while(m--){
                cin>>s;
                if(graph[s]==0){
                    graph[s]=tot++;
                }
            }

            string d;
            int p, q;
            while(n--){
                cin>>s>>d;
                p=graph[s];
                q=graph[d];
                //out<<p<<" "<<q<<endl;

                adjlist[p].pb(q);
                adjlist[q].pb(p);
            }

            int c;
            while(k--){
                cin>>c>>s>>d;
                p=graph[s];
                q=graph[d];
                bfs(p, q);

                if(graph[s]==0 || graph[d]==0 || bfs(p, q)==0){
                    printf("NO SHIPMENT POSSIBLE\n");
                }

                else{
                    printf("$%d\n", c*cost[q]*100);
                }
            }

            //printf("\n");

            for(int i=0; i<tot; i++){
                adjlist[i].clear();
            }

            graph.clear();
        }

        puts("\nEND OF OUTPUT");

        return 0;
    }
