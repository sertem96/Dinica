#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <bits/stdc++.h>
#include "FlowEdge.h"

class Graph;

std::istream &operator>>(std::istream &in, Graph &graph);

std::ostream &operator<<(std::ostream &out, Graph &graph);

class Graph {
protected:
	long long flow;
	std::vector<std::vector<FlowEdge *>> edge;
public:
	Graph() : flow(), edge(0) {}
	
	size_t getV() const;

	friend std::istream &operator>> (std::istream &in,
			Graph &graph);
	friend std::ostream &operator<< (std::ostream &out,
			Graph &graph);
    friend class FlowSolver;
    friend class DinicFlowSolver;
    friend class PreflowPushFlowSolver;
};

#include "Graph.cpp"

#endif
