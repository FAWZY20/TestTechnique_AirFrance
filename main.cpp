
#include <vector>
#include "src/OAndD.h"
#include "src/FlightNbr.h"

int main()
{
    // Tarifs min, max , moy

    /*
    std::set<long> tarifs = {100, 220, 450};
    OAndD od("CDG", "JFK", tarifs);
    std::cout << "Tarif max : " << tarifMax(od.getTarifs()) << " Tarif min : " << tarifMin(od.getTarifs()) << " Tarif moyen : " << tarifMoy(od.getTarifs()) << std::endl;
    */

    // Lire le OrigineDestinationTarif dans un objet OAndD

    /*
    std::vector<OAndD> listTrajet = lireCSVetConstruireOD("data/OrigineDestinationTarif.csv");
    afficherInformations(listTrajet);
    */

    // exporter dans un fichier donné en paramètre la ligne suivante : Origine,Destination,TarifMinimum,TarifMaximum,TarifMoyen

    /*
    std::string origine;
    std::string destination;   
    std::vector<OAndD> listTrajet = lireCSVetConstruireOD("data/OrigineDestinationTarif.csv");
 
    std::cout << "quel est votre pays d'Origine ?" << std::endl;
    std::cin >> origine;

    std::cout << "quel est votre pays de destination ?" << std::endl;
    std::cin >> destination;

    exportCsv(listTrajet, origine, destination);
    */

    //pour chaque objet O&D stocké à la question 4 la ligne définie à la question 5, dans un seul et même fichier
    /*
     std::vector<OAndD> listTrajet = lireCSVetConstruireOD("data/OrigineDestinationTarif.csv");
     exportCsvAllTarif(listTrajet);
    */

    // Numero de vol
    
    /*
    std::set<long> tarifs;
    tarifs.insert(365);

    OAndD od("CDG", "EXJ", tarifs);
    FlightNbr flightNbr("A5486", od);

    exportCsvFlightNbr(flightNbr);
    */

    return 0;
}