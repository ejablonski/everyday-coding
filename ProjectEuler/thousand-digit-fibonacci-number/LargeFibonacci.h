#pragma once

#include <string>
#include "LargeNumber.h"

namespace lf
{
    // _i = number of digits number should have
    int largeFibonacci(int _i)
    {
        ln::LargeNumber a("0");
        ln::LargeNumber b("1");

        int index = 0;

        while(a.number().length() != _i)
        {
            ln::LargeNumber tmp(a.number());

            a = ln::LargeNumber::add(a, b);

            b = tmp;

            index++;
        }

        return index;
    }
}
