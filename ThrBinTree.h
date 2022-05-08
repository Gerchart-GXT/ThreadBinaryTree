#include "Data.h"
class ThrBinTree {
private:
    bool ltag;
    bool rtag;
    ThrBinTree* llink;
    ThrBinTree* rlink;
    Data* val;

public:
    ThrBinTree(int ltag, ThrBinTree* llink, int rtag, ThrBinTree* rlink, Data* val);
    bool changeLlink(ThrBinTree* llink);
    bool changerlink(ThrBinTree* rlink);
    ThrBinTree* getLlink();
    int getLtag();
    ThrBinTree* getRlink();
    int getRtag();
    Data* getVal();
};
ThrBinTree::ThrBinTree(int ltag, ThrBinTree* llink, int rtag, ThrBinTree* rlink, Data* val)
{
    this->ltag = ltag;
    this->rtag = rtag;
    this->llink = llink;
    this->rlink = rlink;
    this->val = val;
}
ThrBinTree* ThrBinTree::getLlink()
{
    return this->llink;
}
int ThrBinTree::getLtag()
{
    return this->ltag;
}
ThrBinTree* ThrBinTree::getRlink()
{
    return this->rlink;
}
int ThrBinTree::getRtag()
{
    return this->rtag;
}
bool ThrBinTree::changeLlink(ThrBinTree* llink)
{
    this->ltag = 1;
    this->llink = llink;
    return true;
}
bool ThrBinTree::changerlink(ThrBinTree* rlink)
{
    this->rtag = 1;
    this->rlink = rlink;
    return true;
}
Data* ThrBinTree::getVal()
{
    return this->val;
}