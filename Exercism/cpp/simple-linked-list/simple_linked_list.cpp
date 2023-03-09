#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {
  size_t List::size() {
    size_t count = 0;
    Element* current = head;

    while (current != nullptr) {
      count++;
      current = current->next;
    }

    return count;
  }

  void List::push(int data) {
    Element* e = new Element(data);
    e->next = this->head;
    this->head = e;
  }

  int List::pop() {
    int data = this->head->data;

    Element* e = this->head;
    this->head = this->head->next;
    delete e;

    return data;
  }

  void List::reverse() {
    Element* current = this->head;
    Element* prev = nullptr, *next = nullptr;

    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    this->head = prev;
  }

  List::~List() {
    Element* current = this->head;
    Element* next = nullptr;
 
    while (current != nullptr) {
      next = current->next;
      free(current);
      current = next;
    }

    this->head = nullptr;
  }
}  // namespace simple_linked_list
