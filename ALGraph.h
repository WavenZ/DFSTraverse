#pragma once
#include <stdio.h>
#include <stdlib.h>


#define Status int
#define MAX_VERTEX_NUM 20//��󶥵���
#define VertexType char
#define InfoType int
typedef enum { DN, UDN, DG, UDG }GraphKind;
typedef struct ArcNode {//�����
	int adjvex;//�û�ָ��Ķ����±�
	struct ArcNode *nextarc;//ָ����һ������ָ��
	InfoType *info;
}ArcNode;
typedef struct VNode {//����
	VertexType data;
	ArcNode *firstarc;//ָ�������е�һ�����
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {//��ǰͼ�����ݽṹ
	AdjList vertices;
	int vexnum, arcnum;//ͼ�еĽ�����ͻ�/����
	int kind;//ͼ������
}ALGraph;


int LocateVex(ALGraph *G, VertexType vex);
void print(ALGraph G);
Status CreateDN(ALGraph *G);//������
Status CreateUDN(ALGraph *G);//������
Status CreateDG(ALGraph *G);//����ͼ
Status CreateUDG(ALGraph *G);//����ͼ
Status CreateGraph(ALGraph *G);