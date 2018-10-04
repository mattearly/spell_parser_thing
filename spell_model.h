#pragma once
#include <string>
using std::string;

class spell
{

public:
  string name;
  string classes;
  string components;
  string duration;

  int level;
  string school;
  bool ritual;
  string castingTime;
  string range;
  string material;
  string description;
  string source;
  int page;

  bool find_and_set_name(const string &);
  bool find_and_set_classes(const string &);
  bool find_and_set_components(const string &);
  bool find_and_set_level(const string &);
  bool find_and_set_school(const string &);
  bool find_and_set_ritual(const string &);

  bool find_and_set_castingTime(const string &);
  bool find_and_set_range(const string &);
  bool find_and_set_material(const string &);
  bool find_and_set_duration(const string &);
  bool find_and_set_description(const string &);
  bool find_and_set_source(const string &);
  bool find_and_set_page(const string &);

  void resetModel();
};
