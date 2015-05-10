#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<cstring>


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

int isCycle( struct Graph* graph ){
    int V=graph->V;
    int E=graph->E;

    struct subset *subsets;
    subsets=(struct subset*) malloc (V * sizeof(struct subset));

    for(int v=0; v<V; v++){
        subsets[v].parent=v;
        subsets[v].rank=0;
    }

    for(int i=0; i<graph->E; ++i){
        int x=find(subsets, graph->edge[i].src);
        int y=find(subsets, graph->edge[i].des);

        if(x==y){
            return 1;
        }

        Union(subsets, x, y);
    }

    return 0;
}


int main()
{
    /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */
    struct Graph* graph = creategraph(3, 3);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].des = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].des = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].des = 2;
    //cout<<"poop"<<endl;
    if (isCycle(graph))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" );
    cout<<endl;
    //cout<<"poop"<<endl;
    return 0;
}
