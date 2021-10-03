#pragma once
#include "ServicePiramide.h"
#include "ServiceFaraoni.h"
#include "ServiceTranzacti.h"

using namespace std;

void test_create(){
    string s="altele";
    Piramida::repo.create(Piramida(1, s, 20));
    assert(Piramida::repo.idcheck(1) == 1);
    assert(Piramida::repo.findbyid(1).getMarime()==s);
    assert(Piramida::repo.findbyid(1).getPret()==20);

    Faraon::repo.create(Faraon(1,s));
    assert(Faraon::repo.idcheck(1) == 1);
    assert(Faraon::repo.findbyid(1).getNume() == s);

    Tranzactie::repo.create(Tranzactie(1,s,1,20));
    assert(Tranzactie::repo.findbyid(1).getPret() == 20);
}

void test_update(){
    string s1="altele";
    Piramida::repo.update(Piramida(1, s1, 30));
    assert(Piramida::repo.findbyid(1).getMarime()==s1);
    assert(Piramida::repo.findbyid(1).getPret()==30);
    Piramida::repo.remove(1);


}

void test_delete(){
    string s="altele";
    Piramida::repo.create(Piramida(200, s, 80));
    Piramida::repo.remove(200);
    assert(Piramida::repo.idcheck(200) == 0);

    Faraon::repo.remove(1);
    assert(Faraon::repo.idcheck(1) == 0);

    Tranzactie::repo.remove(1);
    assert(Tranzactie::repo.idcheck(1) == 0);


}

void test_functionalities(){
    assert(ServiceTranzacti::trz_cea_mai_scumpa().id_entitate == 1);

    assert(ServiceTranzacti::trz_crescator()[0].id_entitate == 1);

    assert(ServiceTranzacti::trz_mai_mari_de_10k().empty());
}

void tests(){
    test_create();
    test_update();
    test_functionalities();
    test_delete();
}