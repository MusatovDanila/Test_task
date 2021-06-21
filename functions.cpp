//This code is the intellectual property of Danila Musatov .
//Contacts danilarumus2000@gmail.com
//This program contains a number of numerical methods for finding the root on the interval.
// Copyright reserved 2021 

#include<iostream>
#include<vector>
#include<map>
#include<string>

using vector_i = std::vector<int>;
using vector_b = std::vector<bool>;
using map_ui_i = std::map<unsigned int, int>;
using std::endl;
using std::cout;

vector_i init_vec(unsigned int m) {
    vector_i cur_vec(m, 0);
    for (unsigned int i = 0; i < m; ++i) {
        cur_vec[i] = (rand() % 9+1);
    }
    return cur_vec;
}

map_ui_i init_map(unsigned int m) {
    std::map<unsigned int, int> cur_map;
    for (unsigned int i = 0; i < m; ++i) {
        cur_map[i] = (rand() % 9 + 1);
    }
    return cur_map;
}

void rand_delete_vec(vector_i& vec) {
    int quantity_d = 0;
    for (auto it = vec.begin(); it != vec.end() && quantity_d < 15; ) {
        if (*it % (rand() % 9+1) == 0) {
            it = vec.erase(it);
            ++quantity_d;
        }
        else {
            ++it;
        }
    }
    return;
}

void rand_delete_map(map_ui_i& cur_map) {
    int quantity_d = 0;
    for (auto it = cur_map.begin(); it != cur_map.end() && quantity_d < 15; ) {
        if ((it->second % (rand() % 9+1) ) == 0) {
            it = cur_map.erase(it);
            ++quantity_d;
        }
        else {
            ++it;
        }
    }
    return;
}

void print_vector(const vector_i& vec)
{
    cout << "vector content" << endl;
    for (auto& i : vec) {
        cout << i << " ";
    }
    cout << endl << endl;
}

void print_map(const map_ui_i& cur_map) {
    cout << "map content(value of keys)" << endl;
    for (auto& p : cur_map) {
        cout << p.second << ' ';
    }
    cout << endl << endl;
}

void syncing_v_m(vector_i& vec, map_ui_i& cur_map) {
    vector_b availability(9, 0);
    for (auto& it_m : cur_map) {
        for (auto& it_v : vec) {
            if (it_v == it_m.second) {
                availability[it_v-1] = 1;
            }
        }
    }
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (availability[vec[*it]-1] == 0) {
            it = vec.erase(it);
        }
        else {
            ++it;
        }
    }

    for (auto it = cur_map.begin(); it != cur_map.end(); ) {
        if (availability[it->second - 1] == 0) {
            it = cur_map.erase(it);
        }
        else {
            ++it;
        }
    }
    return;
}

void makeResult(unsigned int quantity_v, unsigned int quantity_m) {
    srand(static_cast<unsigned int>(time(0)));
    map_ui_i my_map = init_map(quantity_m);
    vector_i my_vec = init_vec(quantity_v);

    cout << endl << "after initializations" << endl << endl;
    print_vector(my_vec);
    print_map(my_map);

    rand_delete_map(my_map);
    rand_delete_vec(my_vec);
    cout << endl << "after delete" << endl << endl;
    print_vector(my_vec);
    print_map(my_map);

    syncing_v_m(my_vec, my_map);
    cout << endl << "after syncing" << endl << endl;
    print_vector(my_vec);
    print_map(my_map);
    return;
}