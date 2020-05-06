#ifndef MINHEAP_HH_
#define MINHEAP_HH_

#include "job.hh"
class MinHeap{
	public:
	bool prior(Job j1, Job j2){
		return j1.priority1 < j2.priority1;
	}
};
#endif
