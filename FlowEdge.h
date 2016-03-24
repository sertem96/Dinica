#ifndef _FLOWEDGE_H_
#define _FLOWEDGE_H_

#include <bits/stdc++.h>

class FlowEdge;

std::istream &operator>>(std::istream &in, FlowEdge &flowEdge);

class FlowEdge {
protected:
	int id, startVertex, finishVertex;
	long long capacity, flow;
	FlowEdge *reversedEdge;
public:
	FlowEdge() : id(-1), startVertex(-1), finishVertex(-1), capacity(0), flow(0),
				 reversedEdge(NULL) {}
	FlowEdge(int myId, int myStartVertex = 0, int myFinishVertex = 0,
			 long long myCapacity = 0, long long myFlow = 0) :
			id(myId), startVertex(myStartVertex), finishVertex(myFinishVertex), capacity(myCapacity), flow(myFlow),
			reversedEdge(NULL) {}
	FlowEdge(FlowEdge *myReversedEdge) :
			id(-1), startVertex(myReversedEdge->getFinishVertex()), finishVertex(myReversedEdge->getStartVertex()),
			capacity(0), flow(0), reversedEdge(myReversedEdge) {}

    int getID() const;
    int getStartVertex() const;
    int getFinishVertex() const;
	FlowEdge *getReversedEdge() const;
	long long getCapacity() const;
	long long getFlow() const;

	void setReversedEdge(FlowEdge *myReversedEdge);
	void incFlow(long long d);

	friend std::istream &operator>>(std::istream &in,
									   FlowEdge &flowEdge);
};

#include "FlowEdge.cpp"

#endif
