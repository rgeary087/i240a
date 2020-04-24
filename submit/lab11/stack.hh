#ifndef STACK_HH_
#define STACK_HH_

class Stack{
	private:
		int arr[16];
		int loc = 0;
	public:
		int pop() {
			return arr[--loc];
		}
		void push(int a) {
			arr[loc++] = a;
		}
		int size(){
			return loc;
		}
};
#endif
