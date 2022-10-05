#include "map/map.hpp"

// void printTree(Node *root, std::string indent, bool last) {
//   if (root != nullptr) {
//     cout << indent;
//     if (last) {
//       cout << "R----";
//       indent += "   ";
//     } else {
//       cout << "L----";
//       indent += "|  ";
//     }
//     cout << root->key << endl;
//     printTree(root->left, indent, false);
//     printTree(root->right, indent, true);
//   }
// }

int main()
{
    //int int
    ft::map<int, int> m;

    //insert
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(2, 20));
    // m.insert(ft::pair<int, int>(2, 20));
    // m.insert(ft::pair<int, int>(3, 30));
    // m.insert(ft::pair<int, int>(0, 35));
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // m.insert(ft::pair<int, int>(1, 10));
    // printTree(m, "", true);

    m[2] = 10;
    m[3] = 20;
    m[4] = 30;
    // m[4] = 30;

    return 0;
}