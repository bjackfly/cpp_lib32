/* 
 * File:   dl32Typing.h
 * Author: Manu343726
 *
 * Created on 27 de abril de 2013, 21:13
 */

#ifndef DL32TYPING_H
#define	DL32TYPING_H

#include "dl32Config.h"

//Nota: Soy plenamente consciente de que todo ésto está implementado desde C++11 en la STL ( http://en.cppreference.com/w/cpp/types ), lo hago por mero entretenimiento.

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Type representing types without semantic sense (Non-valid types).
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
class dl32NoType {};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Basic type.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
class dl32EmptyType {};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 type checking basic data.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template< typename T , typename U>
class dl32TypeChecker_Base
{
public:
    ///< Small size unit type.
    typedef char dl32TypeSize_Small;

    ///< Big size unit type.
    typedef class { char _dummy[2]; } dl32TypeSize_Big;
    
    ///< Compile-time size units types size.
    enum
    {
        _sizeof_Small = sizeof( dl32TypeSize_Small ),
        _sizeof_Big   = sizeof( dl32TypeSize_Big )
    };

protected:    
    static dl32TypeSize_Small _testTtoU( U );   //U args calls use this.
    static dl32TypeSize_Big   _testTtoU( ... ); //Non-U args calls use this.
    static dl32TypeSize_Small _testUtoT( T );   //T args calls use this.
    static dl32TypeSize_Big   _testUtoT( ... ); //Non-T args calls use this.
    
    static T _makeT();
    static U _makeU();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 type comparator. 
/// @detailts Use dl32SameType<T,U>::value to check if T and U are the same type.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T , typename U>
struct dl32SameType
{
    enum { value = FALSE };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 type comparator. 
/// @detailts Use dl32SameType<T,U>::same_type to check if T and U are the same type.
///
/// @author	Manu343726
///
/// @remarks Template specialitation for same types.
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
struct dl32SameType<T,T>
{
    enum { value = TRUE };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 implicit type conversion checker.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T , typename U>
struct dl32Conversion : public dl32TypeChecker_Base<T,U>
{
    enum { value = sizeof( dl32TypeChecker_Base<T,U>::_testTtoU( dl32TypeChecker_Base<T,U>::_makeT() ) ) == dl32TypeChecker_Base<T,U>::_sizeof_Small };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 inheritance checker.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T , typename U>
struct dl32SuperclassSubclass
{
    enum { value = dl32Conversion<const U* , const T*>::value && !dl32SameType<const T* , const void*>::value && !dl32SameType<const T , const U>::value };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 compile-time type data.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T , typename U>
class dl32TypeChecking
{
public:
    enum
    { 
        //Implicit type-conversion checking:
        conversion_exists = dl32Conversion<T,U>::value, ///< Checks if a conversion from T to U is alowed. Its value is 1 (TRUE) if a implicit conversion is alowed). 0 (FALSE) if is not alowed.)
        
        //Basic type-checking:
        same_type = dl32SameType<T,U>::value, ///< Checks if the two types provided are the same type.
        
        //Inheritance checking:
        superclass_subclass = dl32SuperclassSubclass<T,U>::value ///< Checks if T is a superclass of U (U is a subclass of T).
    };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 type selection.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<bool flag , typename T , typename U>
struct dl32Select { typedef T result; };

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 type selection. (Template specialitation for second type selection). 
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T , typename U>
struct dl32Select<false,T,U> { typedef U result; };

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 type list.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T , typename U>
struct dl32BasicTypeList
{
    typedef T Head;
    typedef U Tail;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Type info provider.
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class dl32TypeTraits
{
private:
#define TRAITS( name , type , checkingType , typedefName ) \
    template<typename type>                                \
    struct name                                            \
    {                                                      \
        enum { value = FALSE };                            \
        typedef dl32NoType typedefName;                    \
    };                                                     \
    template<typename type>                                \
    struct name<checkingType>                              \
    {                                                      \
        enum { value = TRUE };                             \
        typedef type typedefName;                          \
    };                        
    
#define TRAITS_FULL_EXPLICITTRAITNAME(attribute_name , trait_name , type , checking_type , typedef_name ) \
        TRAITS( trait_name , type , checking_type , typedef_name );                                       \
        public:                                                                                           \
                enum { attribute_name = trait_name<T>::value };                                           \
                typedef typename trait_name<T>::typedef_name typedef_name;                                \
        private:
    
#define TRAITS_FULL_IMPLICITTRAITNAME( attribute_name , unique_id , type , checking_type , typedef_name ) TRAITS_FULL_EXPLICITTRAITNAME(attribute_name , CONCAT( _trait_ , unique_id ) , type , checking_type , typedef_name )
    
#define TRAITS_FULL( attribute_name , type , checking_type , typedef_name ) TRAITS_FULL_IMPLICITTRAITNAME( attribute_name , __COUNTER__ /* unique class identifier */ , type , checking_type , typedef_name )
    
    TRAITS_FULL( isPointer   , U , U*      , PointeeType )    //Checks if T is a pointer
    TRAITS_FULL( isReference , U , U&      , ReferencedType ) //Checks if T is a reference
    TRAITS_FULL( hasConst    , U , const U , NonConstType )   //Checks if T is const
    TRAITS_FULL( isRvalue    , U , U&&     , MovedType )      //Checks if T is a rvalue
 
public:
    typedef T OriginalType;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Implementation of a loki-like (C++ 98/03 style) type list
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename HEAD ,typename TAIL>
class dl32Loki_like_TypeList 
{
public:
  typedef HEAD head;
  typedef TAIL tail;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Implements a linear search of a type in a given type list (Type list in loki-format).
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<int index, typename TYPELIST>
struct dl32TypeAt
{
    typedef typename dl32TypeAt<index-1,typename TYPELIST::tail>::value value;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Implements a linear search of a type in a given type list (Type list in loki-format).
///
/// @author	Manu343726
///
/// @remarks Template specialitation for index-th case (The type was finded).)
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename TYPELIST>
struct dl32TypeAt<0,TYPELIST>
{
    typedef typename TYPELIST::head value;
};



///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 loki-like typelist wrapper
/// @details This class wrapps recursive-based typelist and provides a variadic template interface
///
/// @author	Manu343726
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename... Ts>
struct dl32TypeList;

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 loki-like typelist wrapper
/// @details This class wrapps recursive-based typelist and provides a variadic template interface
///
/// @author	Manu343726
///
/// @remarks Recoursive-case template specialitation.
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename HEAD , typename... TAIL>
struct dl32TypeList<HEAD,TAIL...>
{
    enum { size = sizeof...(TAIL) + 1 };
    typedef dl32Loki_like_TypeList<HEAD, typename dl32TypeList<TAIL...>::value> value;
    
    template<int index>
    using type_at = typename dl32TypeAt<index,value>::value; ///< Gets the index-th type of the list. If index is out of range, a compilation error will be generated ("dl32Notype not has member 'head'").
    
    //template<typename T>
    //using index_of = dl32IndexOf<T,value>; ///< Gets the position of a given type in the list. If the type is not in the list, dl32NoType will be returned.
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief cpp_lib32 loki-like typelist wrapper
/// @details This class wrapps recursive-based typelist and provides a variadic template interface
///
/// @author	Manu343726
///
/// @remarks Base-case template specialitation.
///////////////////////////////////////////////////////////////////////////////////////////////////////
template<>
struct dl32TypeList<>
{
  typedef dl32NoType value;
  
  enum { size = 0 };
  
  template<int index>
  using type_at = dl32NoType; ///< Gets the index-th type of the list. If index is out of range, a compilation error will be generated ("dl32Notype not has member 'head'").
  
  template<typename T>
  using index_of = dl32NoType; ///< Gets the position of a given type in the list. If the type is not in the list, dl32NoType will be returned.
};
#endif	/* DL32TYPING_H */
