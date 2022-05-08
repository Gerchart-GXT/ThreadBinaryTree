class Data {
private:
    int val;

public:
    Data(int val);

    int getVal();
};

Data::Data(int val)
{
    this->val = val;
}
int Data::getVal()
{
    return this->val;
}