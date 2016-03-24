#ifndef _DINICFLOWSOLVER_H_
#define _DINICFLOWSOLVER_H_

#include <bits/stdc++.h>
#include "Graph.h"
#include "FlowSolver.h"

class DinicFlowSolver : public FlowSolver {
private:
	class EdgeIsNotFull;
	long long dfs(Graph &graph, int vertex, int sink, long long flowToPush,
					 std::vector<int> const &levelOfVertex,
					 std::vector<int> &indexOfEdge);
	void bfs(int start, std::vector<int> &distanceToVertex);
public:
	DinicFlowSolver(Graph &myGraph) : FlowSolver(myGraph) {}
    virtual void solve(int source, int sink);
};

#include "DinicFlowSolver.cpp"

#endif
