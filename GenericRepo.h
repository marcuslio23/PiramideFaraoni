#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Entitate.h"
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

template <class T>
class RepositoryFile
{

protected:
    string filename;

public:
    RepositoryFile(const RepositoryFile &rep) = default;
    RepositoryFile() = default;
    explicit RepositoryFile(const string&);
    ~RepositoryFile();
    void saveToFile(vector<T>&);
    vector<T> getFromFile();
    T findbyid(int);
    void create(T el);
    void remove(int);
    void update(T el);
    int idcheck(int);
};


template<class T>
RepositoryFile<T>::RepositoryFile(const string& name){
    this->filename = name;
}

template<class T>
RepositoryFile<T>::~RepositoryFile() = default;


template <class T>
T RepositoryFile<T>::findbyid(int i){
    vector<T> container = getFromFile();
    for(T obiect : container){
        if (obiect.get_id() == i){
            return obiect;
        }
    }
}

template <class T>
void RepositoryFile<T>::create(T el){
    vector<T> container = getFromFile();
    container.push_back(el);
    saveToFile(container);
}

template<class T>
void RepositoryFile<T>::remove(int i){
    vector<T> container = getFromFile();
    for(int j=0; j<container.size(); j++)
        if(container[j].get_id() == i)
        {container.erase(container.begin()+j);}
    saveToFile(container);
}

template<class T>
void RepositoryFile<T>::update(T el) {
    vector<T> container = getFromFile();
    for(auto& obiect : container)
        if(obiect.get_id() == el.get_id())
            obiect = el;
    saveToFile(container);
}

template<class T>
int RepositoryFile<T>::idcheck(int i) {
    vector<T> container = getFromFile();
    for(auto obiect : container)
    {if(obiect.get_id() == i) return 1;}
    return 0;
}


template<class T>
void RepositoryFile<T>::saveToFile(vector<T>& container)
{
    string line;

    for(auto obiect:container)
    {line += obiect.ob_to_str();}

    ofstream fclear(filename);
    fclear.close();
    fstream file(filename);
    file << line;
    file.close();
}

template<class T>
vector<T> RepositoryFile<T>::getFromFile()
{
    vector<T> in_container;
    string line, genparsed;

    fstream file(filename.c_str());
    getline(file,line);
    file.close();

    stringstream ss(line);
    while (getline(ss, genparsed, ';'))
    {
        in_container.push_back(T::str_to_ob(genparsed));
    }
    return in_container;
}
