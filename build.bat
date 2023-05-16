@ECHO OFF
TITLE SDL2-mingw32-g++ Batch script compiler
ECHO  Compiling...
SET   outputfile=%1

FOR %%A IN (%*) DO (
  IF %%A=="-debug"   GOTO DEBUG_MODE
  IF %%A=="-release" GOTO RELEASE_MODE
  GOTO EMPTYARG
)


:DEBUG_MODE
@ECHO ON
g++ *.cpp -Iinclude -Llib/SDL2/lib -O -Wall -w -Wl,-subsystem,console -lmingw32 -lSDL2main -lSDL2 -o %outputfile%
GOTO _EXIT

:RELEASE_MODE
@ECHO ON
g++ *.cpp -Iinclude -Llib/SDL2/lib -O3 -Wall -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o %outputfile%
GOTO _EXIT

:EMPTYARG
@ECHO ON
g++ *.cpp -Iinclude -Llib/SDL2/lib -Wall -w -Wl,-subsystem,console -lmingw32 -lSDL2main -lSDL2 -o %outputfile%


:_EXIT
@ECHO OFF
ECHO.
ECHO  Compiling finished, running compiled output.
START %outputfile%