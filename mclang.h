/**
 * Copyright (C), 2020, Jason Hu, www.book-os.org
 * File name: mclang.h
 * Description:
 *      This is a programming language based on the C language macro.
 *  Based on the C language, the macro function is used to redefine
 *  some keywords and syntax. This is not like the interpreter, 
 *  it will be expanded into C language code during the C macro 
 *  expansion stage, and then compiled into assembly and machine code,
 *  so its execution efficiency is the same as C language. In other words,
 *  just changed the C language, it still looks very cool!
 * 
 * Change Logs:
 *  | Date          | Author        | Notes             | Version
 *  | 2020-05-23    | Jason Hu      | First Release     | 0.1
 *  | 2020-05-30    | Jason Hu      | Masonry           | 0.2
 *  | 2020-06-1     | Jason Hu      | Masonry           | 0.3
 *  | 2020-10-20    | Jason Hu      | Cola              | 0.4
 *  | 2020-11-27    | Jason Hu      | Peisi             | 0.5
 */
#ifndef _MARCO_C_LANG_H
#define _MARCO_C_LANG_H

#define _MCLANG_VERSION    0x05    /* v0.5 */

/* keywords */
#define cmp                 if(                 
#define recmp               }else if(           
#define nocmp               }else{              
#define then                ){                  
#define loop                while(              
#define and                 &&                  
#define or                  ||                  
#define not                 !                 
#define end                 }                      

#define match               switch(

#ifdef _Bool
#define bool                _Bool
#else
#define bool                char
#define true                1
#define false               0
#endif
#define out

#define forcond             for(
#define branch(x)           case x:
#define nomatch             default:
#define skip                break;
#define rep                 continue;
#define local               static

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long int   u64;
typedef char                s8;
typedef short               s16;
typedef int                 s32;
typedef long int            s64;
typedef float               f32;
typedef double              f64;
typedef long double         f128;
typedef void * nil;

/* declare a function */
#define decl(_func, _ret, ...) \
        _ret _func (__VA_ARGS__);

/* define a function */
#define def(_func, _ret, ...) \
        _ret _func (__VA_ARGS__) {

/* call a function */
#define call(_func, ...) \
        _func(__VA_ARGS__);

/* get each item in array */
#define foreach(_item, _idx, _array) \
        for(_item = _array[0];\
        _idx < (sizeof(_array) / sizeof(_array[0]));\
        ++_idx, _item = _array[_idx]

/* get each index in a number */
#define forindex(_item, _num, _step) \
        for(_item = 0;\
        _item < _num;\
        _item += _step

/* ternary operation */
#define ternary(_cond, _x, _y) \
        _cond ? _x : _y

/* mutli elememnts with list,group,let */
#define mutli(_name, ...)           _name {__VA_ARGS__};

#define list(_name)                 enum _name
#define group(_name)                struct _name

#define lable(_name)                _name:
#define jmp(_name)                  goto _name;

#define let(_name, _type)          _type _name = 

#define as(_val, _state)            _val = _state;
#define arg(_name, _type)           _type _name

#define inc(_val)                   _val++
#define dec(_val)                   _val--
#define incr(_val)                  ++_val
#define decr(_val)                  ++_val
#define back(_val)                  return _val;

#define arraysize(_array)           (sizeof(_array) / sizeof(_array[0]))


/* For the full documentation and explanation of the code below, please refer to
 * https://github.com/GorgonMeducer/PLOOC/blob/master/plooc.h
 */
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__cplusplus)
/*! \brief You can use __PLOOC_EVAL() to dynamically select the right API which
 *!        has the right number of parameters (no more than 8).
 */
//! @{
#define __PLOOC_VA_NUM_ARGS_IMPL(   _0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,  \
                                    _13,_14,_15,_16,__N,...)      __N
#define __PLOOC_VA_NUM_ARGS(...)                                                \
            __PLOOC_VA_NUM_ARGS_IMPL( 0,##__VA_ARGS__,16,15,14,13,12,11,10,9,   \
                                      8,7,6,5,4,3,2,1,0)

#define __16_PLOOC_EVAL(__FUNC, __NO_ARGS)  __FUNC##__NO_ARGS
#define __15_PLOOC_EVAL(__FUNC, __NO_ARGS)  __16_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __14_PLOOC_EVAL(__FUNC, __NO_ARGS)  __16_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __13_PLOOC_EVAL(__FUNC, __NO_ARGS)  __14_PLOOC_EVAL(__FUNC, __NO_ARGS)

#define __12_PLOOC_EVAL(__FUNC, __NO_ARGS)  __13_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __11_PLOOC_EVAL(__FUNC, __NO_ARGS)  __12_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __10_PLOOC_EVAL(__FUNC, __NO_ARGS)  __11_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __9_PLOOC_EVAL(__FUNC, __NO_ARGS)   __10_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __8_PLOOC_EVAL(__FUNC, __NO_ARGS)   __9_PLOOC_EVAL(__FUNC, __NO_ARGS)

#define __7_PLOOC_EVAL(__FUNC, __NO_ARGS)   __8_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __6_PLOOC_EVAL(__FUNC, __NO_ARGS)   __7_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __5_PLOOC_EVAL(__FUNC, __NO_ARGS)   __6_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __4_PLOOC_EVAL(__FUNC, __NO_ARGS)   __5_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __3_PLOOC_EVAL(__FUNC, __NO_ARGS)   __4_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __2_PLOOC_EVAL(__FUNC, __NO_ARGS)   __3_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __1_PLOOC_EVAL(__FUNC, __NO_ARGS)   __2_PLOOC_EVAL(__FUNC, __NO_ARGS)
#define __0_PLOOC_EVAL(__FUNC, __NO_ARGS)   __1_PLOOC_EVAL(__FUNC, __NO_ARGS)

#define __PLOOC_EVAL(__FUNC, ...)           __0_PLOOC_EVAL(                     \
                                                __FUNC,                         \
                                                __PLOOC_VA_NUM_ARGS(__VA_ARGS__))
//! @}   
#endif

#define __var_declare_and_set(__name, __type, __value) \
        __type __name = __value;
#define __var_declare(__name, __type) __type __name;

#define __var2  __var_declare
#define __var3  __var_declare_and_set

#define var(__name, __type, ...)                       \
        __PLOOC_EVAL(__var, __name, __type, ##__VA_ARGS__)(__name, __type, ##__VA_ARGS__)

//#define var(_name, _type)           

#define _USE_EXCEPTION
#ifdef _USE_EXCEPTION
/* try catch */
#include <setjmp.h>
/* For the full documentation and explanation of the code below, please refer to
 * http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html
 */
#define try         do { jmp_buf ex_buf__; switch( setjmp(ex_buf__) ) { case 0: while(1) { {
#define catch(_x)   } break; case _x: {
#define finally     } break; } default: { {
#define endtry      } break; } } }while(0);
#define throw(_x)   longjmp(ex_buf__, _x);
#endif /* _USE_EXCEPTION */

#define _USE_COROUTINE
#ifdef _USE_COROUTINE

/* For the full documentation and explanation of the code below, please refer to
 * https://www.chiark.greenend.org.uk/~sgtatham/coroutine.h
 */

#define begincoro      static int _coro_line = 0; switch(_coro_line) { case 0:;;
#define endcoro(z)     } return (z);
#define endcorono      } return;

#define yeild(z)     \
        do {\
            _coro_line=__LINE__;\
            return (z); case __LINE__:;\
        } while (0);
#define yeildno       \
        do {\
            _coro_line=__LINE__;\
            return; case __LINE__:;\
        } while (0);

#endif /* _USE_COROUTINE */



#endif  /* _MARCO_C_LANG_H */