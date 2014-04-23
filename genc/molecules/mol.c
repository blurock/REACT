
extern CHAR *GetNameAtomicNumberCount(AtomicNumberCount *str)
{
     return(str->Name);
}

extern INT GetIDAtomicNumberCount(AtomicNumberCount *str)
{
     return(str->ID);
}

extern AtomicNumberCount *CreateAtomicNumberCount(AtomicNumberCount *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  ACount,
                                           INT  NumberOfValences,
                                           INT *Valences,
                                           INT *VCounts)
{
INT *oldValences,*newValences;
INT *oldVCounts,*newVCounts;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->ACount = ACount;
     newstruct->NumberOfValences = NumberOfValences;

     newstruct->Valences = AllocArrayINT(newstruct->NumberOfValences);
     if(Valences != 0)
          {
          oldValences = Valences;
          newValences = newstruct->Valences;
          LOOPi(newstruct->NumberOfValences)
               CopyFullINT(newValences++, oldValences++);
          }

     newstruct->VCounts = AllocArrayINT(newstruct->NumberOfValences);
     if(VCounts != 0)
          {
          oldVCounts = VCounts;
          newVCounts = newstruct->VCounts;
          LOOPi(newstruct->NumberOfValences)
               CopyFullINT(newVCounts++, oldVCounts++);
          }



     return(newstruct);
}


extern void CopyFullAtomicNumberCount(AtomicNumberCount *newstruct, AtomicNumberCount *oldstruct)
{
INT *oldValences,*newValences;
INT *oldVCounts,*newVCounts;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->ACount = oldstruct->ACount;
     newstruct->NumberOfValences = oldstruct->NumberOfValences;


     newstruct->Valences = AllocArrayINT(newstruct->NumberOfValences);
     if(oldstruct->Valences != 0)
          {
          oldValences = oldstruct->Valences;
          newValences = newstruct->Valences;
          LOOPi(newstruct->NumberOfValences)
               CopyFullINT(newValences++, oldValences++);
          }

     newstruct->VCounts = AllocArrayINT(newstruct->NumberOfValences);
     if(oldstruct->VCounts != 0)
          {
          oldVCounts = oldstruct->VCounts;
          newVCounts = newstruct->VCounts;
          LOOPi(newstruct->NumberOfValences)
               CopyFullINT(newVCounts++, oldVCounts++);
          }


}
extern void PrintAtomicNumberCount(AtomicNumberCount *eleptr)
{
INT *ptrValences;
INT *ptrVCounts;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of this atomic number:");
     printf("%d\n",eleptr->ACount);
     printf("The number of different valences:");
     printf("%d\n",eleptr->NumberOfValences);

     printf(" The Set of Valences:\n");
     if(eleptr->Valences != 0)
          {
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfValences)
               PrintINT(ptrValences++);
          }


     printf("The number of each valence:\n");
     if(eleptr->VCounts != 0)
          {
          ptrVCounts = eleptr->VCounts;
          LOOPi(eleptr->NumberOfValences)
               PrintINT(ptrVCounts++);
          }


}
extern void FreeAtomicNumberCount(AtomicNumberCount *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Valences);

     Free(eleptr->VCounts);

}
extern void WriteBinAtomicNumberCount(AtomicNumberCount *eleptr, DbaseLinkedList *file)
{
INT *ptrValences;
INT *ptrVCounts;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->ACount),file);
     WriteBinINT(&(eleptr->NumberOfValences),file);

     if(eleptr->Valences != 0)
          {
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfValences)
               WriteBinINT(ptrValences++,file);
          }

     if(eleptr->VCounts != 0)
          {
          ptrVCounts = eleptr->VCounts;
          LOOPi(eleptr->NumberOfValences)
               WriteBinINT(ptrVCounts++,file);
          }

}
extern INT ReadBinAtomicNumberCount(AtomicNumberCount *eleptr,DbaseLinkedList *file)
     {
INT *ptrValences;
INT *ptrVCounts;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->ACount),file);
     ReadBinINT(&(eleptr->NumberOfValences),file);

          eleptr->Valences = AllocArrayINT(eleptr->NumberOfValences);
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfValences)
               ReadBinINT(ptrValences++,file);

          eleptr->VCounts = AllocArrayINT(eleptr->NumberOfValences);
          ptrVCounts = eleptr->VCounts;
          LOOPi(eleptr->NumberOfValences)
               ReadBinINT(ptrVCounts++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_AtomicNumberCount(XDR *stream, char **eleptrp)
{
     AtomicNumberCount *eleptr;
     eleptr = (AtomicNumberCount *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->ACount));
     xdr_INT(stream,(char **) &(eleptr->NumberOfValences));

     xdr_array(stream,(char **) &(eleptr->Valences),
             (uint *) &(eleptr->NumberOfValences),eleptr->NumberOfValences,
               INTSize,(xdrproc_t) xdr_INT);
     xdr_array(stream,(char **) &(eleptr->VCounts),
             (uint *) &(eleptr->NumberOfValences),eleptr->NumberOfValences,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocAtomicNumberCount()
{
     return((void *) AllocateAtomicNumberCount);
}

extern CHAR *GetNameMoleculeAtomCounts(MoleculeAtomCounts *str)
{
     return(str->Name);
}

extern INT GetIDMoleculeAtomCounts(MoleculeAtomCounts *str)
{
     return(str->ID);
}

extern MoleculeAtomCounts *CreateMoleculeAtomCounts(MoleculeAtomCounts *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfAtomCounts,
                                             AtomicNumberCount *AtomCounts,
                                             INT  NumberOfAtoms,
                                             INT *Valences)
{
AtomicNumberCount *oldAtomCounts,*newAtomCounts;
INT *oldValences,*newValences;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAtomCounts = NumberOfAtomCounts;
     newstruct->NumberOfAtoms = NumberOfAtoms;

     newstruct->AtomCounts = AllocArrayAtomicNumberCount(newstruct->NumberOfAtomCounts);
     if(AtomCounts != 0)
          {
          oldAtomCounts = AtomCounts;
          newAtomCounts = newstruct->AtomCounts;
          LOOPi(newstruct->NumberOfAtomCounts)
               CopyFullAtomicNumberCount(newAtomCounts++, oldAtomCounts++);
          }

     newstruct->Valences = AllocArrayINT(newstruct->NumberOfAtoms);
     if(Valences != 0)
          {
          oldValences = Valences;
          newValences = newstruct->Valences;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullINT(newValences++, oldValences++);
          }



     return(newstruct);
}


extern void CopyFullMoleculeAtomCounts(MoleculeAtomCounts *newstruct, MoleculeAtomCounts *oldstruct)
{
AtomicNumberCount *oldAtomCounts,*newAtomCounts;
INT *oldValences,*newValences;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAtomCounts = oldstruct->NumberOfAtomCounts;
     newstruct->NumberOfAtoms = oldstruct->NumberOfAtoms;


     newstruct->AtomCounts = AllocArrayAtomicNumberCount(newstruct->NumberOfAtomCounts);
     if(oldstruct->AtomCounts != 0)
          {
          oldAtomCounts = oldstruct->AtomCounts;
          newAtomCounts = newstruct->AtomCounts;
          LOOPi(newstruct->NumberOfAtomCounts)
               CopyFullAtomicNumberCount(newAtomCounts++, oldAtomCounts++);
          }

     newstruct->Valences = AllocArrayINT(newstruct->NumberOfAtoms);
     if(oldstruct->Valences != 0)
          {
          oldValences = oldstruct->Valences;
          newValences = newstruct->Valences;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullINT(newValences++, oldValences++);
          }


}
extern void PrintMoleculeAtomCounts(MoleculeAtomCounts *eleptr)
{
AtomicNumberCount *ptrAtomCounts;
INT *ptrValences;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Difference Atoms:");
     printf("%d\n",eleptr->NumberOfAtomCounts);
     printf("The number of atoms in the molecule:");
     printf("%d\n",eleptr->NumberOfAtoms);

     printf("The total counts of atoms and valence:\n");
     if(eleptr->AtomCounts != 0)
          {
          ptrAtomCounts = eleptr->AtomCounts;
          LOOPi(eleptr->NumberOfAtomCounts)
               PrintAtomicNumberCount(ptrAtomCounts++);
          }


     printf(" The set of Valences:\n");
     if(eleptr->Valences != 0)
          {
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfAtoms)
               PrintINT(ptrValences++);
          }


}
extern void FreeMoleculeAtomCounts(MoleculeAtomCounts *eleptr)
{
AtomicNumberCount *ptrAtomCounts;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrAtomCounts = eleptr->AtomCounts;
     LOOPi(eleptr->NumberOfAtomCounts)
          FreeAtomicNumberCount(ptrAtomCounts++);
     Free(eleptr->AtomCounts);

     Free(eleptr->Valences);

}
extern void WriteBinMoleculeAtomCounts(MoleculeAtomCounts *eleptr, DbaseLinkedList *file)
{
AtomicNumberCount *ptrAtomCounts;
INT *ptrValences;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAtomCounts),file);
     WriteBinINT(&(eleptr->NumberOfAtoms),file);

     if(eleptr->AtomCounts != 0)
          {
          ptrAtomCounts = eleptr->AtomCounts;
          LOOPi(eleptr->NumberOfAtomCounts)
               WriteBinAtomicNumberCount(ptrAtomCounts++,file);
          }

     if(eleptr->Valences != 0)
          {
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfAtoms)
               WriteBinINT(ptrValences++,file);
          }

}
extern INT ReadBinMoleculeAtomCounts(MoleculeAtomCounts *eleptr,DbaseLinkedList *file)
     {
AtomicNumberCount *ptrAtomCounts;
INT *ptrValences;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAtomCounts),file);
     ReadBinINT(&(eleptr->NumberOfAtoms),file);

          eleptr->AtomCounts = AllocArrayAtomicNumberCount(eleptr->NumberOfAtomCounts);
          ptrAtomCounts = eleptr->AtomCounts;
          LOOPi(eleptr->NumberOfAtomCounts)
               ReadBinAtomicNumberCount(ptrAtomCounts++,file);

          eleptr->Valences = AllocArrayINT(eleptr->NumberOfAtoms);
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfAtoms)
               ReadBinINT(ptrValences++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MoleculeAtomCounts(XDR *stream, char **eleptrp)
{
     MoleculeAtomCounts *eleptr;
     eleptr = (MoleculeAtomCounts *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAtomCounts));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAtoms));

     xdr_array(stream,(char **) &(eleptr->AtomCounts),
             (uint *) &(eleptr->NumberOfAtomCounts),eleptr->NumberOfAtomCounts,
               AtomicNumberCountSize,(xdrproc_t) xdr_AtomicNumberCount);
     xdr_array(stream,(char **) &(eleptr->Valences),
             (uint *) &(eleptr->NumberOfAtoms),eleptr->NumberOfAtoms,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocMoleculeAtomCounts()
{
     return((void *) AllocateMoleculeAtomCounts);
}

extern CHAR *GetNameMoleculeSubGraph(MoleculeSubGraph *str)
{
     return(str->Name);
}

extern INT GetIDMoleculeSubGraph(MoleculeSubGraph *str)
{
     return(str->ID);
}

extern MoleculeSubGraph *CreateMoleculeSubGraph(MoleculeSubGraph *newstruct,
                                         INT id,
                                         CHAR *name,
                                         Graph *SubGraph,
                                         DataSubSet *WithHydrogens,
                                         DataSubSet *HeavyAtoms,
                                         SetOfPairSets *Symmetry)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(SubGraph != 0)
          {
          newstruct->SubGraph = AllocateGraph;
          CopyFullGraph(newstruct->SubGraph, SubGraph);
          }
     else
          newstruct->SubGraph = 0;
     if(WithHydrogens != 0)
          {
          newstruct->WithHydrogens = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->WithHydrogens, WithHydrogens);
          }
     else
          newstruct->WithHydrogens = 0;
     if(HeavyAtoms != 0)
          {
          newstruct->HeavyAtoms = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->HeavyAtoms, HeavyAtoms);
          }
     else
          newstruct->HeavyAtoms = 0;
     if(Symmetry != 0)
          {
          newstruct->Symmetry = AllocateSetOfPairSets;
          CopyFullSetOfPairSets(newstruct->Symmetry, Symmetry);
          }
     else
          newstruct->Symmetry = 0;



     return(newstruct);
}


extern void CopyFullMoleculeSubGraph(MoleculeSubGraph *newstruct, MoleculeSubGraph *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->SubGraph != 0)
          {
          newstruct->SubGraph = AllocateGraph;
          CopyFullGraph(newstruct->SubGraph, oldstruct->SubGraph);
          }
     else
          newstruct->SubGraph = 0;
     if(oldstruct->WithHydrogens != 0)
          {
          newstruct->WithHydrogens = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->WithHydrogens, oldstruct->WithHydrogens);
          }
     else
          newstruct->WithHydrogens = 0;
     if(oldstruct->HeavyAtoms != 0)
          {
          newstruct->HeavyAtoms = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->HeavyAtoms, oldstruct->HeavyAtoms);
          }
     else
          newstruct->HeavyAtoms = 0;
     if(oldstruct->Symmetry != 0)
          {
          newstruct->Symmetry = AllocateSetOfPairSets;
          CopyFullSetOfPairSets(newstruct->Symmetry, oldstruct->Symmetry);
          }
     else
          newstruct->Symmetry = 0;


}
extern void PrintMoleculeSubGraph(MoleculeSubGraph *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("        The SubGraph:\n");
     PrintGraph(eleptr->SubGraph);

     printf("The Atomset with all the hydrogens:\n");
     PrintDataSubSet(eleptr->WithHydrogens);

     printf("The Atomset with only Heavy Atoms:\n");
     PrintDataSubSet(eleptr->HeavyAtoms);

     printf("The subgraph matchings with itself (representing symmetry):\n");
     PrintSetOfPairSets(eleptr->Symmetry);

}
extern void FreeMoleculeSubGraph(MoleculeSubGraph *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeGraph(eleptr->SubGraph);
     Free(eleptr->SubGraph);

     FreeDataSubSet(eleptr->WithHydrogens);
     Free(eleptr->WithHydrogens);

     FreeDataSubSet(eleptr->HeavyAtoms);
     Free(eleptr->HeavyAtoms);

     FreeSetOfPairSets(eleptr->Symmetry);
     Free(eleptr->Symmetry);

}
extern void WriteBinMoleculeSubGraph(MoleculeSubGraph *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinGraph(eleptr->SubGraph,file);

     WriteBinDataSubSet(eleptr->WithHydrogens,file);

     WriteBinDataSubSet(eleptr->HeavyAtoms,file);

     WriteBinSetOfPairSets(eleptr->Symmetry,file);

}
extern INT ReadBinMoleculeSubGraph(MoleculeSubGraph *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->SubGraph = AllocateGraph;
     if(ReadBinGraph(eleptr->SubGraph,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SubGraph);
           eleptr->SubGraph = 0;
           }

     eleptr->WithHydrogens = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->WithHydrogens,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->WithHydrogens);
           eleptr->WithHydrogens = 0;
           }

     eleptr->HeavyAtoms = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->HeavyAtoms,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->HeavyAtoms);
           eleptr->HeavyAtoms = 0;
           }

     eleptr->Symmetry = AllocateSetOfPairSets;
     if(ReadBinSetOfPairSets(eleptr->Symmetry,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Symmetry);
           eleptr->Symmetry = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_MoleculeSubGraph(XDR *stream, char **eleptrp)
{
     MoleculeSubGraph *eleptr;
     eleptr = (MoleculeSubGraph *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->SubGraph),
          GraphSize,
                 (xdrproc_t) xdr_Graph);
     xdr_pointer(stream,
          (char **) &(eleptr->WithHydrogens),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->HeavyAtoms),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Symmetry),
          SetOfPairSetsSize,
                 (xdrproc_t) xdr_SetOfPairSets);
}

extern void *AllocMoleculeSubGraph()
{
     return((void *) AllocateMoleculeSubGraph);
}

extern CHAR *GetNameMoleculeInfo(MoleculeInfo *str)
{
     return(str->Name);
}

extern INT GetIDMoleculeInfo(MoleculeInfo *str)
{
     return(str->ID);
}

extern MoleculeInfo *CreateMoleculeInfo(MoleculeInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 MolFileMolecule *Molfile,
                                 MoleculeElectronic *Electronic,
                                 SetOfPropertyValues *Properties)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Molfile != 0)
          {
          newstruct->Molfile = AllocateMolFileMolecule;
          CopyFullMolFileMolecule(newstruct->Molfile, Molfile);
          }
     else
          newstruct->Molfile = 0;
     if(Electronic != 0)
          {
          newstruct->Electronic = AllocateMoleculeElectronic;
          CopyFullMoleculeElectronic(newstruct->Electronic, Electronic);
          }
     else
          newstruct->Electronic = 0;
     if(Properties != 0)
          {
          newstruct->Properties = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Properties, Properties);
          }
     else
          newstruct->Properties = 0;



     return(newstruct);
}


extern void CopyFullMoleculeInfo(MoleculeInfo *newstruct, MoleculeInfo *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Molfile != 0)
          {
          newstruct->Molfile = AllocateMolFileMolecule;
          CopyFullMolFileMolecule(newstruct->Molfile, oldstruct->Molfile);
          }
     else
          newstruct->Molfile = 0;
     if(oldstruct->Electronic != 0)
          {
          newstruct->Electronic = AllocateMoleculeElectronic;
          CopyFullMoleculeElectronic(newstruct->Electronic, oldstruct->Electronic);
          }
     else
          newstruct->Electronic = 0;
     if(oldstruct->Properties != 0)
          {
          newstruct->Properties = AllocateSetOfPropertyValues;
          CopyFullSetOfPropertyValues(newstruct->Properties, oldstruct->Properties);
          }
     else
          newstruct->Properties = 0;


}
extern void PrintMoleculeInfo(MoleculeInfo *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Molecule Molfile:\n");
     PrintMolFileMolecule(eleptr->Molfile);

     printf("The Electronic Molecular Info:\n");
     PrintMoleculeElectronic(eleptr->Electronic);

     printf("The set of extra property values for the molecule:\n");
     PrintSetOfPropertyValues(eleptr->Properties);

}
extern void FreeMoleculeInfo(MoleculeInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeMolFileMolecule(eleptr->Molfile);
     Free(eleptr->Molfile);

     FreeMoleculeElectronic(eleptr->Electronic);
     Free(eleptr->Electronic);

     FreeSetOfPropertyValues(eleptr->Properties);
     Free(eleptr->Properties);

}
extern void WriteBinMoleculeInfo(MoleculeInfo *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinMolFileMolecule(eleptr->Molfile,file);

     WriteBinMoleculeElectronic(eleptr->Electronic,file);

     WriteBinSetOfPropertyValues(eleptr->Properties,file);

}
extern INT ReadBinMoleculeInfo(MoleculeInfo *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Molfile = AllocateMolFileMolecule;
     if(ReadBinMolFileMolecule(eleptr->Molfile,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molfile);
           eleptr->Molfile = 0;
           }

     eleptr->Electronic = AllocateMoleculeElectronic;
     if(ReadBinMoleculeElectronic(eleptr->Electronic,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Electronic);
           eleptr->Electronic = 0;
           }

     eleptr->Properties = AllocateSetOfPropertyValues;
     if(ReadBinSetOfPropertyValues(eleptr->Properties,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Properties);
           eleptr->Properties = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_MoleculeInfo(XDR *stream, char **eleptrp)
{
     MoleculeInfo *eleptr;
     eleptr = (MoleculeInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Molfile),
          MolFileMoleculeSize,
                 (xdrproc_t) xdr_MolFileMolecule);
     xdr_pointer(stream,
          (char **) &(eleptr->Electronic),
          MoleculeElectronicSize,
                 (xdrproc_t) xdr_MoleculeElectronic);
     xdr_pointer(stream,
          (char **) &(eleptr->Properties),
          SetOfPropertyValuesSize,
                 (xdrproc_t) xdr_SetOfPropertyValues);
}

extern void *AllocMoleculeInfo()
{
     return((void *) AllocateMoleculeInfo);
}

extern CHAR *GetNameMoleculeSet(MoleculeSet *str)
{
     return(str->Name);
}

extern INT GetIDMoleculeSet(MoleculeSet *str)
{
     return(str->ID);
}

extern MoleculeSet *CreateMoleculeSet(MoleculeSet *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfMolecules,
                               MoleculeInfo *Molecules,
                               SetOfPropertyTypes *PropertyTypes,
                               SetOfMolFileMetaAtoms *MetaAtoms)
{
MoleculeInfo *oldMolecules,*newMolecules;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMolecules = NumberOfMolecules;
     if(PropertyTypes != 0)
          {
          newstruct->PropertyTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropertyTypes, PropertyTypes);
          }
     else
          newstruct->PropertyTypes = 0;
     if(MetaAtoms != 0)
          {
          newstruct->MetaAtoms = AllocateSetOfMolFileMetaAtoms;
          CopyFullSetOfMolFileMetaAtoms(newstruct->MetaAtoms, MetaAtoms);
          }
     else
          newstruct->MetaAtoms = 0;

     newstruct->Molecules = AllocArrayMoleculeInfo(newstruct->NumberOfMolecules);
     if(Molecules != 0)
          {
          oldMolecules = Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullMoleculeInfo(newMolecules++, oldMolecules++);
          }



     return(newstruct);
}


extern void CopyFullMoleculeSet(MoleculeSet *newstruct, MoleculeSet *oldstruct)
{
MoleculeInfo *oldMolecules,*newMolecules;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMolecules = oldstruct->NumberOfMolecules;

     if(oldstruct->PropertyTypes != 0)
          {
          newstruct->PropertyTypes = AllocateSetOfPropertyTypes;
          CopyFullSetOfPropertyTypes(newstruct->PropertyTypes, oldstruct->PropertyTypes);
          }
     else
          newstruct->PropertyTypes = 0;
     if(oldstruct->MetaAtoms != 0)
          {
          newstruct->MetaAtoms = AllocateSetOfMolFileMetaAtoms;
          CopyFullSetOfMolFileMetaAtoms(newstruct->MetaAtoms, oldstruct->MetaAtoms);
          }
     else
          newstruct->MetaAtoms = 0;

     newstruct->Molecules = AllocArrayMoleculeInfo(newstruct->NumberOfMolecules);
     if(oldstruct->Molecules != 0)
          {
          oldMolecules = oldstruct->Molecules;
          newMolecules = newstruct->Molecules;
          LOOPi(newstruct->NumberOfMolecules)
               CopyFullMoleculeInfo(newMolecules++, oldMolecules++);
          }


}
extern void PrintMoleculeSet(MoleculeSet *eleptr)
{
MoleculeInfo *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of molecules in the set:");
     printf("%d\n",eleptr->NumberOfMolecules);

     printf("The property types for a set of molecules:\n");
     PrintSetOfPropertyTypes(eleptr->PropertyTypes);

     printf("Meta Atom Information:\n");
     PrintSetOfMolFileMetaAtoms(eleptr->MetaAtoms);

     printf("The set of molecules:\n");
     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               PrintMoleculeInfo(ptrMolecules++);
          }


}
extern void FreeMoleculeSet(MoleculeSet *eleptr)
{
MoleculeInfo *ptrMolecules;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrMolecules = eleptr->Molecules;
     LOOPi(eleptr->NumberOfMolecules)
          FreeMoleculeInfo(ptrMolecules++);
     Free(eleptr->Molecules);

     FreeSetOfPropertyTypes(eleptr->PropertyTypes);
     Free(eleptr->PropertyTypes);

     FreeSetOfMolFileMetaAtoms(eleptr->MetaAtoms);
     Free(eleptr->MetaAtoms);

}
extern void WriteBinMoleculeSet(MoleculeSet *eleptr, DbaseLinkedList *file)
{
MoleculeInfo *ptrMolecules;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfMolecules),file);

     WriteBinSetOfPropertyTypes(eleptr->PropertyTypes,file);

     WriteBinSetOfMolFileMetaAtoms(eleptr->MetaAtoms,file);

     if(eleptr->Molecules != 0)
          {
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               WriteBinMoleculeInfo(ptrMolecules++,file);
          }

}
extern INT ReadBinMoleculeSet(MoleculeSet *eleptr,DbaseLinkedList *file)
     {
MoleculeInfo *ptrMolecules;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMolecules),file);

     eleptr->PropertyTypes = AllocateSetOfPropertyTypes;
     if(ReadBinSetOfPropertyTypes(eleptr->PropertyTypes,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PropertyTypes);
           eleptr->PropertyTypes = 0;
           }

     eleptr->MetaAtoms = AllocateSetOfMolFileMetaAtoms;
     if(ReadBinSetOfMolFileMetaAtoms(eleptr->MetaAtoms,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->MetaAtoms);
           eleptr->MetaAtoms = 0;
           }

          eleptr->Molecules = AllocArrayMoleculeInfo(eleptr->NumberOfMolecules);
          ptrMolecules = eleptr->Molecules;
          LOOPi(eleptr->NumberOfMolecules)
               ReadBinMoleculeInfo(ptrMolecules++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MoleculeSet(XDR *stream, char **eleptrp)
{
     MoleculeSet *eleptr;
     eleptr = (MoleculeSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfMolecules));

     xdr_pointer(stream,
          (char **) &(eleptr->PropertyTypes),
          SetOfPropertyTypesSize,
                 (xdrproc_t) xdr_SetOfPropertyTypes);
     xdr_pointer(stream,
          (char **) &(eleptr->MetaAtoms),
          SetOfMolFileMetaAtomsSize,
                 (xdrproc_t) xdr_SetOfMolFileMetaAtoms);
     xdr_array(stream,(char **) &(eleptr->Molecules),
             (uint *) &(eleptr->NumberOfMolecules),eleptr->NumberOfMolecules,
               MoleculeInfoSize,(xdrproc_t) xdr_MoleculeInfo);
}

extern void *AllocMoleculeSet()
{
     return((void *) AllocateMoleculeSet);
}
