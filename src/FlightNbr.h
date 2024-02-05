#include "OAndD.h"
using namespace std;

class FlightNbr
{
private:
    char* numVol;
    OAndD od;

public:
    FlightNbr(char* numVol, OAndD &od) : numVol(numVol), od(od) {}

    char* getNumVol() const
    {
        return numVol;
    }

    void setNumVol(char* newNumVol)
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
    ofstream fichier("data/" + string(flightNbr.getNumVol()) + "_" + flightNbr.getOD().getOrigine() + "&" + flightNbr.getOD().getDestination() + ".csv");
    fichier << "NuméroDeVol;Origine;Destination;Tarif;TarifMinimum;TarifMaximum;TarifMoyen" << endl;
    fichier << flightNbr.getNumVol() << ";" << flightNbr.getOD().getOrigine() << ";" << flightNbr.getOD().getDestination() << ";" << *flightNbr.getOD().getTarifs().begin() << endl;
}
