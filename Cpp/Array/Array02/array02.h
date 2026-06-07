#ifndef ARRAY02_H
#define ARRAY02_H
#include<iostream>
#include<new>
#include<string.h>
struct arr
{
    int age[3];
    std::string name[3];
    int mark[3];
};
void student(){
    struct arr *ptr;
    ptr = new arr;
    ptr->name[0] = "Harry";ptr->age[0] = 12;ptr->mark[0] = 200;
    ptr->name[1] = "harsh";ptr->age[1] = 13;ptr->mark[1] = 300;
    ptr->name[2] = "rohan";ptr->age[2] = 14;ptr->mark[2] = 400;
    for (int i = 0; i < 3; i++)
    {
        std::cout<<"Name of student is "<<ptr->name[i]<<" Age is "<<ptr->age[i]<<" Marks is "<<ptr->mark[i]<<std::endl;
    }
    delete ptr;
}

#endif // ARRAY02_H