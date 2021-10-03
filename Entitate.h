#pragma once
#include "Exceptie.h"

class Entitate{
public:
    int id_entitate;
    Entitate();
    [[nodiscard]] int get_id() const;
    virtual void toString() const;
};

Entitate::Entitate() {
    this->id_entitate = 0;
}

int Entitate::get_id() const {
    return this->id_entitate;
}

void Entitate::toString() const {
    printf("Entity with id %d", this->id_entitate);
}
