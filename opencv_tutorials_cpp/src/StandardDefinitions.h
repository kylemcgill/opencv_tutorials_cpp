/*
 * StandardDefinitions.h
 *
 *  Created on: Apr 7, 2019
 *      Author: kmcgill
 */

#ifndef STANDARDDEFINITIONS_H_
#define STANDARDDEFINITIONS_H_


//#define NDEBUG	// If present before "assert.h' include then all asserts go to 0


// Global logging macros which compile code if DEBUG flag is present
#define DEBUG

#ifdef DEBUG
#define LOG_CF(c,x) if(c){do{x}while(0);}
#define LOG(x) do{x}while(0)
#else
#define LOG_CF(c,x) if(c){do{}while(0);}
#define LOG(x) do{}while(0)
#endif

#endif /* STANDARDDEFINITIONS_H_ */
