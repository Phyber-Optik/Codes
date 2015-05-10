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
    vector< int > adjlist[1001];
    int cost[1001];
    bool visit[1001];

    void bfs(int source){
    queue<int>q;

    memset(visit, false, sizeof visit);
    memset(cost, -1, sizeof cost);

    cost[source]=0;
    visit[source]=true;

    q.push(source);

    while(!q.empty()){
        int f=q.front();

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
}


    int main(){
        int N;
        scanf("%d", &N);
        int tc=0;
        while(N--){
            getchar();
            int n, p, a, b;
            scanf("%d %d", &n, &p);
            while(p--){
                scanf("%d %d", &a, &b);
                int flag=1;
                for(int i=0; i<adjlist[a].size(); i++){
                    if(b==adjlist[a][i]){
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    adjlist[a].pb(b);

                flag=1;
                for(int i=0; i<adjlist[b].size(); i++){
                    if(a==adjlist[b][i]){
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    adjlist[b].pb(a);
            }

            bfs(0);
            if(tc)
                printf("\n");
            tc++;
            for(int i=1; i<n; i++){
                printf("%d\n", cost[i]);
            }

            for(int i=0; i<n; i++){
                adjlist[i].clear();
            }
        }

        return 0;
    }
