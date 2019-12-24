#ifndef DIRECTEDGRAPH_LIST_H
#define DIRECTEDGRAPH_LIST_H

#include <cstddef>

template <typename T>class ListItem{
    template <typename U> friend class List;
private: //put it in private!!!!!
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
    // need to implement search

    T popFront(){
        if(_size == 0) return -1;
        T popped = _head->_item;
        ListItem<T>* temp = _head->_previous;
        _size--;
        delete _head;
        _head = temp;
        return popped;
    }

    void pushFront(const T t) {
        ListItem<T> *listItem = new ListItem<T>(t);
        if(_size == 0){
            _head = listItem;
            _tail = listItem;
        }
        else{
            _head->_next = listItem;
            listItem->_previous = _head;
            _head = listItem;
        }
        _size++;
    }
    void pushBack(const T t)
    {
        ListItem<T> *listItem = new ListItem<T>(t);
        if (_size == 0 )
        {
            _head = listItem;
            _tail = listItem;
        }
        else
        {
            listItem->_next = _tail;
            _tail->_previous = listItem;
            _tail = listItem;
        }
        _size ++;
    }
    T popBack ()
    {
        if (_size == 0) return -1;
        else
        {
            T popped = _tail->_item;
            ListItem<T>* temp = _tail->_next;
            _size --;
            delete _tail;
            _tail = temp;
            return popped;
        }
    }

// not working
    void erase(ListItem<T>* val)
    {

        if(val->_next!= NULL) val->_next->_previous = val->_previous;
        else{
            _head = val->_previous;
            _head->_next = NULL;
        }
        if (val->_previous!= NULL) val->previous->next = val->next;
        else
            {
            _tail = val->_next;
            _tail->_previous = NULL;
        }
        delete val;
        _size--;
    }


    unsigned getSize() const{
        return _size;
    }

    ~List(){
        ListItem<T> *eraser = _head;
        while(eraser != _tail){
            ListItem<T> *temp = eraser->_previous;
            delete eraser;
            eraser = temp;
        }
        if(eraser != NULL) delete  eraser;
    }

};



#endif //DIRECTEDGRAPH_LIST_H
