#include "bank_account.h"

namespace Bankaccount {
  Bankaccount::Bankaccount() : accBalance(0), isOpen(false) {}

  void Bankaccount::open() {
    if(this->isOpen) {
      throw std::runtime_error("Account already open.");
    } else {
      this->isOpen = true;
    }
  }

  void Bankaccount::close() {
    this->checkIfAccIsOpen();
    this->accBalance = 0;
    this->isOpen = false;
  }

  int Bankaccount::balance() {
    this->checkIfAccIsOpen();
    return this->accBalance;
  }

  void Bankaccount::deposit(int _amount) {
    this->checkIfAccIsOpen();
    if(_amount < 0) {
      throw std::runtime_error("Invalid amount");
    } else {
      this->accBalance += _amount;
    }
  }

  void Bankaccount::withdraw(int _amount) {
    this->checkIfAccIsOpen();

    if(_amount > this->accBalance) {
      throw std::runtime_error("Insufficient funds.");
    }
    if(_amount < 0) {
      throw std::runtime_error("Invalid amount.");
    } else {
      this->accBalance -= _amount;
    }
  }

  void Bankaccount::checkIfAccIsOpen() {
    if(!this->isOpen) throw std::runtime_error("Account is not open.");
  }
}
