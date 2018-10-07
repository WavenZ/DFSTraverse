#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"

int visited[MAX_VERTEX_NUM];

void DFS(ALGraph G, int v);
void DFSTraverse(ALGraph G);