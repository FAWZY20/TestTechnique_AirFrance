
#include <vector>
#include "OAndD.h"
#include "FlightNbr.h"

int main()
{
    std::vector<OAndD> donnees = lireCSVetConstruireOD("OrigineDestinationTarif.csv");
    exportCsvAllTarif(donnees);
    return 0;
}
