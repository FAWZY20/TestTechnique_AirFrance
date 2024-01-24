
#include <vector>
#include "OAndD.h"
#include "FlightNbr.h"

int main()
{

    std::vector<OAndD> donnees = lireCSVetConstruireOD("OrigineDestinationTarif.csv");
    
    if (!donnees.empty())
    {
        for (const OAndD od : donnees)
        {
            od.afficherInformations();
        }

        exportCsv(donnees, "CDG", "JFK");
    }
    else
    {
        std::cout << "Error: Aucune donnée n'a été lue à partir du fichier CSV." <<  std::endl;
    }

    return 0;
}
