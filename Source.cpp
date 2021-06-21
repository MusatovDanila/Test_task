//This code is the intellectual property of Danila Musatov .
//Contacts danilarumus2000@gmail.com
//This program contains a number of numerical methods for finding the root on the interval.
// Copyright reserved 2021 

#include"functions.h"

int main(){
    int v_s = get<int>("vector size");
    int m_s = get<int>("map size");
    m_s = m_s > 0 ? m_s : 20;
    v_s = v_s > 0 ? v_s : 20;
    makeResult(v_s,m_s);
    return 0;
}