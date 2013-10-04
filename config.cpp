/*
 * config.cpp
 *
 *  Created on: 31 oct. 2012
 *      Author: clement
 */

#include "config.h"

Config::Config(const int& argc, char* argv[]) :
		 func1(false), func2(
				false), func3(false), offFile(false), offPath(""), mesh(false) {

	// TCLAP
	try{
			TCLAP::CmdLine cmd("Visualisation d'objets 3D.", ' ', "1");
			TCLAP::ValueArg<string> offArg("", "off", "Charger un object OFF", false,"exemple.off", "string");
			TCLAP::SwitchArg meshArg("m", "mesh", "Charger les objets à base de triangle. Naviguer avec F1,F2 ..", cmd, false);
			TCLAP::SwitchArg func1Arg("", "func1", "Charger la fonction de surface exp(-(x*x/2 + y*y/2))*cos(2*x*x + 2*y*y)", cmd, false);
			TCLAP::SwitchArg func2Arg("", "func2", "Charger la fonction de surface x*exp(-x*x-y*y)", cmd, false);
			TCLAP::SwitchArg func3Arg("", "func3", "Charger la fonction de surface sin(x) - sin(y) + sin(10x)/10 + sin(10y)/y", cmd, false);

			cmd.add(offArg);

			cmd.parse(argc, argv);

			if(offArg.isSet()){
				offFile = true;
				offPath = offArg.getValue();

			}
			mesh = meshArg.getValue();
			func1 = func1Arg.getValue();
			func2 = func2Arg.getValue();
			func3 = func3Arg.getValue();

		}catch (TCLAP::ArgException &e)
		{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }

}

Config::~Config() {

}

