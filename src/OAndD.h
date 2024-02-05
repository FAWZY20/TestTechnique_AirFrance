#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class OAndD
{
private:
    string origine;
    string destination;
    set<long> tarifs;

public:
    OAndD(const string &origine, const string &destination, const set<long> &tarifs)
    {
        this->origine = origine;
        this->destination = destination;
        this->tarifs = tarifs;
    }

    string getOrigine() const
    {
        return origine;
    }

    void setOrigine(string newOrigine)
    {
        origine = newOrigine;
    }

    string getDestination() const
    {
        return destination;
    }

    void setDestination(string newDestination)
    {
        destination = newDestination;
    }

    set<long> getTarifs() const
    {
        return tarifs;
    }

    void setTarifs(set<long> newTarifs)
    {
        tarifs = newTarifs;
    }
};

long tarifMin(const set<long> &tarifs)
{
    long min = *tarifs.begin();
    for (long tarif : tarifs)
    {
        if (tarif < min)
        {
            min = tarif;
        }
    }
    return min;
}

long tarifMax(const set<long> &tarifs)
{
    long max = *tarifs.begin();

    for (long tarif : tarifs)
    {
        if (max < tarif)
        {
            max = tarif;
        }
    }
    return max;
}

long tarifMoy(const set<long> tarifs)
{
    long total = *tarifs.begin();
    for (long tarif : tarifs)
    {
        total += tarif;
    }
    return total / tarifs.size();
}

// pouvoir afficher sur la console les données d'une structure de données sous forme d’objet O&D

void afficherInformations(vector<OAndD> listTrajet)
{
    for (const auto &od : listTrajet)
    {
        cout << "origine: " << od.getOrigine() << ", destination: " << od.getDestination() << ", tarif :";
        for (long tarif : od.getTarifs())
        {
            cout << tarif << " ";
        }
        cout << endl;
    }
}

// parcourir la liste des tarif pour chaque objet O&D stocké en function d'une origine et une destination

set<long> listTarif(vector<OAndD> data, string origine, string destination)
{
    set<long> listTarif;

    for (OAndD ob : data)
    {
        if (ob.getOrigine() == origine && ob.getDestination() == destination)
        {
            long tarif = *ob.getTarifs().begin();
            listTarif.insert(tarif);
        }
    }

    return listTarif;
}

vector<OAndD> lireCSVetConstruireOD(string cheminFichier)
{
    vector<OAndD> donnees;

    ifstream fichierCSV(cheminFichier);

    if (!fichierCSV.is_open())
    {
        cout << "Erreur: Impossible d'ouvrir le fichier " << cheminFichier << endl;
        return donnees;
    }

    string ligne;

    while (getline(fichierCSV, ligne))
    {
        istringstream ss(ligne);
        string origine;
        string destination;
        string tarifStr;

        if (ligne.find("Tarif") != string::npos)
        {
            continue;
        }

        if (getline(ss, origine, ';') &&
            getline(ss, destination, ';') &&
            getline(ss, tarifStr, ';'))
        {
            try
            {
                set<long> tarifs = {stol(tarifStr)};
                donnees.emplace_back(origine, destination, tarifs);
            }
            catch (const invalid_argument &e)
            {
                cout << "Erreur de conversion de la chaîne en entier : " << tarifStr << endl;
            }
        }
        else
        {
            cout << "Erreur de lecture de la ligne : " << ligne << endl;
        }
    }

    fichierCSV.close();

    return donnees;
}

void exportCsv(vector<OAndD> &data, const string origine, const string destination)
{

    ofstream monFichier("data/" + origine + "&" + destination + ".csv");
    monFichier << "Origine;Destination;TarifMinimum;TarifMaximum;TarifMoyen" << endl;

    set<long> lTarif = listTarif(data, origine, destination);
    monFichier << origine << ";" << destination << ";" << tarifMin(lTarif) << ";" << tarifMax(lTarif) << ";" << tarifMoy(lTarif) << endl;
}

void exportCsvAllTarif(vector<OAndD> &data)
{
    ofstream fichier("data/allDestiationTarif.csv");
    fichier << "Origine;Destination;Tarif;TarifMinimum;TarifMaximum;TarifMoyen" << endl;

    for (OAndD od : data)
    {
        set<long> lTarif = listTarif(data, od.getOrigine(), od.getDestination());
        fichier << od.getOrigine() << ";" << od.getDestination() << ";" << *od.getTarifs().begin() << ";" << tarifMin(lTarif) << ";" << tarifMax(lTarif) << ";" << tarifMoy(lTarif) << endl;
    }
}
