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
        spell_iteration_var.name = matches[0];
        return true;
    }
    return false;
}

bool spell::find_and_set_classes(const string &search_through)
{
    static int count = 0;
    std::regex pattern{R"([A-Z][a-zA-Z]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        if (matches[0].compare("Rogue") == 0 || matches[0].compare("Fighter") == 0)
        { // we dont want Rogue and Fighter classes listed as casters
            return false;
        }

        // if (matches[0].compare("components") == 0)  //todo we need a better stop case this wont work
        // {  // if we run into the word components, we're certainly past all the classes
        //     return true;
        // }

        if (count > 0)
        {
            spell_iteration_var.classes += ", ";
            spell_iteration_var.classes += matches[0];
            count++;
            return false;
        }
        else
        {
            spell_iteration_var.classes = matches[0];
            count++;

            return false;
        }
    }
    if (spell_iteration_var.classes.size() > 2)
    {
        return true;
    }

    return false;
}

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

void spell::resetModel()
{
    name = "";
    classes = "";
    level = 0;
    school = "";
    ritual = false;
    castingTime = "";
    range = "";
    components = "";
    material = "";
    duration = "";
    description = "";
    source = "";
    page = 0;
}
