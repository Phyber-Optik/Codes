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

    //vector <int> parent;
    struct Edge{
        int src;
        int des;
        int weight;
    };

    struct Graph{
        int V, E;
        struct Edge* edge;
    };

    struct subset{
        int parent;
        int rank;
    };

    struct Graph* creategraph(int v, int e){
        struct Graph* graph = new Graph();
        graph->V=v;
        graph->E=e;

        graph->edge = (struct Edge*) malloc( graph->E*sizeof( struct Edge ) );
        return graph;
    };

    int find(struct subset subsets[], int i){
        if(subsets[i].parent != i){
            subsets[i].parent = find(subsets, subsets[i].parent);
        }

        return subsets[i].parent;
    }

    void Union(struct subset subsets[], int x, int y){
        int xroot=find(subsets, x);
        int yroot=find(subsets, y);

        if(subsets[xroot].rank<subsets[yroot].rank){
            subsets[xroot].parent=yroot;
        }

        else if(subsets[xroot].rank>subsets[yroot].rank){
            subsets[yroot].parent=xroot;
        }

        else{
            subsets[yroot].parent=xroot;
            subsets[xroot].rank++;
        }
    }

    int myComp(const void *a, const void *b){
        struct Edge* a1= (struct Edge* ) a;
        struct Edge* a2= (struct Edge* ) b;

        return a1->weight > a2->weight;
    }

    void kruskal( struct Graph* graph ){
        int V=graph->V;
        struct Edge result[V];
        int e=0;
        int i=0;

        qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

        struct subset *subsets=(struct subset*) malloc (V*sizeof(struct subset));
        for(int v=0; v<V; v++){
            subsets[v].parent=v;
            subsets[v].rank=0;
        }

        while(e<V-1){
            struct Edge next_edge=graph->edge[i++];

            int x=find(subsets, next_edge.src);
            int y=find(subsets, next_edge.des);

            if(x != y){
                result[e++]=next_edge;
                Union(subsets, x, y);
            }
        }

        printf("Following are the edges in the constructed MST\n");
        for (i = 0; i < e; ++i)
            printf("%d -- %d == %d\n", result[i].src, result[i].des,
                result[i].weight);
        return;
    }


    int main(){
        int V=
        return 0;
    }
