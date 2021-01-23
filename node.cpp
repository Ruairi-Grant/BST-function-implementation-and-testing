#include "node.hpp"

node::node(){
  count = 1;
  data = 0;
  left = nullptr;
  right = nullptr;
}

node::node(int num) {
  count = 1;
  data = num;
  left = nullptr;
  right = nullptr;
}