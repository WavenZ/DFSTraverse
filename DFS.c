#define _CRT_SECURE_NO_WARNINGS
#include "DFS.h"
void visit(ALGraph G, int vex) {
	printf("%c ", G.vertices[vex].data);
}

void DFS(ALGraph G, int v) {
	ArcNode *p = G.vertices[v].firstarc;
	visited[v] = 1;
	visit(G, v);
	while (p) {
		if (!visited[p->adjvex]) DFS(G, p->adjvex);
		p = p->nextarc;
	}
}
void DFSTraverse(ALGraph G) {
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		visited[i] = 0;
	}
	printf("深度优先遍历结果：");
	for (i = 0; i < G.vexnum; ++i) {
		if (!visited[i]) DFS(G, i);
	}
}