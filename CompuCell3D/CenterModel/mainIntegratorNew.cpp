


#include <iostream>
#include <string>
#include <Components/CellCM.h>
#include <Components/SimulationBox.h>
#include <Components/CellInventoryCM.h>
#include <Components/CellFactoryCM.h>
#include <Components/SimulatorCM.h>
#include <time.h>
#include <BasicUtils/BasicRandomNumberGenerator.h>
#include <CompuCell3D/Field3D/Point3D.h>
#include <PublicUtilities/NumericalUtils.h>
#include <limits>
#include <fstream>

#include <Components/LennardJonesForceTerm.h>


#if defined(_WIN32)
	#include <windows.h>
#endif


using namespace std;
using namespace  CenterModel;

// // // PluginManager<Plugin> Simulator::pluginManager;
// // // PluginManager<Steppable> Simulator::steppableManager;
// // // BasicPluginManager<PluginBase> Simulator::pluginBaseManager;


void Syntax(const string name) {
  cerr << "Syntax: " << name << " <config>" << endl;
  exit(1);
}




int main(int argc, char *argv[]) {

	cerr<<"NEW Welcome to CC3D command line edition"<<endl;
    CellCM cell;
    cell.grow();
	cerr<<"cell.position="<<cell.position<<endl;

    SimulatorCM simulator;

    simulator.setBoxDim(21.2,45.7,80.1);
    simulator.setGridSpacing(2.01,2.01,2.01);
    simulator.setBoundaryConditionVec(0.,0.,0.); //no flux bc

    simulator.init();
    int N=20000;
    double r_min=1.0;
    double r_max=2.0;
    simulator.createRandomCells(N,r_min,r_max);


    LennardJonesForceTerm ljTerm;
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);
    simulator.registerForce(&ljTerm);

#if defined(_WIN32)
	volatile DWORD dwStart;
	dwStart = GetTickCount();
#endif

    simulator.step();



#if defined(_WIN32)
	cerr<<"DISTANCE CALCULATION FOR  "<<N<<" cells too "<<GetTickCount()-dwStart<<" miliseconds to complete"<<endl;
	dwStart = GetTickCount();
#endif	



	
	
  return 1;
}