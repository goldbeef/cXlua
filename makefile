all: mylib.so cToLua

mylib.so: mylib.c
	gcc mylib.c   -I/usr/local/Cellar/lua/5.3.5_1/include/lua5.3 -L/usr/local/Cellar/lua/5.3.5_1/lib -llua -shared -o mylib.so -fPIC
cToLua: cToLua.c
	gcc cToLua.c -o cToLua   -I/usr/local/Cellar/lua/5.3.5_1/include/lua5.3 -L/usr/local/Cellar/lua/5.3.5_1/lib -llua

clean:
	rm -rf mylib.so cToLua
