# Enumeration Classes

The enum classes ("new enums", "strong enums") address three problems with traditional C++ enumerations:
	• conventional enums implicitly convert to int, causing errors when someone does not want an enumeration to act as an integer.
	
	• conventional enums export their enumerators to the surrounding scope, causing name clashes.
	
	• the underlying type of an enum cannot be specified, causing confusion, compatibility problems, and makes forward declaration impossible.

Notes : 
	1. When underlying type is used as range is not integral type
	- Clang++ 
		○ Error : non-integral type 'smallenum' is an invalid underlying type
	- g++ 
		○ Error : underlying type ‘smallenum’ of ‘color’ must be an integral type 

References :
	 (http://www.stroustrup.com/C++11FAQ.html#enum)
	 (http://eel.is/c++draft/dcl.enum)
	 (http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html#enum-enumerations)
         (http://en.cppreference.com/w/cpp/language/enum)
