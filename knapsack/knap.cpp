#include "knap.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void mochilaFrac(knap &k, vector<item> items)
{
    for(int i = items.size()-1; i >= 0; i--)
    {
        if(items[i].weight <= k.cap)
        {
            k.items[i] = 1;
            k.cap -= items[i].weight;
        }
        else
        {
            k.items[i] = (k.cap/items[i].weight);
            k.cap = 0;
        }
    }
}
int main()
{
    knap k(5,50);
    knap k2(5,50);

    vector<item> items;
    item e1 = item(40, 840);
    item e2 = item(30, 600);
    item e3 = item(20, 400);
    item e4 = item(10, 100);
    item e5 = item(20, 300);
    items.push_back(e1);
    items.push_back(e2);
    items.push_back(e3);
    items.push_back(e4);
    items.push_back(e5);
    
    mochilaFrac(k,items);
    cout << "Sem ordenar por ratio de valor: \n";
    double lucro = 0;
    for(int i = 0; i < k.items.size(); i++)
    {
        cout << k.items[i] << '\n';
        lucro += k.items[i]*items[i].value;
    }
    cout << "lucro: " << lucro << '\n';
    lucro = 0;
    cout << "Ordenando por ratio de valor: \n";

    sort(items.begin(),items.end(),compareItem);
    mochilaFrac(k2,items);

    for(int i = 0; i < k2.items.size(); i++)
    {
        cout << k2.items[i] << '\n';
                lucro += k.items[i]*items[i].value;

    }
    cout << "lucro: " << lucro << '\n';
    items.clear();

}