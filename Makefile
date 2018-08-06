##===================================================================================================================
##
## Makefile -- This is the file that will control the project build
##
## -----------------------------------------------------------------------------------------------------------------
##
##    Date      Tracker  Version  Pgmr  Description
## -----------  -------  -------  ----  ----------------------------------------------------------------------------
## 2018-Jul-24   Initial   0.0.0   ADCL  Initial Version
##
##===================================================================================================================


##
## -- Some defines to make the compilaton easier
##    ------------------------------------------
FILES=db model-elements main logger view-mainwindow
SRC=$(addsuffix .cc,$(addprefix src/,$(FILES)))
OBJ=$(addsuffix .o,$(addprefix obj/,$(FILES)))
INC=inc/*.h
TGT=bin/cba-elements


##
## -- The recipes needed to build the targets
##    ---------------------------------------
.PHONY: all
all: $(TGT)


$(TGT): $(OBJ)
	g++ -o $@ $(OBJ) -lmysqlcppconn -lQtGui -lQtCore


obj/%.o: src/%.cc Makefile $(INC)
	g++ -std=c++11 -I inc -I /usr/include/qt4/QtGui -I /usr/include/qt4 -fPIC -c -o $@ $<

##
## -- The recipe to clean up the mess
##    -------------------------------
.PHONY: clean
clean:
	rm -f bin/*
	rm -f obj/*

##
## -- Force a rebuild of the entire project
##    -------------------------------------
.PHONY: force
force: clean all


##
## -- Run the program targets
##    -----------------------
.PHONY: run
run: all
	$(TGT)