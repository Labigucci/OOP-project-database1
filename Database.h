// Copyright [2021] <Sean Adin, Krzysztof Hoszowski>
// Lab 4

#if !defined (DATABASE__H)
#define DATABASE__H

#include <ostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

bool is_number_in_range_inclusive(double number, double mini, double maxi)
    { return ( (number - mini) * (maxi - number) >= 0 ) ? true : false; }

class Book {
 private:
    string author;
    bool hardcover;
    float pricetag;
    string title;
    char commonletter;

 public:
    /*      Con-, Destructors     */
    Book();
    Book(const string &a, bool h, float p, const string &t, char c);
    ~Book() = default;

    /*      Getters     */
    char get_commonletter() const { return commonletter; }

    /*      Misc     */
    void ostream_Book(std::ostream &, string delimiter) const;
    void set_Book(string, bool, float, string, char);
};

class Library {
 private:
    vector<Book> shelf;
    string library_name = "Library";

 public:
    /*      Con-, Destructors     */

    Library() = default;
    ~Library() = default;

    /*      Getters     */
    string get_library_name() const { return library_name; }
    int get_size() const { return shelf.size(); }
    int get_max_size() const { return shelf.max_size(); }
    Book access_on_Shelf_Book(int book_index) const
        { return shelf[book_index]; }

    /*      Misc     */
    void add_Book(const Book &book) { shelf.push_back(book); }
    void remove_Book(int position_on_shelf) { shelf.erase(shelf.begin()+position_on_shelf); }
};

#endif  // DATABASE__H
