#include <stdio.h>

typedef struct {
	int A[100][100]; //A[x][e]  A[y][e]  => 1 cung
	int n, m;
}Graph;

void init_graph(Graph* G, int n, int m) { //n l� s? d?nh, m l� s? cung
    G->n = n;
    G->m = m;
}


void add_edge(Graph* G, int e, int x, int y){
    G->A[x][e] = 1;
    G->A[y][e] = 1;
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
    init_graph(&G, 4, 5);
	add_edge(&G, 1, 1, 2);
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 4);
	add_edge(&G, 4, 2, 3);
	add_edge(&G, 5, 4, 4);
	int bac = deg(&G,1);
	printf("%d",bac);
    return 0;
}
