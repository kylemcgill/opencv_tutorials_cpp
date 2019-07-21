/*
 * Main.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: kmcgill
 */

#include "StandardDefinitions.h"

#include "core_functionality/CoreFunctionality.h"
#include "core_functionality_2/CoreFunctionality2.h"
#include "core_functionality_3/CoreFunctionality3.h"
#include "core_functionality_4/CoreFunctionality4.h"
#include "core_functionality_5/CoreFunctionality5.h"
#include "core_functionality_6/CoreFunctionality6.h"
#include "core_functionality_7/CoreFunctionality7.h"
#include "image_processing/BasicDrawing.h"

enum Tutorial{
	NONE,
	CORE_FUNCTIONALITY,
	CORE_FUNCTIONALITY_2,
	CORE_FUNCTIONALITY_3,
	CORE_FUNCTIONALITY_4,
	CORE_FUNCTIONALITY_5,
	CORE_FUNCTIONALITY_6,
	CORE_FUNCTIONALITY_7,
	BASIC_DRAWING
};


Tutorial parseTutorial(std::string str){
	if(strcmp("core_functionality", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY;
	}else if(strcmp("core_functionality_2", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY_2;
	}else if(strcmp("core_functionality_3", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY_3;
	}else if(strcmp("core_functionality_4", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY_4;
	}else if(strcmp("core_functionality_5", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY_5;
	}else if(strcmp("core_functionality_6", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY_6;
	}else if(strcmp("core_functionality_7", str.c_str()) == 0){
		return Tutorial::CORE_FUNCTIONALITY_7;
	}else if(strcmp("basic_drawing", str.c_str()) == 0){
		return Tutorial::BASIC_DRAWING;
	}

	return Tutorial::NONE;
}

void printTutorialOptions(){
	printf("Valid Tutorial Options are:\n");
	printf("\tcore_functionality\n");
	printf("\tcore_functionality_2\n");
	printf("\tcore_functionality_3\n");
	printf("\tcore_functionality_4\n");
	printf("\tcore_functionality_5\n");
	printf("\tcore_functionality_6\n");
	printf("\tcore_functionality_7\n");
	printf("\tbasic_drawing\n");
}

int main(int argc, char* argv[]){
	printf("Beginning opencv...\n");

	if(argc < 3){
		printf("Too few arguments given!\n");
		printf("Usage: -f <path_to_file> -t <tutorial>\n");
	}

	// Parse the arguments
	std::string filename = "";
	Tutorial useTutorial = Tutorial::NONE;
	for(int i = 0; i < argc; ++i){
		if(strcmp("-f", argv[i]) == 0){
			filename = argv[i+1];
		}else if(strcmp("-t", argv[i]) == 0){
			if((useTutorial = parseTutorial(argv[i+1])) == Tutorial::NONE){
				printf("Unable to find tutorial from %s\n", argv[i+1]);
				return -1;
			}
		}
	}

	printf("Using Tutorial: %i\n", useTutorial);
	int error = 0;
	switch(useTutorial){
	case CORE_FUNCTIONALITY:{
		error = CoreFunctionality().run(filename);
		break;
	}
	case CORE_FUNCTIONALITY_2:{
		error = CoreFunctionality2().run(filename);
		break;
	}
	case CORE_FUNCTIONALITY_3:{
		error = CoreFunctionality3().run(filename);
		break;
	}
	case CORE_FUNCTIONALITY_4:{
		error = CoreFunctionality4().run(filename);
		break;
	}
	case CORE_FUNCTIONALITY_5:{
		error = CoreFunctionality5().run(filename);
		break;
	}
	case CORE_FUNCTIONALITY_6:{
		error = CoreFunctionality6().run(filename);
		break;
	}
	case CORE_FUNCTIONALITY_7:{
		CoreFunctionality7 obj;
		error = obj.run(filename);
		break;
	}
	case BASIC_DRAWING:{
		error = BasicDrawing().run(filename);
		break;
	}

	case NONE:{
		printf("Chose NONE as the Tutorial to use.\n");
		break;
	}
	default:{
		printf("UseTutorial doesn't have a valid value.\n");
	}
	}

	printf("Returned demo with error code: %i\n", error);
	return 0;
}
