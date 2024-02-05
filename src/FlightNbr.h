#include "OAndD.h"
using namespace std;

class FlightNbr
{
private:
    string numVol;
    OAndD od;

public:
    FlightNbr(string numVol, OAndD &od) : numVol(numVol), od(od) {}

    string getNumVol() const
    {
        return numVol;
    }

    void setNumVol(string newNumVol)
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
    ofstream fichier("data/" + flightNbr.getNumVol() + "_" + flightNbr.getOD().getOrigine() + "&" + flightNbr.getOD().getDestination() + ".csv");
    fichier << "NuméroDeVol;Origine;Destination;Tarif;TarifMinimum;TarifMaximum;TarifMoyen" << endl;
    fichier << flightNbr.getNumVol() << ";" << flightNbr.getOD().getOrigine() << ";" << flightNbr.getOD().getDestination() << ";" << *flightNbr.getOD().getTarifs().begin() << endl;
}
