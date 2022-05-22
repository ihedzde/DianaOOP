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
        std::cin >> variant;
        std::cout << "\r" << std::endl;
        return variant;
    }

    void Menu::MockTreeSetup(BinarySearchTree* bst) {
        bst->Insert(new Captain("Spange", "Bob", 30, 5, 4));
        bst->Insert(new Cadet("Heraldin", "Diana", 45, 19, "TheCadetOfAzov"));
        bst->Insert(new Captain("Wonka", "Willy", 15, 89, 4));
        bst->Insert(new Cadet("Arestovich", "Jennet", 10, 49, "AnotherCadet"));
        bst->Insert(new Cadet("Jolly", "Angelina", 19, 56, "MovieCadet"));
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
            }
        } while (variant != 'e');
        delete tree;
    }
} // UI