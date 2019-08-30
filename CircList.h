#ifndef CIRC_LIST_H
#define CIRC_LIST_H

#include <iostream>
#include <stdlib.h>
#include <exception>

struct Node{
		Node *next;
		Node *ant;
		int data;
};

struct List{
		Node *first;
		Node *final;
		int size;
};

class cList{
private:
	List *p;
	std::string name;

public:

	void init(){
		p = new List;
		p->first = NULL;
		p->size = 0;
	}

	cList(std::string tname){
		init();
		name = tname;
	}

	cList(){
		init();
	}



	~cList(){
		delete[] p;
	}

	int Insert(int key){
		Node *n = new Node;
		n->data = key;

		if(p->first == NULL){
			n->ant   = n;
			n->next  = n;
			p->first = n;
			p->size++;
		}

		else{
			Node *aux = p->first;

			while(aux->next != p->first){
				aux = aux->next;
			}

			aux->next 		= n;
			p->final		= aux->next;
			p->final->ant	= aux;
			p->final->next 	= p->first;
			p->first->ant 	= p->final;
			p->size++;
		}

		return 1;

	}

	bool isEmpty(){
		return p->size == 0 ?  true :  false; 
	}

	int Remove(int key){
		if(isEmpty()){
			throw std::logic_error("Cannot remove elements of an empty List");
		}

		int c   = p->size;
		Node *n = p->first;
		if(n->data == key){
			p->first = p->first->next;
			p->first->ant = p->final;
			p->final->next =  p->first;
			p->size--;
		}

		else{
			for(int i = 0; i < p->size; i++){
				Node *aux = n;
				
				if(n->next->data == key){
					n->next = n->next->next;
					n->next->next->ant = aux;
					p->size--;
				}

			}

		}

		if(c == p->size){
				std::cout<<"Number '"<<key<<"' isn't found in List"<<std::endl;

		}

		return 1;	

	}

	int getSize(){
		return p->size;
	}

	void setName(std::string tname1){
		name = tname1;
	}

	std::string getName(){
		return name;
	}

	void show(){
		Node *n = p->first;
		std::cout<<name<<" [ ";
		for(int i = 0; i < p->size; i++){
			std::cout<<n->data<<", ";
			n = n->next;
		}

		std::cout<<"\b\b ]"<<std::endl;

	}

	void RemoveIndex(int n){
		int x = n % p->size;

		Node *aux = p->first;

		for(int i=0; i<x; i++){
			aux = aux->next;
		}

		Remove(aux->data);

	}

	int Josephus(int Num_Jumps){
		Node *n    = p->first;
		if(isEmpty()){
			throw std::range_error("Invalid number of soldiers");
		}

		while(n->next != n){
			srand(time(NULL));
			
			int jumps = rand() % Num_Jumps;

			for(int i = 1; i<=jumps; i++){
				Node *aux = n;
				n = n->next;				
				if(i == jumps){
					n->next 			= n->next->next;
					n->next->next->ant  = aux;
					p->size--;
				}

				n = n->next;	
			}	

			
		}

		p->first = n;
		return p->first->data;
	}

};

#endif