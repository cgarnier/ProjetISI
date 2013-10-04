#include "disk.h"

using namespace std;
Disk::Disk(int nb) :
		TriMesh() {
	_name = "Dsik";



	GLint nbCercle = nb / 4;
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

	for (GLint i = 0; i < nbCercle +1 ; ++i) {
		// Ratio
		t = (1.0 / nbCercle) * i;
		// Calcul centre du cercle
		centre[0] = 0;

		rayon = t;

		for (GLint j = 0; j < nb; ++j)
			addVertex(centre[0], rayon * tempSin.at(j), rayon * tempCos.at(j));

	}
	addVertex(0, 0, 0);


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

	// Centres
	for (GLint i = 0; i < nb; ++i) {
		ptId0 = i;
		if (i >= nb - 1)
			ptId1 = 0;
		else
			ptId1 = i + 1;
		ptId2 = (nbCercle + 1) * nb;
		addTriangle(ptId1,ptId0, ptId2);

	}

	tempCos.clear();
	tempSin.clear();

	computeNormalsT();
	computeNormalsV();
}
