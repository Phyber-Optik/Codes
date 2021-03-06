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

int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = creategraph(V, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].des = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].des = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].des = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].des = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].des = 3;
    graph->edge[4].weight = 4;

    kruskal(graph);

    return 0;
}
