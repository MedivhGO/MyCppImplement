//
// Created by Lee on 2022/9/28.
//
#include "MyBST.h"
#include "gtest/gtest.h"
#include <algorithm>

TEST(MyBST, TEST1) {

    BST::Node left{10, nullptr, nullptr};
    BST::Node right{10, nullptr, nullptr};
    BST::Node node{10, &left, &right};
    EXPECT_EQ(node.left, &left);
    EXPECT_EQ(node.right, &right);
}

TEST(MyBST, TEST2) {

    BST::Node left{10, nullptr, nullptr};
    BST::Node right{10, nullptr, nullptr};
    BST::Node node{10, &left, &right};
    BST::Node copy{node};
    EXPECT_EQ(copy.value, node.value);
    EXPECT_EQ(copy.left, node.left);
    EXPECT_EQ(copy.right, node.right);
}

TEST(MyBST, TEST3) {

    BST::Node default_{};
    EXPECT_EQ(default_.value, 0);
    EXPECT_EQ(default_.left, nullptr);
    EXPECT_EQ(default_.right, nullptr);
}

TEST(MyBST, TEST4) {

    BST::Node left{10, nullptr, nullptr};
    BST::Node right{10, nullptr, nullptr};
    BST::Node node{10, &left, &right};

    std::cout << "address of node: " << &node << std::endl;
    std::cout << "address of left: " << &left << std::endl;
    std::cout << "address of right: " << &right << std::endl;
    std::cout << std::string(80, '*') << std::endl;
    std::cout << "PRINT A NODE" << std::endl;
    std::cout << node << std::endl;
    std::cout << std::string(80, '*') << std::endl;
}

TEST(MyBST, TEST5) {
    BST::Node node{5, nullptr, nullptr};

    EXPECT_TRUE(node > 4);
    EXPECT_FALSE(node > 5);
    EXPECT_TRUE(node >= 5);
    EXPECT_FALSE(node >= 6);
    EXPECT_TRUE(node < 6);
    EXPECT_FALSE(node < 2);
    EXPECT_TRUE(node <= 5);
    EXPECT_FALSE(node <= 2);
    EXPECT_TRUE(node == 5);
    EXPECT_FALSE(node == 3);

    EXPECT_TRUE(4 < node);
    EXPECT_FALSE(5 < node);
    EXPECT_TRUE(5 <= node);
    EXPECT_FALSE(6 <= node);
    EXPECT_TRUE(6 > node);
    EXPECT_FALSE(2 > node);
    EXPECT_TRUE(5 >= node);
    EXPECT_FALSE(2 >= node);
    EXPECT_TRUE(5 == node);
    EXPECT_FALSE(3 == node);
}

TEST(MyBST, TEST6) {
    BST bst{};
    EXPECT_EQ(bst.get_root(), nullptr);
}

TEST(MyBST, TEST7) {
    BST bst{};
    bst.add_node(10);
    bst.add_node(20);
    bst.add_node(5);
    EXPECT_EQ(bst.get_root()->value, 10);
    EXPECT_EQ(bst.get_root()->left->value, 5);
    EXPECT_EQ(bst.get_root()->right->value, 20);
}

TEST(MyBST, TEST8) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);

    EXPECT_FALSE(bst.add_node(53));
    EXPECT_EQ(bst.get_root()->left->left->value, 7);
    EXPECT_EQ(bst.get_root()->left->right->value, 15);
    EXPECT_EQ(bst.get_root()->right->right->value, 53);
}

TEST(MyBST, TEST9) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);

    EXPECT_FALSE(bst.add_node(50));

    std::vector<int> values;
    bst.bfs([&values](BST::Node *&node) { values.push_back(node->value); });
    EXPECT_EQ(values.size(), 4);
    EXPECT_TRUE(std::find(values.begin(), values.end(), 25) != values.end());
    EXPECT_TRUE(std::find(values.begin(), values.end(), 10) != values.end());
    EXPECT_TRUE(std::find(values.begin(), values.end(), 50) != values.end());
    EXPECT_TRUE(std::find(values.begin(), values.end(), 53) != values.end());
}

TEST(MyBST, TEST10) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);

    EXPECT_EQ(bst.length(), 6);
}

TEST(MyBST, TEST11) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);

    std::cout << "PRINT A BINARY SEARCH TREE" << std::endl;
    std::cout << bst << std::endl;
}

TEST(MyBST, TEST12) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);

    BST::Node **node{bst.find_node(10)};
    EXPECT_EQ((*node)->value, 10);
    EXPECT_EQ(((*node)->left)->value, 7);
    EXPECT_EQ((*node)->right->value, 15);
}

TEST(MyBST, TEST13) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);

    BST::Node **node{bst.find_node(11)};
    EXPECT_EQ(node, nullptr);
}

TEST(MyBST, TEST14) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);

    std::cout << "here" << std::endl;
    BST::Node **node{bst.find_parrent(15)};
    std::cout << "here2" << std::endl;
    EXPECT_EQ((*node)->value, 10);
    EXPECT_EQ((*node)->left->value, 7);
    EXPECT_EQ((*node)->right->value, 15);
}

TEST(MyBST, TEST15) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);
    bst.add_node(8);
    bst.add_node(9);

    BST::Node **node{bst.find_predecessor(10)};
    EXPECT_EQ((*node)->value, 9);
    EXPECT_EQ((*node)->left, nullptr);
    EXPECT_EQ((*node)->right, nullptr);

    BST::Node **node_suc{bst.find_successor(10)};
    EXPECT_EQ((*node_suc)->value, 15);
    EXPECT_EQ((*node_suc)->left, nullptr);
    EXPECT_EQ((*node_suc)->right, nullptr);
}

TEST(MyBST, TEST16) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);
    bst.add_node(8);
    bst.add_node(9);

    EXPECT_FALSE(bst.delete_node(11));
}

TEST(MyBST, TEST17) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(53);
    bst.add_node(15);
    bst.add_node(7);
    bst.add_node(8);
    bst.add_node(9);

    EXPECT_EQ(bst.length(), 8);
    EXPECT_TRUE(bst.delete_node(53)); // leaf node
    EXPECT_EQ(bst.length(), 7);
    EXPECT_EQ(bst.get_root()->right->right, nullptr);
}

TEST(MyBST, TEST18) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(60);
    bst.add_node(70);
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(7);
    bst.add_node(75);

    EXPECT_EQ(bst.length(), 10);
    EXPECT_TRUE(bst.delete_node(10)); // only left child
    EXPECT_EQ(bst.length(), 9);
    EXPECT_EQ(bst.get_root()->left->value, 5);
    EXPECT_EQ(bst.get_root()->left->left->value, 2);
    EXPECT_EQ(bst.get_root()->left->right->value, 7);
    EXPECT_EQ(bst.get_root()->left->right->left, nullptr);
    EXPECT_EQ(bst.get_root()->left->right->right, nullptr);
}

TEST(MyBST, TEST19) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(60);
    bst.add_node(70);
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(7);
    bst.add_node(75);

    BST::Node *address_of_5{*bst.find_node(5)};
    BST::Node *address_of_2{*bst.find_node(2)};

    EXPECT_TRUE(bst.delete_node(10)); // only left child

    // the remaining nodes should not be regenerated
    // => address of remaining nodes before and after deletion should be the same
    // when deleting a node: just reconnect the needed parents and children
    EXPECT_EQ(*bst.find_node(5), address_of_5);
    EXPECT_EQ(*bst.find_node(2), address_of_2);
}

TEST(MyBST, TEST20) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(60);
    bst.add_node(70);
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(7);
    bst.add_node(75);

    EXPECT_EQ(bst.length(), 10);
    EXPECT_TRUE(bst.delete_node(50)); // only right child
    EXPECT_EQ(bst.length(), 9);
    EXPECT_EQ(bst.get_root()->right->value, 65);
    EXPECT_EQ(bst.get_root()->right->right->value, 70);
    EXPECT_EQ(bst.get_root()->right->right->right->value, 75);
    EXPECT_EQ(bst.get_root()->right->left->value, 60);
    EXPECT_EQ(bst.get_root()->right->left->left, nullptr);
    EXPECT_EQ(bst.get_root()->right->left->right, nullptr);
}

TEST(MyBST, TEST21) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(60);
    bst.add_node(70);
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(7);
    bst.add_node(75);

    BST::Node *address_of_60{*bst.find_node(60)};
    BST::Node *address_of_75{*bst.find_node(75)};

    EXPECT_TRUE(bst.delete_node(50)); // only left child

    // the remaining nodes should not be regenerated
    // => address of remaining nodes before and after deletion should be the same
    // when deleting a node: just reconnect the needed parents and children
    EXPECT_EQ(*bst.find_node(60), address_of_60);
    EXPECT_EQ(*bst.find_node(75), address_of_75);
}

TEST(MyBST, TEST22) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(60);
    bst.add_node(70);
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(7);
    bst.add_node(75);
    bst.add_node(20);
    bst.add_node(15);

    EXPECT_EQ(bst.length(), 12);
    EXPECT_TRUE(bst.delete_node(10)); // both children exist
    EXPECT_EQ(bst.length(), 11);
    EXPECT_EQ(bst.get_root()->left->value, 7);
    EXPECT_EQ(bst.get_root()->left->left->right, nullptr);
    EXPECT_EQ(bst.get_root()->left->left->value, 5);
}

TEST(MyBST, TEST23) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(60);
    bst.add_node(70);
    bst.add_node(5);
    bst.add_node(2);
    bst.add_node(7);
    bst.add_node(75);
    bst.add_node(20);
    bst.add_node(15);
    bst.add_node(22);

    EXPECT_EQ(bst.length(), 13);
    EXPECT_TRUE(bst.delete_node(25)); // both children exist
    EXPECT_EQ(bst.length(), 12);
    EXPECT_EQ(bst.get_root()->value, 22);
    EXPECT_EQ(bst.get_root()->left->value, 10);
    EXPECT_EQ(bst.get_root()->left->right->right, nullptr);
}

TEST(MyBST, TEST24) {
    BST bst{};
    bst.add_node(5);
    bst.add_node(10);
    bst.add_node(50);
    BST copy{bst};
    EXPECT_EQ(bst.length(), copy.length());
    EXPECT_EQ(bst.get_root()->right->value, copy.get_root()->right->value);
}

TEST(MyBST, TEST25) {
    BST bst{};
    bst.add_node(5);
    bst.add_node(10);
    bst.add_node(50);

    BST equal{};
    bst.add_node(51);
    bst.add_node(66);
    bst.add_node(10);
    equal = bst;
    EXPECT_EQ(bst.length(), equal.length());
    EXPECT_EQ(bst.get_root()->right->right->value, equal.get_root()->right->right->value);
}

TEST(MyBST, TEST26) {
    BST bst{};
    bst.add_node(5);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(1);
    bst.add_node(2);
    bst.add_node(4);
    bst.add_node(60);
    bst.add_node(8);

    bst = bst;
    EXPECT_EQ(bst.get_root()->right->left->value, 8);
}

TEST(MyBST, TEST27) {
    BST bst{};
    bst.add_node(5);
    bst.add_node(10);
    bst.add_node(50);

    int test_value{bst.get_root()->right->value};
    BST::Node *address_of_root{*bst.find_node(5)};

    BST move{std::move(bst)};
    EXPECT_EQ(address_of_root, move.get_root());
    EXPECT_EQ(test_value, move.get_root()->right->value);
}

TEST(MyBST, TEST28) {
    BST bst{};
    bst.add_node(25);
    bst.add_node(10);
    bst.add_node(50);
    bst.add_node(65);
    bst.add_node(5);
    bst.add_node(20);
    bst.add_node(22);

    int test_value{bst.get_root()->left->right->value};
    BST::Node *address_of_root{*bst.find_node(25)};

    BST move{};
    move = std::move(bst);
    EXPECT_EQ(address_of_root, move.get_root());
    EXPECT_EQ(test_value, move.get_root()->left->right->value);
}

TEST(MyBST, TEST29) {
    BST bst1{5, 1, 10, 2, 8, 50, 4, 60};
    BST bst2{3, 2, 100, 20, 8, 50, 4, 60, 44, 23};
    EXPECT_EQ((*bst1.find_predecessor(5))->value, 4);
    EXPECT_EQ((*bst1.find_successor(5))->value, 8);
    EXPECT_EQ(bst2.length(), 10);
}

TEST(MyBST, TEST30) {
    BST bst{5, 1, 10, 2, 8, 50, 4, 60};
    BST bst2{++bst};

    std::vector<int> values;
    EXPECT_EQ(bst.get_root()->value, 6);
    EXPECT_EQ(bst2.get_root()->value, 6);
    EXPECT_EQ(bst.get_root()->right->right->right->value, 61);
    EXPECT_EQ(bst2.get_root()->right->right->right->value, 61);
}

TEST(MyBST, TEST31) {
    BST bst1{5, 1, 10, 2, 8, 50, 4, 60};
    BST bst2{bst1++};

    std::vector<int> values1;
    bst1.bfs([&values1](BST::Node *&node) { values1.push_back(node->value); });

    std::vector<int> values2;
    bst2.bfs([&values2](BST::Node *&node) { values2.push_back(node->value); });

    for (size_t i{}; i < values1.size(); i++)
        EXPECT_EQ(values2[i], values1[i] - 1);
}