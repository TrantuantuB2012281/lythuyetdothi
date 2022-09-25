#include <stdio.h>

typedef struct{
	int A[100][100];
	int n, m;
}Graph;

void init_graph(Graph* G, int n) { //n là s? d?nh, m là s? cung
    G->n = n;
    G->m = 0;
}


void add_edge(Graph* G, int x, int y){
    G->A[x][y] = 1;
    G->m++;
}

int main() {
    Graph G;
    init_graph(&G, 4);
	add_edge(&G, 1, 2);
	add_edge(&G, 1, 3);
	add_edge(&G, 3, 4);
	int i,j;
	for(i = 1; i <= G.n;i++){
		for(j = 1; j <= G.n;j++)
			printf("%d ",G.A[i][j]);
		printf("\n");
	}
    return 0;
}
