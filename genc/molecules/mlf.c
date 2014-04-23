
extern CHAR *GetNameMolFileAtom(MolFileAtom *str)
{
     return(str->Name);
}

extern INT GetIDMolFileAtom(MolFileAtom *str)
{
     return(str->ID);
}

extern MolFileAtom *CreateMolFileAtom(MolFileAtom *newstruct,
                               INT id,
                               CHAR *name,
                               FLOAT  X,
                               FLOAT  Y,
                               FLOAT  Z,
                               INT  AtomicNumber,
                               FLOAT  Charge,
                               INT  Radical,
                               INT  NumberOfParameters,
                               INT *Parameters)
{
INT *oldParameters,*newParameters;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->X = X;
     newstruct->Y = Y;
     newstruct->Z = Z;
     newstruct->AtomicNumber = AtomicNumber;
     newstruct->Charge = Charge;
     newstruct->Radical = Radical;
     newstruct->NumberOfParameters = NumberOfParameters;

     newstruct->Parameters = AllocArrayINT(newstruct->NumberOfParameters);
     if(Parameters != 0)
          {
          oldParameters = Parameters;
          newParameters = newstruct->Parameters;
          LOOPi(newstruct->NumberOfParameters)
               CopyFullINT(newParameters++, oldParameters++);
          }



     return(newstruct);
}


extern void CopyFullMolFileAtom(MolFileAtom *newstruct, MolFileAtom *oldstruct)
{
INT *oldParameters,*newParameters;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->X = oldstruct->X;
     newstruct->Y = oldstruct->Y;
     newstruct->Z = oldstruct->Z;
     newstruct->AtomicNumber = oldstruct->AtomicNumber;
     newstruct->Charge = oldstruct->Charge;
     newstruct->Radical = oldstruct->Radical;
     newstruct->NumberOfParameters = oldstruct->NumberOfParameters;


     newstruct->Parameters = AllocArrayINT(newstruct->NumberOfParameters);
     if(oldstruct->Parameters != 0)
          {
          oldParameters = oldstruct->Parameters;
          newParameters = newstruct->Parameters;
          LOOPi(newstruct->NumberOfParameters)
               CopyFullINT(newParameters++, oldParameters++);
          }


}
extern void PrintMolFileAtom(MolFileAtom *eleptr)
{
INT *ptrParameters;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("    The X coordinate:");
     printf("%f\n",eleptr->X);
     printf("    The Y coordinate:");
     printf("%f\n",eleptr->Y);
     printf("    The Z coordinate:");
     printf("%f\n",eleptr->Z);
     printf("   The atomic number:");
     printf("%d\n",eleptr->AtomicNumber);
     printf("The Charge on the atom :");
     printf("%f\n",eleptr->Charge);
     printf("   If a Free Radical:");
     printf("%d\n",eleptr->Radical);
     printf("The number of parameters:");
     printf("%d\n",eleptr->NumberOfParameters);

     printf("      The Parameters:\n");
     if(eleptr->Parameters != 0)
          {
          ptrParameters = eleptr->Parameters;
          LOOPi(eleptr->NumberOfParameters)
               PrintINT(ptrParameters++);
          }


}
extern void FreeMolFileAtom(MolFileAtom *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Parameters);

}
extern void WriteBinMolFileAtom(MolFileAtom *eleptr, DbaseLinkedList *file)
{
INT *ptrParameters;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->X),file);
     WriteBinFLOAT(&(eleptr->Y),file);
     WriteBinFLOAT(&(eleptr->Z),file);
     WriteBinINT(&(eleptr->AtomicNumber),file);
     WriteBinFLOAT(&(eleptr->Charge),file);
     WriteBinINT(&(eleptr->Radical),file);
     WriteBinINT(&(eleptr->NumberOfParameters),file);

     if(eleptr->Parameters != 0)
          {
          ptrParameters = eleptr->Parameters;
          LOOPi(eleptr->NumberOfParameters)
               WriteBinINT(ptrParameters++,file);
          }

}
extern INT ReadBinMolFileAtom(MolFileAtom *eleptr,DbaseLinkedList *file)
     {
INT *ptrParameters;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->X),file);
     ReadBinFLOAT(&(eleptr->Y),file);
     ReadBinFLOAT(&(eleptr->Z),file);
     ReadBinINT(&(eleptr->AtomicNumber),file);
     ReadBinFLOAT(&(eleptr->Charge),file);
     ReadBinINT(&(eleptr->Radical),file);
     ReadBinINT(&(eleptr->NumberOfParameters),file);

          eleptr->Parameters = AllocArrayINT(eleptr->NumberOfParameters);
          ptrParameters = eleptr->Parameters;
          LOOPi(eleptr->NumberOfParameters)
               ReadBinINT(ptrParameters++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MolFileAtom(XDR *stream, char **eleptrp)
{
     MolFileAtom *eleptr;
     eleptr = (MolFileAtom *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->X));
     xdr_FLOAT(stream,(char **) &(eleptr->Y));
     xdr_FLOAT(stream,(char **) &(eleptr->Z));
     xdr_INT(stream,(char **) &(eleptr->AtomicNumber));
     xdr_FLOAT(stream,(char **) &(eleptr->Charge));
     xdr_INT(stream,(char **) &(eleptr->Radical));
     xdr_INT(stream,(char **) &(eleptr->NumberOfParameters));

     xdr_array(stream,(char **) &(eleptr->Parameters),
             (uint *) &(eleptr->NumberOfParameters),eleptr->NumberOfParameters,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocMolFileAtom()
{
     return((void *) AllocateMolFileAtom);
}

extern CHAR *GetNameMolFileBond(MolFileBond *str)
{
     return(str->Name);
}

extern INT GetIDMolFileBond(MolFileBond *str)
{
     return(str->ID);
}

extern MolFileBond *CreateMolFileBond(MolFileBond *newstruct,
                               INT id,
                               CHAR *name,
                               INT  I,
                               INT  J,
                               INT  Order,
                               INT  NumberOfParameters,
                               INT *Parameters)
{
INT *oldParameters,*newParameters;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->I = I;
     newstruct->J = J;
     newstruct->Order = Order;
     newstruct->NumberOfParameters = NumberOfParameters;

     newstruct->Parameters = AllocArrayINT(newstruct->NumberOfParameters);
     if(Parameters != 0)
          {
          oldParameters = Parameters;
          newParameters = newstruct->Parameters;
          LOOPi(newstruct->NumberOfParameters)
               CopyFullINT(newParameters++, oldParameters++);
          }



     return(newstruct);
}


extern void CopyFullMolFileBond(MolFileBond *newstruct, MolFileBond *oldstruct)
{
INT *oldParameters,*newParameters;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->I = oldstruct->I;
     newstruct->J = oldstruct->J;
     newstruct->Order = oldstruct->Order;
     newstruct->NumberOfParameters = oldstruct->NumberOfParameters;


     newstruct->Parameters = AllocArrayINT(newstruct->NumberOfParameters);
     if(oldstruct->Parameters != 0)
          {
          oldParameters = oldstruct->Parameters;
          newParameters = newstruct->Parameters;
          LOOPi(newstruct->NumberOfParameters)
               CopyFullINT(newParameters++, oldParameters++);
          }


}
extern void PrintMolFileBond(MolFileBond *eleptr)
{
INT *ptrParameters;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The label of the first atom:");
     printf("%d\n",eleptr->I);
     printf("The label of the second atom:");
     printf("%d\n",eleptr->J);
     printf("      The bond order:");
     printf("%d\n",eleptr->Order);
     printf("The Number Of Parameters:");
     printf("%d\n",eleptr->NumberOfParameters);

     printf(" The Bond Parameters:\n");
     if(eleptr->Parameters != 0)
          {
          ptrParameters = eleptr->Parameters;
          LOOPi(eleptr->NumberOfParameters)
               PrintINT(ptrParameters++);
          }


}
extern void FreeMolFileBond(MolFileBond *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Parameters);

}
extern void WriteBinMolFileBond(MolFileBond *eleptr, DbaseLinkedList *file)
{
INT *ptrParameters;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->I),file);
     WriteBinINT(&(eleptr->J),file);
     WriteBinINT(&(eleptr->Order),file);
     WriteBinINT(&(eleptr->NumberOfParameters),file);

     if(eleptr->Parameters != 0)
          {
          ptrParameters = eleptr->Parameters;
          LOOPi(eleptr->NumberOfParameters)
               WriteBinINT(ptrParameters++,file);
          }

}
extern INT ReadBinMolFileBond(MolFileBond *eleptr,DbaseLinkedList *file)
     {
INT *ptrParameters;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->I),file);
     ReadBinINT(&(eleptr->J),file);
     ReadBinINT(&(eleptr->Order),file);
     ReadBinINT(&(eleptr->NumberOfParameters),file);

          eleptr->Parameters = AllocArrayINT(eleptr->NumberOfParameters);
          ptrParameters = eleptr->Parameters;
          LOOPi(eleptr->NumberOfParameters)
               ReadBinINT(ptrParameters++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MolFileBond(XDR *stream, char **eleptrp)
{
     MolFileBond *eleptr;
     eleptr = (MolFileBond *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->I));
     xdr_INT(stream,(char **) &(eleptr->J));
     xdr_INT(stream,(char **) &(eleptr->Order));
     xdr_INT(stream,(char **) &(eleptr->NumberOfParameters));

     xdr_array(stream,(char **) &(eleptr->Parameters),
             (uint *) &(eleptr->NumberOfParameters),eleptr->NumberOfParameters,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocMolFileBond()
{
     return((void *) AllocateMolFileBond);
}

extern CHAR *GetNameMolFileMolecule(MolFileMolecule *str)
{
     return(str->Name);
}

extern INT GetIDMolFileMolecule(MolFileMolecule *str)
{
     return(str->ID);
}

extern MolFileMolecule *CreateMolFileMolecule(MolFileMolecule *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NAtoms,
                                       INT  NBonds,
                                       MolFileAtom *Atoms,
                                       MolFileBond *Bonds,
                                       ASCIIProperties *Properties)
{
MolFileAtom *oldAtoms,*newAtoms;
MolFileBond *oldBonds,*newBonds;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NAtoms = NAtoms;
     newstruct->NBonds = NBonds;
     if(Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, Properties);
          }
     else
          newstruct->Properties = 0;

     newstruct->Atoms = AllocArrayMolFileAtom(newstruct->NAtoms);
     if(Atoms != 0)
          {
          oldAtoms = Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NAtoms)
               CopyFullMolFileAtom(newAtoms++, oldAtoms++);
          }

     newstruct->Bonds = AllocArrayMolFileBond(newstruct->NBonds);
     if(Bonds != 0)
          {
          oldBonds = Bonds;
          newBonds = newstruct->Bonds;
          LOOPi(newstruct->NBonds)
               CopyFullMolFileBond(newBonds++, oldBonds++);
          }



     return(newstruct);
}


extern void CopyFullMolFileMolecule(MolFileMolecule *newstruct, MolFileMolecule *oldstruct)
{
MolFileAtom *oldAtoms,*newAtoms;
MolFileBond *oldBonds,*newBonds;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NAtoms = oldstruct->NAtoms;
     newstruct->NBonds = oldstruct->NBonds;

     if(oldstruct->Properties != 0)
          {
          newstruct->Properties = AllocateASCIIProperties;
          CopyFullASCIIProperties(newstruct->Properties, oldstruct->Properties);
          }
     else
          newstruct->Properties = 0;

     newstruct->Atoms = AllocArrayMolFileAtom(newstruct->NAtoms);
     if(oldstruct->Atoms != 0)
          {
          oldAtoms = oldstruct->Atoms;
          newAtoms = newstruct->Atoms;
          LOOPi(newstruct->NAtoms)
               CopyFullMolFileAtom(newAtoms++, oldAtoms++);
          }

     newstruct->Bonds = AllocArrayMolFileBond(newstruct->NBonds);
     if(oldstruct->Bonds != 0)
          {
          oldBonds = oldstruct->Bonds;
          newBonds = newstruct->Bonds;
          LOOPi(newstruct->NBonds)
               CopyFullMolFileBond(newBonds++, oldBonds++);
          }


}
extern void PrintMolFileMolecule(MolFileMolecule *eleptr)
{
MolFileAtom *ptrAtoms;
MolFileBond *ptrBonds;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of atoms in the molecule:");
     printf("%d\n",eleptr->NAtoms);
     printf("  The number of bonds in the molecule:");
     printf("%d\n",eleptr->NBonds);

     printf("The set of properties:\n");
     PrintASCIIProperties(eleptr->Properties);

     printf("  An array of MolfileAtom structures:\n");
     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NAtoms)
               PrintMolFileAtom(ptrAtoms++);
          }


     printf("  An array of MolfileBonds structures:\n");
     if(eleptr->Bonds != 0)
          {
          ptrBonds = eleptr->Bonds;
          LOOPi(eleptr->NBonds)
               PrintMolFileBond(ptrBonds++);
          }


}
extern void FreeMolFileMolecule(MolFileMolecule *eleptr)
{
MolFileAtom *ptrAtoms;
MolFileBond *ptrBonds;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrAtoms = eleptr->Atoms;
     LOOPi(eleptr->NAtoms)
          FreeMolFileAtom(ptrAtoms++);
     Free(eleptr->Atoms);

     ptrBonds = eleptr->Bonds;
     LOOPi(eleptr->NBonds)
          FreeMolFileBond(ptrBonds++);
     Free(eleptr->Bonds);

     FreeASCIIProperties(eleptr->Properties);
     Free(eleptr->Properties);

}
extern void WriteBinMolFileMolecule(MolFileMolecule *eleptr, DbaseLinkedList *file)
{
MolFileAtom *ptrAtoms;
MolFileBond *ptrBonds;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NAtoms),file);
     WriteBinINT(&(eleptr->NBonds),file);

     WriteBinASCIIProperties(eleptr->Properties,file);

     if(eleptr->Atoms != 0)
          {
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NAtoms)
               WriteBinMolFileAtom(ptrAtoms++,file);
          }

     if(eleptr->Bonds != 0)
          {
          ptrBonds = eleptr->Bonds;
          LOOPi(eleptr->NBonds)
               WriteBinMolFileBond(ptrBonds++,file);
          }

}
extern INT ReadBinMolFileMolecule(MolFileMolecule *eleptr,DbaseLinkedList *file)
     {
MolFileAtom *ptrAtoms;
MolFileBond *ptrBonds;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NAtoms),file);
     ReadBinINT(&(eleptr->NBonds),file);

     eleptr->Properties = AllocateASCIIProperties;
     if(ReadBinASCIIProperties(eleptr->Properties,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Properties);
           eleptr->Properties = 0;
           }

          eleptr->Atoms = AllocArrayMolFileAtom(eleptr->NAtoms);
          ptrAtoms = eleptr->Atoms;
          LOOPi(eleptr->NAtoms)
               ReadBinMolFileAtom(ptrAtoms++,file);

          eleptr->Bonds = AllocArrayMolFileBond(eleptr->NBonds);
          ptrBonds = eleptr->Bonds;
          LOOPi(eleptr->NBonds)
               ReadBinMolFileBond(ptrBonds++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MolFileMolecule(XDR *stream, char **eleptrp)
{
     MolFileMolecule *eleptr;
     eleptr = (MolFileMolecule *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NAtoms));
     xdr_INT(stream,(char **) &(eleptr->NBonds));

     xdr_pointer(stream,
          (char **) &(eleptr->Properties),
          ASCIIPropertiesSize,
                 (xdrproc_t) xdr_ASCIIProperties);
     xdr_array(stream,(char **) &(eleptr->Atoms),
             (uint *) &(eleptr->NAtoms),eleptr->NAtoms,
               MolFileAtomSize,(xdrproc_t) xdr_MolFileAtom);
     xdr_array(stream,(char **) &(eleptr->Bonds),
             (uint *) &(eleptr->NBonds),eleptr->NBonds,
               MolFileBondSize,(xdrproc_t) xdr_MolFileBond);
}

extern void *AllocMolFileMolecule()
{
     return((void *) AllocateMolFileMolecule);
}

extern CHAR *GetNameMolFileMetaAtom(MolFileMetaAtom *str)
{
     return(str->Name);
}

extern INT GetIDMolFileMetaAtom(MolFileMetaAtom *str)
{
     return(str->ID);
}

extern MolFileMetaAtom *CreateMolFileMetaAtom(MolFileMetaAtom *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfAliased,
                                       INT *AtomicNumbers,
                                       INT *Bonding)
{
INT *oldAtomicNumbers,*newAtomicNumbers;
INT *oldBonding,*newBonding;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAliased = NumberOfAliased;

     newstruct->AtomicNumbers = AllocArrayINT(newstruct->NumberOfAliased);
     if(AtomicNumbers != 0)
          {
          oldAtomicNumbers = AtomicNumbers;
          newAtomicNumbers = newstruct->AtomicNumbers;
          LOOPi(newstruct->NumberOfAliased)
               CopyFullINT(newAtomicNumbers++, oldAtomicNumbers++);
          }

     newstruct->Bonding = AllocArrayINT(newstruct->NumberOfAliased);
     if(Bonding != 0)
          {
          oldBonding = Bonding;
          newBonding = newstruct->Bonding;
          LOOPi(newstruct->NumberOfAliased)
               CopyFullINT(newBonding++, oldBonding++);
          }



     return(newstruct);
}


extern void CopyFullMolFileMetaAtom(MolFileMetaAtom *newstruct, MolFileMetaAtom *oldstruct)
{
INT *oldAtomicNumbers,*newAtomicNumbers;
INT *oldBonding,*newBonding;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAliased = oldstruct->NumberOfAliased;


     newstruct->AtomicNumbers = AllocArrayINT(newstruct->NumberOfAliased);
     if(oldstruct->AtomicNumbers != 0)
          {
          oldAtomicNumbers = oldstruct->AtomicNumbers;
          newAtomicNumbers = newstruct->AtomicNumbers;
          LOOPi(newstruct->NumberOfAliased)
               CopyFullINT(newAtomicNumbers++, oldAtomicNumbers++);
          }

     newstruct->Bonding = AllocArrayINT(newstruct->NumberOfAliased);
     if(oldstruct->Bonding != 0)
          {
          oldBonding = oldstruct->Bonding;
          newBonding = newstruct->Bonding;
          LOOPi(newstruct->NumberOfAliased)
               CopyFullINT(newBonding++, oldBonding++);
          }


}
extern void PrintMolFileMetaAtom(MolFileMetaAtom *eleptr)
{
INT *ptrAtomicNumbers;
INT *ptrBonding;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Possibilities:");
     printf("%d\n",eleptr->NumberOfAliased);

     printf("  The Atomic Numbers:\n");
     if(eleptr->AtomicNumbers != 0)
          {
          ptrAtomicNumbers = eleptr->AtomicNumbers;
          LOOPi(eleptr->NumberOfAliased)
               PrintINT(ptrAtomicNumbers++);
          }


     printf("        The Bonding :\n");
     if(eleptr->Bonding != 0)
          {
          ptrBonding = eleptr->Bonding;
          LOOPi(eleptr->NumberOfAliased)
               PrintINT(ptrBonding++);
          }


}
extern void FreeMolFileMetaAtom(MolFileMetaAtom *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->AtomicNumbers);

     Free(eleptr->Bonding);

}
extern void WriteBinMolFileMetaAtom(MolFileMetaAtom *eleptr, DbaseLinkedList *file)
{
INT *ptrAtomicNumbers;
INT *ptrBonding;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAliased),file);

     if(eleptr->AtomicNumbers != 0)
          {
          ptrAtomicNumbers = eleptr->AtomicNumbers;
          LOOPi(eleptr->NumberOfAliased)
               WriteBinINT(ptrAtomicNumbers++,file);
          }

     if(eleptr->Bonding != 0)
          {
          ptrBonding = eleptr->Bonding;
          LOOPi(eleptr->NumberOfAliased)
               WriteBinINT(ptrBonding++,file);
          }

}
extern INT ReadBinMolFileMetaAtom(MolFileMetaAtom *eleptr,DbaseLinkedList *file)
     {
INT *ptrAtomicNumbers;
INT *ptrBonding;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAliased),file);

          eleptr->AtomicNumbers = AllocArrayINT(eleptr->NumberOfAliased);
          ptrAtomicNumbers = eleptr->AtomicNumbers;
          LOOPi(eleptr->NumberOfAliased)
               ReadBinINT(ptrAtomicNumbers++,file);

          eleptr->Bonding = AllocArrayINT(eleptr->NumberOfAliased);
          ptrBonding = eleptr->Bonding;
          LOOPi(eleptr->NumberOfAliased)
               ReadBinINT(ptrBonding++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MolFileMetaAtom(XDR *stream, char **eleptrp)
{
     MolFileMetaAtom *eleptr;
     eleptr = (MolFileMetaAtom *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAliased));

     xdr_array(stream,(char **) &(eleptr->AtomicNumbers),
             (uint *) &(eleptr->NumberOfAliased),eleptr->NumberOfAliased,
               INTSize,(xdrproc_t) xdr_INT);
     xdr_array(stream,(char **) &(eleptr->Bonding),
             (uint *) &(eleptr->NumberOfAliased),eleptr->NumberOfAliased,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocMolFileMetaAtom()
{
     return((void *) AllocateMolFileMetaAtom);
}

extern CHAR *GetNameSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *str)
{
     return(str->Name);
}

extern INT GetIDSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *str)
{
     return(str->ID);
}

extern SetOfMolFileMetaAtoms *CreateSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfMetaAtoms,
                                                   MolFileMetaAtom *MetaAtoms)
{
MolFileMetaAtom *oldMetaAtoms,*newMetaAtoms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMetaAtoms = NumberOfMetaAtoms;

     newstruct->MetaAtoms = AllocArrayMolFileMetaAtom(newstruct->NumberOfMetaAtoms);
     if(MetaAtoms != 0)
          {
          oldMetaAtoms = MetaAtoms;
          newMetaAtoms = newstruct->MetaAtoms;
          LOOPi(newstruct->NumberOfMetaAtoms)
               CopyFullMolFileMetaAtom(newMetaAtoms++, oldMetaAtoms++);
          }



     return(newstruct);
}


extern void CopyFullSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *newstruct, SetOfMolFileMetaAtoms *oldstruct)
{
MolFileMetaAtom *oldMetaAtoms,*newMetaAtoms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMetaAtoms = oldstruct->NumberOfMetaAtoms;


     newstruct->MetaAtoms = AllocArrayMolFileMetaAtom(newstruct->NumberOfMetaAtoms);
     if(oldstruct->MetaAtoms != 0)
          {
          oldMetaAtoms = oldstruct->MetaAtoms;
          newMetaAtoms = newstruct->MetaAtoms;
          LOOPi(newstruct->NumberOfMetaAtoms)
               CopyFullMolFileMetaAtom(newMetaAtoms++, oldMetaAtoms++);
          }


}
extern void PrintSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr)
{
MolFileMetaAtom *ptrMetaAtoms;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of MetaAtoms:");
     printf("%d\n",eleptr->NumberOfMetaAtoms);

     printf("The Set of MetaAtoms:\n");
     if(eleptr->MetaAtoms != 0)
          {
          ptrMetaAtoms = eleptr->MetaAtoms;
          LOOPi(eleptr->NumberOfMetaAtoms)
               PrintMolFileMetaAtom(ptrMetaAtoms++);
          }


}
extern void FreeSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr)
{
MolFileMetaAtom *ptrMetaAtoms;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrMetaAtoms = eleptr->MetaAtoms;
     LOOPi(eleptr->NumberOfMetaAtoms)
          FreeMolFileMetaAtom(ptrMetaAtoms++);
     Free(eleptr->MetaAtoms);

}
extern void WriteBinSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr, DbaseLinkedList *file)
{
MolFileMetaAtom *ptrMetaAtoms;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMetaAtoms),file);

     if(eleptr->MetaAtoms != 0)
          {
          ptrMetaAtoms = eleptr->MetaAtoms;
          LOOPi(eleptr->NumberOfMetaAtoms)
               WriteBinMolFileMetaAtom(ptrMetaAtoms++,file);
          }

}
extern INT ReadBinSetOfMolFileMetaAtoms(SetOfMolFileMetaAtoms *eleptr,DbaseLinkedList *file)
     {
MolFileMetaAtom *ptrMetaAtoms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMetaAtoms),file);

          eleptr->MetaAtoms = AllocArrayMolFileMetaAtom(eleptr->NumberOfMetaAtoms);
          ptrMetaAtoms = eleptr->MetaAtoms;
          LOOPi(eleptr->NumberOfMetaAtoms)
               ReadBinMolFileMetaAtom(ptrMetaAtoms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfMolFileMetaAtoms(XDR *stream, char **eleptrp)
{
     SetOfMolFileMetaAtoms *eleptr;
     eleptr = (SetOfMolFileMetaAtoms *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMetaAtoms));

     xdr_array(stream,(char **) &(eleptr->MetaAtoms),
             (uint *) &(eleptr->NumberOfMetaAtoms),eleptr->NumberOfMetaAtoms,
               MolFileMetaAtomSize,(xdrproc_t) xdr_MolFileMetaAtom);
}

extern void *AllocSetOfMolFileMetaAtoms()
{
     return((void *) AllocateSetOfMolFileMetaAtoms);
}
