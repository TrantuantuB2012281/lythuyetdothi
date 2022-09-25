#include <stdio.h>

typedef struct{
	int A[100][100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n) { //n l� s? d?nh, m l� s? cung
    G->n = n;
    G->m = 0;
}


void add_edge(Graph* G, int x, int y){
    G->A[x][y] = 1;
    G->m++;
}

int deg(Graph *G, int x){
    int count = 0, i;
    for( i = 1; i <= G->m;i++){
        count += G->A[x][i];
    }
    return count;
}

int main() {
    Graph G;
    init_graph(&G, 4);
	add_edge(&G,  1, 2);
	add_edge(&G,  1, 3);
	add_edge(&G,  1, 4);
	add_edge(&G,  2, 3);
	add_edge(&G,  1, 3);
	printf("%d",deg(&G,1));
    return 0;
}
