//
//  btree.h
//  btree
//
//  Created by remy DEME on 26/04/2017.
//  Copyright © 2017 remy DEME. All rights reserved.
//

#pragma once

#include <iostream>
#include "btree_source.hpp"



template <typename T>
void Btree<T>::add(T value)
{
    if (!size_)
        btree_->value = value;
    else
        add_func(value, btree_);
     size_++;
}

template <typename T>
void Btree<T>::add(node_t *value)
{
    if (!size_)
        btree_ = value;
    else
        add_func(btree_, value);
    size_++;
}


template <typename T>
void Btree<T>::add_func(T value, node_t * node)
{
    if (node->value < value && node->r == nullptr)
        node->r = new node_t(value, nullptr, nullptr);
    else if (node->value > value && node->l == nullptr)
        node->l = new node_t(value, nullptr, nullptr);
    else if (node->value > value)
        add_func(value, node->l);
    else
        add_func(value, node->r);
    return;
    
}


template <typename T>
void Btree<T>::add_func(node_t *value, node_t * node)
{
    if (node->value < value->value && node->r == nullptr)
        node->r = value;
    else if (node->value > value->value && node->l == nullptr)
        node->l =  value;
    else if (node->value > value->value)
        add_func(value, node->l);
    else
        add_func(value, node->r);
    return;
    
}


template <typename T>
void Btree<T>::postfix()
{
    postfix_func(btree_);
}

template <typename T>
void Btree<T>::prefix()
{
    prefix_func(btree_);
}

template <typename T>
void Btree<T>::display()
{
    display_func(btree_);
}


template <typename T>
void Btree<T>::prefix_func(node_t * node)
{
    if (!node)
        return;
    prefix(node->l);
    prefix(node->r);
    std::cout << node->value << " ";
}

template <typename T>
void Btree<T>::postfix_func(node_t * node)
{
    if (!node)
        return;
    display(node->l);
    std::cout << node->value << " ";
    display(node->r);
}

template <typename T>
void Btree<T>::display_func(node_t * node)
{
    if (!node)
        return;
    std::cout << node->value << " ";
    display_func(node->l);
    display_func(node->r);
}


