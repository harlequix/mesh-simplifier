#include "Vertex.h"
#include "Edge.h"
#include "FileReader.h"
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <functional>
/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/08/2016 03:00:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
int main(int argc, char *argv[]){

        FileReader reader;
        Graphicobject input_object;
        int dreiecke = 500;
   	std::string input_file;
        std::string output_file = "collapsed.obj";
	std::string algorithm = "--simple";
	//std::cerr << argc <<std::endl;
	if(argc > 1){
		input_file = argv[1];
		if(argc > 2){
			output_file = argv[2];
		}
		if(argc > 3){
			dreiecke = std::stoi(argv[3]);
		}
		if (argc > 4) {
			algorithm = argv[4];
		}
		input_object = reader.readFile(input_file);
		input_object.simplifytil(dreiecke, algorithm);
		input_object.show(output_file);
	}
	else{
		std::cerr << "Bitte geben sie wenigstens einen Parameter an" <<std::endl;
		return -1;
	}
	return 0;
}
