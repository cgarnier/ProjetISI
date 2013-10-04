/*
 * Bench.cpp
 *
 *  Created on: 2 nov. 2012
 *      Author: clement
 */

#include "Bench.h"


using namespace std;
Bench::Bench(const string& label) : label(label) {
}

Bench::~Bench() {

}

void Bench::start() {
	std::cout << "[ Start Bench : " << label << " ]" << endl;
	_t = clock();
}

void Bench::stop() {
	_t = clock() -_t;
	show();
}

void Bench::show() {
	cout << "[ Stop bench: " << label << " - " << _t << " ticks  ]" << endl;
}
