#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include "l_exception.h"

L_exception::L_exception(int code_, string message_) {
    this -> cod = code_;
    this -> mes = message_;
}

string L_exception::message() const {
    return this -> mes;
}

int L_exception::code() const {
    return this -> cod;
}
