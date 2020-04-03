#ifndef COUNTER_HH_
#define COUNTER_HH_

class Counter : public Ops{
	public:
		int compc = 0;
		int swapc = 0;
		int compare(int a, int b){
			compc++;
			return Ops::compare(a,b);
		}	
		void swap(int a[], int i, int j){
			swapc++;
			return Ops::swap(a,i,j);
		}
};
#endif
