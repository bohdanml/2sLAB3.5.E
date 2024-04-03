#pragma once

#include "Pair.h"

class Rational : public Pair {
public:
    using Pair::Pair; 

    
    Rational(int a, int b) : Pair(a, b) {}
    Rational() : Pair(0, 1) {}
    Rational(const Rational& other) : Pair(other) {}

    
    Rational operator+(const Rational& other) const {
        return Rational(getFirst() * other.getSecond() + getSecond() * other.getFirst(),
            getSecond() * other.getSecond());
    }

    Rational operator-(const Rational& other) const {
        return Rational(getFirst() * other.getSecond() - getSecond() * other.getFirst(),
            getSecond() * other.getSecond());
    }

    Rational operator/(const Rational& other) const {
        return Rational(getFirst() * other.getSecond(), getSecond() * other.getFirst());
    }

    
    Rational& operator=(const Rational& other) {
        Pair::operator=(other);
        return *this;
    }

    
    friend std::istream& operator>>(std::istream& is, Rational& rational) {
        is >> static_cast<Pair&>(rational);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& rational) {
        os << static_cast<const Pair&>(rational);
        return os;
    }

    
    operator std::string() const {
        return std::string(static_cast<const Pair&>(*this));
    }

    
    Rational& operator++() {
        Pair::operator++();
        return *this;
    }

    Rational operator++(int) {
        Rational temp(*this);
        Pair::operator++();
        return temp;
    }

    Rational& operator--() {
        Pair::operator--();
        return *this;
    }

    Rational operator--(int) {
        Rational temp(*this);
        Pair::operator--();
        return temp;
    }
};
