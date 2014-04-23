
extern CHAR *GetNameBensonCalcConnections(BensonCalcConnections *str)
{
     return(str->Name);
}

extern INT GetIDBensonCalcConnections(BensonCalcConnections *str)
{
     return(str->ID);
}

extern BensonCalcConnections *CreateBensonCalcConnections(BensonCalcConnections *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfNeighbors,
                                                   INT *Valences,
                                                   INT  NumberOfUniqueConnections,
                                                   BensonAtomConnections *Connections)
{
INT *oldValences,*newValences;
BensonAtomConnections *oldConnections,*newConnections;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNeighbors = NumberOfNeighbors;
     newstruct->NumberOfUniqueConnections = NumberOfUniqueConnections;

     newstruct->Valences = AllocArrayINT(newstruct->NumberOfNeighbors);
     if(Valences != 0)
          {
          oldValences = Valences;
          newValences = newstruct->Valences;
          LOOPi(newstruct->NumberOfNeighbors)
               CopyFullINT(newValences++, oldValences++);
          }

     newstruct->Connections = AllocArrayBensonAtomConnections(newstruct->NumberOfUniqueConnections);
     if(Connections != 0)
          {
          oldConnections = Connections;
          newConnections = newstruct->Connections;
          LOOPi(newstruct->NumberOfUniqueConnections)
               CopyFullBensonAtomConnections(newConnections++, oldConnections++);
          }



     return(newstruct);
}


extern void CopyFullBensonCalcConnections(BensonCalcConnections *newstruct, BensonCalcConnections *oldstruct)
{
INT *oldValences,*newValences;
BensonAtomConnections *oldConnections,*newConnections;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNeighbors = oldstruct->NumberOfNeighbors;
     newstruct->NumberOfUniqueConnections = oldstruct->NumberOfUniqueConnections;


     newstruct->Valences = AllocArrayINT(newstruct->NumberOfNeighbors);
     if(oldstruct->Valences != 0)
          {
          oldValences = oldstruct->Valences;
          newValences = newstruct->Valences;
          LOOPi(newstruct->NumberOfNeighbors)
               CopyFullINT(newValences++, oldValences++);
          }

     newstruct->Connections = AllocArrayBensonAtomConnections(newstruct->NumberOfUniqueConnections);
     if(oldstruct->Connections != 0)
          {
          oldConnections = oldstruct->Connections;
          newConnections = newstruct->Connections;
          LOOPi(newstruct->NumberOfUniqueConnections)
               CopyFullBensonAtomConnections(newConnections++, oldConnections++);
          }


}
extern void PrintBensonCalcConnections(BensonCalcConnections *eleptr)
{
INT *ptrValences;
BensonAtomConnections *ptrConnections;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Neighbors:");
     printf("%d\n",eleptr->NumberOfNeighbors);
     printf("The Number of Unique Connections:");
     printf("%d\n",eleptr->NumberOfUniqueConnections);

     printf("The set of Valences of Neighbors:\n");
     if(eleptr->Valences != 0)
          {
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfNeighbors)
               PrintINT(ptrValences++);
          }


     printf("The Set of Connections and Multiplicities:\n");
     if(eleptr->Connections != 0)
          {
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfUniqueConnections)
               PrintBensonAtomConnections(ptrConnections++);
          }


}
extern void FreeBensonCalcConnections(BensonCalcConnections *eleptr)
{
BensonAtomConnections *ptrConnections;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Valences);

     ptrConnections = eleptr->Connections;
     LOOPi(eleptr->NumberOfUniqueConnections)
          FreeBensonAtomConnections(ptrConnections++);
     Free(eleptr->Connections);

}
extern void WriteBinBensonCalcConnections(BensonCalcConnections *eleptr, DbaseLinkedList *file)
{
INT *ptrValences;
BensonAtomConnections *ptrConnections;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfNeighbors),file);
     WriteBinINT(&(eleptr->NumberOfUniqueConnections),file);

     if(eleptr->Valences != 0)
          {
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfNeighbors)
               WriteBinINT(ptrValences++,file);
          }

     if(eleptr->Connections != 0)
          {
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfUniqueConnections)
               WriteBinBensonAtomConnections(ptrConnections++,file);
          }

}
extern INT ReadBinBensonCalcConnections(BensonCalcConnections *eleptr,DbaseLinkedList *file)
     {
INT *ptrValences;
BensonAtomConnections *ptrConnections;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNeighbors),file);
     ReadBinINT(&(eleptr->NumberOfUniqueConnections),file);

          eleptr->Valences = AllocArrayINT(eleptr->NumberOfNeighbors);
          ptrValences = eleptr->Valences;
          LOOPi(eleptr->NumberOfNeighbors)
               ReadBinINT(ptrValences++,file);

          eleptr->Connections = AllocArrayBensonAtomConnections(eleptr->NumberOfUniqueConnections);
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfUniqueConnections)
               ReadBinBensonAtomConnections(ptrConnections++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BensonCalcConnections(XDR *stream, char **eleptrp)
{
     BensonCalcConnections *eleptr;
     eleptr = (BensonCalcConnections *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfNeighbors));
     xdr_INT(stream,(char **) &(eleptr->NumberOfUniqueConnections));

     xdr_array(stream,(char **) &(eleptr->Valences),
             (uint *) &(eleptr->NumberOfNeighbors),eleptr->NumberOfNeighbors,
               INTSize,(xdrproc_t) xdr_INT);
     xdr_array(stream,(char **) &(eleptr->Connections),
             (uint *) &(eleptr->NumberOfUniqueConnections),eleptr->NumberOfUniqueConnections,
               BensonAtomConnectionsSize,(xdrproc_t) xdr_BensonAtomConnections);
}

extern void *AllocBensonCalcConnections()
{
     return((void *) AllocateBensonCalcConnections);
}

extern CHAR *GetNameSetOfBensonCalcConnections(SetOfBensonCalcConnections *str)
{
     return(str->Name);
}

extern INT GetIDSetOfBensonCalcConnections(SetOfBensonCalcConnections *str)
{
     return(str->ID);
}

extern SetOfBensonCalcConnections *CreateSetOfBensonCalcConnections(SetOfBensonCalcConnections *newstruct,
INT id,
CHAR *name,
INT  NumberOfAtoms,
BensonCalcConnections *Connections)
{
BensonCalcConnections *oldConnections,*newConnections;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAtoms = NumberOfAtoms;

     newstruct->Connections = AllocArrayBensonCalcConnections(newstruct->NumberOfAtoms);
     if(Connections != 0)
          {
          oldConnections = Connections;
          newConnections = newstruct->Connections;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullBensonCalcConnections(newConnections++, oldConnections++);
          }



     return(newstruct);
}


extern void CopyFullSetOfBensonCalcConnections(SetOfBensonCalcConnections *newstruct, SetOfBensonCalcConnections *oldstruct)
{
BensonCalcConnections *oldConnections,*newConnections;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAtoms = oldstruct->NumberOfAtoms;


     newstruct->Connections = AllocArrayBensonCalcConnections(newstruct->NumberOfAtoms);
     if(oldstruct->Connections != 0)
          {
          oldConnections = oldstruct->Connections;
          newConnections = newstruct->Connections;
          LOOPi(newstruct->NumberOfAtoms)
               CopyFullBensonCalcConnections(newConnections++, oldConnections++);
          }


}
extern void PrintSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr)
{
BensonCalcConnections *ptrConnections;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of atoms:");
     printf("%d\n",eleptr->NumberOfAtoms);

     printf("The set of Connections for each Atom:\n");
     if(eleptr->Connections != 0)
          {
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfAtoms)
               PrintBensonCalcConnections(ptrConnections++);
          }


}
extern void FreeSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr)
{
BensonCalcConnections *ptrConnections;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrConnections = eleptr->Connections;
     LOOPi(eleptr->NumberOfAtoms)
          FreeBensonCalcConnections(ptrConnections++);
     Free(eleptr->Connections);

}
extern void WriteBinSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr, DbaseLinkedList *file)
{
BensonCalcConnections *ptrConnections;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAtoms),file);

     if(eleptr->Connections != 0)
          {
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfAtoms)
               WriteBinBensonCalcConnections(ptrConnections++,file);
          }

}
extern INT ReadBinSetOfBensonCalcConnections(SetOfBensonCalcConnections *eleptr,DbaseLinkedList *file)
     {
BensonCalcConnections *ptrConnections;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAtoms),file);

          eleptr->Connections = AllocArrayBensonCalcConnections(eleptr->NumberOfAtoms);
          ptrConnections = eleptr->Connections;
          LOOPi(eleptr->NumberOfAtoms)
               ReadBinBensonCalcConnections(ptrConnections++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfBensonCalcConnections(XDR *stream, char **eleptrp)
{
     SetOfBensonCalcConnections *eleptr;
     eleptr = (SetOfBensonCalcConnections *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAtoms));

     xdr_array(stream,(char **) &(eleptr->Connections),
             (uint *) &(eleptr->NumberOfAtoms),eleptr->NumberOfAtoms,
               BensonCalcConnectionsSize,(xdrproc_t) xdr_BensonCalcConnections);
}

extern void *AllocSetOfBensonCalcConnections()
{
     return((void *) AllocateSetOfBensonCalcConnections);
}

extern CHAR *GetNameBensonConnectionTree(BensonConnectionTree *str)
{
     return(str->Name);
}

extern INT GetIDBensonConnectionTree(BensonConnectionTree *str)
{
     return(str->ID);
}

extern BensonConnectionTree *CreateBensonConnectionTree(BensonConnectionTree *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 BensonAtomConnections *Connection,
                                                 BensonSecondThermoTable *ThermoValues,
                                                 INT  NumberOfConnectionCases,
                                                 BensonConnectionTree *Cases)
{
BensonConnectionTree *oldCases,*newCases;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfConnectionCases = NumberOfConnectionCases;
     if(Connection != 0)
          {
          newstruct->Connection = AllocateBensonAtomConnections;
          CopyFullBensonAtomConnections(newstruct->Connection, Connection);
          }
     else
          newstruct->Connection = 0;
     if(ThermoValues != 0)
          {
          newstruct->ThermoValues = AllocateBensonSecondThermoTable;
          CopyFullBensonSecondThermoTable(newstruct->ThermoValues, ThermoValues);
          }
     else
          newstruct->ThermoValues = 0;

     newstruct->Cases = AllocArrayBensonConnectionTree(newstruct->NumberOfConnectionCases);
     if(Cases != 0)
          {
          oldCases = Cases;
          newCases = newstruct->Cases;
          LOOPi(newstruct->NumberOfConnectionCases)
               CopyFullBensonConnectionTree(newCases++, oldCases++);
          }



     return(newstruct);
}


extern void CopyFullBensonConnectionTree(BensonConnectionTree *newstruct, BensonConnectionTree *oldstruct)
{
BensonConnectionTree *oldCases,*newCases;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfConnectionCases = oldstruct->NumberOfConnectionCases;

     if(oldstruct->Connection != 0)
          {
          newstruct->Connection = AllocateBensonAtomConnections;
          CopyFullBensonAtomConnections(newstruct->Connection, oldstruct->Connection);
          }
     else
          newstruct->Connection = 0;
     if(oldstruct->ThermoValues != 0)
          {
          newstruct->ThermoValues = AllocateBensonSecondThermoTable;
          CopyFullBensonSecondThermoTable(newstruct->ThermoValues, oldstruct->ThermoValues);
          }
     else
          newstruct->ThermoValues = 0;

     newstruct->Cases = AllocArrayBensonConnectionTree(newstruct->NumberOfConnectionCases);
     if(oldstruct->Cases != 0)
          {
          oldCases = oldstruct->Cases;
          newCases = newstruct->Cases;
          LOOPi(newstruct->NumberOfConnectionCases)
               CopyFullBensonConnectionTree(newCases++, oldCases++);
          }


}
extern void PrintBensonConnectionTree(BensonConnectionTree *eleptr)
{
BensonConnectionTree *ptrCases;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Further Connection Cases:");
     printf("%d\n",eleptr->NumberOfConnectionCases);

     printf("The Connection Valence and Multiplicity (Zero if the first one after Central atom):\n");
     PrintBensonAtomConnections(eleptr->Connection);

     printf("If Finished, the thermodynamic values:\n");
     PrintBensonSecondThermoTable(eleptr->ThermoValues);

     printf("The further Connection Cases:\n");
     if(eleptr->Cases != 0)
          {
          ptrCases = eleptr->Cases;
          LOOPi(eleptr->NumberOfConnectionCases)
               PrintBensonConnectionTree(ptrCases++);
          }


}
extern void FreeBensonConnectionTree(BensonConnectionTree *eleptr)
{
BensonConnectionTree *ptrCases;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrCases = eleptr->Cases;
     LOOPi(eleptr->NumberOfConnectionCases)
          FreeBensonConnectionTree(ptrCases++);
     Free(eleptr->Cases);

     FreeBensonAtomConnections(eleptr->Connection);
     Free(eleptr->Connection);

     FreeBensonSecondThermoTable(eleptr->ThermoValues);
     Free(eleptr->ThermoValues);

}
extern void WriteBinBensonConnectionTree(BensonConnectionTree *eleptr, DbaseLinkedList *file)
{
BensonConnectionTree *ptrCases;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfConnectionCases),file);

     WriteBinBensonAtomConnections(eleptr->Connection,file);

     WriteBinBensonSecondThermoTable(eleptr->ThermoValues,file);

     if(eleptr->Cases != 0)
          {
          ptrCases = eleptr->Cases;
          LOOPi(eleptr->NumberOfConnectionCases)
               WriteBinBensonConnectionTree(ptrCases++,file);
          }

}
extern INT ReadBinBensonConnectionTree(BensonConnectionTree *eleptr,DbaseLinkedList *file)
     {
BensonConnectionTree *ptrCases;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfConnectionCases),file);

     eleptr->Connection = AllocateBensonAtomConnections;
     if(ReadBinBensonAtomConnections(eleptr->Connection,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Connection);
           eleptr->Connection = 0;
           }

     eleptr->ThermoValues = AllocateBensonSecondThermoTable;
     if(ReadBinBensonSecondThermoTable(eleptr->ThermoValues,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->ThermoValues);
           eleptr->ThermoValues = 0;
           }

          eleptr->Cases = AllocArrayBensonConnectionTree(eleptr->NumberOfConnectionCases);
          ptrCases = eleptr->Cases;
          LOOPi(eleptr->NumberOfConnectionCases)
               ReadBinBensonConnectionTree(ptrCases++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BensonConnectionTree(XDR *stream, char **eleptrp)
{
     BensonConnectionTree *eleptr;
     eleptr = (BensonConnectionTree *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfConnectionCases));

     xdr_pointer(stream,
          (char **) &(eleptr->Connection),
          BensonAtomConnectionsSize,
                 (xdrproc_t) xdr_BensonAtomConnections);
     xdr_pointer(stream,
          (char **) &(eleptr->ThermoValues),
          BensonSecondThermoTableSize,
                 (xdrproc_t) xdr_BensonSecondThermoTable);
     xdr_array(stream,(char **) &(eleptr->Cases),
             (uint *) &(eleptr->NumberOfConnectionCases),eleptr->NumberOfConnectionCases,
               BensonConnectionTreeSize,(xdrproc_t) xdr_BensonConnectionTree);
}

extern void *AllocBensonConnectionTree()
{
     return((void *) AllocateBensonConnectionTree);
}

extern CHAR *GetNameCentralAtomBranch(CentralAtomBranch *str)
{
     return(str->Name);
}

extern INT GetIDCentralAtomBranch(CentralAtomBranch *str)
{
     return(str->ID);
}

extern CentralAtomBranch *CreateCentralAtomBranch(CentralAtomBranch *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  CentralAtomValence,
                                           BensonConnectionTree *Tree)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->CentralAtomValence = CentralAtomValence;
     if(Tree != 0)
          {
          newstruct->Tree = AllocateBensonConnectionTree;
          CopyFullBensonConnectionTree(newstruct->Tree, Tree);
          }
     else
          newstruct->Tree = 0;



     return(newstruct);
}


extern void CopyFullCentralAtomBranch(CentralAtomBranch *newstruct, CentralAtomBranch *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->CentralAtomValence = oldstruct->CentralAtomValence;

     if(oldstruct->Tree != 0)
          {
          newstruct->Tree = AllocateBensonConnectionTree;
          CopyFullBensonConnectionTree(newstruct->Tree, oldstruct->Tree);
          }
     else
          newstruct->Tree = 0;


}
extern void PrintCentralAtomBranch(CentralAtomBranch *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Central Atom Valence:");
     printf("%d\n",eleptr->CentralAtomValence);

     printf(" The Connection Tree:\n");
     PrintBensonConnectionTree(eleptr->Tree);

}
extern void FreeCentralAtomBranch(CentralAtomBranch *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeBensonConnectionTree(eleptr->Tree);
     Free(eleptr->Tree);

}
extern void WriteBinCentralAtomBranch(CentralAtomBranch *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->CentralAtomValence),file);

     WriteBinBensonConnectionTree(eleptr->Tree,file);

}
extern INT ReadBinCentralAtomBranch(CentralAtomBranch *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->CentralAtomValence),file);

     eleptr->Tree = AllocateBensonConnectionTree;
     if(ReadBinBensonConnectionTree(eleptr->Tree,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Tree);
           eleptr->Tree = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_CentralAtomBranch(XDR *stream, char **eleptrp)
{
     CentralAtomBranch *eleptr;
     eleptr = (CentralAtomBranch *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->CentralAtomValence));

     xdr_pointer(stream,
          (char **) &(eleptr->Tree),
          BensonConnectionTreeSize,
                 (xdrproc_t) xdr_BensonConnectionTree);
}

extern void *AllocCentralAtomBranch()
{
     return((void *) AllocateCentralAtomBranch);
}

extern CHAR *GetNameSecondOrderBensonTree(SecondOrderBensonTree *str)
{
     return(str->Name);
}

extern INT GetIDSecondOrderBensonTree(SecondOrderBensonTree *str)
{
     return(str->ID);
}

extern SecondOrderBensonTree *CreateSecondOrderBensonTree(SecondOrderBensonTree *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfCentralAtomTypes,
                                                   CentralAtomBranch *CentralAtomTree)
{
CentralAtomBranch *oldCentralAtomTree,*newCentralAtomTree;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfCentralAtomTypes = NumberOfCentralAtomTypes;

     newstruct->CentralAtomTree = AllocArrayCentralAtomBranch(newstruct->NumberOfCentralAtomTypes);
     if(CentralAtomTree != 0)
          {
          oldCentralAtomTree = CentralAtomTree;
          newCentralAtomTree = newstruct->CentralAtomTree;
          LOOPi(newstruct->NumberOfCentralAtomTypes)
               CopyFullCentralAtomBranch(newCentralAtomTree++, oldCentralAtomTree++);
          }



     return(newstruct);
}


extern void CopyFullSecondOrderBensonTree(SecondOrderBensonTree *newstruct, SecondOrderBensonTree *oldstruct)
{
CentralAtomBranch *oldCentralAtomTree,*newCentralAtomTree;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfCentralAtomTypes = oldstruct->NumberOfCentralAtomTypes;


     newstruct->CentralAtomTree = AllocArrayCentralAtomBranch(newstruct->NumberOfCentralAtomTypes);
     if(oldstruct->CentralAtomTree != 0)
          {
          oldCentralAtomTree = oldstruct->CentralAtomTree;
          newCentralAtomTree = newstruct->CentralAtomTree;
          LOOPi(newstruct->NumberOfCentralAtomTypes)
               CopyFullCentralAtomBranch(newCentralAtomTree++, oldCentralAtomTree++);
          }


}
extern void PrintSecondOrderBensonTree(SecondOrderBensonTree *eleptr)
{
CentralAtomBranch *ptrCentralAtomTree;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number of Central Atom Types:");
     printf("%d\n",eleptr->NumberOfCentralAtomTypes);

     printf("The Central Atom Tree:\n");
     if(eleptr->CentralAtomTree != 0)
          {
          ptrCentralAtomTree = eleptr->CentralAtomTree;
          LOOPi(eleptr->NumberOfCentralAtomTypes)
               PrintCentralAtomBranch(ptrCentralAtomTree++);
          }


}
extern void FreeSecondOrderBensonTree(SecondOrderBensonTree *eleptr)
{
CentralAtomBranch *ptrCentralAtomTree;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrCentralAtomTree = eleptr->CentralAtomTree;
     LOOPi(eleptr->NumberOfCentralAtomTypes)
          FreeCentralAtomBranch(ptrCentralAtomTree++);
     Free(eleptr->CentralAtomTree);

}
extern void WriteBinSecondOrderBensonTree(SecondOrderBensonTree *eleptr, DbaseLinkedList *file)
{
CentralAtomBranch *ptrCentralAtomTree;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfCentralAtomTypes),file);

     if(eleptr->CentralAtomTree != 0)
          {
          ptrCentralAtomTree = eleptr->CentralAtomTree;
          LOOPi(eleptr->NumberOfCentralAtomTypes)
               WriteBinCentralAtomBranch(ptrCentralAtomTree++,file);
          }

}
extern INT ReadBinSecondOrderBensonTree(SecondOrderBensonTree *eleptr,DbaseLinkedList *file)
     {
CentralAtomBranch *ptrCentralAtomTree;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfCentralAtomTypes),file);

          eleptr->CentralAtomTree = AllocArrayCentralAtomBranch(eleptr->NumberOfCentralAtomTypes);
          ptrCentralAtomTree = eleptr->CentralAtomTree;
          LOOPi(eleptr->NumberOfCentralAtomTypes)
               ReadBinCentralAtomBranch(ptrCentralAtomTree++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SecondOrderBensonTree(XDR *stream, char **eleptrp)
{
     SecondOrderBensonTree *eleptr;
     eleptr = (SecondOrderBensonTree *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfCentralAtomTypes));

     xdr_array(stream,(char **) &(eleptr->CentralAtomTree),
             (uint *) &(eleptr->NumberOfCentralAtomTypes),eleptr->NumberOfCentralAtomTypes,
               CentralAtomBranchSize,(xdrproc_t) xdr_CentralAtomBranch);
}

extern void *AllocSecondOrderBensonTree()
{
     return((void *) AllocateSecondOrderBensonTree);
}

extern CHAR *GetNameBensonCalculation(BensonCalculation *str)
{
     return(str->Name);
}

extern INT GetIDBensonCalculation(BensonCalculation *str)
{
     return(str->ID);
}

extern BensonCalculation *CreateBensonCalculation(BensonCalculation *newstruct,
                                           INT id,
                                           CHAR *name,
                                           SecondOrderBensonTree *SecondOrderTree,
                                           INT  NumberOfTemperatures)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfTemperatures = NumberOfTemperatures;
     if(SecondOrderTree != 0)
          {
          newstruct->SecondOrderTree = AllocateSecondOrderBensonTree;
          CopyFullSecondOrderBensonTree(newstruct->SecondOrderTree, SecondOrderTree);
          }
     else
          newstruct->SecondOrderTree = 0;



     return(newstruct);
}


extern void CopyFullBensonCalculation(BensonCalculation *newstruct, BensonCalculation *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfTemperatures = oldstruct->NumberOfTemperatures;

     if(oldstruct->SecondOrderTree != 0)
          {
          newstruct->SecondOrderTree = AllocateSecondOrderBensonTree;
          CopyFullSecondOrderBensonTree(newstruct->SecondOrderTree, oldstruct->SecondOrderTree);
          }
     else
          newstruct->SecondOrderTree = 0;


}
extern void PrintBensonCalculation(BensonCalculation *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of temperatures for the Heat Capactities:");
     printf("%d\n",eleptr->NumberOfTemperatures);

     printf("The Second Order Central Atom Tree:\n");
     PrintSecondOrderBensonTree(eleptr->SecondOrderTree);

}
extern void FreeBensonCalculation(BensonCalculation *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSecondOrderBensonTree(eleptr->SecondOrderTree);
     Free(eleptr->SecondOrderTree);

}
extern void WriteBinBensonCalculation(BensonCalculation *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfTemperatures),file);

     WriteBinSecondOrderBensonTree(eleptr->SecondOrderTree,file);

}
extern INT ReadBinBensonCalculation(BensonCalculation *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfTemperatures),file);

     eleptr->SecondOrderTree = AllocateSecondOrderBensonTree;
     if(ReadBinSecondOrderBensonTree(eleptr->SecondOrderTree,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->SecondOrderTree);
           eleptr->SecondOrderTree = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BensonCalculation(XDR *stream, char **eleptrp)
{
     BensonCalculation *eleptr;
     eleptr = (BensonCalculation *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfTemperatures));

     xdr_pointer(stream,
          (char **) &(eleptr->SecondOrderTree),
          SecondOrderBensonTreeSize,
                 (xdrproc_t) xdr_SecondOrderBensonTree);
}

extern void *AllocBensonCalculation()
{
     return((void *) AllocateBensonCalculation);
}
