#pragma once
#include "Tranzactie.h"

class ServiceTranzacti{
public:
    static void create_tranzactie(int id_trz, const string& nume_faraon, int id_piramida, int pret){
        Tranzactie::repo.create(Tranzactie(id_trz, nume_faraon, id_piramida, pret));
    }

    static void update_tranzactie(int id_trz, const string& nume_faraon, int id_piramida, int pret){
        Tranzactie::repo.update(Tranzactie(id_trz, nume_faraon, id_piramida, pret));
    }

    static void delete_tranzactie(int id){
        Tranzactie::repo.remove(id);
    }

    static void show_all_tranzactii(){
        for(const auto& i:Tranzactie::repo.getFromFile())
            i.toString();
    }

    static int id_check(int id){
        return Tranzactie::repo.idcheck(id);
    }

    [[maybe_unused]] static vector<Tranzactie> get_all_T(){
        vector<Tranzactie> container = Tranzactie::repo.getFromFile();
        return container;
    }

    static vector<Tranzactie> trz_crescator(){
        vector<Tranzactie> rez = Tranzactie::repo.getFromFile();
        for(int i = 0; i < rez.size() - 1; ++i){
            for(int j = i + 1; j < rez.size(); ++j){
                if(rez[i].getPret() > rez[j].getPret())
                    swap(rez[i], rez[j]);
            }
        }
        return rez;
    }

    static Tranzactie trz_cea_mai_scumpa(){
        return trz_crescator()[trz_crescator().size()-1];
    }

    static vector<Tranzactie> trz_mai_mari_de_10k(){
        vector<Tranzactie> rez;
        for(const auto& tranzcatie: Tranzactie::repo.getFromFile()){
            if (tranzcatie.getPret() >= 10000)
                rez.push_back(tranzcatie);
        }
        return rez;
    }
};