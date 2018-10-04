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
            }
            break;
        case 5:
            success = spell_iteration_var.find_and_set_material(data_to_search);
            if (success)
            {
                cout << "MATERIAL: " << spell_iteration_var.material << endl;
            }
            break;
        case 6:
            success = spell_iteration_var.find_and_set_range(data_to_search);
            if (success)
            {
                cout << "RANGE: " << spell_iteration_var.range << endl;
            }
            break;
        case 7:
            success = spell_iteration_var.find_and_set_ritual(data_to_search);
            if (success)
            {
                cout << "RITUAL: " << spell_iteration_var.ritual << endl;
            }
            break;
        case 8:
            success = spell_iteration_var.find_and_set_school(data_to_search);
            if (success)
            {
                cout << "SCHOOL: " << spell_iteration_var.school << endl;
            }
            break;
        case 9:
            success = spell_iteration_var.find_and_set_source(data_to_search);
            if (success)
            {
                cout << "SOURCE: " << spell_iteration_var.source << endl;
            }
            break;
        case 10:
            success = spell_iteration_var.find_and_set_page(data_to_search);
            if (success)
            {
                cout << "PAGE: " << spell_iteration_var.page << endl;
                exit(0);
            }
            break;
        case 11:
            spell_iteration_var.find_and_set_description(data_to_search);

            break;
        case 12:
            spell_iteration_var.find_and_set_castingTime(data_to_search);
            break;
        default:
            cout << "somehow hit default case in switch \n";
            exit(0);
            break;
        }

        if (success)
        {
            step++;
            success = false;
        }
    }

    return 0;
}
