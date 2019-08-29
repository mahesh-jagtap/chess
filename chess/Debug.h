#pragma once

#ifdef _DEBUG 
#define PRINT(msg) std::cout << __FILE__ << "("+ std::to_string(__LINE__) +"): " << msg << std::endl 
//#define PRINT(msg) std::cout << msg << std::endl 
#else
#define PRINT(msg)
#endif
