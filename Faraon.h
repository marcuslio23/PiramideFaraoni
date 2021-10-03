#pragma once
#include "Entitate.h"
#include "GenericRepo.h"

class Faraon: public Entitate{
private:
    string nume;
public:
    inline static RepositoryFile<Faraon> repo;
    Faraon();
    Faraon(int id, string nume);
    ~Faraon() = default;
    void setNume(string nume);
    string getNume();
    static Faraon str_to_ob(const string&);
    string ob_to_str();
    void toString() const;
    static void getSize();
};

Faraon::Faraon() {
    this->nume = ' ';
}

Faraon::Faraon(int id, string nume) {
    this->id_entitate = id;
    this->nume = std::move(nume);
}

void Faraon::setNume(string nume) {
    this->nume = std::move(nume);
}

string Faraon::getNume() {
    return this->nume;
}

Faraon Faraon::str_to_ob(const string &line) {
    string parsed,id, nume;
    stringstream ss1(line);

    getline(ss1, parsed, ' ');
    id = parsed;
    getline(ss1, parsed, ' ');
    nume = parsed;

    return Faraon(stoi(id) , nume);
}

string Faraon::ob_to_str() {
    string line;
    line += to_string(this->get_id()) + " " + this->nume + ";";
    return line;
}

void Faraon::toString() const {
    printf("\nFaraonul cu id-ul: %d, numele: %s", this->id_entitate, this->nume.c_str());
}

void Faraon::getSize() {
    printf("\n\nCurrent repository size: %u\n", repo.getFromFile().size());
}
