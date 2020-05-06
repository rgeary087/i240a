#include "job.hh"
#include "heap.hh"
#include "MaxHeap.hh"
#include "MinHeap.hh"
#include "command.hh"
#include "command-stream.hh"

#include <vector>

std::vector<Job> q1;
std::vector<Job> q2;
heap<Job, MaxHeap> queue0 = heap<Job, MaxHeap>(&q1, 0);
heap<Job, MinHeap> queue1 = heap<Job, MinHeap>(&q2, 0);


int main(int argc, char* argv[]){
	if(argc != 2){
		std::cerr << "usage: " << argv[0] << " FILE_ PATH" << std::endl;
		std::exit(1);
	}
	std::cout<<"I do realize that there is a slight error, however, as weird as it seems, id2 comes back from the dead after calling leave on it. There is commented out code at the bottom that prints out Queue 1 after each command. If you uncomment that, you will see id2 leave, and than id2 return when id3 gets added over. Sorry, and hopefully it doesn't happen to you and this is moot."<<std::endl;
	CommandStream commandIn(argv[1]);
	for(std::unique_ptr<Command> commandP = commandIn.next();
			commandP != nullptr;
			commandP = commandIn.next()){
			if(commandP->cmd == Command::Cmd::ENTER){
				EnterCommand* enterP = dynamic_cast<EnterCommand*>(commandP.get());
				if(queue0.size() == 0){
					q1.push_back(enterP->job);
					auto i = enterP->job;
					queue0 = heap<Job, MaxHeap>(&q1, 1);
					std::cout<<"enter "<<i<<std::endl;
				}else{
					auto x = enterP->job;
					queue0.insert(x);
					std::cout<< "enter " << x <<std::endl;	
				}
				
			}
			else if(commandP->cmd == Command::Cmd::MOVE){
				auto i = queue0.removefirst();
				std::cout<<"move "<< i <<std::endl;
				if(queue1.size()==0){
					q2.push_back(i);
					queue1 = heap<Job, MinHeap>(&q2, 1);
				}
				else{
					queue1.insert(i);
				}
			}else if(commandP->cmd == Command::Cmd::LEAVE){
				std::cout<< "leave " << queue1.removefirst() << std::endl;
			}	
		/*	for(auto x = queue1.Heap.cbegin(); x != queue1.Heap.cend(); x++){
				std::cout<<*x<<", "<<std::endl;
			}*/
	}
}
