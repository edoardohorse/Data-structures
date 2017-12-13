#pragma once

namespace NListDoublePointerTest{

    template<typename TypeElem>
    class Node{
    public:
        TypeElem getValue(){return value;}
        void setValue(TypeElem value){Node::value = value;}
        Node* getNext(){return next;}
        void setNext(Node* next){Node::next = next;}
        Node* getPrevious(){return previous;}
        void setPrevious(Node* previous){Node::previous = previous;}

    private:
        TypeElem value;
        Node* next = nullptr;
        Node* previous = nullptr;
    };


    template<typename TypeElem>
    using Position = Node<TypeElem>*;

    template<typename TypeElem>
    class ListDoublePointer{
    public:
        ListDoublePointer();

        ~ListDoublePointer();

        bool isEmpty();

        Position<TypeElem> first();

        bool isLast(Position<TypeElem>);

        Position<TypeElem> next(Position<TypeElem>);

        Position<TypeElem> previous(Position<TypeElem>);

        TypeElem get(Position<TypeElem>);

        void set(Position<TypeElem>, TypeElem);

        void insert(Position<TypeElem>&, TypeElem);

        void remove(Position<TypeElem>&);

    private:
        typedef Position<TypeElem> List;
        List ls;

    };

    template<typename TypeElem>
    ListDoublePointer<TypeElem>::ListDoublePointer(){
        ls = new Node<TypeElem>;
        ls->setNext(nullptr);
        ls->setPrevious(nullptr);
    }

    template<typename TypeElem>
    ListDoublePointer<TypeElem>::~ListDoublePointer(){
        Position<TypeElem> tmp = first();
        while(!isLast(tmp)){
            Position<TypeElem> p = tmp;
            tmp = next(tmp);
            delete p;
        }
        delete ls;
    }

    template<typename TypeElem>
    bool ListDoublePointer<TypeElem>::isEmpty(){
        return (ls->getNext() == nullptr);
    }

    template<typename TypeElem>
    Position<TypeElem> ListDoublePointer<TypeElem>::first(){
        return ls->getNext();
    }

    template<typename TypeElem>
    bool ListDoublePointer<TypeElem>::isLast(Position<TypeElem> p){
        return (p == nullptr);
    }

    template<typename TypeElem>
    Position<TypeElem> ListDoublePointer<TypeElem>::next(Position<TypeElem> p){
        return p->getNext();
    }

    template<typename TypeElem>
    Position<TypeElem> ListDoublePointer<TypeElem>::previous(Position<TypeElem> p){
        return p->getPrevious();
    }

    template<typename TypeElem>
    TypeElem ListDoublePointer<TypeElem>::get(Position<TypeElem> p){
        return p->getValue();
    }

    template<typename TypeElem>
    void ListDoublePointer<TypeElem>::set(Position<TypeElem> p, TypeElem e){
        p->setValue(e);
    }

    template<typename TypeElem>
    void ListDoublePointer<TypeElem>::insert(Position<TypeElem>& p, TypeElem e){
        Position<TypeElem> newNode = new Node<TypeElem>;
        newNode->setValue(e);
        newNode->setNext(p);

        if(ls->getNext() == p){
            ls->setNext(newNode);
	        if(p!= nullptr){
		        p->setPrevious(newNode);
	        }
        }
        else{
            Position<TypeElem> tmp = first();
            if(p == nullptr){
                while (next(tmp) != p){
                    tmp = next(tmp);
                }
            }
            else
                tmp = p;
			newNode->setNext(tmp->getNext());
            tmp->setNext(newNode);
	        newNode->setPrevious(tmp);
        }

        p = newNode;
    }

    template<typename TypeElem>
    void ListDoublePointer<TypeElem>::remove(Position<TypeElem>& p){
        Position<TypeElem> toRemove = p;

        if(ls->getNext() == toRemove){
            ls->setNext( toRemove->getNext() );
            ls->getNext()->setPrevious(nullptr);
        }
        else{
            toRemove->getPrevious()->setNext( toRemove->getNext() );
            toRemove->getNext()->setPrevious( toRemove->getPrevious() );
        }
        p = toRemove->getNext();
        delete toRemove;
    }

}