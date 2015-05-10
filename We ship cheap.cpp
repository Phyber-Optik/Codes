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
        int n, tc=0;
        while(scanf("%d", &n)!=EOF){
            vector<int>adjlist[100000];
            map<string, int> graph;

            int tot=1, e=n;
            string s1, s2;

            while(n--){
                cin>>s1>>s2;
                if(graph[s1]==0){
                    graph[s1]=tot++;
                }

                if(graph[s2]==0){
                    graph[s2]=tot++;
                }

                int z=graph[s1];
                int x=graph[s2];

                adjlist[z].pb(x);
                adjlist[x].pb(z);
            }

            map<string,int>::iterator it;

            string source;
            cin>>source>>s2;

            if(tc)
                cout<<endl;
            tc++;

            if(source==s2)
                cout<<endl;

            else{
                queue<int>q;
                bool visit[1000];
                vector< string >route[1000];
                //int cost[1000];
                memset(visit, false, sizeof visit);
                //memset(cost, -1, sizeof cost);

                //cout<<graph[source]<<endl;

                //cost[graph[source]]=0;
                visit[graph[source]]=true;

                q.push(graph[source]);

                int ff=0;
                while(!q.empty()){
                    int f=q.front();
                    //cout<<"f="<<f<<endl;
                    int flag=0;

                    for(int i=0; i<adjlist[f].size(); i++){
                        int v=adjlist[f][i];
                        //cout<<adjlist[f][i]<<endl;

                        if(visit[v]==false){
                            //cost[v]=cost[f]+1;

                            for(int j=0; j<route[f].size(); j++){
                                route[v].pb(route[f][j]);
                            }

                            map<string, int>::iterator it;
                            for(it=graph.begin(); it!=graph.end(); it++){
                                if(it->second==f)
                                    route[v].pb(it->first);
                            }

                            if(graph[s2]==v){
                                flag=1;
                                break;
                            }

                            visit[v]=true;
                            q.push(v);
                        }
                    }
                    if(flag==1){
                        ff=1;
                        break;
                    }
                    q.pop();
                }

                //PRINT COST

                /*map<string, int>::iterator iit;
                int j=1;
                for(iit=graph.begin(); iit!=graph.end(); iit++){
                    cout<<(*iit).second<<" "<<(*iit).first<<" "<<cost[iit->second]<<endl;
                    j++;
                }*/

                if(ff==1){
                    cout<<source;
                    for(int i=1; i<route[graph[s2]].size(); i++){
                        cout<<" "<< route[graph[s2]][i] <<endl<<route[graph[s2]][i] ;
                    }
                    cout<<" "<<s2<<endl;
                }

                else
                    cout<<"No route"<<endl;

                for(int i=0; i<=tot; i++){
                    //adjlist[i].clear();
                    route[i].clear();
                }
            }

            for(int i=0; i<=tot; i++){
                adjlist[i].clear();
                //route[i].clear();
            }

            graph.clear();
        }
        return 0;
    }
