#pragma once
#include "llist.h"

template <class T>
class queue{
public:
    typedef T value_type;
private:
    List<value_type> list;

public:
    queue(){}
    ~queue(){}

    void push(value_type val){
        list.push_back(val);
    }

    void pop(){
        list.pop_front();
    }

    value_type back(){
        return list.back();
    }

    value_type front(){
        return list.front();
    }

    size_t size(){
        return list.size();
    }

    bool empty(){
        return list.empty();
    }
};
