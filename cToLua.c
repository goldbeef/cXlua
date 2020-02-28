#ifdef __cplusplus
#include "lua.hpp"
#else
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#endif

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
    
    //return number of results
    return 2;
}

#ifdef __cplusplus
}
#endif


/*
 * https://lua.programmingpedia.net/en/tutorial/671/introduction-to-lua-c-api
 *
 * https://www.lua.org/manual/5.3/manual.html#lua_call
 *
 * */
int main(){
    /*
    // Create new Lua state and load the lua libraries
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    //Expose the c_swap function to the lua environment
    lua_pushcfunction(L, c_swap);
    lua_setglobal(L, "c_swap");

    // Tell Lua to execute a lua command
    luaL_dostring(L, "print(c_swap(4, 5))");
    luaL_dostring(L, "print(\"hello world\")");
     */

    lua_State *lvm_hnd = luaL_newstate();
    luaL_openlibs(lvm_hnd);

    /* Load a standard Lua function from global table: */
    lua_getglobal(lvm_hnd, "print");

    /* Push an argument onto Lua C API stack: */
    lua_pushstring(lvm_hnd, "Hello C API!");

    /* Call Lua function with 1 argument and 0 results: */
    lua_call(lvm_hnd, 1, 0);

    lua_close(lvm_hnd);

    return 0;
}