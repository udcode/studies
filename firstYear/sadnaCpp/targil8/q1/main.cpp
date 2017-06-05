#include <iostream>
#include "List.h"
#include "menu.h"
#include<string>
using namespace std;

int main() {
	List<string> ls1;
    MenuOption choice;

    while ((choice = menu()) != EXIT) {
        string num;
        switch (choice) {
        case ADD:
            cout << "Enter 5 numbers: ";
           /* for (int i = 0; i < 5; i++) {
                cin >> num;
                try{
                    ls1.add(num);
                }catch(const char * s){
                    cerr<<s<<endl;
                }
            }*/
			cin >> ls1;
           ls1.print();
            break;

        case ADD_TO_END:
            cout << "Enter 5 numbers: ";
            for (int i = 0; i < 5; i++) {
                cin >> num;
                ls1.insert(num);
            }
           // ls1.print();

            break;

        case REMOVE_FIRST:
            try{
                ls1.removeFirst();
            }catch(const char * s){
                cerr<<s<<endl;
            }
            break;
        case SEARCH:
            cout << "Enter a number: ";
            cin >> num;
            cout << ls1.search(num) << endl;
            break;

        case CLEAR:
            ls1.clear();
            break;

        case EMPTY:
            if (ls1.isEmpty())
                cout << "Empty" << endl;
            else
                cout << "Not empty" << endl;
            break;

        default:
            cout << "ERROR!" << endl;
        }
    }
    return 0;
}

