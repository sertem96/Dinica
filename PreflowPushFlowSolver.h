#ifndef _PREFLOWPUSHFLOWSOLVER_H_
#define _PREFLOWPUSHFLOWSOLVER_H_

#include <bits/stdc++.h>
#include "Graph.h"
#include "FlowSolver.h"

class PreflowPushFlowSolver : public FlowSolver {
private:
	std::vector<int> height, heightCount;
	std::vector<long long> excess;
	std::queue<int> vertexQueue;
	std::vector<int> indexOfCurrentEdge;

	void relable(int v);
	void push(FlowEdge *edge);
	void discharge(int v);
public:
	PreflowPushFlowSolver(Graph &myGraph) : FlowSolver(myGraph) {}

    virtual void solve(int source, int sink);
};

#include "PreflowPushFlowSolver.cpp"

#endif
