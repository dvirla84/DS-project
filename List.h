#ifndef DIRECTEDGRAPH_LIST_H
#define DIRECTEDGRAPH_LIST_H

#include <cstddef>

template <typename T>class ListItem{
public: //put it in private!!!!!
    T _item;
    T* _next;
    T* _previous;
    ListItem(const T &_item):_item(_item),_next(NULL),_previous(NULL){};
};

template <typename T>
class List{
private:
    ListItem<T> *_head;
    ListItem<T> *_tail;
    unsigned _size;
public:
    List():
        _head(NULL),
        _tail(NULL),
        _size(0)
    {}
    T* pop(){
        T* popped = _tail->_item;
        _tail = _tail->previous;
        delete _tail->next;
        _size--;
        return popped;
    }

    void push(const T t) {
        ListItem<T> listItem;

        if(!_head){
            _head = t;
            _tail = t;
        }
        else{
            _tail->next = t;
            t->previous = _tail;
            _tail = t;
        }
        _size++;
    }


    void erase(ListItem<T>* val){
        val->previous->next = val->next;
        delete val;
        _size--;
    }

    unsigned getSize() const{
        return _size;
    }
    ~List(){
        ListItem<T> *eraser = _head;
        while(eraser != _tail){
            ListItem<T> *temp = eraser->next;
            delete eraser;
            eraser = temp;
        }
        delete  eraser;
    }
};


#endif //DIRECTEDGRAPH_LIST_H
