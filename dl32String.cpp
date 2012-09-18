#include "dl32String.h"
#include <cmath>

dl32String::dl32String()
{
	Array=new char[1];
	Array[0]=DL32STRING_FINALSYMBOL;
	size=0;
}

dl32String::~dl32String()
{
	if(Array!=NULL)
	{
		delete [] Array;
		Array=NULL;
		size=-1;
	}
}

bool dl32String::Ready()
{
	return size>=0;
}

dl32String::dl32String(char Str)
{
	Array=new char[2];
	size=1;
	Array[0]=Str;
	Array[1]=DL32STRING_FINALSYMBOL;
}

void dl32String::LongCasting(long Number)
{
	int c,n;

	if(Number>0)
	{
		size=floor(log10(float(Number)))+1;
		Array=new char[size+1];

		c=pow(float(10),float(size-1));

		for(int i=0;i<size;++i)
		{
			n=Number / c;
			Number %= c;
			c/=10;

			Array[i]=char(n+DL32CONSTS_0CHARCODE);
		}
	}
	else
	{
		if(Number==0)
		{
			size=1;
			Array=new char[2];
			Array[0]=DL32CONSTS_0CHARCODE;
			Array[1]=DL32STRING_FINALSYMBOL;
		}
		else
		{
			Number=-Number;

			size=floor(log10(float(Number)))+2;
			Array=new char[size+1];

			c=pow(float(10),float(size-2));

			Array[0]='-';

			for(int i=1;i<size;++i)
			{
				n=Number / c;
				Number %= c;
				c/=10;

				Array[i]=char(n+DL32CONSTS_0CHARCODE);
			}
		}
	}

	Array[size]=DL32STRING_FINALSYMBOL;
}

dl32String::dl32String(const char Str[])
{
	size=strlen(Str);

	Array=new char[size+1];

	for(int i=0;i<size;++i)
		Array[i]=Str[i];
	
	Array[size]=DL32STRING_FINALSYMBOL;
}

dl32String::dl32String(char Str[],int Size)
{
	size=Size;
	Array=Str;
}

dl32String::dl32String(dl32String &str)
{
	if(this != &str)
	{
		size=str.size;
		Array=new char[size+1];

		for(int i=0;i<=size;++i)
			Array[i]=str.Array[i];
	}
}

dl32String::dl32String(string &str)
{
	size=str.length();
	Array=new char[size+1];

	for(int i=0;i<size;++i)
		Array[i]=str[i];

	Array[size]=DL32STRING_FINALSYMBOL;
}

dl32String::dl32String(const dl32String &str)
{
	if(this != &str)
	{
		size=str.size;
		Array=new char[size+1];

		for(int i=0;i<=size;++i)
			Array[i]=str.Array[i];
	}
}

dl32String::dl32String(const string &str)
{
	size=str.length();
	Array=new char[size+1];

	for(int i=0;i<size;++i)
		Array[i]=str[i];

	Array[size]=DL32STRING_FINALSYMBOL;
}

dl32String::dl32String(long Number)
{
	LongCasting(Number);
}

dl32String::dl32String(int Number)
{
	LongCasting(long(Number));
}

dl32String::dl32String(float Number,int Decimals)
{
	LongCasting(long(Number));
}

dl32String::dl32String(double Number,int Decimals)
{
	LongCasting(long(Number));
}

char* dl32String::c_str()
{
	return Array;
}

dl32String dl32String::Concat(dl32String &str1,dl32String &str2)
{
	if(str1.Ready() && str2.Ready())
	{
		int size=str1.size+str2.size;
		char *Array=new char[size+1];

		for(int i=0;i<str1.size;++i)
			Array[i]=str1.Array[i];
		for(int i=0;i<str2.size;++i)
			Array[i+str1.size]=str2.Array[i];
		Array[size]=DL32STRING_FINALSYMBOL;

		return dl32String(Array,size);
	}
	else
	{
		if(str1.Ready()) return str1;
		if(str2.Ready()) return str2;
		return dl32String();
	}
}

dl32String& dl32String::operator=(dl32String &string)
{
	if(this != &string)
	{
		if(Array!=NULL) delete Array;
		
		size=string.size;
		Array=new char[size+1];

		for(int i=0;i<=size;++i)
			Array[i]=string.Array[i];
	}

	return *this;
}

dl32String operator+(dl32String &str1,dl32String &str2)
{
	return dl32String::Concat(str1,str2);
}

dl32String operator+(char str1[],dl32String &str2)
{
	return dl32String::Concat(dl32String(str1),str2);
}

dl32String operator+(dl32String &str1,char str2[])
{
	return dl32String::Concat(str1,dl32String(str2));
}

dl32String operator+(dl32String &str,long &number)
{
	return dl32String::Concat(str,dl32String(number));
}

dl32String operator+(long &number,dl32String &str)
{
	return dl32String::Concat(dl32String(number),str);
}

dl32String operator+(dl32String &str,int &number)
{
	return dl32String::Concat(str,dl32String(number));
}

dl32String operator+(int &number,dl32String &str)
{
	return dl32String::Concat(dl32String(number),str);
}

dl32String operator+(dl32String &str,double &number)
{
	return dl32String::Concat(str,dl32String(number));
}

dl32String operator+(double &number,dl32String &str)
{
	return dl32String::Concat(dl32String(number),str);
}

dl32String operator+(dl32String &str,float &number)
{
	return dl32String::Concat(str,dl32String(number));
}

dl32String operator+(float &number,dl32String &str)
{
	return dl32String::Concat(dl32String(number),str);
}

//dl32String& operator+(char str[],long &number)
//{
//	return dl32String::Concat(dl32String(str),dl32String(number));
//}
//
//dl32String& operator+(long &number,char str[])
//{
//	return dl32String::Concat(dl32String(number),dl32String(str));
//}
//
//dl32String& operator+(char str[],int &number)
//{
//	return dl32String::Concat(dl32String(str),dl32String(number));
//}
//
//dl32String& operator+(int &number,char str[])
//{
//	return dl32String::Concat(dl32String(number),dl32String(str));
//}
//
//dl32String& operator+(char str[],double &number)
//{
//	return dl32String::Concat(dl32String(str),dl32String(number));
//}
//
//dl32String& operator+(double &number,char str[])
//{
//	return dl32String::Concat(dl32String(number),dl32String(str));
//}
//
//dl32String& operator+(char str[],float &number)
//{
//	return dl32String::Concat(dl32String(str),dl32String(number));
//}
//
//dl32String& operator+(float &number,char str[])
//{
//	return dl32String::Concat(dl32String(number),dl32String(str));
//}

