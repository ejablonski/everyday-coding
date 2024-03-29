# Simple linked list

Welcome to Simple linked list on Exercism's C++ Track.
If you need help running the tests or submitting your code, check out `HELP.md`.

## Instructions

Write a simple linked list implementation that uses Elements and a List.

The linked list is a fundamental data structure in computer science, often used in the implementation of other data structures.
They're pervasive in functional programming languages, such as Clojure, Erlang, or Haskell, but far less common in imperative languages such as Ruby or Python.

The simplest kind of linked list is a singly linked list.
Each element in the list contains data and a "next" field pointing to the next element in the list of elements.

This variant of linked lists is often used to represent sequences or push-down stacks (also called a LIFO stack; Last In, First Out).

As a first take, lets create a singly linked list to contain integers, and provide functions to reverse a linked list.

When implementing this in a language with built-in linked lists, implement your own abstract data type.

We have provided the general structure of a `List` class for you.
It has the private variables `head` of type `Element*` and `current_size` of type `size_t` that you can use.

The `Element` class was given as well, it has two public variables: `data` of type `int` and `next` of type `Element*`.

You can see the details in `simple_linked_list.h`. You do not have to change that file, but you can if it fits your needs.

The tests use the functions as they are supplied in `simple_linked_list.cpp`, don't change their signature. You can add more functions and members if you want to.

## Can I use smart pointers?

Although the header-file includes raw pointers, you are free to chose a different implementation.

## Source

### Created by

- @vaeng

### Based on

Inspired by 'Data Structures and Algorithms with Object-Oriented Design Patterns in Ruby', singly linked-lists. - https://web.archive.org/web/20160731005714/http://brpreiss.com/books/opus8/html/page96.html