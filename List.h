#ifndef DIRECTEDGRAPH_LIST_H
#define DIRECTEDGRAPH_LIST_H

#include <cstddef>

template <typename T>class ListItem{
private:
    T item;
    T* next;
public:
    ListItem(const T &_item):item(_item),next(NULL){}
};

template <typename T>
class List{
private:
    ListItem<T> *head;
    ListItem<T> *tail;
public:
    List():
        head(NULL),
        tail(NULL)
    {}

    void push(const T &val) {
        ListItem<T> *t = new ListItem<T>(val);
        if(!head){
            head = t;
            tail = t;
        }
        else{
            tail->next = t;
            tail = t;
        }
    }

    T* search(T val) const{
        ListItem<T> *temp = head;
        while(temp)
            if(temp->item == val)
                return temp;
        return NULL;
    }

    void erase(T val){
        ListItem<T> *before = head;
        while(before->next->item != val)
            before = before->next;
        ListItem<T> *ToErase = before->next;
        before->next = ToErase->next;
        delete ToErase;
    }

    unsigned getSize() const{
        size_t counter = 0;
        ListItem<T> *temp = head;
        while(temp->next)
            counter++;
        return counter;
    }
    ~List(){
        ListItem<T> *eraser = head;
        while(eraser != tail){
            ListItem<T> *temp = eraser->next;
            delete eraser;
            eraser = temp;
        }
        delete  eraser;
    }
};


#endif //DIRECTEDGRAPH_LIST_H
