#include "OAndD.h"

class FlightNbr
{
private:
    char numVol;
    OAndD od;

public:

    FlightNbr(char numVol, OAndD& od): numVol(numVol), od(od) {}

    char getNumVol() const
    {
        return numVol;
    }

    void setNumVol(char newNumVol)
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
