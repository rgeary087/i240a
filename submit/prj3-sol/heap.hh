#ifndef HEAP_HH_
#define HEAP_HH_

#include <vector>

template <typename E, typename Comp> class heap{
	public:
		std::vector<E> Heap;
		int n = 0;
		Comp comp;
		void swap(std::vector<E> h, int p1, int p2){
			auto temp = Heap[p1];
			Heap[p1] = Heap[p2];
			Heap[p2] = temp;
		}
		void siftdown(int pos){
			while(!isLeaf(pos)){
				int j = leftchild(pos); int rc = rightchild(pos);
				if((rc<n) && comp.prior(Heap[rc], Heap[j])){
				       j = rc;	
				}
				if(comp.prior(Heap[pos], Heap[j])) return;
				swap(Heap, pos, j);
				pos = j;
			}
		}
		heap(){}
		heap(std::vector<E>*  h, int num)
		{ Heap = *h; n = num; buildHeap();}
		int size() const
		{ return Heap.size();}
		bool isLeaf(int pos) const
		{return (pos >= n/2) && (pos < n);}
		int leftchild(int pos) const
		{return 2*pos +1;}
		int rightchild(int pos) const
		{return 2*pos +2;}
		int parent(int pos) const
		{
			return (pos-1)/2;}
		void buildHeap(){
			for(int i = n/2 - 1; i >=0; i--) siftdown(i);
		}
		void insert(const E& it){
			Heap.push_back(it);
			int curr = Heap.size()-1;
			n= Heap.size();
			while((curr!=0) && (comp.prior(Heap[curr], Heap[parent(curr)]))){
				swap(Heap, curr, parent(curr));
				curr = parent(curr);	
			}
		}
		E removefirst(){
			n=Heap.size();
			if(n<=0){
				std::cerr<<"Heap is empty"<<std::endl;
			}
			swap(Heap, 0, --n);
			if(n!= 0) siftdown(0);
			auto i = Heap[n];
			Heap.pop_back();
			return i;
		}

		E remove(int pos){
			if((pos < 0) || (pos >= n)){
				std::cerr<<"Bad position"<<std::endl;
			}
			if(pos == (n-1)) n--;
			else{
				swap(Heap, pos, --n);
				while((pos!= 0) && (comp.prior(Heap[pos], Heap[parent(pos)]))){
				swap(Heap, pos, parent(pos));
				pos = parent(pos);
				}
			
			if (n!=0) siftdown(pos);
			}
			n = Heap.size();
			return Heap[n];
		}
};



#endif
