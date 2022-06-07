#include "menu.h++"

namespace UI {


    char Menu::PrintMenu() {
        char variant;
        std::cout << std::endl;
        std::cout << "Choose please:" << std::endl;
        std::cout << "e. Exit program" << std::endl;
        std::cout << "1. Add new cadet" << std::endl;
        std::cout << "2. Add new captain" << std::endl;
        std::cout << "3. Print all tree" << std::endl;
        std::cout << "4. Print captain subordinates by rank" << std::endl;
        std::cout << "5. Use mock data" << std::endl;
        std::cout << "6. Load from file" << std::endl;
        std::cout << "7. Load in file" << std::endl;
        std::cout << "8. Clean binary tree" << std::endl;
        std::cin >> variant;
        std::cout << "\r" << std::endl;
        return variant;
    }

    void Menu::MockTreeSetup(BinarySearchTree* bst) {
        bst->Insert(new Captain("Sydorov", "Sidr", 15, 30, 4));
        bst->Insert(new Cadet("Ivanov", "Ivan", 8, 22, "2 polk"));
        bst->Insert(new Captain("Petrov", "Petro", 45, 55, 25));
        bst->Insert(new Cadet("Nykolayv", "Nykolay", 1, 21, "2 polk"));
        bst->Insert(new Cadet("Aloxin", "Alixey", 10, 20, "2 polk"));
        bst->Insert(new Cadet("Alexandrov", "Alexandr", 30, 35, "1 polk"));
        bst->Insert(new Cadet("Nikitin", "Nikita", 55, 42, "1 polk"));
        bst->Insert(new Captain("Pavlov", "Pavlo", 31, 43, 14));
        bst->Insert(new Cadet("Valerych", "Valeriy", 13, 28, "3 polk"));
        bst->Insert(new Cadet("Illich", "Illiya", 24, 29, "3 polk"));
    }

    Cadet *Menu::CreateCadet() {
        string firstName;
        string lastName;
        int rank;
        int age;
        string subordinate;
        cout << "First Name:" << endl;
        cin >> firstName;
        cout << "Last Name:" << endl;
        cin >> lastName;
        cout << "Rank:" << endl;
        cin >> rank;
        cout << "Age:" << endl;
        cin >> age;
        cout << "Subordinate:" << endl;
        cin >> subordinate;
        return new Cadet(lastName, firstName, rank, age, subordinate);
    }

    Captain *Menu::CreateCaptain() {
        string firstName;
        string lastName;
        int rank;
        int age;
        int experience;
        cout << "First Name:" << endl;
        cin >> firstName;
        cout << "Last Name:" << endl;
        cin >> lastName;
        cout << "Rank:" << endl;
        cin >> rank;
        cout << "Age:" << endl;
        cin >> age;
        cout << "Years of experience:" << endl;
        cin >> experience;
        return new Captain(lastName, firstName, rank, age, experience);
    }

    void Menu::Dialog() {
        char variant;
        auto *tree = new BinarySearchTree();
        do {
            variant = PrintMenu();
            switch (variant) {
                case '1':
                    tree->Insert(CreateCadet());
                    break;
                case '2':
                    tree->Insert(CreateCaptain());
                    break;
                case '3':
                    tree->PrintTree();
                    break;
                case '4':
                    int rank;
                    cout << "Input captain rank: "<< endl;
                    cin >> rank;
                    tree->PrintChildrenByRank(rank);
                    break;
                case '5':
                    MockTreeSetup(tree);
                    break;
                case '6':
                    tree->LoadFromFile();
                    break;
                case '7':
                    tree->LoadIntoFile();
                    break;
                case '8':
                    delete tree;
                    tree = new BinarySearchTree();
            }
        } while (variant != 'e');
        delete tree;
    }
} // UI