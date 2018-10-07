#define _CRT_SECURE_NO_WARNINGS
#include "ALGraph.h"
int LocateVex(ALGraph *G, VertexType vex) {
	for (int i = 0; i < G->vexnum; ++i) {
		if (vex == G->vertices[i].data) return i;
	}
	return -1;
}

void print(ALGraph G)
{
	int i, j;
	ArcNode *p;
	for (i = 0; i < G.vexnum; ++i) {
		p = G.vertices[i].firstarc;
		printf("%c: ", G.vertices[i].data);
		while (p)
		{
			printf("%c --> %c  ", G.vertices[i].data, G.vertices[p->adjvex].data);
			p = p->nextarc;
		}
		printf("\n");
	}
}

Status CreateDN(ALGraph *G)//有向网
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;

	printf("请输入图的顶点数和弧数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; ++i) {
		G->vertices[i].firstarc = NULL;
	}
	printf("请输入图中各顶点名称：");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("请输入第%d条弧的弧尾、弧头和权值：", i + 1);
		scanf("%c %c %d", &tail, &head, &weight);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//该弧指向的顶点
		p->nextarc = G->vertices[tail].firstarc;//将结点插入链表
		G->vertices[tail].firstarc = p;//将结点插入链表
	}
	return 1;
}
Status CreateUDN(ALGraph *G)//无向网
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;

	printf("请输入图的顶点数和边数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	printf("请输入图中各顶点名称：");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("请输入第%d条边依附的两个顶点和权值：", i + 1);
		scanf("%c %c %d", &tail, &head, &weight);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//该弧指向的顶点
		p->nextarc = G->vertices[tail].firstarc;//将结点插入链表
		G->vertices[tail].firstarc = p;//将结点插入链表

		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = tail;//该弧指向的顶点
		p->nextarc = G->vertices[head].firstarc;//将结点插入链表
		G->vertices[head].firstarc = p;//将结点插入链表
	}
	return 1;
}
Status CreateDG(ALGraph *G)//有向图
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;

	printf("请输入图的顶点数和弧数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();

	printf("请输入图中各顶点名称：");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("请输入第%d条弧的弧尾、弧头：", i + 1);
		scanf("%c %c", &tail, &head);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//该弧指向的顶点
		p->nextarc = G->vertices[tail].firstarc;//将结点插入链表
		G->vertices[tail].firstarc = p;//将结点插入链表
	}
	return 1;
}
Status CreateUDG(ALGraph *G)//无向图
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;
	printf("请输入图的顶点数和边数：");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	printf("请输入图中各顶点名称：");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("请输入第%d条弧依附的两条边：", i + 1);
		scanf("%c %c", &tail, &head);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//该弧指向的顶点
		p->nextarc = G->vertices[tail].firstarc;//将结点插入链表
		G->vertices[tail].firstarc = p;//将结点插入链表

		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = tail;//该弧指向的顶点
		p->nextarc = G->vertices[head].firstarc;//将结点插入链表
		G->vertices[head].firstarc = p;//将结点插入链表
	}
	return 1;
}
Status CreateGraph(ALGraph *G)
{
	int kind;
	printf("请输入创建的图的类型（1.DN 2.UDN 3.DG 4.UDG）：");
	scanf("%d%c", &kind);
	switch (kind) {
	case 1: {
		G->kind = kind;
		return CreateDN(G);
	}break;
	case 2: {
		G->kind = kind;
		return CreateUDN(G);
	}break;
	case 3: {
		G->kind = kind;
		return CreateDG(G);
	}break;
	case 4: {
		G->kind = kind;
		return CreateUDG(G);
	}break;
	default:return 0;
	}
}