#include <catch.hpp>
#include <sstream>

#include "bstree.hpp"
using namespace BSTree;

TEST_CASE("save_tree_to_the_file")
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
  
  tree.save_tree_to_the_file (out);
  out.close();
  
  std::string result;
  std::string text = "5 1 2 3 4 9 8 7 6";
  std::ifstream in("file.txt");
  in >> result;
  
  REQUIRE(result == text);
}
