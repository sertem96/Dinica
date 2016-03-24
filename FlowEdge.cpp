#ifndef _FLOWEDGE_CPP_
#define _FLOWEDGE_CPP_

#include "FlowEdge.h"

int FlowEdge::getID() const {
	return id;
}

int FlowEdge::getStartVertex() const {
	return startVertex;
}

int FlowEdge::getFinishVertex() const {
	return finishVertex;
}
std::istream &operator>>(std::istream &in, FlowEdge &flowEdge) {
	int from, to, capacity;
	in >> from >> to >> capacity;
	from--;
	to--;
	flowEdge.startVertex = from;
	flowEdge.finishVertex = to;
	flowEdge.capacity = capacity;
	return in;
}

long long FlowEdge::getCapacity() const {
	return capacity;
}

long long FlowEdge::getFlow() const {
	return flow;
}

FlowEdge *FlowEdge::getReversedEdge() const {
	return reversedEdge;
}

void FlowEdge::setReversedEdge(FlowEdge *myReversedEdge) {
	reversedEdge = myReversedEdge;
}

void FlowEdge::incFlow(long long d) {
	flow += d;
	reversedEdge->flow -= d;
}

#endif
