#include <bits/stdc++.h>
#include "PreflowPushFlowSolver.h"
#include "DinicFlowSolver.h"

int main() {
	std::ios_base::sync_with_stdio(false);
    Graph graph;
    std::cin >> graph;
    FlowSolver *flowSolver;
    if (time(NULL) % 2) {
        flowSolver = new PreflowPushFlowSolver(graph);
    } else {
        flowSolver = new DinicFlowSolver(graph);
    }
    flowSolver->solve(0, graph.getV() - 1);
    std::cout << graph;
    return 0;
}
/*
4 5
1 2 1
1 3 2
3 2 1
2 4 2
3 4 1
 */