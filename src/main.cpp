
#include <vector>
#include "OAndD.h"
#include "FlightNbr.h"

int main()
{
    std::set<long> tarifs;
    tarifs.insert(365);
    OAndD od("CDG", "EXJ", tarifs);  
    FlightNbr flightNbr("A5486", od);
    
    exportCsvFlightNbr(flightNbr);
    return 0;
}