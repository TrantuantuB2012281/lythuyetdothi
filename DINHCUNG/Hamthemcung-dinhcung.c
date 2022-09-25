#include <stdio.h>

typedef struct {
	int A[100][100]; //A[x][e]  A[y][e]  => 1 cung
	int n, m;
}Graph;

void init_graph(Graph* G, int n, int m) { //n là s? d?nh, m là s? cung
    G->n = n;
    G->m = m;
}


void add_edge(Graph* G, int e, int x, int y){
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

int main() {
    Graph G;
    init_graph(&G, 4, 5);
	add_edge(&G, 1, 2, 3);
	printf("%d %d\n", G.A[2][1], G.A[4][1]);
    return 0;
}
