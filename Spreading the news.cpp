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
    vector<int>adjlist[2501];
    int cost[2501];
    bool visit[2501];

    void bfs(int source){
        queue<int>q;

        mem(cost, -1);
        mem(visit, false);

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
        //read(in);
        int E, a[2501], i, t, frnd;
        map<int, int>graph;
        while(scanf("%d", &E)!=EOF){
            for(i=0; i<E; i++){
                a[i]=i;
                scanf("%d", &t);
                while(t--){
                    scanf("%d", &frnd);
                    adjlist[i].pb(frnd);
                    //adjlist[frnd].pb(i);
                }
            }

            int T, source;
            scanf("%d", &T);
            while(T--){
                scanf("%d", &source);
                bfs(source);

                if(adjlist[source].size()==0){
                    printf("0\n");
                }

                else{
                    int max=0, q;

                    for(i=0; i<E; i++){
                        if(cost[i]>max){
                            max=cost[i];
                        }
                    }

                    int count[2501];
                    mem(count, 0);

                    //for(i=0; i<E; i++)
                        //cout<<cost[i]<<" ";

                    for(i=0; i<E; i++){
                        if(cost[i]>0)
                            count[cost[i]]++;
                    }

                    int m=0, n=0;
                    for(i=1; i<=max; i++){
                        if(count[i]>m){
                            m=count[i];
                            n=i;
                        }
                    }
                    //cout<<endl;
                    if(m==0)
                        printf("0\n");
                    else
                        printf("%d %d\n", m, n);
                }
            }

            for(int j=0; j<E; j++){
                adjlist[j].clear();
            }
        }
        return 0;
    }
