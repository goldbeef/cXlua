//
// Created by Heng Zhao on 2020-02-27.
//

#ifdef __cplusplus
#include "lua.hpp"
#else
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#endif
#include <math.h>

//so that name mangling doesn't mess up function names
#ifdef __cplusplus
extern "C"{
#endif

static int c_swap (lua_State *L) {
    //check and fetch the arguments
    double arg1 = luaL_checknumber (L, 1);
    double arg2 = luaL_checknumber (L, 2);

    //push the results
    lua_pushnumber(L, arg2);
    lua_pushnumber(L, arg1);

    //lua_getglobal(L, "tbl");
    //lua_getfield(L, -1, "hello");

    //return number of results
    return 2;
}


//library to be registered
static const struct luaL_Reg mylib [] = {
        {"c_swap", c_swap},
        {NULL, NULL}  /* sentinel */
};

//name of this function is not flexible
int luaopen_mylib (lua_State *L){
    luaL_newlib(L, mylib);
    return 1;
}

#ifdef __cplusplus
}
#endif

