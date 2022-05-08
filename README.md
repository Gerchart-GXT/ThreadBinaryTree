# 数据结构作业之——线索二叉树创建（二叉树排序）
## 题干
* 创建二叉树结点数据的策略有三个，如下：
1. 将第一个要创建的元素插入成为根节点。
2. 将元素值与结点值比较，如果元素值大于结点值，将此元素送往结点的右儿子结点，如果右儿子结点不是空的，需要重复比较，否则创建结点将元素值插入。
3. 如果元素值小于结点值，将此元素送往结点的左儿子结点，如果左儿子结点不是空的，需要重复比较，否则创建结点将此元素值插入。
## 文件结构
1. `ThrBinTree.h`
    * 线索二叉树类
    * 包括`rtag,ltag`--为`true`代表是树枝，为`false`代表线索
    * `Data`域与`左右link`
    * `change`操作为更改节点为树枝
2. `Data.h`
    * 数据类
    * 本题中为`一个int参数`
3. `BuildThrTree.h`
    * 为操作实现
    ```cpp
    //创建根节点
    ThrBinTree* buildRoot(int val);
    //二叉树排序策略插入节点,同时进行判重
    ThrBinTree* findPostion(ThrBinTree* Node, Data* val);//找到需插入的目标值的直接根节点，并返回
    bool insertNode(ThrBinTree* root, Data* val);//根据直接根节点来判断加入左/右树，如果为重复元素则返回false

    //递归中序遍历
    void printThrBinTree_withDFS(ThrBinTree* node);
    //利用线索中序遍历
    void printThrBinTree(ThrBinTree* root);
    ```