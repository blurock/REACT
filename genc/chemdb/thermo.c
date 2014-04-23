
extern CHAR *GetNameBensonTables(BensonTables *str)
{
     return(str->Name);
}

extern INT GetIDBensonTables(BensonTables *str)
{
     return(str->ID);
}

extern BensonTables *CreateBensonTables(BensonTables *newstruct,
                                 INT id,
                                 CHAR *name,
                                 BensonSecondOrderTable *SecondOrder,
                                 BensonCalculation *BensonTree,
                                 SetOfBensonAtomTranslationPairs *Translation)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(SecondOrder != 0)
          {
          newstruct->SecondOrder = AllocateBensonSecondOrderTable;
          CopyFullBensonSecondOrderTable(newstruct->SecondOrder, SecondOrder);
          }
     else
          newstruct->SecondOrder = 0;
     if(BensonTree != 0)
          {
          newstruct->BensonTree = AllocateBensonCalculation;
          CopyFullBensonCalculation(newstruct->BensonTree, BensonTree);
          }
     else
          newstruct->BensonTree = 0;
     if(Translation != 0)
          {
          newstruct->Translation = AllocateSetOfBensonAtomTranslationPairs;
          CopyFullSetOfBensonAtomTranslationPairs(newstruct->Translation, Translation);
          }
     else
          newstruct->Translation = 0;



     return(newstruct);
}


extern void CopyFullBensonTables(BensonTables *newstruct, BensonTables *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->SecondOrder != 0)
          {
          newstruct->SecondOrder = AllocateBensonSecondOrderTable;
          CopyFullBensonSecondOrderTable(newstruct->SecondOrder, oldstruct->SecondOrder);
          }
     else
          newstruct->SecondOrder = 0;
     if(oldstruct->BensonTree != 0)
          {
          newstruct->BensonTree = AllocateBensonCalculation;
          CopyFullBensonCalculation(newstruct->BensonTree, oldstruct->BensonTree);
          }
     else
          newstruct->BensonTree = 0;
     if(oldstruct->Translation != 0)
          {
          newstruct->Translation = AllocateSetOfBensonAtomTranslationPairs;
          CopyFullSetOfBensonAtomTranslationPairs(newstruct->Translation, oldstruct->Translation);
          }
     else
          newstruct->Translation = 0;


}
extern void PrintBensonTables(BensonTables *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Table of Second Order Bond Values:\n");
     PrintBensonSecondOrderTable(eleptr->SecondOrder);

     printf("The Table Values in Tree form:\n");
     PrintBensonCalculation(eleptr->BensonTree);

     printf("The corresponding translation table:\n");
     PrintSetOfBensonAtomTranslationPairs(eleptr->Translation);

}
extern void FreeBensonTables(BensonTables *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeBensonSecondOrderTable(eleptr->SecondOrder);
     Free(eleptr->SecondOrder);

     FreeBensonCalculation(eleptr->BensonTree);
     Free(eleptr->BensonTree);

     FreeSetOfBensonAtomTranslationPairs(eleptr->Translation);
     Free(eleptr->Translation);

}
extern void WriteBinBensonTables(BensonTables *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinBensonSecondOrderTable(eleptr->SecondOrder,file);

     WriteBinBensonCalculation(eleptr->BensonTree,file);

     WriteBinSetOfBensonAtomTranslationPairs(eleptr->Translation,file);

}
extern INT ReadBinBensonTables(BensonTables *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->SecondOrder = AllocateBensonSecondOrderTable;
     if(ReadBinBensonSecondOrderTable(eleptr->SecondOrder,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SecondOrder);
           eleptr->SecondOrder = 0;
           }

     eleptr->BensonTree = AllocateBensonCalculation;
     if(ReadBinBensonCalculation(eleptr->BensonTree,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->BensonTree);
           eleptr->BensonTree = 0;
           }

     eleptr->Translation = AllocateSetOfBensonAtomTranslationPairs;
     if(ReadBinSetOfBensonAtomTranslationPairs(eleptr->Translation,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Translation);
           eleptr->Translation = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BensonTables(XDR *stream, char **eleptrp)
{
     BensonTables *eleptr;
     eleptr = (BensonTables *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->SecondOrder),
          BensonSecondOrderTableSize,
                 (xdrproc_t) xdr_BensonSecondOrderTable);
     xdr_pointer(stream,
          (char **) &(eleptr->BensonTree),
          BensonCalculationSize,
                 (xdrproc_t) xdr_BensonCalculation);
     xdr_pointer(stream,
          (char **) &(eleptr->Translation),
          SetOfBensonAtomTranslationPairsSize,
                 (xdrproc_t) xdr_SetOfBensonAtomTranslationPairs);
}

extern void *AllocBensonTables()
{
     return((void *) AllocateBensonTables);
}
