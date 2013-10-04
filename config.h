/**
 * @author Clement Garnier
 * @date   Oct 2012
 *
 *      Config class parse the program arguments and define which objects will be added to the scene.
 */

#ifndef CONFIG_H_
#define CONFIG_H_


#include <tclap/CmdLine.h>

using namespace std;
class Config {
public:
	Config(const int& argc, char* argv[]);
	virtual ~Config();

//	bool cube;
//	bool pyramid;
//	bool cylinder;
//	bool disk;
//	bool cone;
//	bool partialDisk;
//	bool sphere;
	bool mesh;
	bool offFile;
	string offPath;
	bool func1;
	bool func2;
	bool func3;

};

#endif /* CONFIG_H_ */
