#include <cstdio>
#include "lua.hpp"
#include <assert.h>
#include <string.h>
#include <new>
#include <vector>
#include <iostream>
using namespace std;

int AddNumbers(int a, int b) {
    return a + b;
}

int Lua_AddNumbers(lua_State* L) {
    int a = luaL_checkinteger(L, 1);
    int b = luaL_checkinteger(L, 2);

    int sum = AddNumbers(a, b);

    lua_pushinteger(L, sum);

    return 1;
}
int custom_print(lua_State* L) {
  int nr = lua_gettop(L);
  for(int i = 1; i <= nr; i++) {
    const char* str = lua_tostring(L, i);
    cout << str;
    if(i != nr) {
      cout << "\t";
    }
  }
  cout << endl;
  return 0;
}

int main() {
  lua_State* L = luaL_newstate();
  luaL_openlibs(L);

  lua_pushcfunction(L, Lua_AddNumbers);
  lua_setglobal(L, "addto");

  int result = luaL_dostring(L, "return addto(2, 5)");

  lua_pushcfunction(L, custom_print);
  lua_setglobal(L, "print");

  int result_2 = luaL_dostring(L, "print('LUA: ' .. addto(7, 5))");

  if (result_2 != LUA_OK) {
    cout << "Error executing Lua script: " << lua_tostring(L, -1) << endl;
  }

  if (result == LUA_OK) {
    int value = lua_tointeger(L, -1);
    cout << "CPP: " << value << endl;
  } else {
    cout << "Error executing Lua script: " << lua_tostring(L, -1) << endl;
  }

  lua_newtable(L);

  lua_pushinteger(L,1);
  lua_pushstring(L,"Hello");
  lua_settable(L, -3);

  lua_pushinteger(L,2);
  lua_pushstring(L,"World");
  lua_settable(L, -3);


  luaL_dostring(L, "print('LUA: ' .. addto(7, 5))");


  if (luaL_loadfile(L, "test.lua"))
    {
         cout << "Error: " << lua_tostring(L, -1) << endl;
    }
    else if (lua_pcall(L, 0, LUA_MULTRET, 0))
    {
         cout << "Error: " << lua_tostring(L, -1) << endl;
    }
    else
    {
         // call successful
    }
    lua_getglobal(L, "CPP");

    int a = 10;
    lua_pushinteger(L, a);
    lua_call(L, 1, 0);//Second lua, calls funcFromLua. right?




  lua_close(L);

  return 0;
}
