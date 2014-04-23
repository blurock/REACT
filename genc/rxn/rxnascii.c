
extern CHAR *GetNameMolFileReaction(MolFileReaction *str)
{
     return(str->Name);
}

extern INT GetIDMolFileReaction(MolFileReaction *str)
{
     return(str->ID);
}

extern MolFileReaction *CreateMolFileReaction(MolFileReaction *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfReactants,
                                       INT  NumberOfProducts,
                                       MolFileMolecule *Reactants,
                                       MolFileMolecule *Products,
                                       ASCIIProperties *Properties)
{
MolFileMolecule *oldReactants,*newReactants;
MolFileMolecule *oldProducts,*newProducts;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactants = NumberOfReactants;
     newstruct->NumberOfProducts = NumberOfProducts;
     if(Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, Properties);
          }
     else
          newstruct->Properties = 0;

     newstruct->Reactants = AllocArrayMolFileMolecule(newstruct->NumberOfReactants);
     if(Reactants != 0)
          {
          oldReactants = Reactants;
          newReactants = newstruct->Reactants;
          LOOPi(newstruct->NumberOfReactants)
               CopyFullMolFileMolecule(newReactants++, oldReactants++);
          }

     newstruct->Products = AllocArrayMolFileMolecule(newstruct->NumberOfProducts);
     if(Products != 0)
          {
          oldProducts = Products;
          newProducts = newstruct->Products;
          LOOPi(newstruct->NumberOfProducts)
               CopyFullMolFileMolecule(newProducts++, oldProducts++);
          }



     return(newstruct);
}


extern void CopyFullMolFileReaction(MolFileReaction *newstruct, MolFileReaction *oldstruct)
{
MolFileMolecule *oldReactants,*newReactants;
MolFileMolecule *oldProducts,*newProducts;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactants = oldstruct->NumberOfReactants;
     newstruct->NumberOfProducts = oldstruct->NumberOfProducts;

     if(oldstruct->Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, oldstruct->Properties);
          }
     else
          newstruct->Properties = 0;

     newstruct->Reactants = AllocArrayMolFileMolecule(newstruct->NumberOfReactants);
     if(oldstruct->Reactants != 0)
          {
          oldReactants = oldstruct->Reactants;
          newReactants = newstruct->Reactants;
          LOOPi(newstruct->NumberOfReactants)
               CopyFullMolFileMolecule(newReactants++, oldReactants++);
          }

     newstruct->Products = AllocArrayMolFileMolecule(newstruct->NumberOfProducts);
     if(oldstruct->Products != 0)
          {
          oldProducts = oldstruct->Products;
          newProducts = newstruct->Products;
          LOOPi(newstruct->NumberOfProducts)
               CopyFullMolFileMolecule(newProducts++, oldProducts++);
          }


}
extern void PrintMolFileReaction(MolFileReaction *eleptr)
{
MolFileMolecule *ptrReactants;
MolFileMolecule *ptrProducts;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of reactants:");
     printf("%d\n",eleptr->NumberOfReactants);
     printf("The Number of Products:");
     printf("%d\n",eleptr->NumberOfProducts);

     printf("The Primitive Reaction Properties:\n");
     PrintASCIIProperties(eleptr->Properties);

     printf("The Set of Reactants:\n");
     if(eleptr->Reactants != 0)
          {
          ptrReactants = eleptr->Reactants;
          LOOPi(eleptr->NumberOfReactants)
               PrintMolFileMolecule(ptrReactants++);
          }


     printf(" The Set of Products:\n");
     if(eleptr->Products != 0)
          {
          ptrProducts = eleptr->Products;
          LOOPi(eleptr->NumberOfProducts)
               PrintMolFileMolecule(ptrProducts++);
          }


}
extern void FreeMolFileReaction(MolFileReaction *eleptr)
{
MolFileMolecule *ptrReactants;
MolFileMolecule *ptrProducts;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactants = eleptr->Reactants;
     LOOPi(eleptr->NumberOfReactants)
          FreeMolFileMolecule(ptrReactants++);
     Free(eleptr->Reactants);

     ptrProducts = eleptr->Products;
     LOOPi(eleptr->NumberOfProducts)
          FreeMolFileMolecule(ptrProducts++);
     Free(eleptr->Products);

     FreeASCIIProperties(eleptr->Properties);
     Free(eleptr->Properties);

}
extern void WriteBinMolFileReaction(MolFileReaction *eleptr, DbaseLinkedList *file)
{
MolFileMolecule *ptrReactants;
MolFileMolecule *ptrProducts;
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

     WriteBinASCIIProperties(eleptr->Properties,file);

     if(eleptr->Reactants != 0)
          {
          ptrReactants = eleptr->Reactants;
          LOOPi(eleptr->NumberOfReactants)
               WriteBinMolFileMolecule(ptrReactants++,file);
          }

     if(eleptr->Products != 0)
          {
          ptrProducts = eleptr->Products;
          LOOPi(eleptr->NumberOfProducts)
               WriteBinMolFileMolecule(ptrProducts++,file);
          }

}
extern INT ReadBinMolFileReaction(MolFileReaction *eleptr,DbaseLinkedList *file)
     {
MolFileMolecule *ptrReactants;
MolFileMolecule *ptrProducts;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactants),file);
     ReadBinINT(&(eleptr->NumberOfProducts),file);

     eleptr->Properties = AllocateASCIIProperties;
     if(ReadBinASCIIProperties(eleptr->Properties,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Properties);
           eleptr->Properties = 0;
           }

          eleptr->Reactants = AllocArrayMolFileMolecule(eleptr->NumberOfReactants);
          ptrReactants = eleptr->Reactants;
          LOOPi(eleptr->NumberOfReactants)
               ReadBinMolFileMolecule(ptrReactants++,file);

          eleptr->Products = AllocArrayMolFileMolecule(eleptr->NumberOfProducts);
          ptrProducts = eleptr->Products;
          LOOPi(eleptr->NumberOfProducts)
               ReadBinMolFileMolecule(ptrProducts++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MolFileReaction(XDR *stream, char **eleptrp)
{
     MolFileReaction *eleptr;
     eleptr = (MolFileReaction *) eleptrp;
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
          (char **) &(eleptr->Properties),
          ASCIIPropertiesSize,
                 (xdrproc_t) xdr_ASCIIProperties);
     xdr_array(stream,(char **) &(eleptr->Reactants),
             (uint *) &(eleptr->NumberOfReactants),eleptr->NumberOfReactants,
               MolFileMoleculeSize,(xdrproc_t) xdr_MolFileMolecule);
     xdr_array(stream,(char **) &(eleptr->Products),
             (uint *) &(eleptr->NumberOfProducts),eleptr->NumberOfProducts,
               MolFileMoleculeSize,(xdrproc_t) xdr_MolFileMolecule);
}

extern void *AllocMolFileReaction()
{
     return((void *) AllocateMolFileReaction);
}

extern CHAR *GetNameASCIIReaction(ASCIIReaction *str)
{
     return(str->Name);
}

extern INT GetIDASCIIReaction(ASCIIReaction *str)
{
     return(str->ID);
}

extern ASCIIReaction *CreateASCIIReaction(ASCIIReaction *newstruct,
                                   INT id,
                                   CHAR *name,
                                   ReadInMoleculeSet *Reactants,
                                   INT  ReactionType,
                                   ReadInMoleculeSet *Products,
                                   ASCIIProperties *Properties)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->ReactionType = ReactionType;
     if(Reactants != 0)
          {
          newstruct->Reactants = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Reactants, Reactants);
          }
     else
          newstruct->Reactants = 0;
     if(Products != 0)
          {
          newstruct->Products = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Products, Products);
          }
     else
          newstruct->Products = 0;
     if(Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, Properties);
          }
     else
          newstruct->Properties = 0;



     return(newstruct);
}


extern void CopyFullASCIIReaction(ASCIIReaction *newstruct, ASCIIReaction *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->ReactionType = oldstruct->ReactionType;

     if(oldstruct->Reactants != 0)
          {
          newstruct->Reactants = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Reactants, oldstruct->Reactants);
          }
     else
          newstruct->Reactants = 0;
     if(oldstruct->Products != 0)
          {
          newstruct->Products = AllocateReadInMoleculeSet;
          CopyFullReadInMoleculeSet(newstruct->Products, oldstruct->Products);
          }
     else
          newstruct->Products = 0;
     if(oldstruct->Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, oldstruct->Properties);
          }
     else
          newstruct->Properties = 0;


}
extern void PrintASCIIReaction(ASCIIReaction *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Reaction Types (forward, reverse, equilibrium):");
     printf("%d\n",eleptr->ReactionType);

     printf("The set of Reactant Molecules:\n");
     PrintReadInMoleculeSet(eleptr->Reactants);

     printf("The set of Product Molecules:\n");
     PrintReadInMoleculeSet(eleptr->Products);

     printf("The set of properties:\n");
     PrintASCIIProperties(eleptr->Properties);

}
extern void FreeASCIIReaction(ASCIIReaction *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeReadInMoleculeSet(eleptr->Reactants);
     Free(eleptr->Reactants);

     FreeReadInMoleculeSet(eleptr->Products);
     Free(eleptr->Products);

     FreeASCIIProperties(eleptr->Properties);
     Free(eleptr->Properties);

}
extern void WriteBinASCIIReaction(ASCIIReaction *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->ReactionType),file);

     WriteBinReadInMoleculeSet(eleptr->Reactants,file);

     WriteBinReadInMoleculeSet(eleptr->Products,file);

     WriteBinASCIIProperties(eleptr->Properties,file);

}
extern INT ReadBinASCIIReaction(ASCIIReaction *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->ReactionType),file);

     eleptr->Reactants = AllocateReadInMoleculeSet;
     if(ReadBinReadInMoleculeSet(eleptr->Reactants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactants);
           eleptr->Reactants = 0;
           }

     eleptr->Products = AllocateReadInMoleculeSet;
     if(ReadBinReadInMoleculeSet(eleptr->Products,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Products);
           eleptr->Products = 0;
           }

     eleptr->Properties = AllocateASCIIProperties;
     if(ReadBinASCIIProperties(eleptr->Properties,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Properties);
           eleptr->Properties = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ASCIIReaction(XDR *stream, char **eleptrp)
{
     ASCIIReaction *eleptr;
     eleptr = (ASCIIReaction *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->ReactionType));

     xdr_pointer(stream,
          (char **) &(eleptr->Reactants),
          ReadInMoleculeSetSize,
                 (xdrproc_t) xdr_ReadInMoleculeSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Products),
          ReadInMoleculeSetSize,
                 (xdrproc_t) xdr_ReadInMoleculeSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Properties),
          ASCIIPropertiesSize,
                 (xdrproc_t) xdr_ASCIIProperties);
}

extern void *AllocASCIIReaction()
{
     return((void *) AllocateASCIIReaction);
}

extern CHAR *GetNameASCIIReactionSet(ASCIIReactionSet *str)
{
     return(str->Name);
}

extern INT GetIDASCIIReactionSet(ASCIIReactionSet *str)
{
     return(str->ID);
}

extern ASCIIReactionSet *CreateASCIIReactionSet(ASCIIReactionSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfReactions,
                                         ASCIIReaction *Reactions)
{
ASCIIReaction *oldReactions,*newReactions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactions = NumberOfReactions;

     newstruct->Reactions = AllocArrayASCIIReaction(newstruct->NumberOfReactions);
     if(Reactions != 0)
          {
          oldReactions = Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullASCIIReaction(newReactions++, oldReactions++);
          }



     return(newstruct);
}


extern void CopyFullASCIIReactionSet(ASCIIReactionSet *newstruct, ASCIIReactionSet *oldstruct)
{
ASCIIReaction *oldReactions,*newReactions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactions = oldstruct->NumberOfReactions;


     newstruct->Reactions = AllocArrayASCIIReaction(newstruct->NumberOfReactions);
     if(oldstruct->Reactions != 0)
          {
          oldReactions = oldstruct->Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullASCIIReaction(newReactions++, oldReactions++);
          }


}
extern void PrintASCIIReactionSet(ASCIIReactionSet *eleptr)
{
ASCIIReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of reactions:");
     printf("%d\n",eleptr->NumberOfReactions);

     printf("The set of reactions:\n");
     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               PrintASCIIReaction(ptrReactions++);
          }


}
extern void FreeASCIIReactionSet(ASCIIReactionSet *eleptr)
{
ASCIIReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactions = eleptr->Reactions;
     LOOPi(eleptr->NumberOfReactions)
          FreeASCIIReaction(ptrReactions++);
     Free(eleptr->Reactions);

}
extern void WriteBinASCIIReactionSet(ASCIIReactionSet *eleptr, DbaseLinkedList *file)
{
ASCIIReaction *ptrReactions;
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
               WriteBinASCIIReaction(ptrReactions++,file);
          }

}
extern INT ReadBinASCIIReactionSet(ASCIIReactionSet *eleptr,DbaseLinkedList *file)
     {
ASCIIReaction *ptrReactions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactions),file);

          eleptr->Reactions = AllocArrayASCIIReaction(eleptr->NumberOfReactions);
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               ReadBinASCIIReaction(ptrReactions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ASCIIReactionSet(XDR *stream, char **eleptrp)
{
     ASCIIReactionSet *eleptr;
     eleptr = (ASCIIReactionSet *) eleptrp;
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
               ASCIIReactionSize,(xdrproc_t) xdr_ASCIIReaction);
}

extern void *AllocASCIIReactionSet()
{
     return((void *) AllocateASCIIReactionSet);
}

extern CHAR *GetNameReadInReaction(ReadInReaction *str)
{
     return(str->Name);
}

extern INT GetIDReadInReaction(ReadInReaction *str)
{
     return(str->ID);
}

extern ReadInReaction *CreateReadInReaction(ReadInReaction *newstruct,
                                     INT id,
                                     CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullReadInReaction(ReadInReaction *newstruct, ReadInReaction *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintReadInReaction(ReadInReaction *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeReadInReaction(ReadInReaction *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinReadInReaction(ReadInReaction *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinReadInReaction(ReadInReaction *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReadInReaction(XDR *stream, char **eleptrp)
{
     ReadInReaction *eleptr;
     eleptr = (ReadInReaction *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocReadInReaction()
{
     return((void *) AllocateReadInReaction);
}

extern CHAR *GetNameReadInReactionSet(ReadInReactionSet *str)
{
     return(str->Name);
}

extern INT GetIDReadInReactionSet(ReadInReactionSet *str)
{
     return(str->ID);
}

extern ReadInReactionSet *CreateReadInReactionSet(ReadInReactionSet *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfReactions,
                                           ReadInReaction *Reactions)
{
ReadInReaction *oldReactions,*newReactions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactions = NumberOfReactions;

     newstruct->Reactions = AllocArrayReadInReaction(newstruct->NumberOfReactions);
     if(Reactions != 0)
          {
          oldReactions = Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullReadInReaction(newReactions++, oldReactions++);
          }



     return(newstruct);
}


extern void CopyFullReadInReactionSet(ReadInReactionSet *newstruct, ReadInReactionSet *oldstruct)
{
ReadInReaction *oldReactions,*newReactions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactions = oldstruct->NumberOfReactions;


     newstruct->Reactions = AllocArrayReadInReaction(newstruct->NumberOfReactions);
     if(oldstruct->Reactions != 0)
          {
          oldReactions = oldstruct->Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullReadInReaction(newReactions++, oldReactions++);
          }


}
extern void PrintReadInReactionSet(ReadInReactionSet *eleptr)
{
ReadInReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of reactions:");
     printf("%d\n",eleptr->NumberOfReactions);

     printf("The set of reactions:\n");
     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               PrintReadInReaction(ptrReactions++);
          }


}
extern void FreeReadInReactionSet(ReadInReactionSet *eleptr)
{
ReadInReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactions = eleptr->Reactions;
     LOOPi(eleptr->NumberOfReactions)
          FreeReadInReaction(ptrReactions++);
     Free(eleptr->Reactions);

}
extern void WriteBinReadInReactionSet(ReadInReactionSet *eleptr, DbaseLinkedList *file)
{
ReadInReaction *ptrReactions;
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
               WriteBinReadInReaction(ptrReactions++,file);
          }

}
extern INT ReadBinReadInReactionSet(ReadInReactionSet *eleptr,DbaseLinkedList *file)
     {
ReadInReaction *ptrReactions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactions),file);

          eleptr->Reactions = AllocArrayReadInReaction(eleptr->NumberOfReactions);
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               ReadBinReadInReaction(ptrReactions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReadInReactionSet(XDR *stream, char **eleptrp)
{
     ReadInReactionSet *eleptr;
     eleptr = (ReadInReactionSet *) eleptrp;
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
               ReadInReactionSize,(xdrproc_t) xdr_ReadInReaction);
}

extern void *AllocReadInReactionSet()
{
     return((void *) AllocateReadInReactionSet);
}
