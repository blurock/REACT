
extern CHAR *GetNameRxnAtom(RxnAtom *str)
{
     return(str->Name);
}

extern INT GetIDRxnAtom(RxnAtom *str)
{
     return(str->ID);
}

extern RxnAtom *CreateRxnAtom(RxnAtom *newstruct,
                       INT id,
                       CHAR *name,
                       INT  MoleculeNumber,
                       INT  AtomNumber)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->MoleculeNumber = MoleculeNumber;
     newstruct->AtomNumber = AtomNumber;



     return(newstruct);
}


extern void CopyFullRxnAtom(RxnAtom *newstruct, RxnAtom *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->MoleculeNumber = oldstruct->MoleculeNumber;
     newstruct->AtomNumber = oldstruct->AtomNumber;



}
extern void PrintRxnAtom(RxnAtom *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("        The Molecule:");
     printf("%d\n",eleptr->MoleculeNumber);
     printf("The Atom in Molecule:");
     printf("%d\n",eleptr->AtomNumber);

}
extern void FreeRxnAtom(RxnAtom *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinRxnAtom(RxnAtom *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->MoleculeNumber),file);
     WriteBinINT(&(eleptr->AtomNumber),file);

}
extern INT ReadBinRxnAtom(RxnAtom *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->MoleculeNumber),file);
     ReadBinINT(&(eleptr->AtomNumber),file);

     return(STRUCTURE_READ);
     }
extern void xdr_RxnAtom(XDR *stream, char **eleptrp)
{
     RxnAtom *eleptr;
     eleptr = (RxnAtom *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->MoleculeNumber));
     xdr_INT(stream,(char **) &(eleptr->AtomNumber));

}

extern void *AllocRxnAtom()
{
     return((void *) AllocateRxnAtom);
}

extern CHAR *GetNameRxnAtomCorrespondence(RxnAtomCorrespondence *str)
{
     return(str->Name);
}

extern INT GetIDRxnAtomCorrespondence(RxnAtomCorrespondence *str)
{
     return(str->ID);
}

extern RxnAtomCorrespondence *CreateRxnAtomCorrespondence(RxnAtomCorrespondence *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   RxnAtom *Product,
                                                   RxnAtom *Reactant,
                                                   INT  ReactantPosition,
                                                   INT  ProductPosition)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->ReactantPosition = ReactantPosition;
     newstruct->ProductPosition = ProductPosition;
     if(Product != 0)
          {
          newstruct->Product = AllocateRxnAtom;
          CopyFullRxnAtom(newstruct->Product, Product);
          }
     else
          newstruct->Product = 0;
     if(Reactant != 0)
          {
          newstruct->Reactant = AllocateRxnAtom;
          CopyFullRxnAtom(newstruct->Reactant, Reactant);
          }
     else
          newstruct->Reactant = 0;



     return(newstruct);
}


extern void CopyFullRxnAtomCorrespondence(RxnAtomCorrespondence *newstruct, RxnAtomCorrespondence *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->ReactantPosition = oldstruct->ReactantPosition;
     newstruct->ProductPosition = oldstruct->ProductPosition;

     if(oldstruct->Product != 0)
          {
          newstruct->Product = AllocateRxnAtom;
          CopyFullRxnAtom(newstruct->Product, oldstruct->Product);
          }
     else
          newstruct->Product = 0;
     if(oldstruct->Reactant != 0)
          {
          newstruct->Reactant = AllocateRxnAtom;
          CopyFullRxnAtom(newstruct->Reactant, oldstruct->Reactant);
          }
     else
          newstruct->Reactant = 0;


}
extern void PrintRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Molecule Position in the set of Reactants:");
     printf("%d\n",eleptr->ReactantPosition);
     printf("The Molecule Position in the set of Products:");
     printf("%d\n",eleptr->ProductPosition);

     printf("    The Product Atom:\n");
     PrintRxnAtom(eleptr->Product);

     printf("   The Reactant Atom:\n");
     PrintRxnAtom(eleptr->Reactant);

}
extern void FreeRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeRxnAtom(eleptr->Product);
     Free(eleptr->Product);

     FreeRxnAtom(eleptr->Reactant);
     Free(eleptr->Reactant);

}
extern void WriteBinRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->ReactantPosition),file);
     WriteBinINT(&(eleptr->ProductPosition),file);

     WriteBinRxnAtom(eleptr->Product,file);

     WriteBinRxnAtom(eleptr->Reactant,file);

}
extern INT ReadBinRxnAtomCorrespondence(RxnAtomCorrespondence *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->ReactantPosition),file);
     ReadBinINT(&(eleptr->ProductPosition),file);

     eleptr->Product = AllocateRxnAtom;
     if(ReadBinRxnAtom(eleptr->Product,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Product);
           eleptr->Product = 0;
           }

     eleptr->Reactant = AllocateRxnAtom;
     if(ReadBinRxnAtom(eleptr->Reactant,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reactant);
           eleptr->Reactant = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_RxnAtomCorrespondence(XDR *stream, char **eleptrp)
{
     RxnAtomCorrespondence *eleptr;
     eleptr = (RxnAtomCorrespondence *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->ReactantPosition));
     xdr_INT(stream,(char **) &(eleptr->ProductPosition));

     xdr_pointer(stream,
          (char **) &(eleptr->Product),
          RxnAtomSize,
                 (xdrproc_t) xdr_RxnAtom);
     xdr_pointer(stream,
          (char **) &(eleptr->Reactant),
          RxnAtomSize,
                 (xdrproc_t) xdr_RxnAtom);
}

extern void *AllocRxnAtomCorrespondence()
{
     return((void *) AllocateRxnAtomCorrespondence);
}

extern CHAR *GetNameRxnUnMatchedSet(RxnUnMatchedSet *str)
{
     return(str->Name);
}

extern INT GetIDRxnUnMatchedSet(RxnUnMatchedSet *str)
{
     return(str->ID);
}

extern RxnUnMatchedSet *CreateRxnUnMatchedSet(RxnUnMatchedSet *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberUnMatchedAtoms,
                                       RxnAtom *UnMatchedAtoms)
{
RxnAtom *oldUnMatchedAtoms,*newUnMatchedAtoms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberUnMatchedAtoms = NumberUnMatchedAtoms;

     newstruct->UnMatchedAtoms = AllocArrayRxnAtom(newstruct->NumberUnMatchedAtoms);
     if(UnMatchedAtoms != 0)
          {
          oldUnMatchedAtoms = UnMatchedAtoms;
          newUnMatchedAtoms = newstruct->UnMatchedAtoms;
          LOOPi(newstruct->NumberUnMatchedAtoms)
               CopyFullRxnAtom(newUnMatchedAtoms++, oldUnMatchedAtoms++);
          }



     return(newstruct);
}


extern void CopyFullRxnUnMatchedSet(RxnUnMatchedSet *newstruct, RxnUnMatchedSet *oldstruct)
{
RxnAtom *oldUnMatchedAtoms,*newUnMatchedAtoms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberUnMatchedAtoms = oldstruct->NumberUnMatchedAtoms;


     newstruct->UnMatchedAtoms = AllocArrayRxnAtom(newstruct->NumberUnMatchedAtoms);
     if(oldstruct->UnMatchedAtoms != 0)
          {
          oldUnMatchedAtoms = oldstruct->UnMatchedAtoms;
          newUnMatchedAtoms = newstruct->UnMatchedAtoms;
          LOOPi(newstruct->NumberUnMatchedAtoms)
               CopyFullRxnAtom(newUnMatchedAtoms++, oldUnMatchedAtoms++);
          }


}
extern void PrintRxnUnMatchedSet(RxnUnMatchedSet *eleptr)
{
RxnAtom *ptrUnMatchedAtoms;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Unmatched Reactants:");
     printf("%d\n",eleptr->NumberUnMatchedAtoms);

     printf("The Unmatched Reactant Atoms:\n");
     if(eleptr->UnMatchedAtoms != 0)
          {
          ptrUnMatchedAtoms = eleptr->UnMatchedAtoms;
          LOOPi(eleptr->NumberUnMatchedAtoms)
               PrintRxnAtom(ptrUnMatchedAtoms++);
          }


}
extern void FreeRxnUnMatchedSet(RxnUnMatchedSet *eleptr)
{
RxnAtom *ptrUnMatchedAtoms;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrUnMatchedAtoms = eleptr->UnMatchedAtoms;
     LOOPi(eleptr->NumberUnMatchedAtoms)
          FreeRxnAtom(ptrUnMatchedAtoms++);
     Free(eleptr->UnMatchedAtoms);

}
extern void WriteBinRxnUnMatchedSet(RxnUnMatchedSet *eleptr, DbaseLinkedList *file)
{
RxnAtom *ptrUnMatchedAtoms;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberUnMatchedAtoms),file);

     if(eleptr->UnMatchedAtoms != 0)
          {
          ptrUnMatchedAtoms = eleptr->UnMatchedAtoms;
          LOOPi(eleptr->NumberUnMatchedAtoms)
               WriteBinRxnAtom(ptrUnMatchedAtoms++,file);
          }

}
extern INT ReadBinRxnUnMatchedSet(RxnUnMatchedSet *eleptr,DbaseLinkedList *file)
     {
RxnAtom *ptrUnMatchedAtoms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberUnMatchedAtoms),file);

          eleptr->UnMatchedAtoms = AllocArrayRxnAtom(eleptr->NumberUnMatchedAtoms);
          ptrUnMatchedAtoms = eleptr->UnMatchedAtoms;
          LOOPi(eleptr->NumberUnMatchedAtoms)
               ReadBinRxnAtom(ptrUnMatchedAtoms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_RxnUnMatchedSet(XDR *stream, char **eleptrp)
{
     RxnUnMatchedSet *eleptr;
     eleptr = (RxnUnMatchedSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberUnMatchedAtoms));

     xdr_array(stream,(char **) &(eleptr->UnMatchedAtoms),
             (uint *) &(eleptr->NumberUnMatchedAtoms),eleptr->NumberUnMatchedAtoms,
               RxnAtomSize,(xdrproc_t) xdr_RxnAtom);
}

extern void *AllocRxnUnMatchedSet()
{
     return((void *) AllocateRxnUnMatchedSet);
}

extern CHAR *GetNameRxnBond(RxnBond *str)
{
     return(str->Name);
}

extern INT GetIDRxnBond(RxnBond *str)
{
     return(str->ID);
}

extern RxnBond *CreateRxnBond(RxnBond *newstruct,
                       INT id,
                       CHAR *name,
                       RxnAtomCorrespondence *Atom1,
                       RxnAtomCorrespondence *Atom2,
                       INT  Type)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Type = Type;
     if(Atom1 != 0)
          {
          newstruct->Atom1 = AllocateRxnAtomCorrespondence;
          CopyFullRxnAtomCorrespondence(newstruct->Atom1, Atom1);
          }
     else
          newstruct->Atom1 = 0;
     if(Atom2 != 0)
          {
          newstruct->Atom2 = AllocateRxnAtomCorrespondence;
          CopyFullRxnAtomCorrespondence(newstruct->Atom2, Atom2);
          }
     else
          newstruct->Atom2 = 0;



     return(newstruct);
}


extern void CopyFullRxnBond(RxnBond *newstruct, RxnBond *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Type = oldstruct->Type;

     if(oldstruct->Atom1 != 0)
          {
          newstruct->Atom1 = AllocateRxnAtomCorrespondence;
          CopyFullRxnAtomCorrespondence(newstruct->Atom1, oldstruct->Atom1);
          }
     else
          newstruct->Atom1 = 0;
     if(oldstruct->Atom2 != 0)
          {
          newstruct->Atom2 = AllocateRxnAtomCorrespondence;
          CopyFullRxnAtomCorrespondence(newstruct->Atom2, oldstruct->Atom2);
          }
     else
          newstruct->Atom2 = 0;


}
extern void PrintRxnBond(RxnBond *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The type of bond change:");
     printf("%d\n",eleptr->Type);

     printf("       Atom Number 1:\n");
     PrintRxnAtomCorrespondence(eleptr->Atom1);

     printf("       Atom Number 2:\n");
     PrintRxnAtomCorrespondence(eleptr->Atom2);

}
extern void FreeRxnBond(RxnBond *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeRxnAtomCorrespondence(eleptr->Atom1);
     Free(eleptr->Atom1);

     FreeRxnAtomCorrespondence(eleptr->Atom2);
     Free(eleptr->Atom2);

}
extern void WriteBinRxnBond(RxnBond *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Type),file);

     WriteBinRxnAtomCorrespondence(eleptr->Atom1,file);

     WriteBinRxnAtomCorrespondence(eleptr->Atom2,file);

}
extern INT ReadBinRxnBond(RxnBond *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Type),file);

     eleptr->Atom1 = AllocateRxnAtomCorrespondence;
     if(ReadBinRxnAtomCorrespondence(eleptr->Atom1,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Atom1);
           eleptr->Atom1 = 0;
           }

     eleptr->Atom2 = AllocateRxnAtomCorrespondence;
     if(ReadBinRxnAtomCorrespondence(eleptr->Atom2,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Atom2);
           eleptr->Atom2 = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_RxnBond(XDR *stream, char **eleptrp)
{
     RxnBond *eleptr;
     eleptr = (RxnBond *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Type));

     xdr_pointer(stream,
          (char **) &(eleptr->Atom1),
          RxnAtomCorrespondenceSize,
                 (xdrproc_t) xdr_RxnAtomCorrespondence);
     xdr_pointer(stream,
          (char **) &(eleptr->Atom2),
          RxnAtomCorrespondenceSize,
                 (xdrproc_t) xdr_RxnAtomCorrespondence);
}

extern void *AllocRxnBond()
{
     return((void *) AllocateRxnBond);
}

extern CHAR *GetNameRxnBondChanges(RxnBondChanges *str)
{
     return(str->Name);
}

extern INT GetIDRxnBondChanges(RxnBondChanges *str)
{
     return(str->ID);
}

extern RxnBondChanges *CreateRxnBondChanges(RxnBondChanges *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberBondChanges,
                                     RxnBond *Changes)
{
RxnBond *oldChanges,*newChanges;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberBondChanges = NumberBondChanges;

     newstruct->Changes = AllocArrayRxnBond(newstruct->NumberBondChanges);
     if(Changes != 0)
          {
          oldChanges = Changes;
          newChanges = newstruct->Changes;
          LOOPi(newstruct->NumberBondChanges)
               CopyFullRxnBond(newChanges++, oldChanges++);
          }



     return(newstruct);
}


extern void CopyFullRxnBondChanges(RxnBondChanges *newstruct, RxnBondChanges *oldstruct)
{
RxnBond *oldChanges,*newChanges;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberBondChanges = oldstruct->NumberBondChanges;


     newstruct->Changes = AllocArrayRxnBond(newstruct->NumberBondChanges);
     if(oldstruct->Changes != 0)
          {
          oldChanges = oldstruct->Changes;
          newChanges = newstruct->Changes;
          LOOPi(newstruct->NumberBondChanges)
               CopyFullRxnBond(newChanges++, oldChanges++);
          }


}
extern void PrintRxnBondChanges(RxnBondChanges *eleptr)
{
RxnBond *ptrChanges;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of bond changes:");
     printf("%d\n",eleptr->NumberBondChanges);

     printf("Set of Reaction Bond Changes:\n");
     if(eleptr->Changes != 0)
          {
          ptrChanges = eleptr->Changes;
          LOOPi(eleptr->NumberBondChanges)
               PrintRxnBond(ptrChanges++);
          }


}
extern void FreeRxnBondChanges(RxnBondChanges *eleptr)
{
RxnBond *ptrChanges;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrChanges = eleptr->Changes;
     LOOPi(eleptr->NumberBondChanges)
          FreeRxnBond(ptrChanges++);
     Free(eleptr->Changes);

}
extern void WriteBinRxnBondChanges(RxnBondChanges *eleptr, DbaseLinkedList *file)
{
RxnBond *ptrChanges;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberBondChanges),file);

     if(eleptr->Changes != 0)
          {
          ptrChanges = eleptr->Changes;
          LOOPi(eleptr->NumberBondChanges)
               WriteBinRxnBond(ptrChanges++,file);
          }

}
extern INT ReadBinRxnBondChanges(RxnBondChanges *eleptr,DbaseLinkedList *file)
     {
RxnBond *ptrChanges;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberBondChanges),file);

          eleptr->Changes = AllocArrayRxnBond(eleptr->NumberBondChanges);
          ptrChanges = eleptr->Changes;
          LOOPi(eleptr->NumberBondChanges)
               ReadBinRxnBond(ptrChanges++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_RxnBondChanges(XDR *stream, char **eleptrp)
{
     RxnBondChanges *eleptr;
     eleptr = (RxnBondChanges *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberBondChanges));

     xdr_array(stream,(char **) &(eleptr->Changes),
             (uint *) &(eleptr->NumberBondChanges),eleptr->NumberBondChanges,
               RxnBondSize,(xdrproc_t) xdr_RxnBond);
}

extern void *AllocRxnBondChanges()
{
     return((void *) AllocateRxnBondChanges);
}

extern CHAR *GetNameRxnCorrespondenceSet(RxnCorrespondenceSet *str)
{
     return(str->Name);
}

extern INT GetIDRxnCorrespondenceSet(RxnCorrespondenceSet *str)
{
     return(str->ID);
}

extern RxnCorrespondenceSet *CreateRxnCorrespondenceSet(RxnCorrespondenceSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfCorrs,
                                                 RxnAtomCorrespondence *Corrs,
                                                 RxnBondChanges *BondChanges,
                                                 RxnUnMatchedSet *UnMatched)
{
RxnAtomCorrespondence *oldCorrs,*newCorrs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfCorrs = NumberOfCorrs;
     if(BondChanges != 0)
          {
          newstruct->BondChanges = AllocateRxnBondChanges;
          CopyFullRxnBondChanges(newstruct->BondChanges, BondChanges);
          }
     else
          newstruct->BondChanges = 0;
     if(UnMatched != 0)
          {
          newstruct->UnMatched = AllocateRxnUnMatchedSet;
          CopyFullRxnUnMatchedSet(newstruct->UnMatched, UnMatched);
          }
     else
          newstruct->UnMatched = 0;

     newstruct->Corrs = AllocArrayRxnAtomCorrespondence(newstruct->NumberOfCorrs);
     if(Corrs != 0)
          {
          oldCorrs = Corrs;
          newCorrs = newstruct->Corrs;
          LOOPi(newstruct->NumberOfCorrs)
               CopyFullRxnAtomCorrespondence(newCorrs++, oldCorrs++);
          }



     return(newstruct);
}


extern void CopyFullRxnCorrespondenceSet(RxnCorrespondenceSet *newstruct, RxnCorrespondenceSet *oldstruct)
{
RxnAtomCorrespondence *oldCorrs,*newCorrs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfCorrs = oldstruct->NumberOfCorrs;

     if(oldstruct->BondChanges != 0)
          {
          newstruct->BondChanges = AllocateRxnBondChanges;
          CopyFullRxnBondChanges(newstruct->BondChanges, oldstruct->BondChanges);
          }
     else
          newstruct->BondChanges = 0;
     if(oldstruct->UnMatched != 0)
          {
          newstruct->UnMatched = AllocateRxnUnMatchedSet;
          CopyFullRxnUnMatchedSet(newstruct->UnMatched, oldstruct->UnMatched);
          }
     else
          newstruct->UnMatched = 0;

     newstruct->Corrs = AllocArrayRxnAtomCorrespondence(newstruct->NumberOfCorrs);
     if(oldstruct->Corrs != 0)
          {
          oldCorrs = oldstruct->Corrs;
          newCorrs = newstruct->Corrs;
          LOOPi(newstruct->NumberOfCorrs)
               CopyFullRxnAtomCorrespondence(newCorrs++, oldCorrs++);
          }


}
extern void PrintRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr)
{
RxnAtomCorrespondence *ptrCorrs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Correspondences:");
     printf("%d\n",eleptr->NumberOfCorrs);

     printf("The Set of Bond Changes:\n");
     PrintRxnBondChanges(eleptr->BondChanges);

     printf("The Unmatched Reactant Atoms:\n");
     PrintRxnUnMatchedSet(eleptr->UnMatched);

     printf(" The Correspondences:\n");
     if(eleptr->Corrs != 0)
          {
          ptrCorrs = eleptr->Corrs;
          LOOPi(eleptr->NumberOfCorrs)
               PrintRxnAtomCorrespondence(ptrCorrs++);
          }


}
extern void FreeRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr)
{
RxnAtomCorrespondence *ptrCorrs;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrCorrs = eleptr->Corrs;
     LOOPi(eleptr->NumberOfCorrs)
          FreeRxnAtomCorrespondence(ptrCorrs++);
     Free(eleptr->Corrs);

     FreeRxnBondChanges(eleptr->BondChanges);
     Free(eleptr->BondChanges);

     FreeRxnUnMatchedSet(eleptr->UnMatched);
     Free(eleptr->UnMatched);

}
extern void WriteBinRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr, DbaseLinkedList *file)
{
RxnAtomCorrespondence *ptrCorrs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfCorrs),file);

     WriteBinRxnBondChanges(eleptr->BondChanges,file);

     WriteBinRxnUnMatchedSet(eleptr->UnMatched,file);

     if(eleptr->Corrs != 0)
          {
          ptrCorrs = eleptr->Corrs;
          LOOPi(eleptr->NumberOfCorrs)
               WriteBinRxnAtomCorrespondence(ptrCorrs++,file);
          }

}
extern INT ReadBinRxnCorrespondenceSet(RxnCorrespondenceSet *eleptr,DbaseLinkedList *file)
     {
RxnAtomCorrespondence *ptrCorrs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfCorrs),file);

     eleptr->BondChanges = AllocateRxnBondChanges;
     if(ReadBinRxnBondChanges(eleptr->BondChanges,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->BondChanges);
           eleptr->BondChanges = 0;
           }

     eleptr->UnMatched = AllocateRxnUnMatchedSet;
     if(ReadBinRxnUnMatchedSet(eleptr->UnMatched,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->UnMatched);
           eleptr->UnMatched = 0;
           }

          eleptr->Corrs = AllocArrayRxnAtomCorrespondence(eleptr->NumberOfCorrs);
          ptrCorrs = eleptr->Corrs;
          LOOPi(eleptr->NumberOfCorrs)
               ReadBinRxnAtomCorrespondence(ptrCorrs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_RxnCorrespondenceSet(XDR *stream, char **eleptrp)
{
     RxnCorrespondenceSet *eleptr;
     eleptr = (RxnCorrespondenceSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfCorrs));

     xdr_pointer(stream,
          (char **) &(eleptr->BondChanges),
          RxnBondChangesSize,
                 (xdrproc_t) xdr_RxnBondChanges);
     xdr_pointer(stream,
          (char **) &(eleptr->UnMatched),
          RxnUnMatchedSetSize,
                 (xdrproc_t) xdr_RxnUnMatchedSet);
     xdr_array(stream,(char **) &(eleptr->Corrs),
             (uint *) &(eleptr->NumberOfCorrs),eleptr->NumberOfCorrs,
               RxnAtomCorrespondenceSize,(xdrproc_t) xdr_RxnAtomCorrespondence);
}

extern void *AllocRxnCorrespondenceSet()
{
     return((void *) AllocateRxnCorrespondenceSet);
}

extern CHAR *GetNameReactionDataConstants(ReactionDataConstants *str)
{
     return(str->Name);
}

extern INT GetIDReactionDataConstants(ReactionDataConstants *str)
{
     return(str->ID);
}

extern ReactionDataConstants *CreateReactionDataConstants(ReactionDataConstants *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  Sym,
                                                   FLOAT  Relative,
                                                   FLOAT  Aconstant,
                                                   FLOAT  Energy,
                                                   FLOAT  TempExp)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Sym = Sym;
     newstruct->Relative = Relative;
     newstruct->Aconstant = Aconstant;
     newstruct->Energy = Energy;
     newstruct->TempExp = TempExp;



     return(newstruct);
}


extern void CopyFullReactionDataConstants(ReactionDataConstants *newstruct, ReactionDataConstants *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Sym = oldstruct->Sym;
     newstruct->Relative = oldstruct->Relative;
     newstruct->Aconstant = oldstruct->Aconstant;
     newstruct->Energy = oldstruct->Energy;
     newstruct->TempExp = oldstruct->TempExp;



}
extern void PrintReactionDataConstants(ReactionDataConstants *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Symmetry Factor of the Products:");
     printf("%d\n",eleptr->Sym);
     printf("The Relative Rate of Reactins:");
     printf("%f\n",eleptr->Relative);
     printf("The Arrhenius Constant:");
     printf("%f\n",eleptr->Aconstant);
     printf("The Activation Energy:");
     printf("%f\n",eleptr->Energy);
     printf("The Temperature Exponent:");
     printf("%f\n",eleptr->TempExp);

}
extern void FreeReactionDataConstants(ReactionDataConstants *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinReactionDataConstants(ReactionDataConstants *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Sym),file);
     WriteBinFLOAT(&(eleptr->Relative),file);
     WriteBinFLOAT(&(eleptr->Aconstant),file);
     WriteBinFLOAT(&(eleptr->Energy),file);
     WriteBinFLOAT(&(eleptr->TempExp),file);

}
extern INT ReadBinReactionDataConstants(ReactionDataConstants *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Sym),file);
     ReadBinFLOAT(&(eleptr->Relative),file);
     ReadBinFLOAT(&(eleptr->Aconstant),file);
     ReadBinFLOAT(&(eleptr->Energy),file);
     ReadBinFLOAT(&(eleptr->TempExp),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReactionDataConstants(XDR *stream, char **eleptrp)
{
     ReactionDataConstants *eleptr;
     eleptr = (ReactionDataConstants *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Sym));
     xdr_FLOAT(stream,(char **) &(eleptr->Relative));
     xdr_FLOAT(stream,(char **) &(eleptr->Aconstant));
     xdr_FLOAT(stream,(char **) &(eleptr->Energy));
     xdr_FLOAT(stream,(char **) &(eleptr->TempExp));

}

extern void *AllocReactionDataConstants()
{
     return((void *) AllocateReactionDataConstants);
}

extern CHAR *GetNameReactionData(ReactionData *str)
{
     return(str->Name);
}

extern INT GetIDReactionData(ReactionData *str)
{
     return(str->ID);
}

extern ReactionData *CreateReactionData(ReactionData *newstruct,
                                 INT id,
                                 CHAR *name,
                                 ReactionDataConstants *Forward,
                                 ReactionDataConstants *Reverse)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Forward != 0)
          {
          newstruct->Forward = AllocateReactionDataConstants;
          CopyFullReactionDataConstants(newstruct->Forward, Forward);
          }
     else
          newstruct->Forward = 0;
     if(Reverse != 0)
          {
          newstruct->Reverse = AllocateReactionDataConstants;
          CopyFullReactionDataConstants(newstruct->Reverse, Reverse);
          }
     else
          newstruct->Reverse = 0;



     return(newstruct);
}


extern void CopyFullReactionData(ReactionData *newstruct, ReactionData *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Forward != 0)
          {
          newstruct->Forward = AllocateReactionDataConstants;
          CopyFullReactionDataConstants(newstruct->Forward, oldstruct->Forward);
          }
     else
          newstruct->Forward = 0;
     if(oldstruct->Reverse != 0)
          {
          newstruct->Reverse = AllocateReactionDataConstants;
          CopyFullReactionDataConstants(newstruct->Reverse, oldstruct->Reverse);
          }
     else
          newstruct->Reverse = 0;


}
extern void PrintReactionData(ReactionData *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The data constants for the forward direction:\n");
     PrintReactionDataConstants(eleptr->Forward);

     printf("The data constants for the reverse direction:\n");
     PrintReactionDataConstants(eleptr->Reverse);

}
extern void FreeReactionData(ReactionData *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeReactionDataConstants(eleptr->Forward);
     Free(eleptr->Forward);

     FreeReactionDataConstants(eleptr->Reverse);
     Free(eleptr->Reverse);

}
extern void WriteBinReactionData(ReactionData *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinReactionDataConstants(eleptr->Forward,file);

     WriteBinReactionDataConstants(eleptr->Reverse,file);

}
extern INT ReadBinReactionData(ReactionData *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Forward = AllocateReactionDataConstants;
     if(ReadBinReactionDataConstants(eleptr->Forward,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Forward);
           eleptr->Forward = 0;
           }

     eleptr->Reverse = AllocateReactionDataConstants;
     if(ReadBinReactionDataConstants(eleptr->Reverse,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Reverse);
           eleptr->Reverse = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ReactionData(XDR *stream, char **eleptrp)
{
     ReactionData *eleptr;
     eleptr = (ReactionData *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Forward),
          ReactionDataConstantsSize,
                 (xdrproc_t) xdr_ReactionDataConstants);
     xdr_pointer(stream,
          (char **) &(eleptr->Reverse),
          ReactionDataConstantsSize,
                 (xdrproc_t) xdr_ReactionDataConstants);
}

extern void *AllocReactionData()
{
     return((void *) AllocateReactionData);
}

extern CHAR *GetNameReactionInfo(ReactionInfo *str)
{
     return(str->Name);
}

extern INT GetIDReactionInfo(ReactionInfo *str)
{
     return(str->ID);
}

extern ReactionInfo *CreateReactionInfo(ReactionInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfReactants,
                                 INT  NumberOfProducts,
                                 INT *Reactants,
                                 INT *Products,
                                 RxnCorrespondenceSet *TotalCorr,
                                 RxnCorrespondenceSet *RxnPatCorr,
                                 ReactionData *Data,
                                 SetOfPropertyValues *Properties)
{
INT *oldReactants,*newReactants;
INT *oldProducts,*newProducts;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactants = NumberOfReactants;
     newstruct->NumberOfProducts = NumberOfProducts;
     if(TotalCorr != 0)
          {
          newstruct->TotalCorr = AllocateRxnCorrespondenceSet;
          CopyFullRxnCorrespondenceSet(newstruct->TotalCorr, TotalCorr);
          }
     else
          newstruct->TotalCorr = 0;
     if(RxnPatCorr != 0)
          {
          newstruct->RxnPatCorr = AllocateRxnCorrespondenceSet;
          CopyFullRxnCorrespondenceSet(newstruct->RxnPatCorr, RxnPatCorr);
          }
     else
          newstruct->RxnPatCorr = 0;
     if(Data != 0)
          {
          newstruct->Data = AllocateReactionData;
          CopyFullReactionData(newstruct->Data, Data);
          }
     else
          newstruct->Data = 0;
     if(Properties != 0)
          {
          newstruct->Properties = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Properties, Properties);
          }
     else
          newstruct->Properties = 0;

     newstruct->Reactants = AllocArrayINT(newstruct->NumberOfReactants);
     if(Reactants != 0)
          {
          oldReactants = Reactants;
          newReactants = newstruct->Reactants;
          LOOPi(newstruct->NumberOfReactants)
               CopyFullINT(newReactants++, oldReactants++);
          }

     newstruct->Products = AllocArrayINT(newstruct->NumberOfProducts);
     if(Products != 0)
          {
          oldProducts = Products;
          newProducts = newstruct->Products;
          LOOPi(newstruct->NumberOfProducts)
               CopyFullINT(newProducts++, oldProducts++);
          }



     return(newstruct);
}


extern void CopyFullReactionInfo(ReactionInfo *newstruct, ReactionInfo *oldstruct)
{
INT *oldReactants,*newReactants;
INT *oldProducts,*newProducts;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactants = oldstruct->NumberOfReactants;
     newstruct->NumberOfProducts = oldstruct->NumberOfProducts;

     if(oldstruct->TotalCorr != 0)
          {
          newstruct->TotalCorr = AllocateRxnCorrespondenceSet;
          CopyFullRxnCorrespondenceSet(newstruct->TotalCorr, oldstruct->TotalCorr);
          }
     else
          newstruct->TotalCorr = 0;
     if(oldstruct->RxnPatCorr != 0)
          {
          newstruct->RxnPatCorr = AllocateRxnCorrespondenceSet;
          CopyFullRxnCorrespondenceSet(newstruct->RxnPatCorr, oldstruct->RxnPatCorr);
          }
     else
          newstruct->RxnPatCorr = 0;
     if(oldstruct->Data != 0)
          {
          newstruct->Data = AllocateReactionData;
          CopyFullReactionData(newstruct->Data, oldstruct->Data);
          }
     else
          newstruct->Data = 0;
     if(oldstruct->Properties != 0)
          {
          newstruct->Properties = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Properties, oldstruct->Properties);
          }
     else
          newstruct->Properties = 0;

     newstruct->Reactants = AllocArrayINT(newstruct->NumberOfReactants);
     if(oldstruct->Reactants != 0)
          {
          oldReactants = oldstruct->Reactants;
          newReactants = newstruct->Reactants;
          LOOPi(newstruct->NumberOfReactants)
               CopyFullINT(newReactants++, oldReactants++);
          }

     newstruct->Products = AllocArrayINT(newstruct->NumberOfProducts);
     if(oldstruct->Products != 0)
          {
          oldProducts = oldstruct->Products;
          newProducts = newstruct->Products;
          LOOPi(newstruct->NumberOfProducts)
               CopyFullINT(newProducts++, oldProducts++);
          }


}
extern void PrintReactionInfo(ReactionInfo *eleptr)
{
INT *ptrReactants;
INT *ptrProducts;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of reactants:");
     printf("%d\n",eleptr->NumberOfReactants);
     printf("The Number of Products:");
     printf("%d\n",eleptr->NumberOfProducts);

     printf("The total set of correspondences:\n");
     PrintRxnCorrespondenceSet(eleptr->TotalCorr);

     printf("The rxn-pattern set of correspondences:\n");
     PrintRxnCorrespondenceSet(eleptr->RxnPatCorr);

     printf("The Set  of Constants associated with a reaction:\n");
     PrintReactionData(eleptr->Data);

     printf("The set of properties for the reactions:\n");
     PrintSetOfPropertyValues(eleptr->Properties);

     printf("The set of Reactants (molecule ID's):\n");
     if(eleptr->Reactants != 0)
          {
          ptrReactants = eleptr->Reactants;
          LOOPi(eleptr->NumberOfReactants)
               PrintINT(ptrReactants++);
          }


     printf("The Set of Products (molecule ID's):\n");
     if(eleptr->Products != 0)
          {
          ptrProducts = eleptr->Products;
          LOOPi(eleptr->NumberOfProducts)
               PrintINT(ptrProducts++);
          }


}
extern void FreeReactionInfo(ReactionInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Reactants);

     Free(eleptr->Products);

     FreeRxnCorrespondenceSet(eleptr->TotalCorr);
     Free(eleptr->TotalCorr);

     FreeRxnCorrespondenceSet(eleptr->RxnPatCorr);
     Free(eleptr->RxnPatCorr);

     FreeReactionData(eleptr->Data);
     Free(eleptr->Data);

     FreeSetOfPropertyValues(eleptr->Properties);
     Free(eleptr->Properties);

}
extern void WriteBinReactionInfo(ReactionInfo *eleptr, DbaseLinkedList *file)
{
INT *ptrReactants;
INT *ptrProducts;
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

     WriteBinRxnCorrespondenceSet(eleptr->TotalCorr,file);

     WriteBinRxnCorrespondenceSet(eleptr->RxnPatCorr,file);

     WriteBinReactionData(eleptr->Data,file);

     WriteBinSetOfPropertyValues(eleptr->Properties,file);

     if(eleptr->Reactants != 0)
          {
          ptrReactants = eleptr->Reactants;
          LOOPi(eleptr->NumberOfReactants)
               WriteBinINT(ptrReactants++,file);
          }

     if(eleptr->Products != 0)
          {
          ptrProducts = eleptr->Products;
          LOOPi(eleptr->NumberOfProducts)
               WriteBinINT(ptrProducts++,file);
          }

}
extern INT ReadBinReactionInfo(ReactionInfo *eleptr,DbaseLinkedList *file)
     {
INT *ptrReactants;
INT *ptrProducts;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactants),file);
     ReadBinINT(&(eleptr->NumberOfProducts),file);

     eleptr->TotalCorr = AllocateRxnCorrespondenceSet;
     if(ReadBinRxnCorrespondenceSet(eleptr->TotalCorr,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->TotalCorr);
           eleptr->TotalCorr = 0;
           }

     eleptr->RxnPatCorr = AllocateRxnCorrespondenceSet;
     if(ReadBinRxnCorrespondenceSet(eleptr->RxnPatCorr,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->RxnPatCorr);
           eleptr->RxnPatCorr = 0;
           }

     eleptr->Data = AllocateReactionData;
     if(ReadBinReactionData(eleptr->Data,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Data);
           eleptr->Data = 0;
           }

     eleptr->Properties = AllocateSetOfPropertyValues;
     if(ReadBinSetOfPropertyValues(eleptr->Properties,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Properties);
           eleptr->Properties = 0;
           }

          eleptr->Reactants = AllocArrayINT(eleptr->NumberOfReactants);
          ptrReactants = eleptr->Reactants;
          LOOPi(eleptr->NumberOfReactants)
               ReadBinINT(ptrReactants++,file);

          eleptr->Products = AllocArrayINT(eleptr->NumberOfProducts);
          ptrProducts = eleptr->Products;
          LOOPi(eleptr->NumberOfProducts)
               ReadBinINT(ptrProducts++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReactionInfo(XDR *stream, char **eleptrp)
{
     ReactionInfo *eleptr;
     eleptr = (ReactionInfo *) eleptrp;
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
          (char **) &(eleptr->TotalCorr),
          RxnCorrespondenceSetSize,
                 (xdrproc_t) xdr_RxnCorrespondenceSet);
     xdr_pointer(stream,
          (char **) &(eleptr->RxnPatCorr),
          RxnCorrespondenceSetSize,
                 (xdrproc_t) xdr_RxnCorrespondenceSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Data),
          ReactionDataSize,
                 (xdrproc_t) xdr_ReactionData);
     xdr_pointer(stream,
          (char **) &(eleptr->Properties),
          SetOfPropertyValuesSize,
                 (xdrproc_t) xdr_SetOfPropertyValues);
     xdr_array(stream,(char **) &(eleptr->Reactants),
             (uint *) &(eleptr->NumberOfReactants),eleptr->NumberOfReactants,
               INTSize,(xdrproc_t) xdr_INT);
     xdr_array(stream,(char **) &(eleptr->Products),
             (uint *) &(eleptr->NumberOfProducts),eleptr->NumberOfProducts,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocReactionInfo()
{
     return((void *) AllocateReactionInfo);
}

extern CHAR *GetNameReactionSet(ReactionSet *str)
{
     return(str->Name);
}

extern INT GetIDReactionSet(ReactionSet *str)
{
     return(str->ID);
}

extern ReactionSet *CreateReactionSet(ReactionSet *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfReactions,
                               ReactionInfo *Reactions,
                               SetOfPropertyTypes *PropertyTypes)
{
ReactionInfo *oldReactions,*newReactions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfReactions = NumberOfReactions;
     if(PropertyTypes != 0)
          {
          newstruct->PropertyTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropertyTypes, PropertyTypes);
          }
     else
          newstruct->PropertyTypes = 0;

     newstruct->Reactions = AllocArrayReactionInfo(newstruct->NumberOfReactions);
     if(Reactions != 0)
          {
          oldReactions = Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullReactionInfo(newReactions++, oldReactions++);
          }



     return(newstruct);
}


extern void CopyFullReactionSet(ReactionSet *newstruct, ReactionSet *oldstruct)
{
ReactionInfo *oldReactions,*newReactions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfReactions = oldstruct->NumberOfReactions;

     if(oldstruct->PropertyTypes != 0)
          {
          newstruct->PropertyTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropertyTypes, oldstruct->PropertyTypes);
          }
     else
          newstruct->PropertyTypes = 0;

     newstruct->Reactions = AllocArrayReactionInfo(newstruct->NumberOfReactions);
     if(oldstruct->Reactions != 0)
          {
          oldReactions = oldstruct->Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfReactions)
               CopyFullReactionInfo(newReactions++, oldReactions++);
          }


}
extern void PrintReactionSet(ReactionSet *eleptr)
{
ReactionInfo *ptrReactions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Reactions:");
     printf("%d\n",eleptr->NumberOfReactions);

     printf("  The property types:\n");
     PrintSetOfPropertyTypes(eleptr->PropertyTypes);

     printf("       The Reactions:\n");
     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               PrintReactionInfo(ptrReactions++);
          }


}
extern void FreeReactionSet(ReactionSet *eleptr)
{
ReactionInfo *ptrReactions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactions = eleptr->Reactions;
     LOOPi(eleptr->NumberOfReactions)
          FreeReactionInfo(ptrReactions++);
     Free(eleptr->Reactions);

     FreeSetOfPropertyTypes(eleptr->PropertyTypes);
     Free(eleptr->PropertyTypes);

}
extern void WriteBinReactionSet(ReactionSet *eleptr, DbaseLinkedList *file)
{
ReactionInfo *ptrReactions;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfReactions),file);

     WriteBinSetOfPropertyTypes(eleptr->PropertyTypes,file);

     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               WriteBinReactionInfo(ptrReactions++,file);
          }

}
extern INT ReadBinReactionSet(ReactionSet *eleptr,DbaseLinkedList *file)
     {
ReactionInfo *ptrReactions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfReactions),file);

     eleptr->PropertyTypes = AllocateSetOfPropertyTypes;
     if(ReadBinSetOfPropertyTypes(eleptr->PropertyTypes,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PropertyTypes);
           eleptr->PropertyTypes = 0;
           }

          eleptr->Reactions = AllocArrayReactionInfo(eleptr->NumberOfReactions);
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfReactions)
               ReadBinReactionInfo(ptrReactions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ReactionSet(XDR *stream, char **eleptrp)
{
     ReactionSet *eleptr;
     eleptr = (ReactionSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfReactions));

     xdr_pointer(stream,
          (char **) &(eleptr->PropertyTypes),
          SetOfPropertyTypesSize,
                 (xdrproc_t) xdr_SetOfPropertyTypes);
     xdr_array(stream,(char **) &(eleptr->Reactions),
             (uint *) &(eleptr->NumberOfReactions),eleptr->NumberOfReactions,
               ReactionInfoSize,(xdrproc_t) xdr_ReactionInfo);
}

extern void *AllocReactionSet()
{
     return((void *) AllocateReactionSet);
}
