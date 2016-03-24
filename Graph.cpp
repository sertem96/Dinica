#ifndef _Graph_CPP_
#define _Graph_CPP_

#include <bits/stdc++.h>
#include "Graph.h"

size_t Graph::getV() const {
	return edge.size();
}

std::istream &operator>>(std::istream &in, Graph &graph) {
	int n, m;
	in >> n >> m;
	graph.edge.resize(n);
	for (int i = 0; i < m; ++i) {
		FlowEdge *directEdge = new FlowEdge(i);
		in >> (*directEdge);
		FlowEdge *reversedEdge = new FlowEdge(directEdge);
		directEdge->setReversedEdge(reversedEdge);
		graph.edge[directEdge->getStartVertex()].push_back(directEdge);
		graph.edge[reversedEdge->getStartVertex()].push_back(reversedEdge);
	}
	return in;
}

std::ostream &operator<<(std::ostream &out, Graph &graph) {
	out << graph.flow << "\n";

    int maxNum = 0;
	for (int i = 0; i < (int)graph.edge.size(); ++i) {
		maxNum += graph.edge[i].size();
	}
	maxNum /= 2;
	std::vector<long long> answer(maxNum);
	for (int i = 0; i < (int)graph.edge.size(); ++i) {
		for (int j = 0; j < (int)graph.edge[i].size(); ++j) {
			if (graph.edge[i][j]->getID() != -1)  {
				answer[graph.edge[i][j]->getID()] = graph.edge[i][j]->getFlow();
			}
		}
	}
	for (int i = 0; i < (int)answer.size(); ++i) {
		out << answer[i] << "\n";
	}

	return out;
}

#endif
