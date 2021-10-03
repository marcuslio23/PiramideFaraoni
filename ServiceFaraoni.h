#pragma once
#include "Faraon.h"

class ServiceFaraoni{
public:
    static void create_faraon(int id, const string& nume){
        Faraon::repo.create(Faraon(id, nume));
    }

    static void update_faraon(int id, const string& nume){
        Faraon::repo.update(Faraon(id, nume));
    }

    static void delete_faraon(int id){
        Faraon::repo.remove(id);
    }

    static void show_all_faraoni(){
        for(const auto& i:Faraon::repo.getFromFile())
            i.toString();
    }

    static int id_check(int id){
        return Faraon::repo.idcheck(id);
    }

    static vector<Faraon> get_all_T(){
        vector<Faraon> container = Faraon::repo.getFromFile();
        return container;
    }
};