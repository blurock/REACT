
extern CHAR *GetNamePerformedRxnInfoConstants(PerformedRxnInfoConstants *str)
{
     return(str->Name);
}

extern INT GetIDPerformedRxnInfoConstants(PerformedRxnInfoConstants *str)
{
     return(str->ID);
}

extern PerformedRxnInfoConstants *CreatePerformedRxnInfoConstants(PerformedRxnInfoConstants *newstruct,
INT id,
CHAR *name,
INT  SymmetryFactor,
FLOAT  Weight,
FLOAT  Aconstant,
FLOAT  Energy,
FLOAT  TempExp)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->SymmetryFactor = SymmetryFactor;
     newstruct->Weight = Weight;
     newstruct->Aconstant = Aconstant;
     newstruct->Energy = Energy;
     newstruct->TempExp = TempExp;



     return(newstruct);
}


extern void CopyFullPerformedRxnInfoConstants(PerformedRxnInfoConstants *newstruct, PerformedRxnInfoConstants *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->SymmetryFactor = oldstruct->SymmetryFactor;
     newstruct->Weight = oldstruct->Weight;
     newstruct->Aconstant = oldstruct->Aconstant;
     newstruct->Energy = oldstruct->Energy;
     newstruct->TempExp = oldstruct->TempExp;



}
extern void PrintPerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The Symmetry Factor:");
     printf("%d\n",eleptr->SymmetryFactor);
     printf("The Weighting (corresponds to the reaction constant:");
     printf("%f\n",eleptr->Weight);
     printf("The Arrhenius Constant:");
     printf("%f\n",eleptr->Aconstant);
     printf("The Activation Energy:");
     printf("%f\n",eleptr->Energy);
     printf("The Temperature Exponent:");
     printf("%f\n",eleptr->TempExp);

}
extern void FreePerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinPerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->SymmetryFactor),file);
     WriteBinFLOAT(&(eleptr->Weight),file);
     WriteBinFLOAT(&(eleptr->Aconstant),file);
     WriteBinFLOAT(&(eleptr->Energy),file);
     WriteBinFLOAT(&(eleptr->TempExp),file);

}
extern INT ReadBinPerformedRxnInfoConstants(PerformedRxnInfoConstants *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->SymmetryFactor),file);
     ReadBinFLOAT(&(eleptr->Weight),file);
     ReadBinFLOAT(&(eleptr->Aconstant),file);
     ReadBinFLOAT(&(eleptr->Energy),file);
     ReadBinFLOAT(&(eleptr->TempExp),file);

     return(STRUCTURE_READ);
     }
extern void xdr_PerformedRxnInfoConstants(XDR *stream, char **eleptrp)
{
     PerformedRxnInfoConstants *eleptr;
     eleptr = (PerformedRxnInfoConstants *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->SymmetryFactor));
     xdr_FLOAT(stream,(char **) &(eleptr->Weight));
     xdr_FLOAT(stream,(char **) &(eleptr->Aconstant));
     xdr_FLOAT(stream,(char **) &(eleptr->Energy));
     xdr_FLOAT(stream,(char **) &(eleptr->TempExp));

}

extern void *AllocPerformedRxnInfoConstants()
{
     return((void *) AllocatePerformedRxnInfoConstants);
}

extern CHAR *GetNamePerformedRxnInfo(PerformedRxnInfo *str)
{
     return(str->Name);
}

extern INT GetIDPerformedRxnInfo(PerformedRxnInfo *str)
{
     return(str->ID);
}

extern PerformedRxnInfo *CreatePerformedRxnInfo(PerformedRxnInfo *newstruct,
                                         INT id,
                                         CHAR *name,
                                         PerformedRxnInfoConstants *Forward,
                                         PerformedRxnInfoConstants *Reverse)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Forward != 0)
          {
          newstruct->Forward = AllocatePerformedRxnInfoConstants;
          CopyFullPerformedRxnInfoConstants(newstruct->Forward, Forward);
          }
     else
          newstruct->Forward = 0;
     if(Reverse != 0)
          {
          newstruct->Reverse = AllocatePerformedRxnInfoConstants;
          CopyFullPerformedRxnInfoConstants(newstruct->Reverse, Reverse);
          }
     else
          newstruct->Reverse = 0;



     return(newstruct);
}


extern void CopyFullPerformedRxnInfo(PerformedRxnInfo *newstruct, PerformedRxnInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Forward != 0)
          {
          newstruct->Forward = AllocatePerformedRxnInfoConstants;
          CopyFullPerformedRxnInfoConstants(newstruct->Forward, oldstruct->Forward);
          }
     else
          newstruct->Forward = 0;
     if(oldstruct->Reverse != 0)
          {
          newstruct->Reverse = AllocatePerformedRxnInfoConstants;
          CopyFullPerformedRxnInfoConstants(newstruct->Reverse, oldstruct->Reverse);
          }
     else
          newstruct->Reverse = 0;


}
extern void PrintPerformedRxnInfo(PerformedRxnInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The forward set of constants:\n");
     PrintPerformedRxnInfoConstants(eleptr->Forward);

     printf("The reverse set of constants:\n");
     PrintPerformedRxnInfoConstants(eleptr->Reverse);

}
extern void FreePerformedRxnInfo(PerformedRxnInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreePerformedRxnInfoConstants(eleptr->Forward);
     Free(eleptr->Forward);

     FreePerformedRxnInfoConstants(eleptr->Reverse);
     Free(eleptr->Reverse);

}
extern void WriteBinPerformedRxnInfo(PerformedRxnInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinPerformedRxnInfoConstants(eleptr->Forward,file);

     WriteBinPerformedRxnInfoConstants(eleptr->Reverse,file);

}
extern INT ReadBinPerformedRxnInfo(PerformedRxnInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Forward = AllocatePerformedRxnInfoConstants;
     if(ReadBinPerformedRxnInfoConstants(eleptr->Forward,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Forward);
           eleptr->Forward = 0;
           }

     eleptr->Reverse = AllocatePerformedRxnInfoConstants;
     if(ReadBinPerformedRxnInfoConstants(eleptr->Reverse,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reverse);
           eleptr->Reverse = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_PerformedRxnInfo(XDR *stream, char **eleptrp)
{
     PerformedRxnInfo *eleptr;
     eleptr = (PerformedRxnInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Forward),
          PerformedRxnInfoConstantsSize,
                 (xdrproc_t) xdr_PerformedRxnInfoConstants);
     xdr_pointer(stream,
          (char **) &(eleptr->Reverse),
          PerformedRxnInfoConstantsSize,
                 (xdrproc_t) xdr_PerformedRxnInfoConstants);
}

extern void *AllocPerformedRxnInfo()
{
     return((void *) AllocatePerformedRxnInfo);
}

extern CHAR *GetNameSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *str)
{
     return(str->Name);
}

extern INT GetIDSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *str)
{
     return(str->ID);
}

extern SetOfPerformedRxnInfo *CreateSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfReactions,
                                                   PerformedRxnInfo *Set)
{
PerformedRxnInfo *oldSet,*newSet;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactions = NumberOfReactions;

     newstruct->Set = AllocArrayPerformedRxnInfo(newstruct->NumberOfReactions);
     if(Set != 0)
          {
          oldSet = Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullPerformedRxnInfo(newSet++, oldSet++);
          }



     return(newstruct);
}


extern void CopyFullSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *newstruct, SetOfPerformedRxnInfo *oldstruct)
{
PerformedRxnInfo *oldSet,*newSet;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactions = oldstruct->NumberOfReactions;


     newstruct->Set = AllocArrayPerformedRxnInfo(newstruct->NumberOfReactions);
     if(oldstruct->Set != 0)
          {
          oldSet = oldstruct->Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullPerformedRxnInfo(newSet++, oldSet++);
          }


}
extern void PrintSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr)
{
PerformedRxnInfo *ptrSet;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of reactions:");
     printf("%d\n",eleptr->NumberOfReactions);

     printf("The Set of Performed Reaction Information:\n");
     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfReactions)
               PrintPerformedRxnInfo(ptrSet++);
          }


}
extern void FreeSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr)
{
PerformedRxnInfo *ptrSet;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSet = eleptr->Set;
     LOOPi(eleptr->NumberOfReactions)
          FreePerformedRxnInfo(ptrSet++);
     Free(eleptr->Set);

}
extern void WriteBinSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr, DbaseLinkedList *file)
{
PerformedRxnInfo *ptrSet;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfReactions),file);

     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfReactions)
               WriteBinPerformedRxnInfo(ptrSet++,file);
          }

}
extern INT ReadBinSetOfPerformedRxnInfo(SetOfPerformedRxnInfo *eleptr,DbaseLinkedList *file)
     {
PerformedRxnInfo *ptrSet;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactions),file);

          eleptr->Set = AllocArrayPerformedRxnInfo(eleptr->NumberOfReactions);
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfReactions)
               ReadBinPerformedRxnInfo(ptrSet++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfPerformedRxnInfo(XDR *stream, char **eleptrp)
{
     SetOfPerformedRxnInfo *eleptr;
     eleptr = (SetOfPerformedRxnInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfReactions));

     xdr_array(stream,(char **) &(eleptr->Set),
             (uint *) &(eleptr->NumberOfReactions),eleptr->NumberOfReactions,
               PerformedRxnInfoSize,(xdrproc_t) xdr_PerformedRxnInfo);
}

extern void *AllocSetOfPerformedRxnInfo()
{
     return((void *) AllocateSetOfPerformedRxnInfo);
}

extern CHAR *GetNamePerformedRxn(PerformedRxn *str)
{
     return(str->Name);
}

extern INT GetIDPerformedRxn(PerformedRxn *str)
{
     return(str->ID);
}

extern PerformedRxn *CreatePerformedRxn(PerformedRxn *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfReactants,
                                 INT  NumberOfProducts,
                                 INT *ReactantIDs,
                                 INT *ProductIDs,
                                 PerformedRxnInfo *Info)
{
INT *oldReactantIDs,*newReactantIDs;
INT *oldProductIDs,*newProductIDs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactants = NumberOfReactants;
     newstruct->NumberOfProducts = NumberOfProducts;
     if(Info != 0)
          {
          newstruct->Info = AllocatePerformedRxnInfo;
          CopyFullPerformedRxnInfo(newstruct->Info, Info);
          }
     else
          newstruct->Info = 0;

     newstruct->ReactantIDs = AllocArrayINT(newstruct->NumberOfReactants);
     if(ReactantIDs != 0)
          {
          oldReactantIDs = ReactantIDs;
          newReactantIDs = newstruct->ReactantIDs;
          LOOPi(newstruct->NumberOfReactants)
               CopyFullINT(newReactantIDs++, oldReactantIDs++);
          }

     newstruct->ProductIDs = AllocArrayINT(newstruct->NumberOfProducts);
     if(ProductIDs != 0)
          {
          oldProductIDs = ProductIDs;
          newProductIDs = newstruct->ProductIDs;
          LOOPi(newstruct->NumberOfProducts)
               CopyFullINT(newProductIDs++, oldProductIDs++);
          }



     return(newstruct);
}


extern void CopyFullPerformedRxn(PerformedRxn *newstruct, PerformedRxn *oldstruct)
{
INT *oldReactantIDs,*newReactantIDs;
INT *oldProductIDs,*newProductIDs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactants = oldstruct->NumberOfReactants;
     newstruct->NumberOfProducts = oldstruct->NumberOfProducts;

     if(oldstruct->Info != 0)
          {
          newstruct->Info = AllocatePerformedRxnInfo;
          CopyFullPerformedRxnInfo(newstruct->Info, oldstruct->Info);
          }
     else
          newstruct->Info = 0;

     newstruct->ReactantIDs = AllocArrayINT(newstruct->NumberOfReactants);
     if(oldstruct->ReactantIDs != 0)
          {
          oldReactantIDs = oldstruct->ReactantIDs;
          newReactantIDs = newstruct->ReactantIDs;
          LOOPi(newstruct->NumberOfReactants)
               CopyFullINT(newReactantIDs++, oldReactantIDs++);
          }

     newstruct->ProductIDs = AllocArrayINT(newstruct->NumberOfProducts);
     if(oldstruct->ProductIDs != 0)
          {
          oldProductIDs = oldstruct->ProductIDs;
          newProductIDs = newstruct->ProductIDs;
          LOOPi(newstruct->NumberOfProducts)
               CopyFullINT(newProductIDs++, oldProductIDs++);
          }


}
extern void PrintPerformedRxn(PerformedRxn *eleptr)
{
INT *ptrReactantIDs;
INT *ptrProductIDs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of reactants:");
     printf("%d\n",eleptr->NumberOfReactants);
     printf("The number of products:");
     printf("%d\n",eleptr->NumberOfProducts);

     printf("The Information about the reaction:\n");
     PrintPerformedRxnInfo(eleptr->Info);

     printf("The set of Reactant ID's:\n");
     if(eleptr->ReactantIDs != 0)
          {
          ptrReactantIDs = eleptr->ReactantIDs;
          LOOPi(eleptr->NumberOfReactants)
               PrintINT(ptrReactantIDs++);
          }


     printf("The set of Product ID's:\n");
     if(eleptr->ProductIDs != 0)
          {
          ptrProductIDs = eleptr->ProductIDs;
          LOOPi(eleptr->NumberOfProducts)
               PrintINT(ptrProductIDs++);
          }


}
extern void FreePerformedRxn(PerformedRxn *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->ReactantIDs);

     Free(eleptr->ProductIDs);

     FreePerformedRxnInfo(eleptr->Info);
     Free(eleptr->Info);

}
extern void WriteBinPerformedRxn(PerformedRxn *eleptr, DbaseLinkedList *file)
{
INT *ptrReactantIDs;
INT *ptrProductIDs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfReactants),file);
     WriteBinINT(&(eleptr->NumberOfProducts),file);

     WriteBinPerformedRxnInfo(eleptr->Info,file);

     if(eleptr->ReactantIDs != 0)
          {
          ptrReactantIDs = eleptr->ReactantIDs;
          LOOPi(eleptr->NumberOfReactants)
               WriteBinINT(ptrReactantIDs++,file);
          }

     if(eleptr->ProductIDs != 0)
          {
          ptrProductIDs = eleptr->ProductIDs;
          LOOPi(eleptr->NumberOfProducts)
               WriteBinINT(ptrProductIDs++,file);
          }

}
extern INT ReadBinPerformedRxn(PerformedRxn *eleptr,DbaseLinkedList *file)
     {
INT *ptrReactantIDs;
INT *ptrProductIDs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactants),file);
     ReadBinINT(&(eleptr->NumberOfProducts),file);

     eleptr->Info = AllocatePerformedRxnInfo;
     if(ReadBinPerformedRxnInfo(eleptr->Info,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Info);
           eleptr->Info = 0;
           }

          eleptr->ReactantIDs = AllocArrayINT(eleptr->NumberOfReactants);
          ptrReactantIDs = eleptr->ReactantIDs;
          LOOPi(eleptr->NumberOfReactants)
               ReadBinINT(ptrReactantIDs++,file);

          eleptr->ProductIDs = AllocArrayINT(eleptr->NumberOfProducts);
          ptrProductIDs = eleptr->ProductIDs;
          LOOPi(eleptr->NumberOfProducts)
               ReadBinINT(ptrProductIDs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_PerformedRxn(XDR *stream, char **eleptrp)
{
     PerformedRxn *eleptr;
     eleptr = (PerformedRxn *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfReactants));
     xdr_INT(stream,(char **) &(eleptr->NumberOfProducts));

     xdr_pointer(stream,
          (char **) &(eleptr->Info),
          PerformedRxnInfoSize,
                 (xdrproc_t) xdr_PerformedRxnInfo);
     xdr_array(stream,(char **) &(eleptr->ReactantIDs),
             (uint *) &(eleptr->NumberOfReactants),eleptr->NumberOfReactants,
               INTSize,(xdrproc_t) xdr_INT);
     xdr_array(stream,(char **) &(eleptr->ProductIDs),
             (uint *) &(eleptr->NumberOfProducts),eleptr->NumberOfProducts,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocPerformedRxn()
{
     return((void *) AllocatePerformedRxn);
}

extern CHAR *GetNameSetOfPerformedRxns(SetOfPerformedRxns *str)
{
     return(str->Name);
}

extern INT GetIDSetOfPerformedRxns(SetOfPerformedRxns *str)
{
     return(str->ID);
}

extern SetOfPerformedRxns *CreateSetOfPerformedRxns(SetOfPerformedRxns *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfReactions,
                                             PerformedRxn *Reactions)
{
PerformedRxn *oldReactions,*newReactions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactions = NumberOfReactions;

     newstruct->Reactions = AllocArrayPerformedRxn(newstruct->NumberOfReactions);
     if(Reactions != 0)
          {
          oldReactions = Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullPerformedRxn(newReactions++, oldReactions++);
          }



     return(newstruct);
}


extern void CopyFullSetOfPerformedRxns(SetOfPerformedRxns *newstruct, SetOfPerformedRxns *oldstruct)
{
PerformedRxn *oldReactions,*newReactions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactions = oldstruct->NumberOfReactions;


     newstruct->Reactions = AllocArrayPerformedRxn(newstruct->NumberOfReactions);
     if(oldstruct->Reactions != 0)
          {
          oldReactions = oldstruct->Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullPerformedRxn(newReactions++, oldReactions++);
          }


}
extern void PrintSetOfPerformedRxns(SetOfPerformedRxns *eleptr)
{
PerformedRxn *ptrReactions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number Of Individual Reactions:");
     printf("%d\n",eleptr->NumberOfReactions);

     printf("The Set of Individual Reactions:\n");
     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               PrintPerformedRxn(ptrReactions++);
          }


}
extern void FreeSetOfPerformedRxns(SetOfPerformedRxns *eleptr)
{
PerformedRxn *ptrReactions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactions = eleptr->Reactions;
     LOOPi(eleptr->NumberOfReactions)
          FreePerformedRxn(ptrReactions++);
     Free(eleptr->Reactions);

}
extern void WriteBinSetOfPerformedRxns(SetOfPerformedRxns *eleptr, DbaseLinkedList *file)
{
PerformedRxn *ptrReactions;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfReactions),file);

     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               WriteBinPerformedRxn(ptrReactions++,file);
          }

}
extern INT ReadBinSetOfPerformedRxns(SetOfPerformedRxns *eleptr,DbaseLinkedList *file)
     {
PerformedRxn *ptrReactions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactions),file);

          eleptr->Reactions = AllocArrayPerformedRxn(eleptr->NumberOfReactions);
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               ReadBinPerformedRxn(ptrReactions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfPerformedRxns(XDR *stream, char **eleptrp)
{
     SetOfPerformedRxns *eleptr;
     eleptr = (SetOfPerformedRxns *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfReactions));

     xdr_array(stream,(char **) &(eleptr->Reactions),
             (uint *) &(eleptr->NumberOfReactions),eleptr->NumberOfReactions,
               PerformedRxnSize,(xdrproc_t) xdr_PerformedRxn);
}

extern void *AllocSetOfPerformedRxns()
{
     return((void *) AllocateSetOfPerformedRxns);
}

extern CHAR *GetNamePerformedRxnMaster(PerformedRxnMaster *str)
{
     return(str->Name);
}

extern INT GetIDPerformedRxnMaster(PerformedRxnMaster *str)
{
     return(str->ID);
}

extern PerformedRxnMaster *CreatePerformedRxnMaster(PerformedRxnMaster *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  Direction,
                                             SetOfGraphs *Molecules,
                                             TransformSet *Reactions,
                                             DataSubSetVector *MoleculeAtomSets,
                                             SetOfPerformedRxns *Performed,
                                             SetOfPerformedRxnInfo *Adjustments)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Direction = Direction;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateSetOfGraphs;
          CopyFullSetOfGraphs(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(Reactions != 0)
          {
          newstruct->Reactions = AllocateTransformSet;
          CopyFullTransformSet(newstruct->Reactions, Reactions);
          }
     else
          newstruct->Reactions = 0;
     if(MoleculeAtomSets != 0)
          {
          newstruct->MoleculeAtomSets = AllocateDataSubSetVector;
          CopyFullDataSubSetVector(newstruct->MoleculeAtomSets, MoleculeAtomSets);
          }
     else
          newstruct->MoleculeAtomSets = 0;
     if(Performed != 0)
          {
          newstruct->Performed = AllocateSetOfPerformedRxns;
          CopyFullSetOfPerformedRxns(newstruct->Performed, Performed);
          }
     else
          newstruct->Performed = 0;
     if(Adjustments != 0)
          {
          newstruct->Adjustments = AllocateSetOfPerformedRxnInfo;
          CopyFullSetOfPerformedRxnInfo(newstruct->Adjustments, Adjustments);
          }
     else
          newstruct->Adjustments = 0;



     return(newstruct);
}


extern void CopyFullPerformedRxnMaster(PerformedRxnMaster *newstruct, PerformedRxnMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Direction = oldstruct->Direction;

     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateSetOfGraphs;
          CopyFullSetOfGraphs(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(oldstruct->Reactions != 0)
          {
          newstruct->Reactions = AllocateTransformSet;
          CopyFullTransformSet(newstruct->Reactions, oldstruct->Reactions);
          }
     else
          newstruct->Reactions = 0;
     if(oldstruct->MoleculeAtomSets != 0)
          {
          newstruct->MoleculeAtomSets = AllocateDataSubSetVector;
          CopyFullDataSubSetVector(newstruct->MoleculeAtomSets, oldstruct->MoleculeAtomSets);
          }
     else
          newstruct->MoleculeAtomSets = 0;
     if(oldstruct->Performed != 0)
          {
          newstruct->Performed = AllocateSetOfPerformedRxns;
          CopyFullSetOfPerformedRxns(newstruct->Performed, oldstruct->Performed);
          }
     else
          newstruct->Performed = 0;
     if(oldstruct->Adjustments != 0)
          {
          newstruct->Adjustments = AllocateSetOfPerformedRxnInfo;
          CopyFullSetOfPerformedRxnInfo(newstruct->Adjustments, oldstruct->Adjustments);
          }
     else
          newstruct->Adjustments = 0;


}
extern void PrintPerformedRxnMaster(PerformedRxnMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The direction of the reaction (REACTANT or PRODUCT):");
     printf("%d\n",eleptr->Direction);

     printf("The Set of Molecules Created by set of reactions:\n");
     PrintSetOfGraphs(eleptr->Molecules);

     printf("The Set of Reactions as Graphs:\n");
     PrintTransformSet(eleptr->Reactions);

     printf("The Set of Atom Sets:\n");
     PrintDataSubSetVector(eleptr->MoleculeAtomSets);

     printf("The set of reactions:\n");
     PrintSetOfPerformedRxns(eleptr->Performed);

     printf("The Set of Adjustments to reaction factors:\n");
     PrintSetOfPerformedRxnInfo(eleptr->Adjustments);

}
extern void FreePerformedRxnMaster(PerformedRxnMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSetOfGraphs(eleptr->Molecules);
     Free(eleptr->Molecules);

     FreeTransformSet(eleptr->Reactions);
     Free(eleptr->Reactions);

     FreeDataSubSetVector(eleptr->MoleculeAtomSets);
     Free(eleptr->MoleculeAtomSets);

     FreeSetOfPerformedRxns(eleptr->Performed);
     Free(eleptr->Performed);

     FreeSetOfPerformedRxnInfo(eleptr->Adjustments);
     Free(eleptr->Adjustments);

}
extern void WriteBinPerformedRxnMaster(PerformedRxnMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Direction),file);

     WriteBinSetOfGraphs(eleptr->Molecules,file);

     WriteBinTransformSet(eleptr->Reactions,file);

     WriteBinDataSubSetVector(eleptr->MoleculeAtomSets,file);

     WriteBinSetOfPerformedRxns(eleptr->Performed,file);

     WriteBinSetOfPerformedRxnInfo(eleptr->Adjustments,file);

}
extern INT ReadBinPerformedRxnMaster(PerformedRxnMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Direction),file);

     eleptr->Molecules = AllocateSetOfGraphs;
     if(ReadBinSetOfGraphs(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

     eleptr->Reactions = AllocateTransformSet;
     if(ReadBinTransformSet(eleptr->Reactions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactions);
           eleptr->Reactions = 0;
           }

     eleptr->MoleculeAtomSets = AllocateDataSubSetVector;
     if(ReadBinDataSubSetVector(eleptr->MoleculeAtomSets,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->MoleculeAtomSets);
           eleptr->MoleculeAtomSets = 0;
           }

     eleptr->Performed = AllocateSetOfPerformedRxns;
     if(ReadBinSetOfPerformedRxns(eleptr->Performed,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Performed);
           eleptr->Performed = 0;
           }

     eleptr->Adjustments = AllocateSetOfPerformedRxnInfo;
     if(ReadBinSetOfPerformedRxnInfo(eleptr->Adjustments,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Adjustments);
           eleptr->Adjustments = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_PerformedRxnMaster(XDR *stream, char **eleptrp)
{
     PerformedRxnMaster *eleptr;
     eleptr = (PerformedRxnMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Direction));

     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          SetOfGraphsSize,
                 (xdrproc_t) xdr_SetOfGraphs);
     xdr_pointer(stream,
          (char **) &(eleptr->Reactions),
          TransformSetSize,
                 (xdrproc_t) xdr_TransformSet);
     xdr_pointer(stream,
          (char **) &(eleptr->MoleculeAtomSets),
          DataSubSetVectorSize,
                 (xdrproc_t) xdr_DataSubSetVector);
     xdr_pointer(stream,
          (char **) &(eleptr->Performed),
          SetOfPerformedRxnsSize,
                 (xdrproc_t) xdr_SetOfPerformedRxns);
     xdr_pointer(stream,
          (char **) &(eleptr->Adjustments),
          SetOfPerformedRxnInfoSize,
                 (xdrproc_t) xdr_SetOfPerformedRxnInfo);
}

extern void *AllocPerformedRxnMaster()
{
     return((void *) AllocatePerformedRxnMaster);
}
