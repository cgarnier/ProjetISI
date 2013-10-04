#include "off_loader.h"
#include <fstream>
#include <sstream>

using namespace std;
Off_Loader::Off_Loader(const string& path) :
		TriMesh() {
	_name = "OffObject";

	// Ouverture du fichier en lecture
	ifstream fichier(path.c_str(), ios::in);

	if (fichier) {
		string contenu;

		// Compteurs de lignes
		int lineCpt = 0;
		int cpt = 0;

		// Nombre de point et de polygones
		int ptNb, trNb;

		bool isCfg = false;

		// Lecture
		while (getline(fichier, contenu)) {


			if (lineCpt == 0) {
				// Fichier OFF?
				if (contenu.at(0) != 'O' || contenu.at(1) != 'F'
						|| contenu.at(2) != 'F') {
					fichier.close();
					throw "Fichier non compatible ";
				}
			} else {

				// Ligne contenant des donnees
				if (contenu.size() > 0 && contenu.at(0) != '#') {
					if (!isCfg) {

						// La premiere ligne de donnee est celle qui definie la structure du fichier
						vector<int> elems;
						string buf;
						stringstream ss(contenu);

						while (ss >> buf) {
							int number;
							std::istringstream ss(buf);
							ss >> number;
							elems.push_back(number);
						}

						// Information sur la structure
						ptNb = elems.at(0);
						trNb = elems.at(1);
						isCfg = true;

					} else {

						// La ligne concerne un point
						if (cpt < ptNb) {
							vector<float> elems;
							string buf;
							stringstream ss(contenu);

							while (ss >> buf) {
								float number;
								std::istringstream ss(buf);
								ss >> number;
								elems.push_back(number);
							}

							addVertex(elems.at(0), elems.at(1), elems.at(2));
						}
						// La ligne concerne un polygone
						else {
							// Points du polygone
							vector<int> elems;
							// Couleur du polygone
							Color color;

							// L element fait parti d un commentaire ?
							bool ignore = false;

							// Nombre de points du polygone
							int nbPt = 0;
							// Compteur de points
							int cptPt = 0;

							// Parse
							string buf;
							stringstream ss(contenu);


							while (ss >> buf) {
								// Detection des commentaires
								if(buf.at(0) == '#') ignore = true;

								if (!ignore) {
									// L'element est l'index d'un point du polygone
									if (cptPt <= nbPt) {
										int number;
										std::istringstream ss(buf);
										ss >> number;
										elems.push_back(number);
										if (cptPt == 0)
											nbPt = number;

									}
									// L'element est une valeur RGBA
									// @fix Support colormap, RGBA int
									else {
										float number;
										std::istringstream ss(buf);
										ss >> number;
										color.push_back(number);

									}
									cptPt++;
								}
							}

//////// Polygones a 3 sommets
//							if(elems.at(0) == 3)
//							addTriangle(elems.at(1), elems.at(2), elems.at(3));
//							else{
//								throw "Le programme ne suporte que les polygognes a 3 sommets.";
//
//							}

							// Triangulisation et colorisation du polygone
							triangulize(elems, color);
						}
						cpt++;
					}
				}
			}
			lineCpt++;
		}
		fichier.close();
	} else
		throw "Impossible d'ouvrir le fichier.";

	computeNormalsT();
	computeNormalsV();
}
void Off_Loader::triangulize(vector<int> elems, Color color) {
	/* Algoritme simplifier de triangularisation
	 * 		Relie un point a son voisin et au dernier point.
	 * 		Pas compatible avec les polygones avec des oreilles ou des trous
	 */
	for (int i = 1; i < elems.at(0) - 1; ++i) {
		addTriangle(elems.at(i), elems.at(i + 1), elems.at(elems.at(0)));

		// RGBA par defaut
		if (color.size() < 3) {
			Color c;
			c.push_back(1.0);
			c.push_back(0.0);
			c.push_back(0.0);
			c.push_back(1.0);
			addTriangleColor(c);
		} else {
			// Alpha par defaut
			if (color.size() < 4)
				color.push_back(1.0);

			// Aplication de la couleur
			addTriangleColor(color);
		}
	}
}
