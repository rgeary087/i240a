#ifndef DLINK_SEQ_HH_
#define DLINK_SEQ_HH_

#include "seq.hh"

#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>
template <typename E> class Link{ //Link Nodes that holds the data and pointers to the next and previous elements	
	public:
	  E element;
	  Link* next;
	  Link* prev;

	Link(const E& it, Link* prevp, Link* nextp){
	  element = it;
	  next = nextp;
	  prev = prevp;
	}
	Link(Link* prevp = NULL, Link* nextp = NULL){
	   prev = prevp;
	   next = nextp;
	}

};
template <typename E> class DLinkSeqConstIter;
template <typename E>
class DLinkSeq : public Seq<E> {
	private:
	Link<E>* head = NULL;//pointers to the first and last elements of the list
	Link<E>* tail = NULL;
	int length = 0;
	public:
	DLinkSeq(){
		head = tail;
		tail = head;
	}
	static SeqPtr<E> make(){
		return std::make_unique<DLinkSeq<E>>();
	}
	void unshift(const E& item){//adds element to start of the list
		if(head == NULL){
			head = new Link<E>(item, NULL, NULL);
			tail = head;
		}else{
			auto temp = new Link<E>(item, NULL, NULL);
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
		length++;
	}
	E shift(){//removes and returns elements from the start of the list
		if(length == 0){
			std::cerr<<"shift() on empty dlist"<<std::endl;
		}
		if(head == NULL){
			std::cerr<<"LIST IS EMPTY"<<std::endl;
		}
		auto temp = head;
		head = head->next;
		head->prev = NULL;
		length--;
		return temp->element;
		
	}	
	void push(const E& item){//appends an item to the end of the lsit
		if(head == NULL){
			head = new Link<E>(item, NULL, NULL);
			tail = head;
		
		}else{
			auto temp = new Link<E>(item, NULL, NULL);
			tail->next = temp;
			temp->prev = tail;
			tail = temp;

			
		}
		length++;
			
	}
	E pop(){//removes and returns an element from the start of the list
		if(length == 0){
			std::cerr<<"pop() on empty dlist"<<std::endl;
		}
		if(tail == NULL){
			std::cerr<<"LIST IS EMPTY"<<std::endl;
		}
		auto temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		length--;
		return temp->element;
	}
	void clear(){
		head = NULL;
		tail = NULL;
	}
	int size() const{return length;}
	ConstIterPtr<E> cbegin() const{
		const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
		return std::make_unique<DLinkSeqConstIter<E>>(constThis, head);
	}
	ConstIterPtr<E> cend() const{
		const DLinkSeq* constThis = static_cast<const DLinkSeq*>(this);
		return std::make_unique<DLinkSeqConstIter<E>>(constThis,tail);
	}

};
template <typename E>
class DLinkSeqConstIter : public ConstIter<E> {
	public:
		DLinkSeqConstIter(const DLinkSeq<E>* const seq, Link<E>* link):
			seq(seq),
			link(link)
		{}
		DLinkSeqConstIter& operator++(){
			link = link->next;
			return *this;		
		}
		DLinkSeqConstIter& operator--(){
			link = link->prev;
			return *this;
		}
		
		virtual operator bool(){
			return link!=NULL;
		}
		const E& operator*(){
			return link->element;
		}
		const E* operator->(){
			return &link->element;
		}
	private:
		const DLinkSeq<E>* const seq;
		Link<E>* link;
};

#endif 

