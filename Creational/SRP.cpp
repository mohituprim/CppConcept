/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//Single Responsibility Principle (SRP)
    //A class should only have a single responsibility

#include <string>
#include <vector>
#include <fstream>

struct Journal
{
  std::string title;
  std::vector<std::string> entries;

  explicit Journal(const std::string& title)
    : title{title}
  {
  }

  void add(const std::string& entry)
  {
    entries.push_back(entry);
  }

  //save function could be added here as well but it violates the srp principle
  
};

struct PersistenceManager
{
  static void save(const Journal& j, const std::string& filename)
  {
    std::ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << std::endl;
  }
};
