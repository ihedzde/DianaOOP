//
// Created by Ivan Hedz on 17.05.2022.
//

#ifndef DIANAOOP_CAPTAIN_H
#define DIANAOOP_CAPTAIN_H

#include <ostream>
#include "../abstraction/conscript.h++"
#include "istream"
#include "string"
using namespace std;
namespace DAL {

    class Captain: public Conscript{
    private:
        int experience;
    public:
        Captain();

        Captain(const string &surname, const string &name, int rank, int age, int experience);

        friend ostream &operator<<(ostream &os, const Captain &captain);
        friend istream &operator>>(istream &is, Captain &data);
    public:
        void show() const override;
        ~Captain() override = default;
    };

} // DAL

#endif //DIANAOOP_CAPTAIN_H
