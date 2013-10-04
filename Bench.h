/*
 * Bench.h
 *
 *  Created on: 2 nov. 2012
 *      Author: clement
 */

#ifndef BENCH_H_
#define BENCH_H_
#include <string>
#include <time.h>
#include <iostream>
using namespace std;
class Bench {
public:
	Bench(const string& label);
	virtual ~Bench();
	void start();
	void stop();
	void show();
private:
	string label;
	int _t;
};

#endif /* BENCH_H_ */
