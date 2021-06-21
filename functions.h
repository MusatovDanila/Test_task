//This code is the intellectual property of Danila Musatov .
//Contacts danilarumus2000@gmail.com
//This program contains a number of numerical methods for finding the root on the interval.
// Copyright reserved 2021 

#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>

using vector_i = std::vector<int>;
using vector_b = std::vector<bool>;
using map_ui_i = std::map<unsigned int, int>;


//initializing the map if we want to work with user input
//including the read function with user input error handling

template<typename T>
T get(std::string name)
{
    while (true)
    {
        std::cout << "Enter " << name << ":";
        T get_v;
        std::cin >> get_v;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "wrong! \nPlease try again:\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');

            return get_v;
        }
    }
}
/*
template<typename T, typename V>
std::map<T, V> init_map() {
    unsigned int quant_keys = get<int>("quantity of map`s keys");
    std::map<T, V> i_map;
    for (unsigned int i = 0; i < quant_keys; ++i) {
        T key = get<T>("name of key");
        i_map[key] = get<V>("value");
    }
    return i_map;
}

*/

map_ui_i init_map(unsigned int m);

vector_i init_vec(unsigned int m);

void rand_delete_vec(vector_i& vec);

void rand_delete_map(map_ui_i& cur_map);

void print_vector(const vector_i& vec); 

void print_map(const map_ui_i& cur_map);

void syncing_v_m(vector_i& vec, map_ui_i& cur_map);

void makeResult(unsigned int quantity_v = 20, unsigned int quantity_m = 20);
