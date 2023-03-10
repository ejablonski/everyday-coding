#pragma once

#include <atomic>
#include <stdexcept>

namespace Bankaccount {
  class Bankaccount {
  public:
    Bankaccount();

    void open();
    void close();
    int balance();
    void deposit(int);
    void withdraw(int);

  private:
    std::atomic_int accBalance;
    bool isOpen;

    void checkIfAccIsOpen();
  };  // class Bankaccount
}  // namespace Bankaccount
