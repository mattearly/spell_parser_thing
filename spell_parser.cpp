#include "includes.h"
using namespace std;

vector<spell> spells_grabbed;
string data_to_search;
spell spell_iteration_var;

int main()
{
    cout << "TEST CASE BEGIN\n";
    string a = "GeeksForGeeks";
    // Here b is an object of regex (regular expression)
    regex b("(Geek)(.*)"); // Geeks followed by any character
    // regex_match function matches string a against regex b
    if (regex_match(a, b))
        cout << "String 'a' matches regular expression 'b' \n";
    // regex_match function for matching a range in string
    // against regex b
    if (regex_match(a.begin(), a.end(), b))
        cout << "String 'a' matches with regular expression "
                "'b' in the range from 0 to string end\n";
    cout << "END TEST CASE\n";

    int step = 0;

    while (getline(cin, data_to_search))
    {
        // cout << step << endl;
        //         cout << "data: " << data_to_search << endl;

        cout << "sending: '" + data_to_search + "' \n";
        switch (step)
        {
        case 0:
            spell_iteration_var.find_and_set_name(data_to_search);
            break;
        case 1:
            spell_iteration_var.find_and_set_classes(data_to_search);
            break;
        case 2:
            spell_iteration_var.find_and_set_components(data_to_search);
            break;
        case 3:
            spell_iteration_var.find_and_set_duration(data_to_search);
            break;
        case 4:
            spell_iteration_var.find_and_set_level(data_to_search);
            break;
        case 5:
            spell_iteration_var.find_and_set_material(data_to_search);
            break;
        case 6:
            spell_iteration_var.find_and_set_range(data_to_search);
            break;
        case 7:
            spell_iteration_var.find_and_set_ritual(data_to_search);
            break;
        case 8:
            spell_iteration_var.find_and_set_school(data_to_search);
            break;
        case 9:
            spell_iteration_var.find_and_set_source(data_to_search);
            break;
        case 10:
            spell_iteration_var.find_and_set_page(data_to_search);
            break;
        case 11:
            spell_iteration_var.find_and_set_description(data_to_search);
            break;
        case 12:
            spell_iteration_var.find_and_set_castingTime(data_to_search);
            break;
        default:
            cout << "somehow hit default case in switch \n";
            exit(1);
            // consider cases of default
            break;
        }

        step++;
        if (step > 0)
        {
            // cout << "exiting, step " << step << " isn't built yet.\n";
            // break;
            step = 0; //create infinite step 0 for now while testing it
        }
    }

    // cout <<
    return 0;
}
