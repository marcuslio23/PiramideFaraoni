#pragma once
#pragma comment(lib, "Winmm.lib")
#include "ServicePiramide.h"
#include "ServiceFaraoni.h"
#include "ServiceTranzacti.h"

class Console
{
    static void printmenu() {
        cout << "\n================MAIN MENU================\n1. CRUD Piramide\n2. CRUD Faraoni\n3. CRUD Tranzacti\n4. CUMPARA & MORE\nX. Exist\n=========================================\n";
    }

    static void printCRUD_P() {
        cout<< "\n=============CRUD PIRAMIDE=============\n1. Create\n2. Show\n3. Update\n4. Delete\nB. Back to menu\n=========================================\n\n";
    };

    static void printCRUD_F() {
        cout<< "\n=============CRUD FARAONI=============\n1. Create\n2. Show\n3. Update\n4. Delete\nB. Back to menu\n=========================================\n\n";
    };

    static void printCRUD_T() {
        cout<< "\n=============CRUD Tranzactii=============\n1. Show\n2. Update\n3. Delete\nB. Back to menu\n=========================================\n\n";
    };

    static void printFunctionalitati() {
        cout<< "\n=============CUMPARA & MORE=============\n1. Cumpara piramida\n2. Tranzactii sortate crescator dupa pret\n3. Cea mai scumpa tranzactie\n4. Tranzactii mai mari de 10k\nB. Back to menu\n=========================================\n\n";
    };

    static bool isInt(const string& str){
        for(auto caracter: str) {
            if (!isdigit(caracter)) return false;
        }
        return true;
    }

    int handle_createP() {
        int ide;
        string marime, pret;
        cout<<"\nID: ";
        cin>>ide;
        if(ServicePiramida::id_check(ide))
        {
            printf("\nExista o entitate cu id-ul %d\n", ide);
            return handle_createP();
        }
        cout<<"\nMarime: ";
        cin>>marime;
        while(true){
            cout<<"\nPret: ";
            cin >> pret;
            if(!isInt(pret) || stoi(pret) <= 0)
            {
                printf("\nNumar invalid pt pret -> %d\n", stoi(pret));
            }
            else break;
        }

        ServicePiramida::create_piramida(ide, marime, stoi(pret));
    }

    int handle_updateP() {
        int ide;
        string marime, pret;
        cout<<"\nID: ";
        cin>>ide;
        if(!ServicePiramida::id_check(ide))
        {   printf("\nNu exista o entitate cu id-ul %d\n", ide);
            return handle_updateP();
        }
        cout<<"\nMarime: ";
        cin>>marime;
        while(true){
            cout<<"\nNoul pret: ";
            cin >> pret;
            if(!isInt(pret) || stoi(pret) <= 0)
            {
                printf("\nNumar invalid pt pret -> %d\n", stoi(pret));
            }
            else break;}

        ServicePiramida::update_piramida(ide, marime, stoi(pret));
    }

    int handle_deleteP() {
        int ide;
        cout<<"\nID-ul entitatii care se va sterge: ";
        cin>>ide;
        if(!ServicePiramida::id_check(ide))
        {   printf("\nNu exista o entitate cu id-ul %d\n", ide);
            return handle_deleteP();
        }
        ServicePiramida::delete_piramida(ide);
    }

    int handle_createF() {
        int ide;
        string nume;
        cout<<"\nID: ";
        cin>>ide;
        if(ServiceFaraoni::id_check(ide))
        {
            printf("\nExista o entitate cu id-ul %d\n", ide);
            return handle_createP();
        }
        cout<<"\nNume: ";
        cin>>nume;

        ServiceFaraoni::create_faraon(ide, nume);
    }

    int handle_updateF() {
        int ide;
        string nume;
        cout<<"\nID: ";
        cin>>ide;
        if(!ServiceFaraoni::id_check(ide))
        {
            printf("\nNu exista o entitate cu id-ul %d\n", ide);
            return handle_createP();
        }
        cout<<"\nNume: ";
        cin>>nume;

        ServiceFaraoni::update_faraon(ide, nume);
    }

    int handle_deleteF() {
        int ide;
        cout<<"\nID-ul entitatii care se va sterge: ";
        cin>>ide;
        if(!ServiceFaraoni::id_check(ide))
        {   printf("\nNu exista o entitate cu id-ul %d\n", ide);
            return handle_deleteF();
        }
        ServiceFaraoni::delete_faraon(ide);
    }

    int handle_createT() {
        int id_trz, id_piramida, id_faraon;

        cout<<"\nID-trz: ";
        cin>>id_trz;
        if(ServiceTranzacti::id_check(id_trz))
        {
            try {
                throw (Exceptie(("\nExista o entitate cu id-ul dat.\n")));
            }catch(Exceptie& e){cout<<e.getMessage();};
            handle_createT();
        }

        cout<<"\nId-faraon: ";
        cin>>id_faraon;
        while(!ServiceFaraoni::id_check(id_faraon)){
            printf("\nNu exista un faraon cu id-ul %d\n" , id_faraon);
            cout<<"\nId-faraon: ";
            cin>>id_faraon;
        }

        cout<<"\nId-piramida: ";
        cin>>id_piramida;
        while(!ServicePiramida::id_check(id_piramida)){
            printf("\nNu exista piramida cu id-ul %d\n" , id_piramida);
            cout<<"Id-piramida: ";
            cin>>id_piramida;
        }

        ServiceTranzacti::create_tranzactie(id_trz, Faraon::repo.findbyid(id_faraon).getNume(), id_piramida, Piramida::repo.findbyid(id_piramida).getPret());
    }

    int handle_updateT() {
        int id_trz, id_piramida, id_faraon;

        cout<<"\nID-trz: ";
        cin>>id_trz;
        if(!ServiceTranzacti::id_check(id_trz))
        {
            printf("\nNu exista o entitate cu id-ul %d\n", id_trz);
            return handle_updateT();
        }

        cout<<"\nId-faraon: ";
        cin>>id_faraon;
        while(!ServiceFaraoni::id_check(id_faraon)){
            printf("\nNu exista un faraon cu id-ul %d\n" , id_faraon);
            cout<<"\nId-faraon: ";
            cin>>id_faraon;
        }

        cout<<"Id-piramida: ";
        cin>>id_piramida;
        while(!ServicePiramida::id_check(id_piramida)){
            printf("\nNu exista piramida cu id-ul %d\n" , id_piramida);
            cout<<"Id-piramida: ";
            cin>>id_piramida;
        }

        ServiceTranzacti::update_tranzactie(id_trz, Faraon::repo.findbyid(id_faraon).getNume(), id_piramida, Piramida::repo.findbyid(id_piramida).getPret());

    }

    int handle_deleteT() {
        int ide;
        cout<<"\nID-ul entitatii care se va sterge: ";
        cin>>ide;
        if(!ServiceTranzacti::id_check(ide)){
            printf("\nNu exista o entitate cu id-ul %d\n", ide);
            return handle_deleteT();
        }
        ServiceTranzacti::delete_tranzactie(ide);
    }


public:
    static void handle_trz_sort_cresc_dupa_pret() {
        vector<Tranzactie> rez = ServiceTranzacti::trz_crescator();
        for(const auto& tranzactie: rez)
            tranzactie.toString();
    }

    static void handle_cea_mai_scuma_trz() {
        ServiceTranzacti::trz_cea_mai_scumpa().toString();
    }

    static void handle_trz_mai_mari_de_10k() {
        vector<Tranzactie> rez = ServiceTranzacti::trz_mai_mari_de_10k();
        for(auto const& trz: rez)
            trz.toString();
    }

    void run_console() {
        mciSendString(R"(open "C:\Users\Asus\CLionProjects\PiramideFaraoni\piesa.mp3" type mpegvideo alias mp3)", nullptr, 0, nullptr);
        mciSendString("play mp3 repeat", nullptr, 0, nullptr);

        while (true) {
            printmenu();
            char answer;
            cin >> answer;

            if(answer == '1')
                while (true) {
                    printCRUD_P();
                    char answer1;
                    cin >> answer1;
                    if (answer1 == '1')
                        handle_createP();
                    else if (answer1 == '2')
                    {ServicePiramida::show_all_piramide();
                        cout<<"\n";}
                    else if (answer1 == '3')
                        handle_updateP();
                    else if (answer1 == '4')
                        handle_deleteP();
                    else if (answer1 == 'b')
                        break;
                    else cout << "\nInvalid input\n\n";}

            if(answer == '2')
                while (true) {
                    printCRUD_F();
                    char answer1;
                    cin >> answer1;
                    if (answer1 == '1')
                        handle_createF();
                    else if (answer1 == '2')
                    {ServiceFaraoni::show_all_faraoni();
                        cout<<"\n";}
                    else if (answer1 == '3')
                        handle_updateF();
                    else if (answer1 == '4')
                        handle_deleteF();
                    else if (answer1 == 'b')
                        break;
                    else cout << "\nInvalid input\n\n";}

            if(answer == '3')
                while (true) {
                    printCRUD_T();
                    char answer1;
                    cin >> answer1;
                    if (answer1 == '1')
                    {ServiceTranzacti::show_all_tranzactii();
                        cout<<"\n";}
                    else if (answer1 == '2')
                        handle_updateT();
                    else if (answer1 == '3')
                        handle_deleteT();
                    else if (answer1 == 'b')
                        break;
                    else cout << "\nInvalid input\n\n";}

            else if(answer == '4')
                while (true) {
                    printFunctionalitati();
                    char answer1;
                    cin >> answer1;
                    if (answer1 == '1')
                        handle_createT();
                    else if (answer1 == '2')
                        handle_trz_sort_cresc_dupa_pret();
                    else if (answer1 == '3')
                        handle_cea_mai_scuma_trz();
                    else if (answer1 == '4')
                        handle_trz_mai_mari_de_10k();
                    else if (answer1 == 'b')
                        break;
                    else cout << "\nInvalid input\n\n";}

            else if (answer == 'x')
                break;
            else cout << "\nInvalid input\n\n";
        }
    }
};