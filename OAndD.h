#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <sstream>

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

    std::string getOrigine()
    {
        return origine;
    }

    void setOrigine(std::string newOrigine)
    {
        origine = newOrigine;
    }

    std::string getDestination()
    {
        return destination;
    }

    void setDestination(std::string newDestination)
    {
        destination = newDestination;
    }

    std::set<long> getTarifs()
    {
        return tarifs;
    }

    void setTarifs(std::set<long> newTarifs)
    {
        tarifs = newTarifs;
    }

    void afficherInformations() const
    {
        std::cout << "origine: " << origine << ", destination: " << destination << ", tarif :";
        for (long tarif : tarifs)
        {
            std::cout << tarif << " ";
        }
        std::cout << std::endl;
    }
};

long tarifMin(const std::set<long> &tarifs)
{
    long min = 0;
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
    long max = 0;
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
    long total = 0;
    for (long tarif : tarifs)
    {
        total += tarif;
    }
    return total / tarifs.size();
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
