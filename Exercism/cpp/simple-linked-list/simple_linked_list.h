#pragma once

#include <cstddef>

namespace simple_linked_list {
  class Element {
  public:
    Element(int data) : data{data} {};
    int data{};
    Element* next{nullptr};
  };

  class List {
  public:
    List() = default;
    ~List();

    size_t size();
    void push(int);
    int pop();
    void reverse();

  private:
    Element* head{nullptr};
  };
}  // namespace simple_linked_list
