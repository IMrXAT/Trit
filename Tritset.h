//
// Created by mrxat on 13.12.2021.
//

#ifndef MAYBE_NOW_TRITSET_H
#define MAYBE_NOW_TRITSET_H
#include <iostream>
#include <vector>
#define TRIT_IN_UINT (sizeof(uint)*4)
#define FALSE_BIT_MASK 0b01
#define TRUE_BIT_MASK 0b11
enum Trit{
    U = 0, F = 1, T = 2
};

class Tritset {
public:
    class ProxyTrit{
    private:
        //Tritset &tritSet;
        uint* smallSet;
        size_t index;
    public:
        ProxyTrit(uint* set, size_t _index) : smallSet(set), index(_index) {}
        ProxyTrit(Tritset &set, size_t index);
        //ProxyTrit(uint set, size_t index);
        explicit operator Trit() const;

        ProxyTrit& operator=(Trit trit);
    };

private:
    std::vector<uint> container;
    size_t amount;
public:
    explicit Tritset(unsigned int size);
    Tritset(const Tritset& set);

    size_t getsize() const;
    void resize(unsigned size);

    ProxyTrit& operator[](unsigned int index);
    Tritset &operator=(const Tritset &set);
    Tritset &operator&(Tritset &set);
    Tritset &operator|(Tritset &set);
    Tritset &operator~();

    friend std::ostream &operator<<(std::ostream& out, const ProxyTrit& proxyTrit);
};


#endif //MAYBE_NOW_TRITSET_H
