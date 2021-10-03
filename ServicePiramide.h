#pragma once
#include "Piramida.h"

class ServicePiramida{
public:
    static void create_piramida(int id, string marime, int pret){
        Piramida::repo.create(Piramida(id, std::move(marime), pret));
    }

    static void update_piramida(int id, string marime, int pret){
        Piramida::repo.update(Piramida(id, std::move(marime), pret));
    }

    static void delete_piramida(int id){
        Piramida::repo.remove(id);
    }

    static void show_all_piramide(){
        for(const auto& i:Piramida::repo.getFromFile())
            i.toString();
    }

    static int id_check(int id){
        return Piramida::repo.idcheck(id);
    }

    static vector<Piramida> get_all_T(){
        vector<Piramida> container = Piramida::repo.getFromFile();
        return container;
    }
};