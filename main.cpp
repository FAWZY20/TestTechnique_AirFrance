
#include <vector>
#include "src/OAndD.h"
#include "src/FlightNbr.h"

using namespace std;

int main()
{
  // Tarifs min, max , moy
  /*
  set<long> tarifs = {100, 220, 450};
  OAndD od("CDG", "JFK", tarifs);
  cout << "Tarif max : " << tarifMax(od.getTarifs()) << " Tarif min : " << tarifMin(od.getTarifs()) << " Tarif moyen : " << tarifMoy(od.getTarifs()) << endl;
  */
  // Lire le OrigineDestinationTarif dans un objet OAndD
  /*
    vector<OAndD> listTrajet = lireCSVetConstruireOD("data/OrigineDestinationTarif.csv");
    afficherInformations(listTrajet);
    */

  // exporter dans un fichier donné en paramètre la ligne suivante : Origine,Destination,TarifMinimum,TarifMaximum,TarifMoyen
  /*
   string origine;
   string destination;
   vector<OAndD> listTrajet = lireCSVetConstruireOD("data/OrigineDestinationTarif.csv");

   cout << "quel est votre pays d'Origine ?" <<  endl;
   cin >> origine;

   cout << "quel est votre pays de destination ?" <<  endl;
   cin >> destination;

  exportCsv(listTrajet, origine, destination);


  // pour chaque objet O&D stocké à la question 4 la ligne définie à la question 5, dans un seul et même fichier
  /*
    vector<OAndD> listTrajet = lireCSVetConstruireOD("data/OrigineDestinationTarif.csv");
   exportCsvAllTarif(listTrajet);
  */

  // Numero de vol

  set<long> tarifs;
  tarifs.insert(365);

  OAndD od("CDG", "LGA", tarifs);
  FlightNbr flightNbr("A5486", od);

  exportCsvFlightNbr(flightNbr);

  return 0;
}