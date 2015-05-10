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
        read(in);
        int N;
        int i, j, m, n, tot;
        vector< int >adjlist[1000];
        map<string, int>graph;
        bool visit[1000];
        int tc=0;
        scanf("%d", &N);
        while(N--){
            getchar();
            scanf("%d %d", &i, &j);
            string s1, s2;
            tot=1;
            while(i--){
                cin>>s1>>s2;
                if(graph[s1]==0){
                    graph[s1]=tot++;
                }

                if(graph[s2]==0){
                    graph[s2]=tot++;
                }
                //cout<<"a"<<endl;
                int p=graph[s1];
                int q=graph[s2];
                //cout<<p<<" "<<q<<endl;
                adjlist[p].pb(q);
                adjlist[q].pb(p);
            }

            map<string, int>::iterator it;
            vector<char>route[1000];
            if(tc)
                    printf("\n");
                tc++;
            while(j--){
                cin>>s1>>s2;
                mem(visit, false);
                queue<int>q;
                visit[graph[s1]]=true;
                //cout<<"destination="<<graph[s2]<<endl;

                q.push(graph[s1]);
                int ff=0;
                route[graph[s2]].pb(s1[0]);

                while(!q.empty()){
                    int f=q.front();
                    //cout<<adjlist[f].size();
                    for(int i=0; i<adjlist[f].size(); i++){
                        int v= adjlist[f][i];

                        if(visit[v]==false){

                            for(int j=0; j<route[f].size(); j++){
                                route[v].pb(route[f][j]);
                            }

                            for(it=graph.begin(); it!=graph.end(); it++){
                                if(it->second==v){
                                    //cout<<it->first<<endl;
                                    route[v].pb(it->first[0]);
                                    //break;
                                }
                            }

                            if(graph[s2]==v){
                                ff=1;
                                //break;
                            }

                            visit[v]=true;
                            q.push(v);
                        }
                    }

                    if(ff=1){
                        //break;
                    }

                    q.pop();
                }

                //route[graph[s2]].pb(s2[0]);

                for(m=0; m<route[graph[s2]].size(); m++){
                    putchar(route[graph[s2]][m]);
                }

                putchar('\n');
                for(i=0; i<tot; i++){
                    route[i].clear();
                }
            }

            for(i=0; i<tot; i++){
                adjlist[i].clear();
            }

            graph.clear();
        }

        return 0;
    }
