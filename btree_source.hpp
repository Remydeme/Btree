//
//  btree_source.hpp
//  btree
//
//  Created by remy DEME on 25/04/2017.
//  Copyright © 2017 remy DEME. All rights reserved.
//

#pragma once 

template <typename T>
struct node
{
    node(T value, node<T>* l, node<T> * r) :
    value(value), r(r), l(l)
    {}
    node() = default;
    node<T>& operator = (node<T>& node) = default;
    node<T>& operator = (node<T>&& node) = default;
    T value = 0;
    node<T> * r = nullptr;
    node<T> * l = nullptr;
};

template <typename T>
class Btree
{
    public:
    
    using node_t = struct node<T>;
    using node_p = node_t **;
    
    Btree() = default;
    
    /* Add an element in the btree */
    void add(T);
    /* add a new node in the btree */
    void add(node_t *);
    /* can remove an element from the btree only if exist */
    /* recursive add fucntion */
    void add_func(T , node_t *);
    /* add a node to the btree*/
    void add_func(node_t * value, node_t *);
    
    bool remove(T);
    /* If the the eleement exist in the btree return true else false*/
    bool exist(T);
    /* postfix */
    void postfix();
    
    /*prefix */
    void prefix();
    
    /* display */
    void display();
    
    private:
    
    void display_func(node_t *);
    void postfix_func(node_t* );
    void prefix_func(node_t* );
    
    private :
    
    long size_ = 0;
    node_t *btree_ = new node_t();
};

#include "btree.hxx"
