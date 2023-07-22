#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int LEN = 225;

class Resource
{
protected:
    char name[LEN];
    char category[LEN];
    char location[LEN];
    char contact_info[LEN];
    char work_schedule[LEN];
    char type_support[LEN];
    char services[LEN];
    vector<string> reviews;
  //  vector<Resource*> resources;//â main
public:
    Resource() = default;
   // ~Resource();
    void SetResource();
    char* GetName();
    char* GetCategory();
    char* GetLocation();
    char* GetTypeSupport();
    void SetReview();
    friend ostream& operator<<(ostream&, const Resource&);
};