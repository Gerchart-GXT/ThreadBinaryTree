#include "BuildThrBinTree.h"

int main()
{
    puts("----------");
    puts("Welcome to Gerchart's Thr-Bin-Tree Buid program!!");
    puts("----------");
    int cnt = 0;
    puts("Please input the count of numbers you want insert:");
    std::cin >> cnt;
    puts("Now input the element list:");
    ThrBinTree* root = nullptr;
    for (int i = 1; i <= cnt; i++) {
        std::cout << "Please input the "
                  << "No." << i << "number:";
        int val = 0;
        std::cin >> val;
        auto tval = new Data(val);
        if (i == 1) {
            root = buildRoot(val);
            continue;
        }
        bool flag = insertNode(root, tval);
        while (!flag) {
            bool skip = false;
            std::cout << "Skip or Re-enter (s/r) ? :";
            char op[2];
            while (std::cin >> op) {
                if (!strcmp(op, "s")) {
                    skip = true;
                    break;
                }
                if (!strcmp(op, "r")) {
                    std::cout << "Please input the "
                              << "No." << i << "number:";
                    std::cin >> val;
                    auto tval = new Data(val);
                    flag = insertNode(root, tval);
                    break;
                }
            }
            if (skip)
                break;
        }
    }
    puts("----------");
    puts("----------");
    puts("Now output In-order ergodic");
    puts("1---DFS-Answer:");
    printThrBinTree_withDFS(root);
    puts("");
    puts("2---UseThread-Answer:");
    printThrBinTree(root);
    return 0;
}