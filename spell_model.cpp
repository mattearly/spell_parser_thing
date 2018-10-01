#include "spell_model.h"
#include <regex>
#include <string>
#include <iostream>

using namespace std;

extern spell spell_iteration_var;

void spell::find_and_set_name(const string &search_through)
{
    cout << "recieved: '" + search_through + "' \n";
    /* SET NAME IF FOUND */
    // name consists of everythign between "" that start with a capital letter
    // std::regex pattern{R"(\u\l+\l*(\u\l)*)"};
    // std::regex pattern{R"((\u\l)+)"};
    // std::regex pattern{R"(\w+)"};
    // std::regex pattern{R"(.*)"};
    // std::regex pattern{R"((A-Z|a-z|\s)+)"};
    // std::regex pattern{R"([A-Z][a-z]+(\s[a-z]+)?(\s[A-Z][a-z]+)?)"};

    //works with quotations hanging on
    // std::regex pattern{R"(["][a-zA-Z \s]+["])"};

    //works with quotations hanging on
    // std::regex pattern{R"([?<="][A-Z][a-zA-Z \s]+[?="])"};

    // probably the best so far
    std::regex pattern{R"([A-Z][a-zA-Z \s]+)"};

    // std::regex pattern{R"([^"].*[^"])"};
    // std::regex pattern{R"([A-Z][a-z]+(\s[a-z]+)?(\s[A-Z][a-z]+)?)"};
    // std::regex pattern{R"([A-Z][a-z]+(\s[a-z]+)?(\s[A-Z][a-z]+)?)"};
    // std::regex pattern{R"(Polymorph)"};
    // std::regex pattern{R"(\u{1}\w+)"};

    smatch matches;

    if (regex_search(search_through, matches, pattern))
    {
        cout << "matches(" << matches.size() << "): ";
        for (auto match : matches)
        {
            cout << match << endl;
        }
        spell_iteration_var.name = matches[0];
    }
    cout << spell_iteration_var.name << endl;
    // std::regex e("(\".*\")"); // reg expression to match things surrounded by ""
    // std::cout << "Target sequence: " << input << std::endl;
    // //   std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
    // std::cout << "The following matches and submatches were found:" << std::endl;
    // while (std::regex_search(input, m, e))
    // {
    //     for (auto x : m)
    //         std::cout << x << " ";
    //     std::cout << std::endl;
    //     // s = m.suffix().str();
    // }
}
