
extern CHAR *GetNameThermoCoefficients(ThermoCoefficients *str)
{
     return(str->Name);
}

extern INT GetIDThermoCoefficients(ThermoCoefficients *str)
{
     return(str->ID);
}

extern ThermoCoefficients *CreateThermoCoefficients(ThermoCoefficients *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfCoefficients,
                                             FLOAT *Coefficients)
{
FLOAT *oldCoefficients,*newCoefficients;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfCoefficients = NumberOfCoefficients;

     newstruct->Coefficients = AllocArrayFLOAT(newstruct->NumberOfCoefficients);
     if(Coefficients != 0)
          {
          oldCoefficients = Coefficients;
          newCoefficients = newstruct->Coefficients;
          LOOPi(newstruct->NumberOfCoefficients)
               CopyFullFLOAT(newCoefficients++, oldCoefficients++);
          }



     return(newstruct);
}


extern void CopyFullThermoCoefficients(ThermoCoefficients *newstruct, ThermoCoefficients *oldstruct)
{
FLOAT *oldCoefficients,*newCoefficients;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfCoefficients = oldstruct->NumberOfCoefficients;


     newstruct->Coefficients = AllocArrayFLOAT(newstruct->NumberOfCoefficients);
     if(oldstruct->Coefficients != 0)
          {
          oldCoefficients = oldstruct->Coefficients;
          newCoefficients = newstruct->Coefficients;
          LOOPi(newstruct->NumberOfCoefficients)
               CopyFullFLOAT(newCoefficients++, oldCoefficients++);
          }


}
extern void PrintThermoCoefficients(ThermoCoefficients *eleptr)
{
FLOAT *ptrCoefficients;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of coefficients:");
     printf("%d\n",eleptr->NumberOfCoefficients);

     printf("The set of coefficients:\n");
     if(eleptr->Coefficients != 0)
          {
          ptrCoefficients = eleptr->Coefficients;
          LOOPi(eleptr->NumberOfCoefficients)
               PrintFLOAT(ptrCoefficients++);
          }


}
extern void FreeThermoCoefficients(ThermoCoefficients *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Coefficients);

}
extern void WriteBinThermoCoefficients(ThermoCoefficients *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrCoefficients;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfCoefficients),file);

     if(eleptr->Coefficients != 0)
          {
          ptrCoefficients = eleptr->Coefficients;
          LOOPi(eleptr->NumberOfCoefficients)
               WriteBinFLOAT(ptrCoefficients++,file);
          }

}
extern INT ReadBinThermoCoefficients(ThermoCoefficients *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrCoefficients;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfCoefficients),file);

          eleptr->Coefficients = AllocArrayFLOAT(eleptr->NumberOfCoefficients);
          ptrCoefficients = eleptr->Coefficients;
          LOOPi(eleptr->NumberOfCoefficients)
               ReadBinFLOAT(ptrCoefficients++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ThermoCoefficients(XDR *stream, char **eleptrp)
{
     ThermoCoefficients *eleptr;
     eleptr = (ThermoCoefficients *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfCoefficients));

     xdr_array(stream,(char **) &(eleptr->Coefficients),
             (uint *) &(eleptr->NumberOfCoefficients),eleptr->NumberOfCoefficients,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocThermoCoefficients()
{
     return((void *) AllocateThermoCoefficients);
}

extern CHAR *GetNameChemkinAtomicInfo(ChemkinAtomicInfo *str)
{
     return(str->Name);
}

extern INT GetIDChemkinAtomicInfo(ChemkinAtomicInfo *str)
{
     return(str->ID);
}

extern ChemkinAtomicInfo *CreateChemkinAtomicInfo(ChemkinAtomicInfo *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  AtomicNumber,
                                           INT  Formula)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->AtomicNumber = AtomicNumber;
     newstruct->Formula = Formula;



     return(newstruct);
}


extern void CopyFullChemkinAtomicInfo(ChemkinAtomicInfo *newstruct, ChemkinAtomicInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->AtomicNumber = oldstruct->AtomicNumber;
     newstruct->Formula = oldstruct->Formula;



}
extern void PrintChemkinAtomicInfo(ChemkinAtomicInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("   The Atomic Number:");
     printf("%d\n",eleptr->AtomicNumber);
     printf("The Number of this atom in the molecule:");
     printf("%d\n",eleptr->Formula);

}
extern void FreeChemkinAtomicInfo(ChemkinAtomicInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinChemkinAtomicInfo(ChemkinAtomicInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->AtomicNumber),file);
     WriteBinINT(&(eleptr->Formula),file);

}
extern INT ReadBinChemkinAtomicInfo(ChemkinAtomicInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->AtomicNumber),file);
     ReadBinINT(&(eleptr->Formula),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ChemkinAtomicInfo(XDR *stream, char **eleptrp)
{
     ChemkinAtomicInfo *eleptr;
     eleptr = (ChemkinAtomicInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->AtomicNumber));
     xdr_INT(stream,(char **) &(eleptr->Formula));

}

extern void *AllocChemkinAtomicInfo()
{
     return((void *) AllocateChemkinAtomicInfo);
}

extern CHAR *GetNameSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *str)
{
     return(str->Name);
}

extern INT GetIDSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *str)
{
     return(str->ID);
}

extern SetOfChemkinAtomicInfo *CreateSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *newstruct,
                                                     INT id,
                                                     CHAR *name,
                                                     INT  NumberOfAtoms,
                                                     ChemkinAtomicInfo *Atoms)
{
ChemkinAtomicInfo *oldAtoms,*newAtoms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAtoms = NumberOfAtoms;

     newstruct->Atoms = AllocArrayChemkinAtomicInfo(newstruct->NumberOfAtoms);
     if(Atoms != 0)
          {
          oldAtoms = Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullChemkinAtomicInfo(newAtoms++, oldAtoms++);
          }



     return(newstruct);
}


extern void CopyFullSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *newstruct, SetOfChemkinAtomicInfo *oldstruct)
{
ChemkinAtomicInfo *oldAtoms,*newAtoms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAtoms = oldstruct->NumberOfAtoms;


     newstruct->Atoms = AllocArrayChemkinAtomicInfo(newstruct->NumberOfAtoms);
     if(oldstruct->Atoms != 0)
          {
          oldAtoms = oldstruct->Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullChemkinAtomicInfo(newAtoms++, oldAtoms++);
          }


}
extern void PrintSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr)
{
ChemkinAtomicInfo *ptrAtoms;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of atoms:");
     printf("%d\n",eleptr->NumberOfAtoms);

     printf("          The atoms :\n");
     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NumberOfAtoms)
               PrintChemkinAtomicInfo(ptrAtoms++);
          }


}
extern void FreeSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr)
{
ChemkinAtomicInfo *ptrAtoms;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrAtoms = eleptr->Atoms;
     LOOPi(eleptr->NumberOfAtoms)
          FreeChemkinAtomicInfo(ptrAtoms++);
     Free(eleptr->Atoms);

}
extern void WriteBinSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr, DbaseLinkedList *file)
{
ChemkinAtomicInfo *ptrAtoms;
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
               WriteBinChemkinAtomicInfo(ptrAtoms++,file);
          }

}
extern INT ReadBinSetOfChemkinAtomicInfo(SetOfChemkinAtomicInfo *eleptr,DbaseLinkedList *file)
     {
ChemkinAtomicInfo *ptrAtoms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAtoms),file);

          eleptr->Atoms = AllocArrayChemkinAtomicInfo(eleptr->NumberOfAtoms);
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NumberOfAtoms)
               ReadBinChemkinAtomicInfo(ptrAtoms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfChemkinAtomicInfo(XDR *stream, char **eleptrp)
{
     SetOfChemkinAtomicInfo *eleptr;
     eleptr = (SetOfChemkinAtomicInfo *) eleptrp;
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
               ChemkinAtomicInfoSize,(xdrproc_t) xdr_ChemkinAtomicInfo);
}

extern void *AllocSetOfChemkinAtomicInfo()
{
     return((void *) AllocateSetOfChemkinAtomicInfo);
}

extern CHAR *GetNameChemkinThermoRead(ChemkinThermoRead *str)
{
     return(str->Name);
}

extern INT GetIDChemkinThermoRead(ChemkinThermoRead *str)
{
     return(str->ID);
}

extern ChemkinThermoRead *CreateChemkinThermoRead(ChemkinThermoRead *newstruct,
                                           INT id,
                                           CHAR *name,
                                           SetOfChemkinAtomicInfo *AtomicSet,
                                           INT  Phase,
                                           FLOAT  LowTemperature,
                                           FLOAT  HighTemperature,
                                           FLOAT  CommonTemperature,
                                           ThermoCoefficients *UpperTempCoefficients,
                                           ThermoCoefficients *LowerTempCoefficients)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Phase = Phase;
     newstruct->LowTemperature = LowTemperature;
     newstruct->HighTemperature = HighTemperature;
     newstruct->CommonTemperature = CommonTemperature;
     if(AtomicSet != 0)
          {
          newstruct->AtomicSet = AllocateSetOfChemkinAtomicInfo;
          CopyFullSetOfChemkinAtomicInfo(newstruct->AtomicSet, AtomicSet);
          }
     else
          newstruct->AtomicSet = 0;
     if(UpperTempCoefficients != 0)
          {
          newstruct->UpperTempCoefficients = AllocateThermoCoefficients;
          CopyFullThermoCoefficients(newstruct->UpperTempCoefficients, UpperTempCoefficients);
          }
     else
          newstruct->UpperTempCoefficients = 0;
     if(LowerTempCoefficients != 0)
          {
          newstruct->LowerTempCoefficients = AllocateThermoCoefficients;
          CopyFullThermoCoefficients(newstruct->LowerTempCoefficients, LowerTempCoefficients);
          }
     else
          newstruct->LowerTempCoefficients = 0;



     return(newstruct);
}


extern void CopyFullChemkinThermoRead(ChemkinThermoRead *newstruct, ChemkinThermoRead *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Phase = oldstruct->Phase;
     newstruct->LowTemperature = oldstruct->LowTemperature;
     newstruct->HighTemperature = oldstruct->HighTemperature;
     newstruct->CommonTemperature = oldstruct->CommonTemperature;

     if(oldstruct->Species != 0)
          {
          newstruct->Species = AllocateSTRING;
          CopyFullSTRING(newstruct->Species, oldstruct->Species);
          }
     else
          newstruct->Species = 0;
     if(oldstruct->AtomicSet != 0)
          {
          newstruct->AtomicSet = AllocateSetOfChemkinAtomicInfo;
          CopyFullSetOfChemkinAtomicInfo(newstruct->AtomicSet, oldstruct->AtomicSet);
          }
     else
          newstruct->AtomicSet = 0;
     if(oldstruct->UpperTempCoefficients != 0)
          {
          newstruct->UpperTempCoefficients = AllocateThermoCoefficients;
          CopyFullThermoCoefficients(newstruct->UpperTempCoefficients, oldstruct->UpperTempCoefficients);
          }
     else
          newstruct->UpperTempCoefficients = 0;
     if(oldstruct->LowerTempCoefficients != 0)
          {
          newstruct->LowerTempCoefficients = AllocateThermoCoefficients;
          CopyFullThermoCoefficients(newstruct->LowerTempCoefficients, oldstruct->LowerTempCoefficients);
          }
     else
          newstruct->LowerTempCoefficients = 0;


}
extern void PrintChemkinThermoRead(ChemkinThermoRead *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Phase of the molecule information:");
     printf("%d\n",eleptr->Phase);
     printf(" The Low Temperature:");
     printf("%f\n",eleptr->LowTemperature);
     printf("The High Temperature:");
     printf("%f\n",eleptr->HighTemperature);
     printf("The command Temperature:");
     printf("%f\n",eleptr->CommonTemperature);

     printf("        Species Name:\n");
     PrintSTRING(eleptr->Species);

     printf("    The set of atoms:\n");
     PrintSetOfChemkinAtomicInfo(eleptr->AtomicSet);

     printf("The coefficients for the upper temperature:\n");
     PrintThermoCoefficients(eleptr->UpperTempCoefficients);

     printf("The coefficients for the lower temperature:\n");
     PrintThermoCoefficients(eleptr->LowerTempCoefficients);

}
extern void FreeChemkinThermoRead(ChemkinThermoRead *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->Species);

     FreeSetOfChemkinAtomicInfo(eleptr->AtomicSet);
     Free(eleptr->AtomicSet);

     FreeThermoCoefficients(eleptr->UpperTempCoefficients);
     Free(eleptr->UpperTempCoefficients);

     FreeThermoCoefficients(eleptr->LowerTempCoefficients);
     Free(eleptr->LowerTempCoefficients);

}
extern void WriteBinChemkinThermoRead(ChemkinThermoRead *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Phase),file);
     WriteBinFLOAT(&(eleptr->LowTemperature),file);
     WriteBinFLOAT(&(eleptr->HighTemperature),file);
     WriteBinFLOAT(&(eleptr->CommonTemperature),file);

     WriteBinSTRING(eleptr->Species,file);

     WriteBinSetOfChemkinAtomicInfo(eleptr->AtomicSet,file);

     WriteBinThermoCoefficients(eleptr->UpperTempCoefficients,file);

     WriteBinThermoCoefficients(eleptr->LowerTempCoefficients,file);

}
extern INT ReadBinChemkinThermoRead(ChemkinThermoRead *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Phase),file);
     ReadBinFLOAT(&(eleptr->LowTemperature),file);
     ReadBinFLOAT(&(eleptr->HighTemperature),file);
     ReadBinFLOAT(&(eleptr->CommonTemperature),file);

     eleptr->Species = AllocateSTRING;
     if(ReadBinSTRING(eleptr->Species,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Species);
           eleptr->Species = 0;
           }

     eleptr->AtomicSet = AllocateSetOfChemkinAtomicInfo;
     if(ReadBinSetOfChemkinAtomicInfo(eleptr->AtomicSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->AtomicSet);
           eleptr->AtomicSet = 0;
           }

     eleptr->UpperTempCoefficients = AllocateThermoCoefficients;
     if(ReadBinThermoCoefficients(eleptr->UpperTempCoefficients,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->UpperTempCoefficients);
           eleptr->UpperTempCoefficients = 0;
           }

     eleptr->LowerTempCoefficients = AllocateThermoCoefficients;
     if(ReadBinThermoCoefficients(eleptr->LowerTempCoefficients,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->LowerTempCoefficients);
           eleptr->LowerTempCoefficients = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ChemkinThermoRead(XDR *stream, char **eleptrp)
{
     ChemkinThermoRead *eleptr;
     eleptr = (ChemkinThermoRead *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Phase));
     xdr_FLOAT(stream,(char **) &(eleptr->LowTemperature));
     xdr_FLOAT(stream,(char **) &(eleptr->HighTemperature));
     xdr_FLOAT(stream,(char **) &(eleptr->CommonTemperature));

     xdr_pointer(stream,
          (char **) &(eleptr->Species),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->AtomicSet),
          SetOfChemkinAtomicInfoSize,
                 (xdrproc_t) xdr_SetOfChemkinAtomicInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->UpperTempCoefficients),
          ThermoCoefficientsSize,
                 (xdrproc_t) xdr_ThermoCoefficients);
     xdr_pointer(stream,
          (char **) &(eleptr->LowerTempCoefficients),
          ThermoCoefficientsSize,
                 (xdrproc_t) xdr_ThermoCoefficients);
}

extern void *AllocChemkinThermoRead()
{
     return((void *) AllocateChemkinThermoRead);
}

extern CHAR *GetNameSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *str)
{
     return(str->Name);
}

extern INT GetIDSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *str)
{
     return(str->ID);
}

extern SetOfChemkinThermoInformation *CreateSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *newstruct,
INT id,
CHAR *name,
INT  NumberOfMolecules,
ChemkinThermoRead *Thermo)
{
ChemkinThermoRead *oldThermo,*newThermo;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMolecules = NumberOfMolecules;

     newstruct->Thermo = AllocArrayChemkinThermoRead(newstruct->NumberOfMolecules);
     if(Thermo != 0)
          {
          oldThermo = Thermo;
          newThermo = newstruct->Thermo;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullChemkinThermoRead(newThermo++, oldThermo++);
          }



     return(newstruct);
}


extern void CopyFullSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *newstruct, SetOfChemkinThermoInformation *oldstruct)
{
ChemkinThermoRead *oldThermo,*newThermo;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMolecules = oldstruct->NumberOfMolecules;


     newstruct->Thermo = AllocArrayChemkinThermoRead(newstruct->NumberOfMolecules);
     if(oldstruct->Thermo != 0)
          {
          oldThermo = oldstruct->Thermo;
          newThermo = newstruct->Thermo;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullChemkinThermoRead(newThermo++, oldThermo++);
          }


}
extern void PrintSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr)
{
ChemkinThermoRead *ptrThermo;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of atoms read in:");
     printf("%d\n",eleptr->NumberOfMolecules);

     printf("The set of thermodynamic information:\n");
     if(eleptr->Thermo != 0)
          {
          ptrThermo = eleptr->Thermo;
          LOOPi(eleptr->NumberOfMolecules)
               PrintChemkinThermoRead(ptrThermo++);
          }


}
extern void FreeSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr)
{
ChemkinThermoRead *ptrThermo;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrThermo = eleptr->Thermo;
     LOOPi(eleptr->NumberOfMolecules)
          FreeChemkinThermoRead(ptrThermo++);
     Free(eleptr->Thermo);

}
extern void WriteBinSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr, DbaseLinkedList *file)
{
ChemkinThermoRead *ptrThermo;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMolecules),file);

     if(eleptr->Thermo != 0)
          {
          ptrThermo = eleptr->Thermo;
          LOOPi(eleptr->NumberOfMolecules)
               WriteBinChemkinThermoRead(ptrThermo++,file);
          }

}
extern INT ReadBinSetOfChemkinThermoInformation(SetOfChemkinThermoInformation *eleptr,DbaseLinkedList *file)
     {
ChemkinThermoRead *ptrThermo;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMolecules),file);

          eleptr->Thermo = AllocArrayChemkinThermoRead(eleptr->NumberOfMolecules);
          ptrThermo = eleptr->Thermo;
          LOOPi(eleptr->NumberOfMolecules)
               ReadBinChemkinThermoRead(ptrThermo++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfChemkinThermoInformation(XDR *stream, char **eleptrp)
{
     SetOfChemkinThermoInformation *eleptr;
     eleptr = (SetOfChemkinThermoInformation *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMolecules));

     xdr_array(stream,(char **) &(eleptr->Thermo),
             (uint *) &(eleptr->NumberOfMolecules),eleptr->NumberOfMolecules,
               ChemkinThermoReadSize,(xdrproc_t) xdr_ChemkinThermoRead);
}

extern void *AllocSetOfChemkinThermoInformation()
{
     return((void *) AllocateSetOfChemkinThermoInformation);
}
