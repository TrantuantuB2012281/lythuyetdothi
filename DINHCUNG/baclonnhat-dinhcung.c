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

typedef struct{
    int bacMax;
    int dinhMax;
}DinhMax;

DinhMax deg_max(Graph *G){
    DinhMax D;
    int i;
	D.bacMax =0;
	D.dinhMax = 0;
     for(i = 1; i <= G->n;i++){
        if(deg(G,i) > D.bacMax){
             D.bacMax = deg(G,i);
             D.dinhMax = i;
        }
     }
     return D;
}

int deg(Graph *G, int x){
    int count = 0, i;
    for( i = 1; i <= G->m;i++){
        count += G->A[x][i];
    }
    return count;
}
int main() {
    freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n, m);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v);
		add_edge(&G, u, v);
	}

    DinhMax D = deg_max(&G);
    printf("%d %d",D.bacMax,D.dinhMax);
    return 0;
}
