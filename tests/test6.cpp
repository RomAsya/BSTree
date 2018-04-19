#include <catch.hpp>
#include <sstream>
#include <string>
#include <fstream>

#include "BSTree.hpp"
using namespace BSTree;

TEST_CASE("save_tree_to_the_file_1")
{
	Tree tree;
  tree.insert(5);
  tree.insert(1);
  tree.insert(9);
  tree.insert(2);
  tree.insert(8);
  tree.insert(3);
  tree.insert(7);
  tree.insert(4);
  tree.insert(6);
  std::ofstream out("file.txt");
  
  tree.save_tree_to_the_file ("file.txt");
  out.close();
  
  std::string result;
  std::string text = "5 1 2 3 4 9 8 7 6 ";
  std::ifstream in("file.txt");
  getline(in, result);
  
  REQUIRE(result == text);
}

TEST_CASE("save_tree_to_the_file_2")
{
	Tree tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);
  tree.insert(7);
  tree.insert(8);
  tree.insert(9);
  std::ofstream out("file.txt");
  
  tree.save_tree_to_the_file ("file.txt");
  out.close();
  
  std::string result;
  std::string text = "1 2 3 4 5 6 7 8 9 ";
  std::ifstream in("file.txt");
  getline(in, result);
  
  REQUIRE(result == text);
}

TEST_CASE("save_tree_to_the_file_3")
{
	Tree tree;
  tree.insert(4);
  tree.insert(3);
  tree.insert(6);
  tree.insert(8);
  tree.insert(9);
  tree.insert(5);
  tree.insert(2);
  std::ofstream out("file.txt");
  
  tree.save_tree_to_the_file ("file.txt");
  out.close();
  
  std::string result;
  std::string text = "4 3 2 6 5 8 9 ";
  std::ifstream in("file.txt");
  getline(in, result);
  
  REQUIRE(result == text);
}
