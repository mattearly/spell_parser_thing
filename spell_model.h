#pragma once
#include <string>
using std::string;

class spell
{

  public:
    string name;
    string classes;
    int level;
    string school;
    bool ritual;
    string castingTime;
    string range;
    string components;
    string material;
    string duration;
    string description;
    string source;
    int page;

    void find_and_set_name(const string &);
    void find_and_set_classes(const string &);
    void find_and_set_level(const string &);
    void find_and_set_school(const string &);
    void find_and_set_ritual(const string &);
    void find_and_set_castingTime(const string &);
    void find_and_set_range(const string &);
    void find_and_set_components(const string &);
    void find_and_set_material(const string &);
    void find_and_set_duration(const string &);
    void find_and_set_description(const string &);
    void find_and_set_source(const string &);
    void find_and_set_page(const string &);
};
