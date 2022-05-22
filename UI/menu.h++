#ifndef DIANAOOP_MENU_H
#define DIANAOOP_MENU_H
#include "../Container/binarySearchTree.h++"
#include "../DAL/abstraction/conscript.h++"
#include "../DAL/implementation/cadet.h++"
#include "../DAL/implementation/captain.h++"
using namespace DAL;
using namespace Container;
namespace UI {

    class Menu {
    public:
        static char PrintMenu();

        static void MockTreeSetup(BinarySearchTree * bst);

        static Cadet *CreateCadet();
        static Captain *CreateCaptain();
        static void Dialog();

    };

} // UI

#endif //DIANAOOP_MENU_H
