// Copyright [2021] <Sean Adin, Krzysztof Hoszowski>
// Lab 4

// #include <string>
// #include <iostream>
// #include <vector>
#include <fstream>      // std::ifstream, std::ofstream

#include "Database.hpp"


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*      Initialization     */
    ifstream infile;

    infile.open("data_in.txt");
    if (!infile) {
        cerr << "There was a problem opening the infile.\n\n";
        return -1;
    }

    infile.close(); infile.open("data_in.txt");

    string a;
    bool h;
    float p;
    string t;
    char c;
    Book b;
    Library l0;

    while (infile >> a >> h >> p >> t >> c) {
        b.set_Book(a, h, p, t, c);
        l0.add_Book(b);
    }

    infile.close();

    /*      Main Loop     */
    int key = 1;
    string line = "__________________________________";

    while (key != 27) {  // Main program loop
        cout << line << "\n\n";

        cout << "Welcome to the " << l0.get_library_name() << ".\n\n"

             << "Press 1 to insert data\n"
             << "Press 2 to access a specific data\n"
             << "Press 3 to remove data\n"
             << "Press 4 to get current number of records\n"
             << "Press 5 to get maximal number of records\n\n"

             << "To exit, press escape (key no 27).\n\n";

        cout << "Selection: " << flush;
        cin >> key; cout << '\n';

        switch (key) {
            case 1: {
                int amount;
                string name;
                bool cover;
                float price;
                string title;
                char letter;

                cout << "How many books would you like to insert?: " << flush;
                cin >> amount; cout << '\n';

                for (; amount > 0; --amount) {
                        cout << "Please enter the book: " << flush;
                        cin >> name >> cover >> price >> title >> letter;
                        Book b(name, cover, price, title, letter);
                        l0.add_Book(b);
                    }
                } break;

            case 2: {
                int book_index;
                cout << "Which book (index) would you like to check?: "
                     << flush;
                cin >> book_index; cout << '\n';

                l0.access_on_Shelf_Book
                    (book_index).ostream_Book(cout, ";");
            } break;

            case 3: {
                int position_on_shelf;
                cout << "Which book (index) would you like to remove?: "
                << flush;
                cin >> position_on_shelf;  cout << '\n';

                l0.remove_Book(position_on_shelf);
            } break;

            case 4: {
                cout << "As for now the number of occupied records is: "
                     << l0.get_size() << "\n\n";
            } break;

            case 5: {
                cout << "The maximal number of occupied records is: "
                     << l0.get_max_size()  << "\n\n";
            } break;
        }
    }

    /*      Exporting     */

    cout << "Would you like to export the database to a file? "
         << "If yes, please type 'y': " << flush;
    cin.ignore();
    if (cin.get() == 'y') {
        ofstream outfile;
        outfile.open("data_out.txt");

        for (int i = 0; i != l0.get_size(); ++i) {
            l0.access_on_Shelf_Book(i).ostream_Book(outfile);
        }

        outfile.close();
    }

    return 0;
}
