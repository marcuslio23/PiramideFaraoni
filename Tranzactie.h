#pragma once
#include <utility>

#include "Entitate.h"
#include "GenericRepo.h"

class Tranzactie: public Entitate{
private:
    string nume_faraon;
    int id_piramida;
    int pret;
public:
    inline static RepositoryFile<Tranzactie> repo;
    Tranzactie();
    Tranzactie(int id_trz, const string& nume_faraon, int id_piramida, int pret);
    ~Tranzactie() = default;
    string getNumeFaraon();
    [[nodiscard]] int getIdPiramida() const;
    [[nodiscard]] int getPret() const;
    void setNumeFaraon(string nume_faraon);
    void setIdPiramida(int id_piramida);
    void setPret(int pret);
    static Tranzactie str_to_ob(const string&);
    string ob_to_str();
    void toString() const;
};

Tranzactie::Tranzactie() {
    this->nume_faraon = ' ';
    this->id_piramida = 0;
    this->pret = 0;
}

Tranzactie::Tranzactie(int id_trz, const string& nume_faraon, int id_piramida, int pret) {
    this->id_entitate = id_trz;
    this->nume_faraon = nume_faraon;
    this->id_piramida = id_piramida;
    this->pret = pret;
}

string Tranzactie::getNumeFaraon() {
    return this->nume_faraon;
}

int Tranzactie::getIdPiramida() const {
    return this->id_piramida;
}

int Tranzactie::getPret() const {
    return this->pret;
}

void Tranzactie::setNumeFaraon(string nume_faraon) {
    this->nume_faraon = std::move(nume_faraon);
}

void Tranzactie::setIdPiramida(int id_piramida) {
    this->id_piramida = id_piramida;
}

void Tranzactie::setPret(int pret) {
    this->pret = pret;
}

Tranzactie Tranzactie::str_to_ob(const string &line) {
    string parsed, id_trz, nume_faraon, id_piramida, pret;
    stringstream ss1(line);

    getline(ss1, parsed, ' ');
    id_trz = parsed;
    getline(ss1, parsed, ' ');
    nume_faraon = parsed;
    getline(ss1, parsed, ' ');
    id_piramida = parsed;
    getline(ss1, parsed, ' ');
    pret = parsed;
    return Tranzactie(stoi(id_trz) , nume_faraon, stoi(id_piramida), stoi(pret));
}

string Tranzactie::ob_to_str() {
    string line;
    line += to_string(this->get_id()) + " " + this->nume_faraon + " " + to_string(this->id_piramida) + " " + to_string(this->pret) + ";";
    return line;
}

void Tranzactie::toString() const {
    printf("\nTranzactia cu id-ul: %d, numele faraonului: %s, id-ul piramidei: %d si pretul: %d", this->id_entitate, this->nume_faraon.c_str(), this->id_piramida, this->pret);
}
