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

    vector< int > adjlist[201];
    bool visit[210];
    int cost[210];

    void bfs(int source, int destination){
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
        //read(in);
        int i, j, m, n, k, x, z, l;
        scanf("%d", &m);
        getchar();

        while(m--){
            map< string, int > graph;

            string s;
            int t=1;

            //getchar();
            while(cin>>s && s!="*"){
                if(graph[s]==0){
                    graph[s]=t++;
                }

                //int p=graph[s];
            }

            string a, b;
            map< string, int >::iterator it1, it2, it3;
            for(it1=graph.begin(); it1!=graph.end(); it1++){
                it3=it1;
                for(it2=it3++; it2!=graph.end(); it2++){
                    int omil=0;

                    if(it1->first.size()!=it2->first.size());
                    else{
                        a=it1->first;
                        b=it2->first;
                        int flag=1;

                        for(i=0; i<a.size(); i++){
                            if(a[i]!=b[i]){
                                omil++;
                            }

                            if(omil>1){
                                flag=0;
                                break;
                            }
                        }

                        if(flag){
                            adjlist[graph[a]].pb(graph[b]);
                            adjlist[graph[b]].pb(graph[a]);
                        }
                    }
                }
            }

            //getchar();

            string start,to,line;

            size_t pos;
            getline(cin,line);
            getline(cin,line);

            while(line != ""){
                pos = line.find(" ");
                start = line.substr(0, pos);
                to = line.substr(pos+1,line.size());

                bfs(graph[start], graph[to]);
                cout<<start<<" "<<to<<" "<<cost[graph[to]]<<endl;
                if(!getline(cin,line))
                    break;
            }

            if(m != 0)
              cout<<endl;

            for(j=0; j<t; j++){
                adjlist[j].clear();
            }

            graph.clear();
        }

        return 0;
    }
