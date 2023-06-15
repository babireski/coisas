#ifndef _knap_hpp
#define _knap_hpp
#include <vector>
using namespace std;
class item
{
public:

    item(double weight, double value)
    {
        this->value = value;
        this->weight = weight;
        this->ratio = value/weight;
    }
    double weight;
    double value;
    double ratio;
};
class knap
{
public:

    knap(int size, double cap)
    {
        items.resize(size);
        this->cap = cap;
    }
    vector<double> items;
    double cap;

};
//Funcao de compare, para ser usado com a funcao *sort* padrao do cpp
//nesse caso queremos ordenar de maneira crescente
bool compareItem(item e1, item e2)
{
    return (e1.ratio < e2.ratio);
}
#endif