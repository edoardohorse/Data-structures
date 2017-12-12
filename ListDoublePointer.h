#pragma once

namespace NListDoublePointer{

    template<typename TypeElem>
    class ListDoublePointer;

    template<typename TypeElem>
    class Node{
    private:
        TypeElem value;
        Node* next;
        Node* previous;
        friend class ListDoublePointer<TypeElem>;
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

        Position next(Position<TypeElem>);

        Position previous(Position<TypeElem>);

        TypeElem get(Position<TypeElem>);

        void set(Position<TypeElem>, TypeElem);

        void insert(Position<TypeElem>, TypeElem);

        void remove(Position<TypeElem>);

    private:
        typedef Position<TypeElem> List;
        List ls;

    };

    template<typename TypeElem>
    ListDoublePointer<TypeElem>::ListDoublePointer() {
        ls = new Node<TypeElem>;
        ls->next = ls->previous = nullptr;
    }

    template<typename TypeElem>
    ListDoublePointer<TypeElem>::~ListDoublePointer() {
        Position<TypeElem> tmp = first();
        while(!isLast(tmp)){
            Position<TypeElem> p = tmp;
            tmp = next(tmp);
            delete p;
        }
        delete ls;
    }

    template<typename TypeElem>
    bool ListDoublePointer<TypeElem>::isEmpty() {
        return (ls->next == nullptr);
    }

    template<typename TypeElem>
    Position<TypeElem> ListDoublePointer<TypeElem>::first() {
        return ls->next;
    }

    template<typename TypeElem>
    bool ListDoublePointer<TypeElem>::isLast(Position<TypeElem> p) {
        return (p->next == nullptr);
    }

    template<typename TypeElem>
    Position<TypeElem> ListDoublePointer<TypeElem>::next(Position<TypeElem> p) {
        return p->next;
    }

    template<typename TypeElem>
    Position<TypeElem> ListDoublePointer<TypeElem>::previous(Position<TypeElem> p) {
        return p->previous;
    }

    template<typename TypeElem>
    TypeElem ListDoublePointer<TypeElem>::get(Position<TypeElem> p) {
        return p->value;
    }

    template<typename TypeElem>
    void ListDoublePointer<TypeElem>::set(Position<TypeElem> p, TypeElem e) {
        p->value = e;
    }

    template<typename TypeElem>
    void ListDoublePointer<TypeElem>::insert(Position<TypeElem> p, TypeElem e) {
        Position<TypeElem> newNode = new Node<TypeElem>;
        newNode->value = e;
        newNode->next = p;
        if(ls->next == p){
            ls->next = newNode;
            newNode->previous = nullptr;
        }
        else{
            p->previous->next = newNode;
            newNode->previous = p->previous;
            p->previous = newNode;
        }
        p = newNode;
    }

    template<typename TypeElem>
    void ListDoublePointer<TypeElem>::remove(Position<TypeElem> p) {
        if(ls->next == p){
            ls->next = p->next;
            ls->next->previous = nullptr;
        }
        else{
            p->previous->next = p->next;
            p->next->previous = p->previous;
        }

        delete p;
    }

}