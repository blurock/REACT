
extern CHAR *GetNamePair(Pair *str)
{
     return(str->Name);
}

extern INT GetIDPair(Pair *str)
{
     return(str->ID);
}

extern Pair *CreatePair(Pair *newstruct,
                 INT id,
                 CHAR *name,
                 INT  I,
                 INT  J)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->I = I;
     newstruct->J = J;



     return(newstruct);
}


extern void CopyFullPair(Pair *newstruct, Pair *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->I = oldstruct->I;
     newstruct->J = oldstruct->J;



}
extern void PrintPair(Pair *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The first in the pair:");
     printf("%d\n",eleptr->I);
     printf("The second in the pair:");
     printf("%d\n",eleptr->J);

}
extern void FreePair(Pair *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinPair(Pair *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->I),file);
     WriteBinINT(&(eleptr->J),file);

}
extern INT ReadBinPair(Pair *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->I),file);
     ReadBinINT(&(eleptr->J),file);

     return(STRUCTURE_READ);
     }
extern void xdr_Pair(XDR *stream, char **eleptrp)
{
     Pair *eleptr;
     eleptr = (Pair *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->I));
     xdr_INT(stream,(char **) &(eleptr->J));

}

extern void *AllocPair()
{
     return((void *) AllocatePair);
}

extern CHAR *GetNamePairSet(PairSet *str)
{
     return(str->Name);
}

extern INT GetIDPairSet(PairSet *str)
{
     return(str->ID);
}

extern PairSet *CreatePairSet(PairSet *newstruct,
                       INT id,
                       CHAR *name,
                       INT  NumberOfPairs,
                       Pair *Pairs)
{
Pair *oldPairs,*newPairs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPairs = NumberOfPairs;

     newstruct->Pairs = AllocArrayPair(newstruct->NumberOfPairs);
     if(Pairs != 0)
          {
          oldPairs = Pairs;
          newPairs = newstruct->Pairs;
          LOOPi(newstruct->NumberOfPairs)
               CopyFullPair(newPairs++, oldPairs++);
          }



     return(newstruct);
}


extern void CopyFullPairSet(PairSet *newstruct, PairSet *oldstruct)
{
Pair *oldPairs,*newPairs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPairs = oldstruct->NumberOfPairs;


     newstruct->Pairs = AllocArrayPair(newstruct->NumberOfPairs);
     if(oldstruct->Pairs != 0)
          {
          oldPairs = oldstruct->Pairs;
          newPairs = newstruct->Pairs;
          LOOPi(newstruct->NumberOfPairs)
               CopyFullPair(newPairs++, oldPairs++);
          }


}
extern void PrintPairSet(PairSet *eleptr)
{
Pair *ptrPairs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The Number of Pairs:");
     printf("%d\n",eleptr->NumberOfPairs);

     printf("    The set of Pairs:\n");
     if(eleptr->Pairs != 0)
          {
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               PrintPair(ptrPairs++);
          }


}
extern void FreePairSet(PairSet *eleptr)
{
Pair *ptrPairs;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrPairs = eleptr->Pairs;
     LOOPi(eleptr->NumberOfPairs)
          FreePair(ptrPairs++);
     Free(eleptr->Pairs);

}
extern void WriteBinPairSet(PairSet *eleptr, DbaseLinkedList *file)
{
Pair *ptrPairs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPairs),file);

     if(eleptr->Pairs != 0)
          {
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               WriteBinPair(ptrPairs++,file);
          }

}
extern INT ReadBinPairSet(PairSet *eleptr,DbaseLinkedList *file)
     {
Pair *ptrPairs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPairs),file);

          eleptr->Pairs = AllocArrayPair(eleptr->NumberOfPairs);
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               ReadBinPair(ptrPairs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_PairSet(XDR *stream, char **eleptrp)
{
     PairSet *eleptr;
     eleptr = (PairSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPairs));

     xdr_array(stream,(char **) &(eleptr->Pairs),
             (uint *) &(eleptr->NumberOfPairs),eleptr->NumberOfPairs,
               PairSize,(xdrproc_t) xdr_Pair);
}

extern void *AllocPairSet()
{
     return((void *) AllocatePairSet);
}

extern CHAR *GetNameSetOfPairSets(SetOfPairSets *str)
{
     return(str->Name);
}

extern INT GetIDSetOfPairSets(SetOfPairSets *str)
{
     return(str->ID);
}

extern SetOfPairSets *CreateSetOfPairSets(SetOfPairSets *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfSets,
                                   PairSet *Sets)
{
PairSet *oldSets,*newSets;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSets = NumberOfSets;

     newstruct->Sets = AllocArrayPairSet(newstruct->NumberOfSets);
     if(Sets != 0)
          {
          oldSets = Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullPairSet(newSets++, oldSets++);
          }



     return(newstruct);
}


extern void CopyFullSetOfPairSets(SetOfPairSets *newstruct, SetOfPairSets *oldstruct)
{
PairSet *oldSets,*newSets;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSets = oldstruct->NumberOfSets;


     newstruct->Sets = AllocArrayPairSet(newstruct->NumberOfSets);
     if(oldstruct->Sets != 0)
          {
          oldSets = oldstruct->Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullPairSet(newSets++, oldSets++);
          }


}
extern void PrintSetOfPairSets(SetOfPairSets *eleptr)
{
PairSet *ptrSets;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number of sets:");
     printf("%d\n",eleptr->NumberOfSets);

     printf(" The set of PairSets:\n");
     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               PrintPairSet(ptrSets++);
          }


}
extern void FreeSetOfPairSets(SetOfPairSets *eleptr)
{
PairSet *ptrSets;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSets = eleptr->Sets;
     LOOPi(eleptr->NumberOfSets)
          FreePairSet(ptrSets++);
     Free(eleptr->Sets);

}
extern void WriteBinSetOfPairSets(SetOfPairSets *eleptr, DbaseLinkedList *file)
{
PairSet *ptrSets;
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
               WriteBinPairSet(ptrSets++,file);
          }

}
extern INT ReadBinSetOfPairSets(SetOfPairSets *eleptr,DbaseLinkedList *file)
     {
PairSet *ptrSets;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSets),file);

          eleptr->Sets = AllocArrayPairSet(eleptr->NumberOfSets);
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               ReadBinPairSet(ptrSets++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfPairSets(XDR *stream, char **eleptrp)
{
     SetOfPairSets *eleptr;
     eleptr = (SetOfPairSets *) eleptrp;
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
               PairSetSize,(xdrproc_t) xdr_PairSet);
}

extern void *AllocSetOfPairSets()
{
     return((void *) AllocateSetOfPairSets);
}

extern CHAR *GetNameDataSetPair(DataSetPair *str)
{
     return(str->Name);
}

extern INT GetIDDataSetPair(DataSetPair *str)
{
     return(str->ID);
}

extern DataSetPair *CreateDataSetPair(DataSetPair *newstruct,
                               INT id,
                               CHAR *name,
                               DataSubSet *Set1,
                               DataSubSet *Set2)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Set1 != 0)
          {
          newstruct->Set1 = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Set1, Set1);
          }
     else
          newstruct->Set1 = 0;
     if(Set2 != 0)
          {
          newstruct->Set2 = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Set2, Set2);
          }
     else
          newstruct->Set2 = 0;



     return(newstruct);
}


extern void CopyFullDataSetPair(DataSetPair *newstruct, DataSetPair *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Set1 != 0)
          {
          newstruct->Set1 = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Set1, oldstruct->Set1);
          }
     else
          newstruct->Set1 = 0;
     if(oldstruct->Set2 != 0)
          {
          newstruct->Set2 = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Set2, oldstruct->Set2);
          }
     else
          newstruct->Set2 = 0;


}
extern void PrintDataSetPair(DataSetPair *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The first set in the pair:\n");
     PrintDataSubSet(eleptr->Set1);

     printf("The second set in the pair:\n");
     PrintDataSubSet(eleptr->Set2);

}
extern void FreeDataSetPair(DataSetPair *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeDataSubSet(eleptr->Set1);
     Free(eleptr->Set1);

     FreeDataSubSet(eleptr->Set2);
     Free(eleptr->Set2);

}
extern void WriteBinDataSetPair(DataSetPair *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinDataSubSet(eleptr->Set1,file);

     WriteBinDataSubSet(eleptr->Set2,file);

}
extern INT ReadBinDataSetPair(DataSetPair *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Set1 = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Set1,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Set1);
           eleptr->Set1 = 0;
           }

     eleptr->Set2 = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Set2,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Set2);
           eleptr->Set2 = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_DataSetPair(XDR *stream, char **eleptrp)
{
     DataSetPair *eleptr;
     eleptr = (DataSetPair *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Set1),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Set2),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
}

extern void *AllocDataSetPair()
{
     return((void *) AllocateDataSetPair);
}

extern CHAR *GetNameEquivalentSets(EquivalentSets *str)
{
     return(str->Name);
}

extern INT GetIDEquivalentSets(EquivalentSets *str)
{
     return(str->ID);
}

extern EquivalentSets *CreateEquivalentSets(EquivalentSets *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfSets,
                                     DataSetPair *Sets)
{
DataSetPair *oldSets,*newSets;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSets = NumberOfSets;

     newstruct->Sets = AllocArrayDataSetPair(newstruct->NumberOfSets);
     if(Sets != 0)
          {
          oldSets = Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullDataSetPair(newSets++, oldSets++);
          }



     return(newstruct);
}


extern void CopyFullEquivalentSets(EquivalentSets *newstruct, EquivalentSets *oldstruct)
{
DataSetPair *oldSets,*newSets;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSets = oldstruct->NumberOfSets;


     newstruct->Sets = AllocArrayDataSetPair(newstruct->NumberOfSets);
     if(oldstruct->Sets != 0)
          {
          oldSets = oldstruct->Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumberOfSets)
               CopyFullDataSetPair(newSets++, oldSets++);
          }


}
extern void PrintEquivalentSets(EquivalentSets *eleptr)
{
DataSetPair *ptrSets;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number of Sets:");
     printf("%d\n",eleptr->NumberOfSets);

     printf("The set of equivalent sets (sets of DataSetPairs):\n");
     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               PrintDataSetPair(ptrSets++);
          }


}
extern void FreeEquivalentSets(EquivalentSets *eleptr)
{
DataSetPair *ptrSets;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSets = eleptr->Sets;
     LOOPi(eleptr->NumberOfSets)
          FreeDataSetPair(ptrSets++);
     Free(eleptr->Sets);

}
extern void WriteBinEquivalentSets(EquivalentSets *eleptr, DbaseLinkedList *file)
{
DataSetPair *ptrSets;
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
               WriteBinDataSetPair(ptrSets++,file);
          }

}
extern INT ReadBinEquivalentSets(EquivalentSets *eleptr,DbaseLinkedList *file)
     {
DataSetPair *ptrSets;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSets),file);

          eleptr->Sets = AllocArrayDataSetPair(eleptr->NumberOfSets);
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumberOfSets)
               ReadBinDataSetPair(ptrSets++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_EquivalentSets(XDR *stream, char **eleptrp)
{
     EquivalentSets *eleptr;
     eleptr = (EquivalentSets *) eleptrp;
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
               DataSetPairSize,(xdrproc_t) xdr_DataSetPair);
}

extern void *AllocEquivalentSets()
{
     return((void *) AllocateEquivalentSets);
}
