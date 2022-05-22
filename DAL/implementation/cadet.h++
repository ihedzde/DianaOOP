//
// Created by Ivan Hedz on 17.05.2022.
//

#ifndef DIANAOOP_CADET_H
#define DIANAOOP_CADET_H
#include "iostream"
#include "string"
#include "../abstraction/conscript.h++"

using namespace std;
namespace DAL {

    class Cadet: public Conscript{
    private:
        string _subordinate;
    public:
        const string &getSubordinate() const;

        void setSubordinate(const string &subordinate);

        Cadet(const string &surname, const string &name, int rank, int age, string subordinate);

        Cadet();

        void show() const;

        friend ostream &operator<<(ostream &os, const Cadet &cadet);
        friend istream &operator>>(istream &is, Cadet &data);
        ~Cadet() = default;

    };

} // DAL

#endif //DIANAOOP_CADET_H
