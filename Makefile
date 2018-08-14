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
MODEL=elements main-win-model
VIEW=about-view main-win-view
CTLR=about-controller main-win-controller
UTIL=db logger

FILES=$(sort $(MODEL) $(VIEW) $(CTLR) $(UTIL))
SRC=$(addsuffix .cc,$(addprefix src/,$(FILES)))
OBJ=$(addsuffix .o,$(addprefix obj/,$(FILES)))
INC=inc/*.h
TGT=bin/cba-elements

INCLUDES=-I inc -I /usr/include/qt5 -I /usr/include/qt5/QtCore -I /usr/include/qt5/QtWidgets


##
## -- The recipes needed to build the targets
##    ---------------------------------------
.PHONY: all
all: $(TGT)
#	tup


$(TGT): $(OBJ)
	g++ -o $@ $(OBJ) -lmysqlcppconn -lQt5Widgets -lQt5Core


obj/%.o: src/%.cc Makefile $(INC)
	g++ -std=c++11 $(INCLUDES) -fPIC -c -o $@ $<


src/%.moc: inc/%.h Makefile
	moc -qt=5 $(INCLUDES) $< -o $@


obj/main-win-controller.o: src/main-win-controller.moc


##
## -- Run the program targets
##    -----------------------
.PHONY: run
run: all
	$(TGT)


.PHONY: clean
clean:
	rm -fR obj/*
	rm -fR bin/*
	rm -f src/*.moc

.PHONY: force
force: clean all
