
extern CHAR *GetNameAtomElectronic(AtomElectronic *str)
{
     return(str->Name);
}

extern INT GetIDAtomElectronic(AtomElectronic *str)
{
     return(str->ID);
}

extern AtomElectronic *CreateAtomElectronic(AtomElectronic *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  AtomicNumber,
                                     FLOAT *Shells,
                                     INT  NOccupied,
                                     FLOAT  NElectrons,
                                     FLOAT  Charge,
                                     FLOAT  Electronegativity,
                                     FLOAT  Screening,
                                     FLOAT  CovalentRadius,
                                     FLOAT  NuclearCharge,
                                     FLOAT  ResidualCharge,
                                     FLOAT  Beta,
                                     FLOAT  ZEff,
                                     INT  NumberOfShells,
                                     FLOAT  Polarizability)
{
FLOAT *oldShells,*newShells;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->AtomicNumber = AtomicNumber;
     newstruct->NOccupied = NOccupied;
     newstruct->NElectrons = NElectrons;
     newstruct->Charge = Charge;
     newstruct->Electronegativity = Electronegativity;
     newstruct->Screening = Screening;
     newstruct->CovalentRadius = CovalentRadius;
     newstruct->NuclearCharge = NuclearCharge;
     newstruct->ResidualCharge = ResidualCharge;
     newstruct->Beta = Beta;
     newstruct->ZEff = ZEff;
     newstruct->NumberOfShells = NumberOfShells;
     newstruct->Polarizability = Polarizability;

     newstruct->Shells = AllocArrayFLOAT(newstruct->NumberOfShells);
     if(Shells != 0)
          {
          oldShells = Shells;
          newShells = newstruct->Shells;
          LOOPi(newstruct->NumberOfShells)
               CopyFullFLOAT(newShells++, oldShells++);
          }



     return(newstruct);
}


extern void CopyFullAtomElectronic(AtomElectronic *newstruct, AtomElectronic *oldstruct)
{
FLOAT *oldShells,*newShells;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->AtomicNumber = oldstruct->AtomicNumber;
     newstruct->NOccupied = oldstruct->NOccupied;
     newstruct->NElectrons = oldstruct->NElectrons;
     newstruct->Charge = oldstruct->Charge;
     newstruct->Electronegativity = oldstruct->Electronegativity;
     newstruct->Screening = oldstruct->Screening;
     newstruct->CovalentRadius = oldstruct->CovalentRadius;
     newstruct->NuclearCharge = oldstruct->NuclearCharge;
     newstruct->ResidualCharge = oldstruct->ResidualCharge;
     newstruct->Beta = oldstruct->Beta;
     newstruct->ZEff = oldstruct->ZEff;
     newstruct->NumberOfShells = oldstruct->NumberOfShells;
     newstruct->Polarizability = oldstruct->Polarizability;


     newstruct->Shells = AllocArrayFLOAT(newstruct->NumberOfShells);
     if(oldstruct->Shells != 0)
          {
          oldShells = oldstruct->Shells;
          newShells = newstruct->Shells;
          LOOPi(newstruct->NumberOfShells)
               CopyFullFLOAT(newShells++, oldShells++);
          }


}
extern void PrintAtomElectronic(AtomElectronic *eleptr)
{
FLOAT *ptrShells;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("       Atomic Number:");
     printf("%d\n",eleptr->AtomicNumber);
     printf("The number of electrons on the atom:");
     printf("%d\n",eleptr->NOccupied);
     printf("An array with the number of electrons in each shell.:");
     printf("%f\n",eleptr->NElectrons);
     printf("The number of shells which are occupied:");
     printf("%f\n",eleptr->Charge);
     printf("The calculated electronegativity:");
     printf("%f\n",eleptr->Electronegativity);
     printf("The sigma screening charge:");
     printf("%f\n",eleptr->Screening);
     printf("The covalent radius of the atom:");
     printf("%f\n",eleptr->CovalentRadius);
     printf("The effective nuclear charge:");
     printf("%f\n",eleptr->NuclearCharge);
     printf("The residual charge on the atom:");
     printf("%f\n",eleptr->ResidualCharge);
     printf("    Screening factor:");
     printf("%f\n",eleptr->Beta);
     printf("Effective Atom Charge:");
     printf("%f\n",eleptr->ZEff);
     printf("    Number of Shells:");
     printf("%d\n",eleptr->NumberOfShells);
     printf("  The Polarizability:");
     printf("%f\n",eleptr->Polarizability);

     printf("The full integral charge on the atom:\n");
     if(eleptr->Shells != 0)
          {
          ptrShells = eleptr->Shells;
          LOOPi(eleptr->NumberOfShells)
               PrintFLOAT(ptrShells++);
          }


}
extern void FreeAtomElectronic(AtomElectronic *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Shells);

}
extern void WriteBinAtomElectronic(AtomElectronic *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrShells;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->AtomicNumber),file);
     WriteBinINT(&(eleptr->NOccupied),file);
     WriteBinFLOAT(&(eleptr->NElectrons),file);
     WriteBinFLOAT(&(eleptr->Charge),file);
     WriteBinFLOAT(&(eleptr->Electronegativity),file);
     WriteBinFLOAT(&(eleptr->Screening),file);
     WriteBinFLOAT(&(eleptr->CovalentRadius),file);
     WriteBinFLOAT(&(eleptr->NuclearCharge),file);
     WriteBinFLOAT(&(eleptr->ResidualCharge),file);
     WriteBinFLOAT(&(eleptr->Beta),file);
     WriteBinFLOAT(&(eleptr->ZEff),file);
     WriteBinINT(&(eleptr->NumberOfShells),file);
     WriteBinFLOAT(&(eleptr->Polarizability),file);

     if(eleptr->Shells != 0)
          {
          ptrShells = eleptr->Shells;
          LOOPi(eleptr->NumberOfShells)
               WriteBinFLOAT(ptrShells++,file);
          }

}
extern INT ReadBinAtomElectronic(AtomElectronic *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrShells;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->AtomicNumber),file);
     ReadBinINT(&(eleptr->NOccupied),file);
     ReadBinFLOAT(&(eleptr->NElectrons),file);
     ReadBinFLOAT(&(eleptr->Charge),file);
     ReadBinFLOAT(&(eleptr->Electronegativity),file);
     ReadBinFLOAT(&(eleptr->Screening),file);
     ReadBinFLOAT(&(eleptr->CovalentRadius),file);
     ReadBinFLOAT(&(eleptr->NuclearCharge),file);
     ReadBinFLOAT(&(eleptr->ResidualCharge),file);
     ReadBinFLOAT(&(eleptr->Beta),file);
     ReadBinFLOAT(&(eleptr->ZEff),file);
     ReadBinINT(&(eleptr->NumberOfShells),file);
     ReadBinFLOAT(&(eleptr->Polarizability),file);

          eleptr->Shells = AllocArrayFLOAT(eleptr->NumberOfShells);
          ptrShells = eleptr->Shells;
          LOOPi(eleptr->NumberOfShells)
               ReadBinFLOAT(ptrShells++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_AtomElectronic(XDR *stream, char **eleptrp)
{
     AtomElectronic *eleptr;
     eleptr = (AtomElectronic *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->AtomicNumber));
     xdr_INT(stream,(char **) &(eleptr->NOccupied));
     xdr_FLOAT(stream,(char **) &(eleptr->NElectrons));
     xdr_FLOAT(stream,(char **) &(eleptr->Charge));
     xdr_FLOAT(stream,(char **) &(eleptr->Electronegativity));
     xdr_FLOAT(stream,(char **) &(eleptr->Screening));
     xdr_FLOAT(stream,(char **) &(eleptr->CovalentRadius));
     xdr_FLOAT(stream,(char **) &(eleptr->NuclearCharge));
     xdr_FLOAT(stream,(char **) &(eleptr->ResidualCharge));
     xdr_FLOAT(stream,(char **) &(eleptr->Beta));
     xdr_FLOAT(stream,(char **) &(eleptr->ZEff));
     xdr_INT(stream,(char **) &(eleptr->NumberOfShells));
     xdr_FLOAT(stream,(char **) &(eleptr->Polarizability));

     xdr_array(stream,(char **) &(eleptr->Shells),
             (uint *) &(eleptr->NumberOfShells),eleptr->NumberOfShells,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocAtomElectronic()
{
     return((void *) AllocateAtomElectronic);
}

extern CHAR *GetNameResonance(Resonance *str)
{
     return(str->Name);
}

extern INT GetIDResonance(Resonance *str)
{
     return(str->ID);
}

extern Resonance *CreateResonance(Resonance *newstruct,
                           INT id,
                           CHAR *name,
                           INT  NumberOfAtoms,
                           INT *Atoms)
{
INT *oldAtoms,*newAtoms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAtoms = NumberOfAtoms;

     newstruct->Atoms = AllocArrayINT(newstruct->NumberOfAtoms);
     if(Atoms != 0)
          {
          oldAtoms = Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullINT(newAtoms++, oldAtoms++);
          }



     return(newstruct);
}


extern void CopyFullResonance(Resonance *newstruct, Resonance *oldstruct)
{
INT *oldAtoms,*newAtoms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAtoms = oldstruct->NumberOfAtoms;


     newstruct->Atoms = AllocArrayINT(newstruct->NumberOfAtoms);
     if(oldstruct->Atoms != 0)
          {
          oldAtoms = oldstruct->Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullINT(newAtoms++, oldAtoms++);
          }


}
extern void PrintResonance(Resonance *eleptr)
{
INT *ptrAtoms;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number of atoms in set:");
     printf("%d\n",eleptr->NumberOfAtoms);

     printf("The set of labels for resonant atoms:\n");
     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NumberOfAtoms)
               PrintINT(ptrAtoms++);
          }


}
extern void FreeResonance(Resonance *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Atoms);

}
extern void WriteBinResonance(Resonance *eleptr, DbaseLinkedList *file)
{
INT *ptrAtoms;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAtoms),file);

     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NumberOfAtoms)
               WriteBinINT(ptrAtoms++,file);
          }

}
extern INT ReadBinResonance(Resonance *eleptr,DbaseLinkedList *file)
     {
INT *ptrAtoms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAtoms),file);

          eleptr->Atoms = AllocArrayINT(eleptr->NumberOfAtoms);
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NumberOfAtoms)
               ReadBinINT(ptrAtoms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_Resonance(XDR *stream, char **eleptrp)
{
     Resonance *eleptr;
     eleptr = (Resonance *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAtoms));

     xdr_array(stream,(char **) &(eleptr->Atoms),
             (uint *) &(eleptr->NumberOfAtoms),eleptr->NumberOfAtoms,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocResonance()
{
     return((void *) AllocateResonance);
}

extern CHAR *GetNameSetOfResonances(SetOfResonances *str)
{
     return(str->Name);
}

extern INT GetIDSetOfResonances(SetOfResonances *str)
{
     return(str->ID);
}

extern SetOfResonances *CreateSetOfResonances(SetOfResonances *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfSets,
                                       Resonance *Sets)
{
Resonance *oldSets,*newSets;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSets = NumberOfSets;

     newstruct->Sets = AllocArrayResonance(newstruct->NumberOfSets);
     if(Sets != 0)
          {
          oldSets = Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullResonance(newSets++, oldSets++);
          }



     return(newstruct);
}


extern void CopyFullSetOfResonances(SetOfResonances *newstruct, SetOfResonances *oldstruct)
{
Resonance *oldSets,*newSets;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSets = oldstruct->NumberOfSets;


     newstruct->Sets = AllocArrayResonance(newstruct->NumberOfSets);
     if(oldstruct->Sets != 0)
          {
          oldSets = oldstruct->Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullResonance(newSets++, oldSets++);
          }


}
extern void PrintSetOfResonances(SetOfResonances *eleptr)
{
Resonance *ptrSets;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("      Number Of Sets:");
     printf("%d\n",eleptr->NumberOfSets);

     printf("The set of Resonant Sets:\n");
     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               PrintResonance(ptrSets++);
          }


}
extern void FreeSetOfResonances(SetOfResonances *eleptr)
{
Resonance *ptrSets;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSets = eleptr->Sets;
     LOOPi(eleptr->NumberOfSets)
          FreeResonance(ptrSets++);
     Free(eleptr->Sets);

}
extern void WriteBinSetOfResonances(SetOfResonances *eleptr, DbaseLinkedList *file)
{
Resonance *ptrSets;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSets),file);

     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               WriteBinResonance(ptrSets++,file);
          }

}
extern INT ReadBinSetOfResonances(SetOfResonances *eleptr,DbaseLinkedList *file)
     {
Resonance *ptrSets;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSets),file);

          eleptr->Sets = AllocArrayResonance(eleptr->NumberOfSets);
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               ReadBinResonance(ptrSets++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfResonances(XDR *stream, char **eleptrp)
{
     SetOfResonances *eleptr;
     eleptr = (SetOfResonances *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSets));

     xdr_array(stream,(char **) &(eleptr->Sets),
             (uint *) &(eleptr->NumberOfSets),eleptr->NumberOfSets,
               ResonanceSize,(xdrproc_t) xdr_Resonance);
}

extern void *AllocSetOfResonances()
{
     return((void *) AllocateSetOfResonances);
}

extern CHAR *GetNameMoleculeElectronic(MoleculeElectronic *str)
{
     return(str->Name);
}

extern INT GetIDMoleculeElectronic(MoleculeElectronic *str)
{
     return(str->ID);
}

extern MoleculeElectronic *CreateMoleculeElectronic(MoleculeElectronic *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NAtoms,
                                             AtomElectronic *Atoms,
                                             BondOrderMatrix *BondOrder,
                                             SetOfResonances *Resonant)
{
AtomElectronic *oldAtoms,*newAtoms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NAtoms = NAtoms;
     if(BondOrder != 0)
          {
          newstruct->BondOrder = AllocateBondOrderMatrix;
          CopyFullBondOrderMatrix(newstruct->BondOrder, BondOrder);
          }
     else
          newstruct->BondOrder = 0;
     if(Resonant != 0)
          {
          newstruct->Resonant = AllocateSetOfResonances;
          CopyFullSetOfResonances(newstruct->Resonant, Resonant);
          }
     else
          newstruct->Resonant = 0;

     newstruct->Atoms = AllocArrayAtomElectronic(newstruct->NAtoms);
     if(Atoms != 0)
          {
          oldAtoms = Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NAtoms)
               CopyFullAtomElectronic(newAtoms++, oldAtoms++);
          }



     return(newstruct);
}


extern void CopyFullMoleculeElectronic(MoleculeElectronic *newstruct, MoleculeElectronic *oldstruct)
{
AtomElectronic *oldAtoms,*newAtoms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NAtoms = oldstruct->NAtoms;

     if(oldstruct->BondOrder != 0)
          {
          newstruct->BondOrder = AllocateBondOrderMatrix;
          CopyFullBondOrderMatrix(newstruct->BondOrder, oldstruct->BondOrder);
          }
     else
          newstruct->BondOrder = 0;
     if(oldstruct->Resonant != 0)
          {
          newstruct->Resonant = AllocateSetOfResonances;
          CopyFullSetOfResonances(newstruct->Resonant, oldstruct->Resonant);
          }
     else
          newstruct->Resonant = 0;

     newstruct->Atoms = AllocArrayAtomElectronic(newstruct->NAtoms);
     if(oldstruct->Atoms != 0)
          {
          oldAtoms = oldstruct->Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NAtoms)
               CopyFullAtomElectronic(newAtoms++, oldAtoms++);
          }


}
extern void PrintMoleculeElectronic(MoleculeElectronic *eleptr)
{
AtomElectronic *ptrAtoms;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of atoms in the molecule:");
     printf("%d\n",eleptr->NAtoms);

     printf("The bond order matrix:\n");
     PrintBondOrderMatrix(eleptr->BondOrder);

     printf("The set of Resonances:\n");
     PrintSetOfResonances(eleptr->Resonant);

     printf("AtomElectronic structures (vector of NAtom):\n");
     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NAtoms)
               PrintAtomElectronic(ptrAtoms++);
          }


}
extern void FreeMoleculeElectronic(MoleculeElectronic *eleptr)
{
AtomElectronic *ptrAtoms;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrAtoms = eleptr->Atoms;
     LOOPi(eleptr->NAtoms)
          FreeAtomElectronic(ptrAtoms++);
     Free(eleptr->Atoms);

     FreeBondOrderMatrix(eleptr->BondOrder);
     Free(eleptr->BondOrder);

     FreeSetOfResonances(eleptr->Resonant);
     Free(eleptr->Resonant);

}
extern void WriteBinMoleculeElectronic(MoleculeElectronic *eleptr, DbaseLinkedList *file)
{
AtomElectronic *ptrAtoms;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NAtoms),file);

     WriteBinBondOrderMatrix(eleptr->BondOrder,file);

     WriteBinSetOfResonances(eleptr->Resonant,file);

     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NAtoms)
               WriteBinAtomElectronic(ptrAtoms++,file);
          }

}
extern INT ReadBinMoleculeElectronic(MoleculeElectronic *eleptr,DbaseLinkedList *file)
     {
AtomElectronic *ptrAtoms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NAtoms),file);

     eleptr->BondOrder = AllocateBondOrderMatrix;
     if(ReadBinBondOrderMatrix(eleptr->BondOrder,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->BondOrder);
           eleptr->BondOrder = 0;
           }

     eleptr->Resonant = AllocateSetOfResonances;
     if(ReadBinSetOfResonances(eleptr->Resonant,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Resonant);
           eleptr->Resonant = 0;
           }

          eleptr->Atoms = AllocArrayAtomElectronic(eleptr->NAtoms);
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NAtoms)
               ReadBinAtomElectronic(ptrAtoms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MoleculeElectronic(XDR *stream, char **eleptrp)
{
     MoleculeElectronic *eleptr;
     eleptr = (MoleculeElectronic *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NAtoms));

     xdr_pointer(stream,
          (char **) &(eleptr->BondOrder),
          BondOrderMatrixSize,
                 (xdrproc_t) xdr_BondOrderMatrix);
     xdr_pointer(stream,
          (char **) &(eleptr->Resonant),
          SetOfResonancesSize,
                 (xdrproc_t) xdr_SetOfResonances);
     xdr_array(stream,(char **) &(eleptr->Atoms),
             (uint *) &(eleptr->NAtoms),eleptr->NAtoms,
               AtomElectronicSize,(xdrproc_t) xdr_AtomElectronic);
}

extern void *AllocMoleculeElectronic()
{
     return((void *) AllocateMoleculeElectronic);
}
