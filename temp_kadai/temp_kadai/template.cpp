#include <iostream>
#include "template.h"

// T Œ^‚Ì”’l‚ğ•\¦‚·‚éŠÖ”‚Ì’è‹`
template<class T>
void disp(T value)
{
    std::cout << value << std::endl;
}

// int Œ^‚Å—˜—p‚·‚é–‚ğ—\‚ß–¾¦‚µ‚Ä‚¨‚­
template void disp<int>(int value);