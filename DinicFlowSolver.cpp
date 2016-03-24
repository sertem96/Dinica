#ifndef _DINICFLOWSOLVER_CPP_
#define _DINICFLOWSOLVER_CPP_

#include <bits/stdc++.h>
#include "DinicFlowSolver.h"

long long DinicFlowSolver::dfs(Graph &graph, int vertex, int sink, long long flowToPush,
                                                std::vector<int> const &levelOfVertex,
                                                std::vector<int> &indexOfEdge) {
	if (vertex == sink) {
		return flowToPush;
	}
	long long answer = 0LL;
	for (;indexOfEdge[vertex] < (int)graph.edge[vertex].size();
          ++indexOfEdge[vertex]) {
		FlowEdge *edge = graph.edge[vertex][indexOfEdge[vertex]];
		int to = edge->getFinishVertex();
		if (levelOfVertex[to] != levelOfVertex[vertex] + 1) {
			continue;
		}
		long long flowAdded = dfs(graph, to, sink, std::min(flowToPush, edge->getCapacity() - edge->getFlow()),
                                  levelOfVertex, indexOfEdge);
		edge->incFlow(flowAdded);
		answer += flowAdded;
		flowToPush -= flowAdded;
		if (flowToPush == 0LL) {
			return answer;
		}
	}
	return answer;
}


void DinicFlowSolver::bfs(int start, std::vector<int> &distanceToVertex) {
    distanceToVertex.resize(graph.getV());
    for (int i = 0; i < (int)distanceToVertex.size(); ++i) {
        distanceToVertex[i] = -1;
    }
    std::queue<int> vertexQueue;
    vertexQueue.push(start);
    distanceToVertex[start] = 0;
    while (!vertexQueue.empty()) {
        int v = vertexQueue.front();
        vertexQueue.pop();
        for (int i = 0; i < (int)graph.edge[v].size(); ++i) {
            FlowEdge *edge = graph.edge[v][i];
            int to = edge->getFinishVertex();
            if (distanceToVertex[to] == -1 && (edge->getCapacity() - edge->getFlow() > 0)) {
                distanceToVertex[to] = distanceToVertex[v] + 1;
                vertexQueue.push(to);
            }
        }
    }
}

void DinicFlowSolver::solve(int source, int sink) {
    while (true) {
        std::vector<int> distanceToVertex;
        bfs(source, distanceToVertex);
        if (distanceToVertex[sink] == -1) {
            break;
        }
        long long MaxFlowPossible = 0LL;
        for (int i = 0; i < (int)graph.edge[source].size(); ++i) {
            FlowEdge *edge = (FlowEdge *)
                    graph.edge[source][i];
            MaxFlowPossible += edge->getCapacity() - edge->getFlow();
        }
        std::vector<int> indexOfEdge(graph.edge.size(), 0);
        long long pushed = dfs(graph, source, sink, MaxFlowPossible, distanceToVertex, indexOfEdge);
        graph.flow += pushed;
    }
}

#endif
