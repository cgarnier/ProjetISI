#include "cylinder.h"

using namespace std;
Cylinder::Cylinder(GLint nb) :
		TriMesh() {
	_name = "Cylinder";

	// Nombre de point sur la circonference minimum
	if (nb < 3)
		nb = 3;

	GLint nbCercle = nb / 4;

	// Nombre de cercle intermediaire min
	if (nbCercle < 2)
		nbCercle = 2;

	GLfloat rayon = 1;
	GLfloat centre[3] = { 0, 0, 0 };

	// Pre calcul des cos et sin
	vector<GLfloat> tempSin;
	vector<GLfloat> tempCos;
	for (GLint j = 0; j < nb; ++j) {
		tempCos.push_back(cosf(2 * j * M_PI / nb));
		tempSin.push_back(sinf(2 * j * M_PI / nb));
	}

	GLfloat t;

	for (GLint i = 0; i < nbCercle + 1; ++i) {
		t = (1.0 / nbCercle) * i;
		// Calcul centre du cercle
		centre[0] = (1 - t) * 2 - 1;

		for (GLint j = 0; j < nb; ++j) {
			addVertex(centre[0], rayon * tempSin.at(j), rayon * tempCos.at(j));

		}

	}
	// Ajout des poles
	addVertex(1, 0, 0);
	addVertex(-1, 0, 0);

	// Surfaces

	GLint ptId0, ptId1, ptId2;
	for (GLint i = 0; i < nbCercle; ++i) {

		for (GLint j = 0; j < nb; ++j) {

			ptId0 = i * nb + j;
			if (j + 1 >= nb)
				ptId1 = i * nb;
			else
				ptId1 = i * nb + j + 1;

			ptId2 = (i + 1) * nb + j;

			addTriangle(ptId0, ptId1, ptId2);

			////

			if (j + 1 >= nb) {
				ptId0 = i * nb;
				ptId1 = (i + 1) * nb;
			} else {
				ptId0 = i * nb + j + 1;
				ptId1 = (i + 1) * nb + j + 1;
			}

			ptId2 = (i + 1) * nb + j;

			addTriangle(ptId0, ptId1, ptId2);

		}

	}
	// Les poles
	for (GLint i = 0; i < nb; ++i) {
		ptId0 = i;
		if (i >= nb - 1)
			ptId1 = 0;
		else
			ptId1 = i + 1;
		ptId2 = (nbCercle + 1) * nb;
		addTriangle(ptId1, ptId0, ptId2);

	}
	for (GLint i = 0; i < nb; ++i) {
		ptId0 = (nbCercle) * nb + i;
		if (i >= nb - 1)
			ptId1 = (nbCercle) * nb;
		else
			ptId1 = (nbCercle) * nb + i + 1;
		ptId2 = (nbCercle + 1) * nb + 1;
		addTriangle(ptId0, ptId1, ptId2);

	}



	tempCos.clear();
	tempSin.clear();

	computeNormalsT();
	computeNormalsV();
}
