#ifndef DL32EXCEPTIONS_H
#define DL32EXCEPTIONS_H

#include <exception>

#define DL32DEFAULTEXCEPTIONMESSAGE "Unexpected dl32Exception"
#define DL32DEFAULTMEMORYEXCEPTIONMESSAGE "Unexpected dl32MemoryException"
#define DL32DEFAULTOUTOFINTERVALEXCEPTIONMESSAGE "Unexpected dl32OutOfIntervalException"

//////////////////////////////////////////////
///The base for the dx_lib32 exceptions family
//////////////////////////////////////////////
class dl32Exception:public std::exception
{
protected:
	char* message;
public:
	dl32Exception(char* message=DL32DEFAULTEXCEPTIONMESSAGE){this->message=message;};

	const char* what(){return message;};
	char* GetMessage(){return message;};
};

///////////////////////////////////
///dx_lib32 memory issues exception
///////////////////////////////////
class dl32MemoryException:public dl32Exception
{
protected:
	void* pointer;
public:
	dl32MemoryException(char* message=DL32DEFAULTMEMORYEXCEPTIONMESSAGE,void* pointer=NULL):dl32Exception(message){this->pointer=pointer;};

	void* GetPOinter(){return pointer;};
};

struct dl32Range
{
	int max;
	int min;

	dl32Range(){max=0;min=0;};
	dl32Range(int max,int min){this->max=max;this->min=min;};
	dl32Range(int size){max=size-1;min=0;};
};

////////////////////////////////////////////////////////////////////////////
///Represents a out of range exception, for example an array buffer overflow
////////////////////////////////////////////////////////////////////////////
class dl32OutOfRangeException:public dl32Exception
{
protected:
	dl32Range range;
	int index;
public:
	dl32OutOfRangeException(dl32Range range, int index, char* message=DL32DEFAULTOUTOFINTERVALEXCEPTIONMESSAGE):dl32Exception(message){this->range=range;this->index=index;};
};

//////////////////////////////////////
///A base for dx_lib32 math exceptions
//////////////////////////////////////
class dl32MathException:public dl32Exception
{
public:
	dl32MathException(char* message):dl32Exception(message){};
};

///////////////////////////////////////
///Represents a math overflow exception
///////////////////////////////////////
class dl32OverflowException:public dl32MathException
{
public:
	dl32OverflowException(char* message):dl32MathException(message){};
};

class dl32DividedByCeroException:public dl32OverflowException
{
public:
	dl32DividedByCeroException(char* message):dl32OverflowException(message){};
};

class dl32InvalidMatrixOperationException:dl32MathException
{
public:
	dl32InvalidMatrixOperationException(char* message):dl32MathException(message){};
};

class dl32ConsoleException:public dl32Exception
{
public:
	dl32ConsoleException(char* message):dl32Exception(message){};
};
#endif