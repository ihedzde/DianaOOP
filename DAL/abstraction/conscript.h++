#ifndef DIANAOOP_CONSCRIPT_H
#define DIANAOOP_CONSCRIPT_H
#include <atomic>
#include "iostream"
#include "string"
using namespace std;
namespace DAL {

    class Conscript {
        static int currentId;
    public:
        int getId() const;

    protected:
        int _id;
        string _surname;
        string _name;
        int _rank;
        int _age;

    public:
        Conscript();

        Conscript(string surname, string name, int rank, int age);

        const string &getSurname() const;

        void setSurname(const string &surname);

        const string &getName() const;

        void setName(const string &name);

        int getRank() const;

        void setRank(int rank);

        int getAge() const;

        void setAge(int age);

        virtual void show()const;

        virtual ~Conscript() = 0;

        friend ostream &operator<<(ostream &os, const Conscript &conscript);
        friend istream &operator>>(istream &is, Conscript& data);
    };

} // DAL

#endif //DIANAOOP_CONSCRIPT_H
