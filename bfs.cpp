bool visit[1010];
int cost[1010];

void bfs(int source){
    queue<int>q;

    memset(visit, false, sizeof visit);
    memset(cost, -1, sizeof cost);

    cost[graph[source]]=0;
    visit[graph[source]]=true;

    q.push(graph[source]);

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
