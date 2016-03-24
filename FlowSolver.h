#ifndef _FLOWSOLVER_H
#define _FLOWSOLVER_H

#include "Graph.h"

class FlowSolver {
protected:
    Graph &graph;
public:
    FlowSolver(Graph &myGraph) : graph(myGraph) {}
    virtual void solve(int source, int sink) = 0;
};

#endif