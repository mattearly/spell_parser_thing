#include "spell_model.h"
#include <regex>
#include <string>
#include <iostream>

using namespace std;

extern spell spell_iteration_var;

bool spell::find_and_set_name(const string &search_through)
{
    std::regex pattern{R"([A-Z][a-zA-Z \s']+)"};
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
        if (spell_iteration_var.classes.length() >= 3)
        {
            spell_iteration_var.classes += ", ";
            spell_iteration_var.classes += matches[0];
            return false;
        }
        else
        {
            spell_iteration_var.classes = matches[0];
            return false;
        }
    }
    if (spell_iteration_var.classes.size() > 2)
    {
        return true;
    }

    return false;
}

bool spell::find_and_set_components(const string &search_through)
{
    std::regex pattern{R"([A-Z])"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        if (spell_iteration_var.components.length() >= 3)
        {
            spell_iteration_var.components += ", ";
            if (matches[0].compare("S") == 0)
                spell_iteration_var.components += "Somatic";
            if (matches[0].compare("M") == 0)
                spell_iteration_var.components += "Material";
            if (matches[0].compare("V") == 0)
                spell_iteration_var.components += "Verbal";
            return false;
        }
        else
        {
            if (matches[0].compare("S") == 0)
                spell_iteration_var.components += "Somatic";
            if (matches[0].compare("M") == 0)
                spell_iteration_var.components += "Material";
            if (matches[0].compare("V") == 0)
                spell_iteration_var.components += "Verbal";
            return false;
        }
    }

    if (spell_iteration_var.components.size() > 2)
    {
        return true;
    }

    return false;
}

bool spell::find_and_set_duration(const string &search_through)
{
    std::regex pattern{R"([A-Z0-9][a-zA-Z0-9, \s]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        if (matches[0].compare("duration") != 0)
        {
            spell_iteration_var.duration = matches[0];
            return true;
        }
    }
    return false;
}

bool spell::find_and_set_level(const string &search_through)
{
    std::regex pattern{R"([0-9])"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        string test = matches[0];
        string numString = "";
        if (test.size() > 0)
        {
            for (uint32_t i = 0; i < test.size(); i++)
            {
                if (isdigit(test[i]))
                {
                    numString += test[i];
                }
                else
                {
                    break;
                }
            }
            spell_iteration_var.level = stoi(numString);
            return true;
        }
    }
    return false;
}

bool spell::find_and_set_material(const string &search_through)
{

    std::regex pattern{R"((null))"};
    smatch matches;
    cout << "checking for null materials...\n";
    if (regex_search(search_through, matches, pattern))
    {
        cout << "number of matches: " << matches.size() << endl;
        for (auto match : matches)
        {
            cout << "M: " << match << endl;
        }
        if (matches[0].compare("null") == 0)
        {
            spell_iteration_var.material = "none";
            return true;
        }
    }

    std::regex pattern2{R"((\"[a-ln-zA-Z0-9][\w,()\s]+\"))"}; //works omg
    smatch matches2;
    cout << "went passed null, checking for string between quotations...\n";
    if (regex_search(search_through, matches2, pattern2))
    {
        cout << "number of matches: " << matches2.size() << endl;
        for (auto match : matches2)
        {
            cout << "M: " << match << endl;
        }
        if (matches2[0].compare("material") != 0)
        {
            //string quotes removal
            string tmp = matches2[0];
            string strippedquotes = tmp.substr(1, matches2[0].length() - 2);
            spell_iteration_var.material = strippedquotes;
            return true;
        }
    }
    return false;
}

bool spell::find_and_set_range(const string &search_through)
{
    std::regex pattern{R"((\"[a-qs-zA-Z0-9][\w\-,()\s]+\"))"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        cout << "number of matches: " << matches.size() << endl;
        for (auto match : matches)
        {
            cout << "M: " << match << endl;
        }
        if (matches[0].compare("range") != 0)
        {
            //string quotes removal
            string tmp = matches[0];
            string strippedquotes = tmp.substr(1, matches[0].length() - 2);
            spell_iteration_var.range = strippedquotes;
            return true;
        }
    }
    return false;
}

bool spell::find_and_set_ritual(const string &search_through)
{
    std::regex pattern2{R"((\"[a-ln-zA-Z0-9][\w,()\s]+\"))"}; //works omg
    smatch matches2;
    cout << "went passed null, checking for string between quotations...\n";
    if (regex_search(search_through, matches2, pattern2))
    {
        cout << "number of matches: " << matches2.size() << endl;
        for (auto match : matches2)
        {
            cout << "M: " << match << endl;
        }
        if (matches2[0].compare("ritual") != 0)
        {
            //string quotes removal
            string tmp = matches2[0];
            string strippedquotes = tmp.substr(1, matches2[0].length() - 2);
            if (strippedquotes.compare("true") == 0)
                spell_iteration_var.ritual = true;
            else
                spell_iteration_var.ritual = false;

            return true;
        }
    }
    return false;
}

bool spell::find_and_set_school(const string &search_through)
{
    std::regex pattern{R"([A-Z][a-zA-Z]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        spell_iteration_var.school = matches[0];
        return true;
    }
    return false;
}

bool spell::find_and_set_source(const string &search_through)
{
    std::regex pattern{R"([A-Z][a-zA-Z' \s]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        spell_iteration_var.source = matches[0];
        return true;
    }
    return false;
}

bool spell::find_and_set_page(const string &search_through)
{
    std::regex pattern{R"([0-9]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        spell_iteration_var.page = stoi(matches[0]);
        return true;
    }
    return false;
}

bool spell::find_and_set_description(const string &search_through)
{
    std::regex pattern{R"([A-Z][a-zA-Z',()0-9 .\-: \s]+)"};
    smatch matches;
    if (regex_search(search_through, matches, pattern))
    {
        if (matches[0].length() > 10)
        {
            spell_iteration_var.description = matches[0];
            return true;
        }
    }
    return false;
}

bool spell::find_and_set_castingTime(const string &search_through)
{
    std::regex pattern2{R"((\"[a-su-zA-Z0-9][\w,()\s]+\"))"};
    smatch matches2;
    if (regex_search(search_through, matches2, pattern2))
    {
        cout << "number of matches: " << matches2.size() << endl;
        for (auto match : matches2)
        {
            cout << "M: " << match << endl;
        }
        if (matches2[0].compare("material") != 0)
        {
            //string quotes removal
            string tmp = matches2[0];
            string strippedquotes = tmp.substr(1, matches2[0].length() - 2);
            spell_iteration_var.castingTime = strippedquotes;
            return true;
        }
    }
    return false;
}

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
