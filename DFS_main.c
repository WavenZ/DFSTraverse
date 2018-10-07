/*
	@brief:深度优先搜索(邻接表
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
	CreateGraph(&G);//创建邻接表
	DFSTraverse(G);//深度优先搜索
	system("pause");
	return 1;
}






