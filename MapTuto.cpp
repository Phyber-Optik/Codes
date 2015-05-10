    #include<iostream>
    #include<map>
    #include<vector>

    using namespace std;

    int main(){
        int edge;
        cin>>edge;
        map<int,int>graph;
            int a,b,i,j,tot=1;

        vector<int>adjlist[110];



        while(edge--){
            cin>>a>>b;
            if(graph[a]==0){
                graph[a]=tot++;
                //cout<<tot<<"TOT"<<endl;
            }
            if(graph[b]==0){
                graph[b]=tot++;
                //cout<<tot<<"TOT"<<endl;
            }

            int p=graph[a],
            q=graph[b];
            //  cout<<p<<" "<<q<<endl;
            adjlist[p].push_back(q);
            adjlist[q].push_back(p);
        }

        map<int,int>::iterator it;

        for(it=graph.begin();it!=graph.end();it++)
            cout<<(*it).first<<" "<<(*it).second<<endl;

        for(i=1;i<tot;i++){
            cout<<i<<" contains "<<(int)adjlist[i].size()<<" nodes"<<endl;
        }

    }
