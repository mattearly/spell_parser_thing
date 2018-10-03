#include "includes.h"
using namespace std;

vector<spell> spells_grabbed;
string data_to_search;
spell spell_iteration_var;

int main()
{
    int step = 0;
    bool success = false;
    while (getline(cin, data_to_search))
    {
        cout << "step " << step << endl;
        cout << "SEND: '" + data_to_search + "' \n";
        switch (step)
        {
        case 0:
            success = spell_iteration_var.find_and_set_name(data_to_search);
            if (success)
            {
                cout << "SPELLNAME: " << spell_iteration_var.name << endl;
            }
            break;
        case 1:
            success = spell_iteration_var.find_and_set_classes(data_to_search);
            if (success)
            {
                cout << "CLASSES: " << spell_iteration_var.classes << endl;
            }
            break;
        case 2:
            success = spell_iteration_var.find_and_set_components(data_to_search);
            if (success)
            {
                cout << "COMPONENTS: " << spell_iteration_var.components << endl;
            }
            break;
        case 3:
            success = spell_iteration_var.find_and_set_duration(data_to_search);
            if (success)
            {
                cout << "DURATION: " << spell_iteration_var.duration << endl;
            }
            break;
        case 4:
            success = spell_iteration_var.find_and_set_level(data_to_search);
            if (success)
            {
                cout << "LEVEL: " << spell_iteration_var.level << endl;
                exit(-1);
            }
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
            break;
        }

        if (success)
        {
            step++;
            success = false;
        }
    }

    // cout <<
    return 0;
}
