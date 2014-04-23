
extern CHAR *GetNameSetOfTables(SetOfTables *str)
{
     return(str->Name);
}

extern INT GetIDSetOfTables(SetOfTables *str)
{
     return(str->ID);
}

extern SetOfTables *CreateSetOfTables(SetOfTables *newstruct,
                               INT id,
                               CHAR *name,
                               SetOfChemkinThermoInformation *ChemkinThermo,
                               SetOfBenson2ndOrderTables *SecondOrder,
                               SetOfBensonAtomTranslationPairs *AtomTranslations,
                               BensonCalculation *BensonTree)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(ChemkinThermo != 0)
          {
          newstruct->ChemkinThermo = AllocateSetOfChemkinThermoInformation;
          CopyFullSetOfChemkinThermoInformation(newstruct->ChemkinThermo, ChemkinThermo);
          }
     else
          newstruct->ChemkinThermo = 0;
     if(SecondOrder != 0)
          {
          newstruct->SecondOrder = AllocateSetOfBenson2ndOrderTables;
          CopyFullSetOfBenson2ndOrderTables(newstruct->SecondOrder, SecondOrder);
          }
     else
          newstruct->SecondOrder = 0;
     if(AtomTranslations != 0)
          {
          newstruct->AtomTranslations = AllocateSetOfBensonAtomTranslationPairs;
          CopyFullSetOfBensonAtomTranslationPairs(newstruct->AtomTranslations, AtomTranslations);
          }
     else
          newstruct->AtomTranslations = 0;
     if(BensonTree != 0)
          {
          newstruct->BensonTree = AllocateBensonCalculation;
          CopyFullBensonCalculation(newstruct->BensonTree, BensonTree);
          }
     else
          newstruct->BensonTree = 0;



     return(newstruct);
}


extern void CopyFullSetOfTables(SetOfTables *newstruct, SetOfTables *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->ChemkinThermo != 0)
          {
          newstruct->ChemkinThermo = AllocateSetOfChemkinThermoInformation;
          CopyFullSetOfChemkinThermoInformation(newstruct->ChemkinThermo, oldstruct->ChemkinThermo);
          }
     else
          newstruct->ChemkinThermo = 0;
     if(oldstruct->SecondOrder != 0)
          {
          newstruct->SecondOrder = AllocateSetOfBenson2ndOrderTables;
          CopyFullSetOfBenson2ndOrderTables(newstruct->SecondOrder, oldstruct->SecondOrder);
          }
     else
          newstruct->SecondOrder = 0;
     if(oldstruct->AtomTranslations != 0)
          {
          newstruct->AtomTranslations = AllocateSetOfBensonAtomTranslationPairs;
          CopyFullSetOfBensonAtomTranslationPairs(newstruct->AtomTranslations, oldstruct->AtomTranslations);
          }
     else
          newstruct->AtomTranslations = 0;
     if(oldstruct->BensonTree != 0)
          {
          newstruct->BensonTree = AllocateBensonCalculation;
          CopyFullBensonCalculation(newstruct->BensonTree, oldstruct->BensonTree);
          }
     else
          newstruct->BensonTree = 0;


}
extern void PrintSetOfTables(SetOfTables *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Chemkin Thermodynamic Table:\n");
     PrintSetOfChemkinThermoInformation(eleptr->ChemkinThermo);

     printf("Set of Benson 2nd Order Tables:\n");
     PrintSetOfBenson2ndOrderTables(eleptr->SecondOrder);

     printf("Set of translations of benson atom strings:\n");
     PrintSetOfBensonAtomTranslationPairs(eleptr->AtomTranslations);

     printf("The transformed Benson Tables:\n");
     PrintBensonCalculation(eleptr->BensonTree);

}
extern void FreeSetOfTables(SetOfTables *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSetOfChemkinThermoInformation(eleptr->ChemkinThermo);
     Free(eleptr->ChemkinThermo);

     FreeSetOfBenson2ndOrderTables(eleptr->SecondOrder);
     Free(eleptr->SecondOrder);

     FreeSetOfBensonAtomTranslationPairs(eleptr->AtomTranslations);
     Free(eleptr->AtomTranslations);

     FreeBensonCalculation(eleptr->BensonTree);
     Free(eleptr->BensonTree);

}
extern void WriteBinSetOfTables(SetOfTables *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSetOfChemkinThermoInformation(eleptr->ChemkinThermo,file);

     WriteBinSetOfBenson2ndOrderTables(eleptr->SecondOrder,file);

     WriteBinSetOfBensonAtomTranslationPairs(eleptr->AtomTranslations,file);

     WriteBinBensonCalculation(eleptr->BensonTree,file);

}
extern INT ReadBinSetOfTables(SetOfTables *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->ChemkinThermo = AllocateSetOfChemkinThermoInformation;
     if(ReadBinSetOfChemkinThermoInformation(eleptr->ChemkinThermo,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ChemkinThermo);
           eleptr->ChemkinThermo = 0;
           }

     eleptr->SecondOrder = AllocateSetOfBenson2ndOrderTables;
     if(ReadBinSetOfBenson2ndOrderTables(eleptr->SecondOrder,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SecondOrder);
           eleptr->SecondOrder = 0;
           }

     eleptr->AtomTranslations = AllocateSetOfBensonAtomTranslationPairs;
     if(ReadBinSetOfBensonAtomTranslationPairs(eleptr->AtomTranslations,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->AtomTranslations);
           eleptr->AtomTranslations = 0;
           }

     eleptr->BensonTree = AllocateBensonCalculation;
     if(ReadBinBensonCalculation(eleptr->BensonTree,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->BensonTree);
           eleptr->BensonTree = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfTables(XDR *stream, char **eleptrp)
{
     SetOfTables *eleptr;
     eleptr = (SetOfTables *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->ChemkinThermo),
          SetOfChemkinThermoInformationSize,
                 (xdrproc_t) xdr_SetOfChemkinThermoInformation);
     xdr_pointer(stream,
          (char **) &(eleptr->SecondOrder),
          SetOfBenson2ndOrderTablesSize,
                 (xdrproc_t) xdr_SetOfBenson2ndOrderTables);
     xdr_pointer(stream,
          (char **) &(eleptr->AtomTranslations),
          SetOfBensonAtomTranslationPairsSize,
                 (xdrproc_t) xdr_SetOfBensonAtomTranslationPairs);
     xdr_pointer(stream,
          (char **) &(eleptr->BensonTree),
          BensonCalculationSize,
                 (xdrproc_t) xdr_BensonCalculation);
}

extern void *AllocSetOfTables()
{
     return((void *) AllocateSetOfTables);
}
