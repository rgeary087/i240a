#ifndef MAXHEAP_HH_
#define MAXHEAP_HH_

#include "job.hh"

class MaxHeap{
	public:
	bool prior(Job j1, Job j2){
		return j1.priority0>j2.priority0;
	}
};

#endif
