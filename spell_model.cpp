#include "spell_model.h"
#include <regex>
#include <string>
#include <iostream>

using namespace std;

extern spell spell_iteration_var;

bool spell::find_and_set_name(const string &search_through)
{
    std::regex pattern{R"([A-Z][a-zA-Z \s]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        // cout << "matches(" << matches.size() << "): ";
        // for (auto match : matches)
            // cout << match << endl;
        spell_iteration_var.name = matches[0];
        return true;
    }
    return false;
}


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



    // std::regex pattern{R"([^"].*[^"])"};
    // std::regex pattern{R"([A-Z][a-z]+(\s[a-z]+)?(\s[A-Z][a-z]+)?)"};
    // std::regex pattern{R"([A-Z][a-z]+(\s[a-z]+)?(\s[A-Z][a-z]+)?)"};
    // std::regex pattern{R"(Polymorph)"};
    // std::regex pattern{R"(\u{1}\w+)"}; 
    
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

    bool spell::find_and_set_classes(const string &search_through) {}
    bool spell::find_and_set_level(const string &search_through) {}
    bool spell::find_and_set_school(const string &search_through) {}
    bool spell::find_and_set_ritual(const string &search_through) {}
    bool spell::find_and_set_castingTime(const string &search_through) {}
    bool spell::find_and_set_range(const string &search_through) {}
    bool spell::find_and_set_components(const string &search_through) {}
    bool spell::find_and_set_material(const string &search_through) {}
    bool spell::find_and_set_duration(const string &search_through) {}
    bool spell::find_and_set_description(const string &search_through) {}
    bool spell::find_and_set_source(const string &search_through) {}
    bool spell::find_and_set_page(const string &search_through) {}