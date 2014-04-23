#!/bin/csh
# ---------------------------------------------------------------------------
#
# Script to Read in a molecule file to the database
#
# ---------------------------------------------------------------------------
#set verbose on

set CHEMPROG        = $REACTROOT/bin/runchem.sh
set INPPRINT        = $REACTROOT/programs/inputs/PrintMoleculeList.inp
set TEMPDIR         = $REACTROOT/tmp

#echo $REACTROOT

$CHEMPROG test < $INPPRINT >! $TEMPDIR/tmp.out
grep ": -->" $TEMPDIR/tmp.out
rm $TEMPDIR/tmp.out
echo "EndOfOutput"
