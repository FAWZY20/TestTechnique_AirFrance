#include <iostream>
#include <string>
#include <set>

class OAndD
{
private:
    char origine;
    char destination;
    std::set<long> tarifs;

public:
    OAndD(char origine, char destination, std::set<long> tarifs)
    {
        this->origine = origine;
        this->destination = destination;
        this->tarifs = tarifs;
    }

    char getOrigine()
    {
        return origine;
    }

    void setOrigine(char newOrigine)
    {
        origine = newOrigine;
    }

    char getDestination()
    {
        return destination;
    }

    void setDestination(char newDestination)
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
};

long tarifMin(std::set<long> tarifs){
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

long tarifMax(std::set<long> tarifs){
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


long tarifMoy(std::set<long> tarifs){
    long total = 0;
    for (long tarif : tarifs)
    {
        total += tarif;
    }
    return total / tarifs.size();
}

void addFlight(){
    
}
