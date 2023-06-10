#include "knap.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void mochilaFrac(knap &k, vector<item> &items)
{
    for(int i = 4; i >= 0; i--)
    {
        if(items[i].weight <= k.cap)
        {
            k.addItem(1);
            k.cap -= items[i].weight;
        }
        else
        {
            k.addItem(k.cap/items[i].weight);
            k.cap = 0;
        }
    }
}
int main()
{
    knap k;
    k.cap = 50;
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
    sort(items.begin(),items.end(),compareItem);
    mochilaFrac(k,items);
    for(int i = 0; i < k.items.size(); i++)
    {
        cout << k.items[i] << '\n';
    }

}