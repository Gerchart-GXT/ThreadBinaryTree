#include "ThrBinTree.h"
#include <iostream>
ThrBinTree* buildRoot(int val)
{
    auto tval = new Data(val);
    auto root = new ThrBinTree(0, nullptr, 0, nullptr, tval);
    return root;
}

ThrBinTree* findPostion(ThrBinTree* Node, Data* val)
{
    int tval = val->getVal();
    int nval = Node->getVal()->getVal();
    if (Node->getRtag() && tval > nval) {
        return findPostion(Node->getRlink(), val);
    } else if (Node->getLtag() && tval < nval) {
        return findPostion(Node->getLlink(), val);
    }
    return Node;
}

bool insertNode(ThrBinTree* root, Data* val)
{
    auto node = findPostion(root, val);
    if (node->getVal()->getVal() == val->getVal()) {
        std::cout << val->getVal() << " has exist!" << std::endl;
        return false;
    }
    if (node->getVal()->getVal() > val->getVal()) {
        auto tnode = new ThrBinTree(0, node->getLlink(), 0, node, val);
        node->changeLlink(tnode);
        return true;
    }
    if (node->getVal()->getVal() < val->getVal()) {
        auto tnode = new ThrBinTree(0, node, 0, node->getRlink(), val);
        node->changerlink(tnode);
        return true;
    }
    return true;
}

void printThrBinTree_withDFS(ThrBinTree* node)
{
    if (node->getLtag())
        printThrBinTree_withDFS(node->getLlink());
    std::cout << " " << node->getVal()->getVal() << " ";
    if (node->getRtag())
        printThrBinTree_withDFS(node->getRlink());
}
void printThrBinTree(ThrBinTree* root)
{
    //先走到最左节点
    while (root->getLtag() && root->getLlink() != nullptr) {
        root = root->getLlink();
    }
    while (root != nullptr) {
        std::cout << " " << root->getVal()->getVal() << " "; // print当前节点
        //如果最左节点有右子树
        if (root->getRtag() && root->getRlink() != nullptr) {
            root = root->getRlink(); //进入右子树
            //走到该子树的最左节点
            while (root->getLtag() && root->getLlink() != nullptr) {
                root = root->getLlink();
            }
        } else
            //没有右子树去右线索
            root = root->getRlink();
    }
    return;
}