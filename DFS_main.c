/*
	@brief:�����������(�ڽӱ�
	@author:WavenZ
	@time:2018/10/7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DFS.h"


int main(int argc, char *argv[]) {
	ALGraph G;
	CreateGraph(&G);//�����ڽӱ�
	DFSTraverse(G);//�����������
	system("pause");
	return 1;
}






