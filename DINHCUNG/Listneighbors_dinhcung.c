#include <stdio.h>
#define MAX_ELEMENTS 100
typedef struct {
	int A[100][500];
	int n, m;
}Graph;

typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
}List;

//tao ds rong
void make_null(List *L){
	L->size = 0;
}

/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
    L->data[L->size] = x;
    L->size++;
}

/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
ElementType element_at(List* L, int i) {
    return L->data[i-1];
}

/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
    return L->size;
}

List neighbors(Graph* G, int x){
    List L;
    make_null(&L);
    int i,j;
    for(i = 0; i <= G->n; i++){
        if(i!=x)
            for(j = 0; j <= G->m; j++)
                if(G->A[x][j] == 1 && G->A[i][j] == 1){
                    push_back(&L,i);
                    break;
                    
            }
    }
    return L;
}

void add_edge(Graph* G, int e, int x, int y){
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}

void init_graph(Graph* G, int n, int m) { //n l� s? d?nh, m l� s? cung
    G->n = n;
    G->m = m;
}
int main(){
	Graph G;
    init_graph(&G, 4, 5);
	add_edge(&G, 1, 1, 2);
	add_edge(&G, 2, 1, 3);
	add_edge(&G, 3, 1, 4);
	add_edge(&G, 4, 2, 3);
	add_edge(&G, 5, 1, 3);
	List L = neighbors(&G,1);
	int i;
	for (i = 0; i < L.size; i++)
		printf("%d ",L.data[i]);
		
	return 0;
}

