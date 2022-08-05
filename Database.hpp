// Copyright [2021] <Sean Adin, Krzysztof Hoszowski>
// Lab 4

#include "Database.h"
#include <iostream>
// #include <string>

using std::cerr;

//class Book {
/*      Con-, Destructors     */
Book :: Book() {
    author = "";
    hardcover = false;
    pricetag = 0;
    title = "";
    commonletter = '\0';
}

Book :: Book(const string &a, bool h, float p, const string &t, char c)
: author(a), hardcover(h), pricetag(p), title(t), commonletter(c) {}

/*      Misc     */
void Book :: ostream_Book(std::ostream &output_stream, string delimiter = "\n")
    const {output_stream << author << delimiter << hardcover << delimiter
      << pricetag << delimiter << title << delimiter << commonletter << "\n\n";
}

void Book :: set_Book(string a = "", bool h = false, float p = 0,
              string t = "", char c = '\0') {
author = a; hardcover = h; pricetag = p; title = t; commonletter = c;
}
//};
