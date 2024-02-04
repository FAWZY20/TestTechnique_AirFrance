#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

class OAndD
{
private:
    std::string origine;
    std::string destination;
    std::set<long> tarifs;

public:
    OAndD(const std::string &origine, const std::string &destination, const std::set<long> &tarifs)
    {
        this->origine = origine;
        this->destination = destination;
        this->tarifs = tarifs;
    }

    std::string getOrigine() const
    {
        return origine;
    }

    void setOrigine(std::string newOrigine)
    {
        origine = newOrigine;
    }

    std::string getDestination() const
    {
        return destination;
    }

    void setDestination(std::string newDestination)
    {
        destination = newDestination;
    }

    std::set<long> getTarifs() const
    {
        return tarifs;
    }

    void setTarifs(std::set<long> newTarifs)
    {
        tarifs = newTarifs;
    }
};

long tarifMin(const std::set<long> &tarifs)
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

long tarifMax(const std::set<long> &tarifs)
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

long tarifMoy(std::set<long> tarifs)
{
    long total = *tarifs.begin();
    for (long tarif : tarifs)
    {
        total += tarif;
    }
    return total / tarifs.size();
}

void afficherInformations(std::vector<OAndD> listTrajet)
{
    for (const auto &od : listTrajet)
    {
        std::cout << "origine: " << od.getOrigine() << ", destination: " << od.getDestination() << ", tarif :";
        for (long tarif : od.getTarifs())
        {
            std::cout << tarif << " ";
        }
        std::cout << std::endl;
    }
}

std::set<long> listTarif(std::vector<OAndD> data, std::string origine, std::string destination)
{
    std::set<long> listTarif;

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

std::vector<OAndD> lireCSVetConstruireOD(std::string cheminFichier)
{
    std::vector<OAndD> donnees;

    std::ifstream fichierCSV(cheminFichier);

    if (!fichierCSV.is_open())
    {
        std::cout << "Erreur: Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return donnees; // ou exit(1);
    }

    std::string ligne;

    while (std::getline(fichierCSV, ligne))
    {
        std::istringstream ss(ligne);
        std::string origine;
        std::string destination;
        std::string tarifStr;

        if (ligne.find("Tarif") != std::string::npos)
        {
            continue; // Passe à la ligne suivante
        }

        if (std::getline(ss, origine, ';') &&
            std::getline(ss, destination, ';') &&
            std::getline(ss, tarifStr, ';'))
        {
            try
            {
                long tarif = std::stol(tarifStr);
                std::set<long> tarifs = {tarif};
                donnees.emplace_back(origine, destination, tarifs);
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Erreur de conversion de la chaîne en entier : " << tarifStr << std::endl;
            }
        }
        else
        {
            std::cout << "Erreur de lecture de la ligne : " << ligne << std::endl;
        }
    }

    fichierCSV.close();

    return donnees;
}

void exportCsv(std::vector<OAndD> &data, const std::string origine, const std::string destination)
{

    std::ofstream monFichier("data/" + origine + "&" + destination + ".csv");
    monFichier << "Origine;Destination;TarifMinimum;TarifMaximum;TarifMoyen" << std::endl;
    std::set<long> lTarif = listTarif(data, origine, destination);
    monFichier << origine << ";" << destination << ";" << tarifMin(lTarif) << ";" << tarifMax(lTarif) << ";" << tarifMoy(lTarif) << std::endl;
}

void exportCsvAllTarif(std::vector<OAndD> &data)
{
    std::ofstream fichier("data/allDestiationTarif.csv");
    fichier << "Origine;Destination;Tarif;TarifMinimum;TarifMaximum;TarifMoyen" << std::endl;

    for (OAndD od : data)
    {
        std::set<long> lTarif = listTarif(data, od.getOrigine(), od.getDestination());
        fichier << od.getOrigine() << ";" << od.getDestination() << ";" << *od.getTarifs().begin() << ";" << tarifMin(lTarif) << ";" << tarifMax(lTarif) << ";" << tarifMoy(lTarif) << std::endl;
    }
}
