/**
 * @file   main.cpp
 * @author Bruno Jobard
 * @author Author1
 * @author Author2
 * @date   Sep 2012
 * 
 * @brief  Declares an application, a main window and a 3D scene
 * 
 * 
 */
#include <QApplication>
#include <time.h>
#include <tclap/CmdLine.h>

#include "my_main_window.h"

#include "my_object3d.h"
#include "objects/cube.h"
#include "objects/pyramid.h"
#include "objects/disk.h"
#include "objects/partialdisk.h"
#include "objects/cylinder.h"
#include "objects/cone.h"
#include "objects/sphere.h"
#include "objects/func_surface.h"
#include "objects/off_loader.h"
#include "objects/sphere_subdiv.h"

#include "config.h"

/**
 * Program usage
 * Should be handled with the tclap library
 */
void usage(char* name) {
	cout << "usage: " << name << " [options]" << endl;
	cout << "options:" << endl;
	cout << "  -h, --help                 shows this message" << endl;
	cout << "  --off file                 loads OFF file" << endl;
}

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	// Parse program arguments here
	// with the tclap library
	// http://tclap.sourceforge.net/manual.html
	//
	Config cfg(argc, argv);

	// initialize my custom 3D scene
	float objectRadius = 1.;
	QPointer<MyScene> myScene = new MyScene(objectRadius);

	//add simple objects
	if (cfg.mesh) {
		myScene->addObject(new SphereSub(4));
		myScene->addObject(new Cube());
		myScene->addObject(new Pyramid());
		myScene->addObject(new Disk(20));
		myScene->addObject(new PartialDisk(20));
		myScene->addObject(new Cylinder(20));
		myScene->addObject(new Cone(20));
		myScene->addObject(new Sphere(20));
	}

	// add surface functions
	// ...

	// func pointer sur fonction
	typedef float (*func)(const float&, const float&);

	if (cfg.func1 || cfg.func2 || cfg.func3) {

		vector<func> funcs;
		func func1, func2, func3;
		if (cfg.func1) {
			func1 = func_expcos;
			funcs.push_back(func1);
		}
		if (cfg.func2) {
			func2 = func_sinsin;
			funcs.push_back(func2);
		}
		if (cfg.func3) {
			func3 = func_expxy;
			funcs.push_back(func3);
		}
		try {
			myScene->addObject(
					new FuncSurface(50, 50, -M_PI, M_PI, -M_PI, M_PI, funcs));
		} catch (const char* e) {
			cerr << "Erreur surface: " << e << endl;
		}

	}

	// add user defined OFF files
	// ...
	if (cfg.offFile) {
		try {
			myScene->addObject(new Off_Loader(cfg.offPath));
		} catch (const char* e) {
			cerr << "Erreur Off Loader: " << e << endl;
		}

	}

	// initialize my custom main window
	QPointer<MyMainWindow> myMainWindow = new MyMainWindow(myScene);
	// display the window
	myMainWindow->show();
	// enter in the main loop
	return app.exec();
}

