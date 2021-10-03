#pragma once
#include "Entitate.h"
#include "GenericRepo.h"

class Piramida: public Entitate{
private:
    string marime;
    int pret;
public:
    inline static RepositoryFile<Piramida> repo;
    Piramida();
    Piramida(int id, string marime, int pret);
    ~Piramida() = default;
    void setMarime(const string& marime);
    void setPret(int pret);
    string getMarime();
    [[nodiscard]] int getPret() const;
    static Piramida str_to_ob(const string&);
    string ob_to_str();
    void toString() const;
    static void getSize();
};

Piramida::Piramida() {
    this->marime = ' ';
    this->pret = 0;
}

Piramida::Piramida(int id, string marime, int pret) {
    this->id_entitate = id;
    this->marime = std::move(marime);
    this->pret = pret;
}

void Piramida::setMarime(const string& marime) {
    this->marime = marime;
}

void Piramida::setPret(int pret) {
    this->pret = pret;
}

string Piramida::getMarime() {
    return this->marime;
}

int Piramida::getPret() const {
    return this->pret;
}

Piramida Piramida::str_to_ob(const string & line) {
    string parsed,id, marime, pret;
    stringstream ss1(line);

    getline(ss1, parsed, ' ');
    id = parsed;
    getline(ss1, parsed, ' ');
    marime = parsed;
    getline(ss1, parsed, ' ');
    pret = parsed;

    return Piramida(stoi(id) , marime, stoi(pret));
}

string Piramida::ob_to_str() {
    string line;
    line += to_string(this->get_id()) + " " + this->getMarime() + " " + to_string(this->getPret()) + ";";
    return line;
}

void Piramida::toString() const {
    printf("\nPiramida cu id-ul %d, marimea %s, pretul %d", this->id_entitate, this->marime.c_str(), this->pret);
}

void Piramida::getSize() {
    printf("\n\nCurrent repository size: %u\n", repo.getFromFile().size());
}
