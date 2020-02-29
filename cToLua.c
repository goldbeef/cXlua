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
 *
 *
lua
    嵌入式语言 -> 被其它语言调用
    扩展性语言 -> 使用其它语言的库
lua-c-api
    lua.h
    lauxlib.h

    stack
        LIFO
        静态类型 -> 动态类型
        手动管理内存 -> 自动管理内存


        push_xxxx
            LUA_API void        (lua_pushnil) (lua_State *L);
            LUA_API void        (lua_pushnumber) (lua_State *L, lua_Number n);
                lua-float
            LUA_API void        (lua_pushinteger) (lua_State *L, lua_Integer n);
                lua-interger
            LUA_API const char *(lua_pushlstring) (lua_State *L, const char *s, size_t len);
            LUA_API const char *(lua_pushstring) (lua_State *L, const char *s);
            LUA_API const char *(lua_pushvfstring) (lua_State *L, const char *fmt,
                                                                  va_list argp);
            LUA_API const char *(lua_pushfstring) (lua_State *L, const char *fmt, ...);
            LUA_API void  (lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
            LUA_API void  (lua_pushboolean) (lua_State *L, int b);
            LUA_API void  (lua_pushlightuserdata) (lua_State *L, void *p);
            LUA_API int   (lua_pushthread) (lua_State *L);

        check_stack
            LUA_API int   (lua_checkstack) (lua_State *L, int n);

        check_type
            LUA_API int             (lua_isnumber) (lua_State *L, int idx);
            LUA_API int             (lua_isstring) (lua_State *L, int idx);
            LUA_API int             (lua_iscfunction) (lua_State *L, int idx);
            LUA_API int             (lua_isinteger) (lua_State *L, int idx);
            LUA_API int             (lua_isuserdata) (lua_State *L, int idx);

        type && type-name
            LUA_API int             (lua_type) (lua_State *L, int idx);
            LUA_API const char     *(lua_typename) (lua_State *L, int tp);

        get stack value
            LUA_API lua_Number      (lua_tonumberx) (lua_State *L, int idx, int *isnum);
            LUA_API lua_Integer     (lua_tointegerx) (lua_State *L, int idx, int *isnum);
            LUA_API int             (lua_toboolean) (lua_State *L, int idx);
            LUA_API const char     *(lua_tolstring) (lua_State *L, int idx, size_t *len);
            LUA_API size_t          (lua_rawlen) (lua_State *L, int idx);
            LUA_API lua_CFunction   (lua_tocfunction) (lua_State *L, int idx);
            LUA_API void	       *(lua_touserdata) (lua_State *L, int idx);
            LUA_API lua_State      *(lua_tothread) (lua_State *L, int idx);
            LUA_API const void     *(lua_topointer) (lua_State *L, int idx);


 * */



int main(){
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_isinteger()

    lua_type()
    /*
     *
    //lua 解释器
    char buff[256];
    int error;

    while (fgets(buff, sizeof(buff), stdin)) {
        error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0);
        if (error) {
            fprintf(stdout, "%s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }

    lua_close(L);
     */

    int n = lua_checkstack(L, 100);
    printf("n[%d]\n", n);


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

    /*
    lua_State *lvm_hnd = luaL_newstate();
    luaL_openlibs(lvm_hnd);

    lua_getglobal(lvm_hnd, "print");

    lua_pushstring(lvm_hnd, "Hello C API!");

    lua_call(lvm_hnd, 1, 0);

    lua_close(lvm_hnd);
     */

    return 0;
}