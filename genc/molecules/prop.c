
extern CHAR *GetNameIntegerPropVector(IntegerPropVector *str)
{
     return(str->Name);
}

extern INT GetIDIntegerPropVector(IntegerPropVector *str)
{
     return(str->ID);
}

extern IntegerPropVector *CreateIntegerPropVector(IntegerPropVector *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfIntegers,
                                           INT *Integers)
{
INT *oldIntegers,*newIntegers;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfIntegers = NumberOfIntegers;

     newstruct->Integers = AllocArrayINT(newstruct->NumberOfIntegers);
     if(Integers != 0)
          {
          oldIntegers = Integers;
          newIntegers = newstruct->Integers;
          LOOPi(newstruct->NumberOfIntegers)
               CopyFullINT(newIntegers++, oldIntegers++);
          }



     return(newstruct);
}


extern void CopyFullIntegerPropVector(IntegerPropVector *newstruct, IntegerPropVector *oldstruct)
{
INT *oldIntegers,*newIntegers;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfIntegers = oldstruct->NumberOfIntegers;


     newstruct->Integers = AllocArrayINT(newstruct->NumberOfIntegers);
     if(oldstruct->Integers != 0)
          {
          oldIntegers = oldstruct->Integers;
          newIntegers = newstruct->Integers;
          LOOPi(newstruct->NumberOfIntegers)
               CopyFullINT(newIntegers++, oldIntegers++);
          }


}
extern void PrintIntegerPropVector(IntegerPropVector *eleptr)
{
INT *ptrIntegers;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Integers Stored:");
     printf("%d\n",eleptr->NumberOfIntegers);

     printf("The Vector of Integers:\n");
     if(eleptr->Integers != 0)
          {
          ptrIntegers = eleptr->Integers;
          LOOPi(eleptr->NumberOfIntegers)
               PrintINT(ptrIntegers++);
          }


}
extern void FreeIntegerPropVector(IntegerPropVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Integers);

}
extern void WriteBinIntegerPropVector(IntegerPropVector *eleptr, DbaseLinkedList *file)
{
INT *ptrIntegers;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfIntegers),file);

     if(eleptr->Integers != 0)
          {
          ptrIntegers = eleptr->Integers;
          LOOPi(eleptr->NumberOfIntegers)
               WriteBinINT(ptrIntegers++,file);
          }

}
extern INT ReadBinIntegerPropVector(IntegerPropVector *eleptr,DbaseLinkedList *file)
     {
INT *ptrIntegers;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfIntegers),file);

          eleptr->Integers = AllocArrayINT(eleptr->NumberOfIntegers);
          ptrIntegers = eleptr->Integers;
          LOOPi(eleptr->NumberOfIntegers)
               ReadBinINT(ptrIntegers++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_IntegerPropVector(XDR *stream, char **eleptrp)
{
     IntegerPropVector *eleptr;
     eleptr = (IntegerPropVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfIntegers));

     xdr_array(stream,(char **) &(eleptr->Integers),
             (uint *) &(eleptr->NumberOfIntegers),eleptr->NumberOfIntegers,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocIntegerPropVector()
{
     return((void *) AllocateIntegerPropVector);
}

extern CHAR *GetNameFloatPropVector(FloatPropVector *str)
{
     return(str->Name);
}

extern INT GetIDFloatPropVector(FloatPropVector *str)
{
     return(str->ID);
}

extern FloatPropVector *CreateFloatPropVector(FloatPropVector *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfFloats,
                                       INT *Floats)
{
INT *oldFloats,*newFloats;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfFloats = NumberOfFloats;

     newstruct->Floats = AllocArrayINT(newstruct->NumberOfFloats);
     if(Floats != 0)
          {
          oldFloats = Floats;
          newFloats = newstruct->Floats;
          LOOPi(newstruct->NumberOfFloats)
               CopyFullINT(newFloats++, oldFloats++);
          }



     return(newstruct);
}


extern void CopyFullFloatPropVector(FloatPropVector *newstruct, FloatPropVector *oldstruct)
{
INT *oldFloats,*newFloats;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfFloats = oldstruct->NumberOfFloats;


     newstruct->Floats = AllocArrayINT(newstruct->NumberOfFloats);
     if(oldstruct->Floats != 0)
          {
          oldFloats = oldstruct->Floats;
          newFloats = newstruct->Floats;
          LOOPi(newstruct->NumberOfFloats)
               CopyFullINT(newFloats++, oldFloats++);
          }


}
extern void PrintFloatPropVector(FloatPropVector *eleptr)
{
INT *ptrFloats;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Floats Stored:");
     printf("%d\n",eleptr->NumberOfFloats);

     printf("The Vector of Floats:\n");
     if(eleptr->Floats != 0)
          {
          ptrFloats = eleptr->Floats;
          LOOPi(eleptr->NumberOfFloats)
               PrintINT(ptrFloats++);
          }


}
extern void FreeFloatPropVector(FloatPropVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Floats);

}
extern void WriteBinFloatPropVector(FloatPropVector *eleptr, DbaseLinkedList *file)
{
INT *ptrFloats;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfFloats),file);

     if(eleptr->Floats != 0)
          {
          ptrFloats = eleptr->Floats;
          LOOPi(eleptr->NumberOfFloats)
               WriteBinINT(ptrFloats++,file);
          }

}
extern INT ReadBinFloatPropVector(FloatPropVector *eleptr,DbaseLinkedList *file)
     {
INT *ptrFloats;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfFloats),file);

          eleptr->Floats = AllocArrayINT(eleptr->NumberOfFloats);
          ptrFloats = eleptr->Floats;
          LOOPi(eleptr->NumberOfFloats)
               ReadBinINT(ptrFloats++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_FloatPropVector(XDR *stream, char **eleptrp)
{
     FloatPropVector *eleptr;
     eleptr = (FloatPropVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfFloats));

     xdr_array(stream,(char **) &(eleptr->Floats),
             (uint *) &(eleptr->NumberOfFloats),eleptr->NumberOfFloats,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocFloatPropVector()
{
     return((void *) AllocateFloatPropVector);
}

extern CHAR *GetNamePropValue(PropValue *str)
{
     return(str->Name);
}

extern INT GetIDPropValue(PropValue *str)
{
     return(str->ID);
}

extern PropValue *CreatePropValue(PropValue *newstruct,
                           INT id,
                           CHAR *name,
                           INT  Integer,
                           FLOAT  Float,
                           IntegerPropVector *IntVec,
                           FloatPropVector *FltVec)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Integer = Integer;
     newstruct->Float = Float;
     if(IntVec != 0)
          {
          newstruct->IntVec = AllocateIntegerPropVector;
          CopyFullIntegerPropVector(newstruct->IntVec, IntVec);
          }
     else
          newstruct->IntVec = 0;
     if(FltVec != 0)
          {
          newstruct->FltVec = AllocateFloatPropVector;
          CopyFullFloatPropVector(newstruct->FltVec, FltVec);
          }
     else
          newstruct->FltVec = 0;



     return(newstruct);
}


extern void CopyFullPropValue(PropValue *newstruct, PropValue *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Integer = oldstruct->Integer;
     newstruct->Float = oldstruct->Float;

     if(oldstruct->IntVec != 0)
          {
          newstruct->IntVec = AllocateIntegerPropVector;
          CopyFullIntegerPropVector(newstruct->IntVec, oldstruct->IntVec);
          }
     else
          newstruct->IntVec = 0;
     if(oldstruct->FltVec != 0)
          {
          newstruct->FltVec = AllocateFloatPropVector;
          CopyFullFloatPropVector(newstruct->FltVec, oldstruct->FltVec);
          }
     else
          newstruct->FltVec = 0;


}
extern void PrintPropValue(PropValue *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("    A Single Integer:");
     printf("%d\n",eleptr->Integer);
     printf("      A Single Float:");
     printf("%f\n",eleptr->Float);

     printf("A Vector of Integers:\n");
     PrintIntegerPropVector(eleptr->IntVec);

     printf("  A Vector of Floats:\n");
     PrintFloatPropVector(eleptr->FltVec);

}
extern void FreePropValue(PropValue *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeIntegerPropVector(eleptr->IntVec);
     Free(eleptr->IntVec);

     FreeFloatPropVector(eleptr->FltVec);
     Free(eleptr->FltVec);

}
extern void WriteBinPropValue(PropValue *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Integer),file);
     WriteBinFLOAT(&(eleptr->Float),file);

     WriteBinIntegerPropVector(eleptr->IntVec,file);

     WriteBinFloatPropVector(eleptr->FltVec,file);

}
extern INT ReadBinPropValue(PropValue *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Integer),file);
     ReadBinFLOAT(&(eleptr->Float),file);

     eleptr->IntVec = AllocateIntegerPropVector;
     if(ReadBinIntegerPropVector(eleptr->IntVec,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->IntVec);
           eleptr->IntVec = 0;
           }

     eleptr->FltVec = AllocateFloatPropVector;
     if(ReadBinFloatPropVector(eleptr->FltVec,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->FltVec);
           eleptr->FltVec = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_PropValue(XDR *stream, char **eleptrp)
{
     PropValue *eleptr;
     eleptr = (PropValue *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Integer));
     xdr_FLOAT(stream,(char **) &(eleptr->Float));

     xdr_pointer(stream,
          (char **) &(eleptr->IntVec),
          IntegerPropVectorSize,
                 (xdrproc_t) xdr_IntegerPropVector);
     xdr_pointer(stream,
          (char **) &(eleptr->FltVec),
          FloatPropVectorSize,
                 (xdrproc_t) xdr_FloatPropVector);
}

extern void *AllocPropValue()
{
     return((void *) AllocatePropValue);
}

extern CHAR *GetNameCompareVector(CompareVector *str)
{
     return(str->Name);
}

extern INT GetIDCompareVector(CompareVector *str)
{
     return(str->ID);
}

extern CompareVector *CreateCompareVector(CompareVector *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfObjects,
                                   INT *Compares)
{
INT *oldCompares,*newCompares;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfObjects = NumberOfObjects;

     newstruct->Compares = AllocArrayINT(newstruct->NumberOfObjects);
     if(Compares != 0)
          {
          oldCompares = Compares;
          newCompares = newstruct->Compares;
          LOOPi(newstruct->NumberOfObjects)
               CopyFullINT(newCompares++, oldCompares++);
          }



     return(newstruct);
}


extern void CopyFullCompareVector(CompareVector *newstruct, CompareVector *oldstruct)
{
INT *oldCompares,*newCompares;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfObjects = oldstruct->NumberOfObjects;


     newstruct->Compares = AllocArrayINT(newstruct->NumberOfObjects);
     if(oldstruct->Compares != 0)
          {
          oldCompares = oldstruct->Compares;
          newCompares = newstruct->Compares;
          LOOPi(newstruct->NumberOfObjects)
               CopyFullINT(newCompares++, oldCompares++);
          }


}
extern void PrintCompareVector(CompareVector *eleptr)
{
INT *ptrCompares;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number Objects:");
     printf("%d\n",eleptr->NumberOfObjects);

     printf("The Comparisons of reference object with rest:\n");
     if(eleptr->Compares != 0)
          {
          ptrCompares = eleptr->Compares;
          LOOPi(eleptr->NumberOfObjects)
               PrintINT(ptrCompares++);
          }


}
extern void FreeCompareVector(CompareVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Compares);

}
extern void WriteBinCompareVector(CompareVector *eleptr, DbaseLinkedList *file)
{
INT *ptrCompares;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfObjects),file);

     if(eleptr->Compares != 0)
          {
          ptrCompares = eleptr->Compares;
          LOOPi(eleptr->NumberOfObjects)
               WriteBinINT(ptrCompares++,file);
          }

}
extern INT ReadBinCompareVector(CompareVector *eleptr,DbaseLinkedList *file)
     {
INT *ptrCompares;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfObjects),file);

          eleptr->Compares = AllocArrayINT(eleptr->NumberOfObjects);
          ptrCompares = eleptr->Compares;
          LOOPi(eleptr->NumberOfObjects)
               ReadBinINT(ptrCompares++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_CompareVector(XDR *stream, char **eleptrp)
{
     CompareVector *eleptr;
     eleptr = (CompareVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfObjects));

     xdr_array(stream,(char **) &(eleptr->Compares),
             (uint *) &(eleptr->NumberOfObjects),eleptr->NumberOfObjects,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocCompareVector()
{
     return((void *) AllocateCompareVector);
}

extern CHAR *GetNameCompareVectorSet(CompareVectorSet *str)
{
     return(str->Name);
}

extern INT GetIDCompareVectorSet(CompareVectorSet *str)
{
     return(str->ID);
}

extern CompareVectorSet *CreateCompareVectorSet(CompareVectorSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfSets,
                                         CompareVector *Sets)
{
CompareVector *oldSets,*newSets;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSets = NumberOfSets;

     newstruct->Sets = AllocArrayCompareVector(newstruct->NumberOfSets);
     if(Sets != 0)
          {
          oldSets = Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullCompareVector(newSets++, oldSets++);
          }



     return(newstruct);
}


extern void CopyFullCompareVectorSet(CompareVectorSet *newstruct, CompareVectorSet *oldstruct)
{
CompareVector *oldSets,*newSets;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSets = oldstruct->NumberOfSets;


     newstruct->Sets = AllocArrayCompareVector(newstruct->NumberOfSets);
     if(oldstruct->Sets != 0)
          {
          oldSets = oldstruct->Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullCompareVector(newSets++, oldSets++);
          }


}
extern void PrintCompareVectorSet(CompareVectorSet *eleptr)
{
CompareVector *ptrSets;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of sets:");
     printf("%d\n",eleptr->NumberOfSets);

     printf("The set of Compare Vectors:\n");
     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               PrintCompareVector(ptrSets++);
          }


}
extern void FreeCompareVectorSet(CompareVectorSet *eleptr)
{
CompareVector *ptrSets;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSets = eleptr->Sets;
     LOOPi(eleptr->NumberOfSets)
          FreeCompareVector(ptrSets++);
     Free(eleptr->Sets);

}
extern void WriteBinCompareVectorSet(CompareVectorSet *eleptr, DbaseLinkedList *file)
{
CompareVector *ptrSets;
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
               WriteBinCompareVector(ptrSets++,file);
          }

}
extern INT ReadBinCompareVectorSet(CompareVectorSet *eleptr,DbaseLinkedList *file)
     {
CompareVector *ptrSets;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSets),file);

          eleptr->Sets = AllocArrayCompareVector(eleptr->NumberOfSets);
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               ReadBinCompareVector(ptrSets++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_CompareVectorSet(XDR *stream, char **eleptrp)
{
     CompareVectorSet *eleptr;
     eleptr = (CompareVectorSet *) eleptrp;
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
               CompareVectorSize,(xdrproc_t) xdr_CompareVector);
}

extern void *AllocCompareVectorSet()
{
     return((void *) AllocateCompareVectorSet);
}
