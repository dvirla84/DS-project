#ifndef DIRECTEDGRAPH_LIST_H
#define DIRECTEDGRAPH_LIST_H

#include <cstddef>

template <typename T>class ListItem{
public: //put it in private!!!!!
    T _item;
    ListItem<T>* _next;
    ListItem<T>* _previous;
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
    T* pop_front(){
        T* popped = _tail->_item;
        _tail = _tail->previous;
        delete _tail->next;
        _size--;
        return popped;
    }

    void pushFront(const T t) {
        ListItem<T> listItem = new ListItem<T>(t);

        if(!_head){
            _head = listItem;
            _tail = listItem;
        }
        else{
            _head->next = listItem;
            listItem->previous = _head;
            _head = listItem;
        }
        _size++;
    }


    void erase(ListItem<T>* val){
        val->_next->_previous = val->_previous;
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
