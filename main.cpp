#include "Console.h"
#include "Tests.h"

int main() {
    RepositoryFile<Piramida> testrepoP("test_repoP.csv");
    Piramida::repo = testrepoP;
    RepositoryFile<Faraon> testrepoF("test_repoF.csv");
    Faraon::repo = testrepoF;
    RepositoryFile<Tranzactie> testrepoT("test_repoT.csv");
    Tranzactie::repo = testrepoT;
    tests();

    ofstream fclear("piramide.csv");
    fclear.close();

    RepositoryFile<Piramida> repoP("piramide.csv");
    Piramida::repo = repoP;

    string nume1 = "mica", nume2 = "medie", nume3 = "mare", nume4 = "delux", nume5 = "delux++", nume6 = "zeuLv", nume7 = "Tutankamun";
    Piramida::repo.create(Piramida(1, nume1, 5000));
    Piramida::repo.create(Piramida(2, nume2, 60000));
    Piramida::repo.create(Piramida(3, nume3, 8000000));
    Piramida::repo.create(Piramida(4, nume4, 30000000));
    Piramida::repo.create(Piramida(5, nume5, 100000000));
    Piramida::repo.create(Piramida(6, nume6, 150000000));
    Piramida::repo.create(Piramida(7, nume7, 2000000000));

    RepositoryFile<Faraon> repoF("faraoni.csv");
    Faraon::repo = repoF;

    RepositoryFile<Tranzactie> repoT("tranzactii.csv");
    Tranzactie::repo = repoT;

    int array[2][2] = {0, 1, 2, 3};

    int i;

    int sum = 0;

    for (i =0; i < 4; ++i){

        int x, y;

        x = i % 2;

        if (x){y = 0 ;}

        else{y = 1;}

        sum += array[x][y];

    }

    cout<<sum<<endl;

    Console console;
    console.run_console();
    return 0;
}
