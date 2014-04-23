#! /bin/tcsh -f

set THERMODIR = $REACTROOT/data/tables

pushd $THERMODIR

readthermotables.sh Table2.14
readthermotables.sh TableA.1
readthermotables.sh TableA.2
readthermotables.sh TableA.2CO

# bensonorganize.sh test Table2.14  TableA.1  TableA.2  TableA.2CO
bensonorganize.sh test Table2.14  TableA.1  TableA.2
#bensonorganize.sh test Table2.14  
popd
