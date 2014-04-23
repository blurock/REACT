
extern CHAR *GetNameRxnReacProdSet(RxnReacProdSet *str)
{
     return(str->Name);
}

extern INT GetIDRxnReacProdSet(RxnReacProdSet *str)
{
     return(str->ID);
}

extern RxnReacProdSet *CreateRxnReacProdSet(RxnReacProdSet *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfMolecules,
                                     INT *Molecules)
{
INT *oldMolecules,*newMolecules;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMolecules = NumberOfMolecules;

     newstruct->Molecules = AllocArrayINT(newstruct->NumberOfMolecules);
     if(Molecules != 0)
          {
          oldMolecules = Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullINT(newMolecules++, oldMolecules++);
          }



     return(newstruct);
}


extern void CopyFullRxnReacProdSet(RxnReacProdSet *newstruct, RxnReacProdSet *oldstruct)
{
INT *oldMolecules,*newMolecules;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMolecules = oldstruct->NumberOfMolecules;


     newstruct->Molecules = AllocArrayINT(newstruct->NumberOfMolecules);
     if(oldstruct->Molecules != 0)
          {
          oldMolecules = oldstruct->Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullINT(newMolecules++, oldMolecules++);
          }


}
extern void PrintRxnReacProdSet(RxnReacProdSet *eleptr)
{
INT *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Molecules:");
     printf("%d\n",eleptr->NumberOfMolecules);

     printf("The set of Molecule ID's:\n");
     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               PrintINT(ptrMolecules++);
          }


}
extern void FreeRxnReacProdSet(RxnReacProdSet *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Molecules);

}
extern void WriteBinRxnReacProdSet(RxnReacProdSet *eleptr, DbaseLinkedList *file)
{
INT *ptrMolecules;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMolecules),file);

     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               WriteBinINT(ptrMolecules++,file);
          }

}
extern INT ReadBinRxnReacProdSet(RxnReacProdSet *eleptr,DbaseLinkedList *file)
     {
INT *ptrMolecules;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMolecules),file);

          eleptr->Molecules = AllocArrayINT(eleptr->NumberOfMolecules);
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               ReadBinINT(ptrMolecules++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_RxnReacProdSet(XDR *stream, char **eleptrp)
{
     RxnReacProdSet *eleptr;
     eleptr = (RxnReacProdSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMolecules));

     xdr_array(stream,(char **) &(eleptr->Molecules),
             (uint *) &(eleptr->NumberOfMolecules),eleptr->NumberOfMolecules,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocRxnReacProdSet()
{
     return((void *) AllocateRxnReacProdSet);
}

extern CHAR *GetNameMechanismReaction(MechanismReaction *str)
{
     return(str->Name);
}

extern INT GetIDMechanismReaction(MechanismReaction *str)
{
     return(str->ID);
}

extern MechanismReaction *CreateMechanismReaction(MechanismReaction *newstruct,
                                           INT id,
                                           CHAR *name,
                                           RxnReacProdSet *Reactants,
                                           RxnReacProdSet *Products,
                                           ArrheniusFormValue *Forward,
                                           STRING *ForwardReference,
                                           ArrheniusFormValue *Reverse,
                                           STRING *ReverseReference,
                                           SetOfPropertyValues *Values)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Reactants != 0)
          {
          newstruct->Reactants = AllocateRxnReacProdSet;
          CopyFullRxnReacProdSet(newstruct->Reactants, Reactants);
          }
     else
          newstruct->Reactants = 0;
     if(Products != 0)
          {
          newstruct->Products = AllocateRxnReacProdSet;
          CopyFullRxnReacProdSet(newstruct->Products, Products);
          }
     else
          newstruct->Products = 0;
     if(Forward != 0)
          {
          newstruct->Forward = AllocateArrheniusFormValue;
          CopyFullArrheniusFormValue(newstruct->Forward, Forward);
          }
     else
          newstruct->Forward = 0;
     if(ForwardReference != 0)
          {
          newstruct->ForwardReference = AllocateSTRING;
          CopyFullSTRING(newstruct->ForwardReference, ForwardReference);
          }
     else
          newstruct->ForwardReference = 0;
     if(Reverse != 0)
          {
          newstruct->Reverse = AllocateArrheniusFormValue;
          CopyFullArrheniusFormValue(newstruct->Reverse, Reverse);
          }
     else
          newstruct->Reverse = 0;
     if(ReverseReference != 0)
          {
          newstruct->ReverseReference = AllocateSTRING;
          CopyFullSTRING(newstruct->ReverseReference, ReverseReference);
          }
     else
          newstruct->ReverseReference = 0;
     if(Values != 0)
          {
          newstruct->Values = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Values, Values);
          }
     else
          newstruct->Values = 0;



     return(newstruct);
}


extern void CopyFullMechanismReaction(MechanismReaction *newstruct, MechanismReaction *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Reactants != 0)
          {
          newstruct->Reactants = AllocateRxnReacProdSet;
          CopyFullRxnReacProdSet(newstruct->Reactants, oldstruct->Reactants);
          }
     else
          newstruct->Reactants = 0;
     if(oldstruct->Products != 0)
          {
          newstruct->Products = AllocateRxnReacProdSet;
          CopyFullRxnReacProdSet(newstruct->Products, oldstruct->Products);
          }
     else
          newstruct->Products = 0;
     if(oldstruct->Forward != 0)
          {
          newstruct->Forward = AllocateArrheniusFormValue;
          CopyFullArrheniusFormValue(newstruct->Forward, oldstruct->Forward);
          }
     else
          newstruct->Forward = 0;
     if(oldstruct->ForwardReference != 0)
          {
          newstruct->ForwardReference = AllocateSTRING;
          CopyFullSTRING(newstruct->ForwardReference, oldstruct->ForwardReference);
          }
     else
          newstruct->ForwardReference = 0;
     if(oldstruct->Reverse != 0)
          {
          newstruct->Reverse = AllocateArrheniusFormValue;
          CopyFullArrheniusFormValue(newstruct->Reverse, oldstruct->Reverse);
          }
     else
          newstruct->Reverse = 0;
     if(oldstruct->ReverseReference != 0)
          {
          newstruct->ReverseReference = AllocateSTRING;
          CopyFullSTRING(newstruct->ReverseReference, oldstruct->ReverseReference);
          }
     else
          newstruct->ReverseReference = 0;
     if(oldstruct->Values != 0)
          {
          newstruct->Values = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Values, oldstruct->Values);
          }
     else
          newstruct->Values = 0;


}
extern void PrintMechanismReaction(MechanismReaction *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The set of Reactant Molecules:\n");
     PrintRxnReacProdSet(eleptr->Reactants);

     printf("The set of Product Molecules:\n");
     PrintRxnReacProdSet(eleptr->Products);

     printf("The Forward Rate Constant:\n");
     PrintArrheniusFormValue(eleptr->Forward);

     printf("Forward Rate Reference:\n");
     PrintSTRING(eleptr->ForwardReference);

     printf("The Reverse Rate Constant:\n");
     PrintArrheniusFormValue(eleptr->Reverse);

     printf("Reverse Rate Reference:\n");
     PrintSTRING(eleptr->ReverseReference);

     printf("Additional Information Needed by a reaction:\n");
     PrintSetOfPropertyValues(eleptr->Values);

}
extern void FreeMechanismReaction(MechanismReaction *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeRxnReacProdSet(eleptr->Reactants);
     Free(eleptr->Reactants);

     FreeRxnReacProdSet(eleptr->Products);
     Free(eleptr->Products);

     FreeArrheniusFormValue(eleptr->Forward);
     Free(eleptr->Forward);

     FreeSTRING(eleptr->ForwardReference);

     FreeArrheniusFormValue(eleptr->Reverse);
     Free(eleptr->Reverse);

     FreeSTRING(eleptr->ReverseReference);

     FreeSetOfPropertyValues(eleptr->Values);
     Free(eleptr->Values);

}
extern void WriteBinMechanismReaction(MechanismReaction *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinRxnReacProdSet(eleptr->Reactants,file);

     WriteBinRxnReacProdSet(eleptr->Products,file);

     WriteBinArrheniusFormValue(eleptr->Forward,file);

     WriteBinSTRING(eleptr->ForwardReference,file);

     WriteBinArrheniusFormValue(eleptr->Reverse,file);

     WriteBinSTRING(eleptr->ReverseReference,file);

     WriteBinSetOfPropertyValues(eleptr->Values,file);

}
extern INT ReadBinMechanismReaction(MechanismReaction *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Reactants = AllocateRxnReacProdSet;
     if(ReadBinRxnReacProdSet(eleptr->Reactants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactants);
           eleptr->Reactants = 0;
           }

     eleptr->Products = AllocateRxnReacProdSet;
     if(ReadBinRxnReacProdSet(eleptr->Products,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Products);
           eleptr->Products = 0;
           }

     eleptr->Forward = AllocateArrheniusFormValue;
     if(ReadBinArrheniusFormValue(eleptr->Forward,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Forward);
           eleptr->Forward = 0;
           }

     eleptr->ForwardReference = AllocateSTRING;
     if(ReadBinSTRING(eleptr->ForwardReference,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ForwardReference);
           eleptr->ForwardReference = 0;
           }

     eleptr->Reverse = AllocateArrheniusFormValue;
     if(ReadBinArrheniusFormValue(eleptr->Reverse,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reverse);
           eleptr->Reverse = 0;
           }

     eleptr->ReverseReference = AllocateSTRING;
     if(ReadBinSTRING(eleptr->ReverseReference,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ReverseReference);
           eleptr->ReverseReference = 0;
           }

     eleptr->Values = AllocateSetOfPropertyValues;
     if(ReadBinSetOfPropertyValues(eleptr->Values,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Values);
           eleptr->Values = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_MechanismReaction(XDR *stream, char **eleptrp)
{
     MechanismReaction *eleptr;
     eleptr = (MechanismReaction *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Reactants),
          RxnReacProdSetSize,
                 (xdrproc_t) xdr_RxnReacProdSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Products),
          RxnReacProdSetSize,
                 (xdrproc_t) xdr_RxnReacProdSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Forward),
          ArrheniusFormValueSize,
                 (xdrproc_t) xdr_ArrheniusFormValue);
     xdr_pointer(stream,
          (char **) &(eleptr->ForwardReference),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Reverse),
          ArrheniusFormValueSize,
                 (xdrproc_t) xdr_ArrheniusFormValue);
     xdr_pointer(stream,
          (char **) &(eleptr->ReverseReference),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Values),
          SetOfPropertyValuesSize,
                 (xdrproc_t) xdr_SetOfPropertyValues);
}

extern void *AllocMechanismReaction()
{
     return((void *) AllocateMechanismReaction);
}

extern CHAR *GetNameMechanismMolecule(MechanismMolecule *str)
{
     return(str->Name);
}

extern INT GetIDMechanismMolecule(MechanismMolecule *str)
{
     return(str->ID);
}

extern MechanismMolecule *CreateMechanismMolecule(MechanismMolecule *newstruct,
                                           INT id,
                                           CHAR *name,
                                           STRING *AbbreviatedName,
                                           ChemkinThermoRead *ThermoConstants,
                                           STRING *ThermoReference,
                                           ArrheniusFormValue *Equilibrium,
                                           MoleculeAtomCounts *AtomCounts,
                                           SetOfPropertyValues *Values)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(AbbreviatedName != 0)
          {
          newstruct->AbbreviatedName = AllocateSTRING;
          CopyFullSTRING(newstruct->AbbreviatedName, AbbreviatedName);
          }
     else
          newstruct->AbbreviatedName = 0;
     if(ThermoConstants != 0)
          {
          newstruct->ThermoConstants = AllocateChemkinThermoRead;
          CopyFullChemkinThermoRead(newstruct->ThermoConstants, ThermoConstants);
          }
     else
          newstruct->ThermoConstants = 0;
     if(ThermoReference != 0)
          {
          newstruct->ThermoReference = AllocateSTRING;
          CopyFullSTRING(newstruct->ThermoReference, ThermoReference);
          }
     else
          newstruct->ThermoReference = 0;
     if(Equilibrium != 0)
          {
          newstruct->Equilibrium = AllocateArrheniusFormValue;
          CopyFullArrheniusFormValue(newstruct->Equilibrium, Equilibrium);
          }
     else
          newstruct->Equilibrium = 0;
     if(AtomCounts != 0)
          {
          newstruct->AtomCounts = AllocateMoleculeAtomCounts;
          CopyFullMoleculeAtomCounts(newstruct->AtomCounts, AtomCounts);
          }
     else
          newstruct->AtomCounts = 0;
     if(Values != 0)
          {
          newstruct->Values = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Values, Values);
          }
     else
          newstruct->Values = 0;



     return(newstruct);
}


extern void CopyFullMechanismMolecule(MechanismMolecule *newstruct, MechanismMolecule *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->AbbreviatedName != 0)
          {
          newstruct->AbbreviatedName = AllocateSTRING;
          CopyFullSTRING(newstruct->AbbreviatedName, oldstruct->AbbreviatedName);
          }
     else
          newstruct->AbbreviatedName = 0;
     if(oldstruct->ThermoConstants != 0)
          {
          newstruct->ThermoConstants = AllocateChemkinThermoRead;
          CopyFullChemkinThermoRead(newstruct->ThermoConstants, oldstruct->ThermoConstants);
          }
     else
          newstruct->ThermoConstants = 0;
     if(oldstruct->ThermoReference != 0)
          {
          newstruct->ThermoReference = AllocateSTRING;
          CopyFullSTRING(newstruct->ThermoReference, oldstruct->ThermoReference);
          }
     else
          newstruct->ThermoReference = 0;
     if(oldstruct->Equilibrium != 0)
          {
          newstruct->Equilibrium = AllocateArrheniusFormValue;
          CopyFullArrheniusFormValue(newstruct->Equilibrium, oldstruct->Equilibrium);
          }
     else
          newstruct->Equilibrium = 0;
     if(oldstruct->AtomCounts != 0)
          {
          newstruct->AtomCounts = AllocateMoleculeAtomCounts;
          CopyFullMoleculeAtomCounts(newstruct->AtomCounts, oldstruct->AtomCounts);
          }
     else
          newstruct->AtomCounts = 0;
     if(oldstruct->Values != 0)
          {
          newstruct->Values = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Values, oldstruct->Values);
          }
     else
          newstruct->Values = 0;


}
extern void PrintMechanismMolecule(MechanismMolecule *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Smaller (though unique) name - to fit more on a line:\n");
     PrintSTRING(eleptr->AbbreviatedName);

     printf("The Thermodynamic Constants (In Chemkin JANAF form):\n");
     PrintChemkinThermoRead(eleptr->ThermoConstants);

     printf("The Reference for the Constants:\n");
     PrintSTRING(eleptr->ThermoReference);

     printf("The Equilibrium Constant (If used to compute reverse reaction):\n");
     PrintArrheniusFormValue(eleptr->Equilibrium);

     printf("The summary of Atom Counts:\n");
     PrintMoleculeAtomCounts(eleptr->AtomCounts);

     printf("Additional Information Needed by a molecule:\n");
     PrintSetOfPropertyValues(eleptr->Values);

}
extern void FreeMechanismMolecule(MechanismMolecule *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSTRING(eleptr->AbbreviatedName);

     FreeChemkinThermoRead(eleptr->ThermoConstants);
     Free(eleptr->ThermoConstants);

     FreeSTRING(eleptr->ThermoReference);

     FreeArrheniusFormValue(eleptr->Equilibrium);
     Free(eleptr->Equilibrium);

     FreeMoleculeAtomCounts(eleptr->AtomCounts);
     Free(eleptr->AtomCounts);

     FreeSetOfPropertyValues(eleptr->Values);
     Free(eleptr->Values);

}
extern void WriteBinMechanismMolecule(MechanismMolecule *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSTRING(eleptr->AbbreviatedName,file);

     WriteBinChemkinThermoRead(eleptr->ThermoConstants,file);

     WriteBinSTRING(eleptr->ThermoReference,file);

     WriteBinArrheniusFormValue(eleptr->Equilibrium,file);

     WriteBinMoleculeAtomCounts(eleptr->AtomCounts,file);

     WriteBinSetOfPropertyValues(eleptr->Values,file);

}
extern INT ReadBinMechanismMolecule(MechanismMolecule *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->AbbreviatedName = AllocateSTRING;
     if(ReadBinSTRING(eleptr->AbbreviatedName,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->AbbreviatedName);
           eleptr->AbbreviatedName = 0;
           }

     eleptr->ThermoConstants = AllocateChemkinThermoRead;
     if(ReadBinChemkinThermoRead(eleptr->ThermoConstants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ThermoConstants);
           eleptr->ThermoConstants = 0;
           }

     eleptr->ThermoReference = AllocateSTRING;
     if(ReadBinSTRING(eleptr->ThermoReference,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ThermoReference);
           eleptr->ThermoReference = 0;
           }

     eleptr->Equilibrium = AllocateArrheniusFormValue;
     if(ReadBinArrheniusFormValue(eleptr->Equilibrium,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Equilibrium);
           eleptr->Equilibrium = 0;
           }

     eleptr->AtomCounts = AllocateMoleculeAtomCounts;
     if(ReadBinMoleculeAtomCounts(eleptr->AtomCounts,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->AtomCounts);
           eleptr->AtomCounts = 0;
           }

     eleptr->Values = AllocateSetOfPropertyValues;
     if(ReadBinSetOfPropertyValues(eleptr->Values,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Values);
           eleptr->Values = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_MechanismMolecule(XDR *stream, char **eleptrp)
{
     MechanismMolecule *eleptr;
     eleptr = (MechanismMolecule *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->AbbreviatedName),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->ThermoConstants),
          ChemkinThermoReadSize,
                 (xdrproc_t) xdr_ChemkinThermoRead);
     xdr_pointer(stream,
          (char **) &(eleptr->ThermoReference),
          STRINGSize,
                 (xdrproc_t) xdr_STRING);
     xdr_pointer(stream,
          (char **) &(eleptr->Equilibrium),
          ArrheniusFormValueSize,
                 (xdrproc_t) xdr_ArrheniusFormValue);
     xdr_pointer(stream,
          (char **) &(eleptr->AtomCounts),
          MoleculeAtomCountsSize,
                 (xdrproc_t) xdr_MoleculeAtomCounts);
     xdr_pointer(stream,
          (char **) &(eleptr->Values),
          SetOfPropertyValuesSize,
                 (xdrproc_t) xdr_SetOfPropertyValues);
}

extern void *AllocMechanismMolecule()
{
     return((void *) AllocateMechanismMolecule);
}

extern CHAR *GetNameMechanismMoleculeSet(MechanismMoleculeSet *str)
{
     return(str->Name);
}

extern INT GetIDMechanismMoleculeSet(MechanismMoleculeSet *str)
{
     return(str->ID);
}

extern MechanismMoleculeSet *CreateMechanismMoleculeSet(MechanismMoleculeSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfMolecules,
                                                 MechanismMolecule *Molecules,
                                                 SetOfPropertyTypes *PropTypes)
{
MechanismMolecule *oldMolecules,*newMolecules;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMolecules = NumberOfMolecules;
     if(PropTypes != 0)
          {
          newstruct->PropTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropTypes, PropTypes);
          }
     else
          newstruct->PropTypes = 0;

     newstruct->Molecules = AllocArrayMechanismMolecule(newstruct->NumberOfMolecules);
     if(Molecules != 0)
          {
          oldMolecules = Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullMechanismMolecule(newMolecules++, oldMolecules++);
          }



     return(newstruct);
}


extern void CopyFullMechanismMoleculeSet(MechanismMoleculeSet *newstruct, MechanismMoleculeSet *oldstruct)
{
MechanismMolecule *oldMolecules,*newMolecules;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMolecules = oldstruct->NumberOfMolecules;

     if(oldstruct->PropTypes != 0)
          {
          newstruct->PropTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropTypes, oldstruct->PropTypes);
          }
     else
          newstruct->PropTypes = 0;

     newstruct->Molecules = AllocArrayMechanismMolecule(newstruct->NumberOfMolecules);
     if(oldstruct->Molecules != 0)
          {
          oldMolecules = oldstruct->Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullMechanismMolecule(newMolecules++, oldMolecules++);
          }


}
extern void PrintMechanismMoleculeSet(MechanismMoleculeSet *eleptr)
{
MechanismMolecule *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of molecules:");
     printf("%d\n",eleptr->NumberOfMolecules);

     printf("The property types of the molecules:\n");
     PrintSetOfPropertyTypes(eleptr->PropTypes);

     printf("The set of Molecules:\n");
     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               PrintMechanismMolecule(ptrMolecules++);
          }


}
extern void FreeMechanismMoleculeSet(MechanismMoleculeSet *eleptr)
{
MechanismMolecule *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrMolecules = eleptr->Molecules;
     LOOPi(eleptr->NumberOfMolecules)
          FreeMechanismMolecule(ptrMolecules++);
     Free(eleptr->Molecules);

     FreeSetOfPropertyTypes(eleptr->PropTypes);
     Free(eleptr->PropTypes);

}
extern void WriteBinMechanismMoleculeSet(MechanismMoleculeSet *eleptr, DbaseLinkedList *file)
{
MechanismMolecule *ptrMolecules;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMolecules),file);

     WriteBinSetOfPropertyTypes(eleptr->PropTypes,file);

     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               WriteBinMechanismMolecule(ptrMolecules++,file);
          }

}
extern INT ReadBinMechanismMoleculeSet(MechanismMoleculeSet *eleptr,DbaseLinkedList *file)
     {
MechanismMolecule *ptrMolecules;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMolecules),file);

     eleptr->PropTypes = AllocateSetOfPropertyTypes;
     if(ReadBinSetOfPropertyTypes(eleptr->PropTypes,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PropTypes);
           eleptr->PropTypes = 0;
           }

          eleptr->Molecules = AllocArrayMechanismMolecule(eleptr->NumberOfMolecules);
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               ReadBinMechanismMolecule(ptrMolecules++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MechanismMoleculeSet(XDR *stream, char **eleptrp)
{
     MechanismMoleculeSet *eleptr;
     eleptr = (MechanismMoleculeSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMolecules));

     xdr_pointer(stream,
          (char **) &(eleptr->PropTypes),
          SetOfPropertyTypesSize,
                 (xdrproc_t) xdr_SetOfPropertyTypes);
     xdr_array(stream,(char **) &(eleptr->Molecules),
             (uint *) &(eleptr->NumberOfMolecules),eleptr->NumberOfMolecules,
               MechanismMoleculeSize,(xdrproc_t) xdr_MechanismMolecule);
}

extern void *AllocMechanismMoleculeSet()
{
     return((void *) AllocateMechanismMoleculeSet);
}

extern CHAR *GetNameMechanismReactionSet(MechanismReactionSet *str)
{
     return(str->Name);
}

extern INT GetIDMechanismReactionSet(MechanismReactionSet *str)
{
     return(str->ID);
}

extern MechanismReactionSet *CreateMechanismReactionSet(MechanismReactionSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfReactions,
                                                 MechanismReaction *Reactions,
                                                 SetOfPropertyTypes *PropTypes)
{
MechanismReaction *oldReactions,*newReactions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactions = NumberOfReactions;
     if(PropTypes != 0)
          {
          newstruct->PropTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropTypes, PropTypes);
          }
     else
          newstruct->PropTypes = 0;

     newstruct->Reactions = AllocArrayMechanismReaction(newstruct->NumberOfReactions);
     if(Reactions != 0)
          {
          oldReactions = Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullMechanismReaction(newReactions++, oldReactions++);
          }



     return(newstruct);
}


extern void CopyFullMechanismReactionSet(MechanismReactionSet *newstruct, MechanismReactionSet *oldstruct)
{
MechanismReaction *oldReactions,*newReactions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactions = oldstruct->NumberOfReactions;

     if(oldstruct->PropTypes != 0)
          {
          newstruct->PropTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropTypes, oldstruct->PropTypes);
          }
     else
          newstruct->PropTypes = 0;

     newstruct->Reactions = AllocArrayMechanismReaction(newstruct->NumberOfReactions);
     if(oldstruct->Reactions != 0)
          {
          oldReactions = oldstruct->Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullMechanismReaction(newReactions++, oldReactions++);
          }


}
extern void PrintMechanismReactionSet(MechanismReactionSet *eleptr)
{
MechanismReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of reactions:");
     printf("%d\n",eleptr->NumberOfReactions);

     printf("The property types of the reactions:\n");
     PrintSetOfPropertyTypes(eleptr->PropTypes);

     printf("The set of Reactions:\n");
     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               PrintMechanismReaction(ptrReactions++);
          }


}
extern void FreeMechanismReactionSet(MechanismReactionSet *eleptr)
{
MechanismReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactions = eleptr->Reactions;
     LOOPi(eleptr->NumberOfReactions)
          FreeMechanismReaction(ptrReactions++);
     Free(eleptr->Reactions);

     FreeSetOfPropertyTypes(eleptr->PropTypes);
     Free(eleptr->PropTypes);

}
extern void WriteBinMechanismReactionSet(MechanismReactionSet *eleptr, DbaseLinkedList *file)
{
MechanismReaction *ptrReactions;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfReactions),file);

     WriteBinSetOfPropertyTypes(eleptr->PropTypes,file);

     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               WriteBinMechanismReaction(ptrReactions++,file);
          }

}
extern INT ReadBinMechanismReactionSet(MechanismReactionSet *eleptr,DbaseLinkedList *file)
     {
MechanismReaction *ptrReactions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactions),file);

     eleptr->PropTypes = AllocateSetOfPropertyTypes;
     if(ReadBinSetOfPropertyTypes(eleptr->PropTypes,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PropTypes);
           eleptr->PropTypes = 0;
           }

          eleptr->Reactions = AllocArrayMechanismReaction(eleptr->NumberOfReactions);
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               ReadBinMechanismReaction(ptrReactions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MechanismReactionSet(XDR *stream, char **eleptrp)
{
     MechanismReactionSet *eleptr;
     eleptr = (MechanismReactionSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfReactions));

     xdr_pointer(stream,
          (char **) &(eleptr->PropTypes),
          SetOfPropertyTypesSize,
                 (xdrproc_t) xdr_SetOfPropertyTypes);
     xdr_array(stream,(char **) &(eleptr->Reactions),
             (uint *) &(eleptr->NumberOfReactions),eleptr->NumberOfReactions,
               MechanismReactionSize,(xdrproc_t) xdr_MechanismReaction);
}

extern void *AllocMechanismReactionSet()
{
     return((void *) AllocateMechanismReactionSet);
}

extern CHAR *GetNameDetailedMechanism(DetailedMechanism *str)
{
     return(str->Name);
}

extern INT GetIDDetailedMechanism(DetailedMechanism *str)
{
     return(str->ID);
}

extern DetailedMechanism *CreateDetailedMechanism(DetailedMechanism *newstruct,
                                           INT id,
                                           CHAR *name,
                                           MechanismReactionSet *RxnSet,
                                           MechanismMoleculeSet *MolSet,
                                           MoleculeSet *Molecules,
                                           ReactionSet *Reactions,
                                           SetOfPropertyValues *Values)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(RxnSet != 0)
          {
          newstruct->RxnSet = AllocateMechanismReactionSet;
          CopyFullMechanismReactionSet(newstruct->RxnSet, RxnSet);
          }
     else
          newstruct->RxnSet = 0;
     if(MolSet != 0)
          {
          newstruct->MolSet = AllocateMechanismMoleculeSet;
          CopyFullMechanismMoleculeSet(newstruct->MolSet, MolSet);
          }
     else
          newstruct->MolSet = 0;
     if(Molecules != 0)
          {
          newstruct->Molecules = AllocateMoleculeSet;
          CopyFullMoleculeSet(newstruct->Molecules, Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(Reactions != 0)
          {
          newstruct->Reactions = AllocateReactionSet;
          CopyFullReactionSet(newstruct->Reactions, Reactions);
          }
     else
          newstruct->Reactions = 0;
     if(Values != 0)
          {
          newstruct->Values = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Values, Values);
          }
     else
          newstruct->Values = 0;



     return(newstruct);
}


extern void CopyFullDetailedMechanism(DetailedMechanism *newstruct, DetailedMechanism *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->RxnSet != 0)
          {
          newstruct->RxnSet = AllocateMechanismReactionSet;
          CopyFullMechanismReactionSet(newstruct->RxnSet, oldstruct->RxnSet);
          }
     else
          newstruct->RxnSet = 0;
     if(oldstruct->MolSet != 0)
          {
          newstruct->MolSet = AllocateMechanismMoleculeSet;
          CopyFullMechanismMoleculeSet(newstruct->MolSet, oldstruct->MolSet);
          }
     else
          newstruct->MolSet = 0;
     if(oldstruct->Molecules != 0)
          {
          newstruct->Molecules = AllocateMoleculeSet;
          CopyFullMoleculeSet(newstruct->Molecules, oldstruct->Molecules);
          }
     else
          newstruct->Molecules = 0;
     if(oldstruct->Reactions != 0)
          {
          newstruct->Reactions = AllocateReactionSet;
          CopyFullReactionSet(newstruct->Reactions, oldstruct->Reactions);
          }
     else
          newstruct->Reactions = 0;
     if(oldstruct->Values != 0)
          {
          newstruct->Values = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Values, oldstruct->Values);
          }
     else
          newstruct->Values = 0;


}
extern void PrintDetailedMechanism(DetailedMechanism *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The set of reactions:\n");
     PrintMechanismReactionSet(eleptr->RxnSet);

     printf("The set of molecules:\n");
     PrintMechanismMoleculeSet(eleptr->MolSet);

     printf("Additional Molecules (not in database):\n");
     PrintMoleculeSet(eleptr->Molecules);

     printf("Additional Reactions (not in database):\n");
     PrintReactionSet(eleptr->Reactions);

     printf("Additional Information Needed by a mechanism:\n");
     PrintSetOfPropertyValues(eleptr->Values);

}
extern void FreeDetailedMechanism(DetailedMechanism *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeMechanismReactionSet(eleptr->RxnSet);
     Free(eleptr->RxnSet);

     FreeMechanismMoleculeSet(eleptr->MolSet);
     Free(eleptr->MolSet);

     FreeMoleculeSet(eleptr->Molecules);
     Free(eleptr->Molecules);

     FreeReactionSet(eleptr->Reactions);
     Free(eleptr->Reactions);

     FreeSetOfPropertyValues(eleptr->Values);
     Free(eleptr->Values);

}
extern void WriteBinDetailedMechanism(DetailedMechanism *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinMechanismReactionSet(eleptr->RxnSet,file);

     WriteBinMechanismMoleculeSet(eleptr->MolSet,file);

     WriteBinMoleculeSet(eleptr->Molecules,file);

     WriteBinReactionSet(eleptr->Reactions,file);

     WriteBinSetOfPropertyValues(eleptr->Values,file);

}
extern INT ReadBinDetailedMechanism(DetailedMechanism *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->RxnSet = AllocateMechanismReactionSet;
     if(ReadBinMechanismReactionSet(eleptr->RxnSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->RxnSet);
           eleptr->RxnSet = 0;
           }

     eleptr->MolSet = AllocateMechanismMoleculeSet;
     if(ReadBinMechanismMoleculeSet(eleptr->MolSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->MolSet);
           eleptr->MolSet = 0;
           }

     eleptr->Molecules = AllocateMoleculeSet;
     if(ReadBinMoleculeSet(eleptr->Molecules,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecules);
           eleptr->Molecules = 0;
           }

     eleptr->Reactions = AllocateReactionSet;
     if(ReadBinReactionSet(eleptr->Reactions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactions);
           eleptr->Reactions = 0;
           }

     eleptr->Values = AllocateSetOfPropertyValues;
     if(ReadBinSetOfPropertyValues(eleptr->Values,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Values);
           eleptr->Values = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_DetailedMechanism(XDR *stream, char **eleptrp)
{
     DetailedMechanism *eleptr;
     eleptr = (DetailedMechanism *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->RxnSet),
          MechanismReactionSetSize,
                 (xdrproc_t) xdr_MechanismReactionSet);
     xdr_pointer(stream,
          (char **) &(eleptr->MolSet),
          MechanismMoleculeSetSize,
                 (xdrproc_t) xdr_MechanismMoleculeSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Molecules),
          MoleculeSetSize,
                 (xdrproc_t) xdr_MoleculeSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Reactions),
          ReactionSetSize,
                 (xdrproc_t) xdr_ReactionSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Values),
          SetOfPropertyValuesSize,
                 (xdrproc_t) xdr_SetOfPropertyValues);
}

extern void *AllocDetailedMechanism()
{
     return((void *) AllocateDetailedMechanism);
}

extern CHAR *GetNameSetOfDetailedMechanisms(SetOfDetailedMechanisms *str)
{
     return(str->Name);
}

extern INT GetIDSetOfDetailedMechanisms(SetOfDetailedMechanisms *str)
{
     return(str->ID);
}

extern SetOfDetailedMechanisms *CreateSetOfDetailedMechanisms(SetOfDetailedMechanisms *newstruct,
INT id,
CHAR *name,
INT  NumberOfMechanisms,
DetailedMechanism *Mechanisms,
SetOfPropertyTypes *PropTypes)
{
DetailedMechanism *oldMechanisms,*newMechanisms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMechanisms = NumberOfMechanisms;
     if(PropTypes != 0)
          {
          newstruct->PropTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropTypes, PropTypes);
          }
     else
          newstruct->PropTypes = 0;

     newstruct->Mechanisms = AllocArrayDetailedMechanism(newstruct->NumberOfMechanisms);
     if(Mechanisms != 0)
          {
          oldMechanisms = Mechanisms;
          newMechanisms = newstruct->Mechanisms;
          LOOPi(newstruct->NumberOfMechanisms)
               CopyFullDetailedMechanism(newMechanisms++, oldMechanisms++);
          }



     return(newstruct);
}


extern void CopyFullSetOfDetailedMechanisms(SetOfDetailedMechanisms *newstruct, SetOfDetailedMechanisms *oldstruct)
{
DetailedMechanism *oldMechanisms,*newMechanisms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMechanisms = oldstruct->NumberOfMechanisms;

     if(oldstruct->PropTypes != 0)
          {
          newstruct->PropTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropTypes, oldstruct->PropTypes);
          }
     else
          newstruct->PropTypes = 0;

     newstruct->Mechanisms = AllocArrayDetailedMechanism(newstruct->NumberOfMechanisms);
     if(oldstruct->Mechanisms != 0)
          {
          oldMechanisms = oldstruct->Mechanisms;
          newMechanisms = newstruct->Mechanisms;
          LOOPi(newstruct->NumberOfMechanisms)
               CopyFullDetailedMechanism(newMechanisms++, oldMechanisms++);
          }


}
extern void PrintSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr)
{
DetailedMechanism *ptrMechanisms;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of current mechanisms:");
     printf("%d\n",eleptr->NumberOfMechanisms);

     printf("The property types of the mechansim:\n");
     PrintSetOfPropertyTypes(eleptr->PropTypes);

     printf("The set of Mechanisms:\n");
     if(eleptr->Mechanisms != 0)
          {
          ptrMechanisms = eleptr->Mechanisms;
          LOOPi(eleptr->NumberOfMechanisms)
               PrintDetailedMechanism(ptrMechanisms++);
          }


}
extern void FreeSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr)
{
DetailedMechanism *ptrMechanisms;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrMechanisms = eleptr->Mechanisms;
     LOOPi(eleptr->NumberOfMechanisms)
          FreeDetailedMechanism(ptrMechanisms++);
     Free(eleptr->Mechanisms);

     FreeSetOfPropertyTypes(eleptr->PropTypes);
     Free(eleptr->PropTypes);

}
extern void WriteBinSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr, DbaseLinkedList *file)
{
DetailedMechanism *ptrMechanisms;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMechanisms),file);

     WriteBinSetOfPropertyTypes(eleptr->PropTypes,file);

     if(eleptr->Mechanisms != 0)
          {
          ptrMechanisms = eleptr->Mechanisms;
          LOOPi(eleptr->NumberOfMechanisms)
               WriteBinDetailedMechanism(ptrMechanisms++,file);
          }

}
extern INT ReadBinSetOfDetailedMechanisms(SetOfDetailedMechanisms *eleptr,DbaseLinkedList *file)
     {
DetailedMechanism *ptrMechanisms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMechanisms),file);

     eleptr->PropTypes = AllocateSetOfPropertyTypes;
     if(ReadBinSetOfPropertyTypes(eleptr->PropTypes,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PropTypes);
           eleptr->PropTypes = 0;
           }

          eleptr->Mechanisms = AllocArrayDetailedMechanism(eleptr->NumberOfMechanisms);
          ptrMechanisms = eleptr->Mechanisms;
          LOOPi(eleptr->NumberOfMechanisms)
               ReadBinDetailedMechanism(ptrMechanisms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfDetailedMechanisms(XDR *stream, char **eleptrp)
{
     SetOfDetailedMechanisms *eleptr;
     eleptr = (SetOfDetailedMechanisms *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMechanisms));

     xdr_pointer(stream,
          (char **) &(eleptr->PropTypes),
          SetOfPropertyTypesSize,
                 (xdrproc_t) xdr_SetOfPropertyTypes);
     xdr_array(stream,(char **) &(eleptr->Mechanisms),
             (uint *) &(eleptr->NumberOfMechanisms),eleptr->NumberOfMechanisms,
               DetailedMechanismSize,(xdrproc_t) xdr_DetailedMechanism);
}

extern void *AllocSetOfDetailedMechanisms()
{
     return((void *) AllocateSetOfDetailedMechanisms);
}
