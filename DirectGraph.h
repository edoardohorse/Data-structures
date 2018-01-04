#pragma once

#include "ListPointer.h"
#include <stdexcept>

using namespace NListPointer;



namespace NDirectGraph{

	typedef int Node;


	template<int MaxLength>
	class Graph{
	public:
		Graph();
		bool isEmpty();
		void insertNode(Node);
		void insertLink(Node, Node);
		void removeNode(Node);
		void removeLink(Node, Node);
		bool hasNode(Node);
		bool hasLink(Node, Node);
		ListPointer<Node>* adjacent(Node) const;
	private:
		ListPointer<Node>* graph[MaxLength];
		int nNodes = 0;
	};

	template<int MaxLength>
	Graph<MaxLength>::Graph() {
		for(int i=0;i<MaxLength;i++){
			graph[i] = nullptr;
		}
	}

	template<int MaxLength>
	bool Graph<MaxLength>::isEmpty() {
		return nNodes == 0;
	}

	template<int MaxLength>
	void Graph<MaxLength>::insertNode(Node n) {
		if(n > MaxLength){
			throw std::invalid_argument("Overflow of array");
		}

		if( graph[n] == nullptr ){
			graph[n] = new ListPointer<Node>;
		}

		Position<Node> first = graph[n]->first();
		if( graph[n]->isEmpty() ){           // if the node n doesn't exist yet
			graph[n]->insert(first,n);
		}

		nNodes++;
	}

	template<int MaxLength>
	void Graph<MaxLength>::insertLink(Node attachedTo, Node toLink) {
		bool alreadyLinked = false;
		ListPointer<Node>* p = graph[attachedTo];          // helper
		Position<Node> tmp = p->first();

		if(p->get(tmp) == attachedTo)           // if the value is equal to its index
			p->remove(tmp);                     // means that node hasn't links attached to

		while( !p->isLast( tmp )){                          // go to the end of list
			if( p->get( tmp ) == toLink ){                  // if the node 'attachedTo' is already linked to the
				alreadyLinked = true;                       // node 'toLink', set a flag true
				break;
			}
			tmp = p->next(tmp);
		}
		if( !alreadyLinked )                                // if the flag is false (not linked yet), append
			p->insert(tmp, toLink);          // at the end of the list the node 'toLink'
	}

	template<int MaxLength>
	bool Graph<MaxLength>::hasNode(Node n) {
		ListPointer<Node>* p = graph[n];
		return p != nullptr;
	}

	template<int MaxLength>
	bool Graph<MaxLength>::hasLink(Node attachedTo, Node linked) {
		ListPointer<Node>* p = graph[attachedTo];          // helper
		Position<Node> tmp = p->first();
		while( !p->isLast( tmp ) ){                         // go to the end of list
			if( p->get(tmp) == linked ){                    // if the link already exist return true
				return true;
			}
			tmp = p->next(tmp);
		}

		return false;                                       // else false
	}

	template<int MaxLength>
	void Graph<MaxLength>::removeNode(Node n) {
		delete graph[n];
		graph[n] = nullptr;
	}

	template<int MaxLength>
	void Graph<MaxLength>::removeLink(Node attachedTo, Node linked) {
		ListPointer<Node>* p = graph[attachedTo];          // helper
		Position<Node> tmp = p->first();
		while( !p->isLast( tmp ) ){                         // go to the end of list
			if( p->get(tmp) == linked ){                    // if the link exist return it
				p->remove(tmp);
				break;
			}
			tmp = p->next(tmp);
		}

		Position<Node> first = p->first();
		if( p->isEmpty() ){
			p->insert(first,attachedTo);
		}
	}

	template<int MaxLength>
	ListPointer<Node>* Graph<MaxLength>::adjacent(Node n) const{
		return graph[n];
	}




}




/*	template<typename TypeCost>
	class Link{
	private:
		TypeCost cost;
		Node* adjacent;
		Link* nextNode;
	public:
		TypeCost getCost() const {return cost;}
		void setCost(TypeCost cost) {Link::cost = cost;}
		Node* getAdjacent() const {return adjacent;}
		void setAdjacent(Node* adjacent) {Link::adjacent = adjacent;}
		Link* getNextNode() const {return nextNode;}
		void setNextNode(Link* nextNode) {Link::nextNode = nextNode;}
	};

	template <typename TypeElem>
	class Node{
	private:
		TypeElem label;
		Node* next;
		Link* adjacent;
	public:
		TypeElem getLabel() const {return label;}
		void setLabel(TypeElem label) {Node::label = label;}
		Node* getNext() const {return next;}
		void setNext(Node* next) {Node::next = next;}
		Link* getAdjacent() const {return adjacent;}
		void setAdjacent(Link* adjacent) {Node::adjacent = adjacent;}

	};

	template <typename TypeElem, typename TypeCost>
	class Graph{
	public:

		bool isEmpty();
		void insertNode(Node);
		void insertLink(Node, Node);
		void removeNode(Node);
		void removeLink(Node, Node);
//		NListPointerTest::ListPointer getAdjacent(Node);
		bool hasNode(Node);
		bool hasLink(Node, Node);

		TypeElem getNode(Node);
		void setNode(Node, TypeElem);


		void getLink(Node);
		void setLink(Node);


	private:
		Node<TypeElem>* graph = nullptr;
	};

	template<typename TypeName, typename TypeCost>
	bool Graph<TypeName, TypeCost>::isEmpty() {
		return graph == nullptr;
	}

	template<typename TypeElem, typename TypeCost>
	void Graph<TypeElem, TypeCost>::insertNode(Node e) {

	}*/