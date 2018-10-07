#pragma once
#include <stdio.h>
#include <stdlib.h>


#define Status int
#define MAX_VERTEX_NUM 20//最大顶点数
#define VertexType char
#define InfoType int
typedef enum { DN, UDN, DG, UDG }GraphKind;
typedef struct ArcNode {//弧结点
	int adjvex;//该弧指向的顶点下标
	struct ArcNode *nextarc;//指向下一条弧的指针
	InfoType *info;
}ArcNode;
typedef struct VNode {//表结点
	VertexType data;
	ArcNode *firstarc;//指向链表中第一个结点
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {//当前图的数据结构
	AdjList vertices;
	int vexnum, arcnum;//图中的结点数和弧/边数
	int kind;//图的类型
}ALGraph;


int LocateVex(ALGraph *G, VertexType vex);
void print(ALGraph G);
Status CreateDN(ALGraph *G);//有向网
Status CreateUDN(ALGraph *G);//无向网
Status CreateDG(ALGraph *G);//有向图
Status CreateUDG(ALGraph *G);//无向图
Status CreateGraph(ALGraph *G);