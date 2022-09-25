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
    G->A[y][x] = 1;
    G->m++;
}

int deg(Graph *G, int x){
    int count = 0, i;
    for( i = 1; i <= G->n;i++){
        count += G->A[x][i];
    }
    return count;
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

void in(Graph G){
    int i,j;
    for(i = 1; i <= G.n;i++){
        for(j = 1; j <= G.n; j++)
            printf("%d ",G.A[i][j]);
        printf("\n");
    }
}

int main() {
 	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int n, m, u, v, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d", &u, &v);
		getchar();
		add_edge(&G, u, v);
	}
	
	//
	printf("\n");
	in(G);
	printf("\n");
	//
	
	DinhMax D = deg_max(&G);
    printf("%d %d",D.dinhMax,D.bacMax);
    return 0;
}
