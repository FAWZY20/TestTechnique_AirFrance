#include "OAndD.h"

class FlightNbr
{
private:
    std::string numVol;
    OAndD od;

public:
    FlightNbr(std::string numVol, OAndD &od) : numVol(numVol), od(od) {}

    std::string getNumVol() const
    {
        return numVol;
    }

    void setNumVol(std::string newNumVol)
    {
        numVol = newNumVol;
    }

    OAndD getOD() const
    {
        return od;
    }

    void setOD(OAndD newOD)
    {
        od = newOD;
    }
};

void exportCsvFlightNbr(FlightNbr flightNbr)
{
    std::ofstream fichier("../data/nomFichier.csv");
    fichier << "NuméroDeVol;Origine;Destination;Tarif;TarifMinimum;TarifMaximum;TarifMoyen" << std::endl;
    fichier << flightNbr.getNumVol() << ";" << flightNbr.getOD().getOrigine() << ";" << flightNbr.getOD().getDestination() << ";" << *flightNbr.getOD().getTarifs().begin() << std::endl;
}
