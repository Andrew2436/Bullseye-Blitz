#pragma once

#if OT_DEBUG==2
	#define OT_ERROR(x) std::cout<<x<<std::endl;
	#define OT_LOG(x) std::cout<<x<<std::endl;
#elif OT_DEBUG==1
	#define OT_ERROR(x) std::cout<<x<<std::endl;
	#define OT_LOG(x) 
#else
	#define OT_ERROR(x) 
	#define OT_LOG(x) 
#endif

#ifdef OTTER_MSCPP
	#ifdef OTTER_LIB
		#define OTTER_API __declspec(dllexport)
	#else
		#define OTTER_API __declspec(dllimport)
	#endif
#else
	#define OTTER_API
#endif

#define OTTER_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}