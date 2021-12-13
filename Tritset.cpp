//
// Created by mrxat on 13.12.2021.
//

#include "Tritset.h"


Tritset::Tritset(unsigned int size) {
    container.resize(size/TRIT_IN_UINT+1);
    amount = size;
}

Tritset::Tritset(const Tritset &set) {
    container = set.container;
    amount = set.amount;
}

size_t Tritset::getsize() const {
    return amount;
}

void Tritset::resize(unsigned int size) {
    container.resize(size/TRIT_IN_UINT+1);
    amount = size;
}


//Tritset::ProxyTrit &Tritset::operator[](unsigned int index) {
//
//}

Tritset::ProxyTrit::ProxyTrit(Tritset &set, size_t _index) {
    if (_index > set.amount || set.container.empty()) {
        index = -1;
    }
    else{
        *smallSet = set.container[_index / TRIT_IN_UINT];
        index = _index % TRIT_IN_UINT;
    }

}



Tritset::ProxyTrit::operator Trit() const {
    if (index == -1){
        return U;
    }
    if (*smallSet & (TRUE_BIT_MASK << index*2)){
        return T;
    }
    if (*smallSet & (FALSE_BIT_MASK << index*2)){
        return F;
    }
    return U;
}

Tritset::ProxyTrit &Tritset::ProxyTrit::operator=(Trit trit) {

}



Tritset::ProxyTrit& Tritset::operator[](unsigned int index) {
    return ProxyTrit(&container[index/TRIT_IN_UINT], index);

}

