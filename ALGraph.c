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

Status CreateDN(ALGraph *G)//������
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;

	printf("������ͼ�Ķ������ͻ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	for (i = 0; i < G->vexnum; ++i) {
		G->vertices[i].firstarc = NULL;
	}
	printf("������ͼ�и��������ƣ�");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("�������%d�����Ļ�β����ͷ��Ȩֵ��", i + 1);
		scanf("%c %c %d", &tail, &head, &weight);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//�û�ָ��Ķ���
		p->nextarc = G->vertices[tail].firstarc;//������������
		G->vertices[tail].firstarc = p;//������������
	}
	return 1;
}
Status CreateUDN(ALGraph *G)//������
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;

	printf("������ͼ�Ķ������ͱ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	printf("������ͼ�и��������ƣ�");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("�������%d�������������������Ȩֵ��", i + 1);
		scanf("%c %c %d", &tail, &head, &weight);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//�û�ָ��Ķ���
		p->nextarc = G->vertices[tail].firstarc;//������������
		G->vertices[tail].firstarc = p;//������������

		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = tail;//�û�ָ��Ķ���
		p->nextarc = G->vertices[head].firstarc;//������������
		G->vertices[head].firstarc = p;//������������
	}
	return 1;
}
Status CreateDG(ALGraph *G)//����ͼ
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;

	printf("������ͼ�Ķ������ͻ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();

	printf("������ͼ�и��������ƣ�");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("�������%d�����Ļ�β����ͷ��", i + 1);
		scanf("%c %c", &tail, &head);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//�û�ָ��Ķ���
		p->nextarc = G->vertices[tail].firstarc;//������������
		G->vertices[tail].firstarc = p;//������������
	}
	return 1;
}
Status CreateUDG(ALGraph *G)//����ͼ
{
	int i, j, k, weight;
	char tail, head;
	ArcNode *p;
	printf("������ͼ�Ķ������ͱ�����");
	scanf("%d %d", &G->vexnum, &G->arcnum);
	getchar();
	printf("������ͼ�и��������ƣ�");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	getchar();
	for (i = 0; i < G->arcnum; ++i) {
		printf("�������%d���������������ߣ�", i + 1);
		scanf("%c %c", &tail, &head);
		getchar();
		tail = LocateVex(G, tail);
		head = LocateVex(G, head);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = head;//�û�ָ��Ķ���
		p->nextarc = G->vertices[tail].firstarc;//������������
		G->vertices[tail].firstarc = p;//������������

		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = tail;//�û�ָ��Ķ���
		p->nextarc = G->vertices[head].firstarc;//������������
		G->vertices[head].firstarc = p;//������������
	}
	return 1;
}
Status CreateGraph(ALGraph *G)
{
	int kind;
	printf("�����봴����ͼ�����ͣ�1.DN 2.UDN 3.DG 4.UDG����");
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