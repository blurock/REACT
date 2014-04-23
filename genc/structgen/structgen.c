
extern CHAR *GetNameStructuralElement(StructuralElement *str)
{
     return(str->Name);
}

extern INT GetIDStructuralElement(StructuralElement *str)
{
     return(str->ID);
}

extern StructuralElement *CreateStructuralElement(StructuralElement *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  Minimum,
                                           INT  Maximum,
                                           INT  Priority)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Minimum = Minimum;
     newstruct->Maximum = Maximum;
     newstruct->Priority = Priority;



     return(newstruct);
}


extern void CopyFullStructuralElement(StructuralElement *newstruct, StructuralElement *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Minimum = oldstruct->Minimum;
     newstruct->Maximum = oldstruct->Maximum;
     newstruct->Priority = oldstruct->Priority;



}
extern void PrintStructuralElement(StructuralElement *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The minimum number of times to appear:");
     printf("%d\n",eleptr->Minimum);
     printf("The maximum number of times to appear:");
     printf("%d\n",eleptr->Maximum);
     printf("        The priority:");
     printf("%d\n",eleptr->Priority);

}
extern void FreeStructuralElement(StructuralElement *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinStructuralElement(StructuralElement *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Minimum),file);
     WriteBinINT(&(eleptr->Maximum),file);
     WriteBinINT(&(eleptr->Priority),file);

}
extern INT ReadBinStructuralElement(StructuralElement *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Minimum),file);
     ReadBinINT(&(eleptr->Maximum),file);
     ReadBinINT(&(eleptr->Priority),file);

     return(STRUCTURE_READ);
     }
extern void xdr_StructuralElement(XDR *stream, char **eleptrp)
{
     StructuralElement *eleptr;
     eleptr = (StructuralElement *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Minimum));
     xdr_INT(stream,(char **) &(eleptr->Maximum));
     xdr_INT(stream,(char **) &(eleptr->Priority));

}

extern void *AllocStructuralElement()
{
     return((void *) AllocateStructuralElement);
}

extern CHAR *GetNameMoleculeStructureSpecification(MoleculeStructureSpecification *str)
{
     return(str->Name);
}

extern INT GetIDMoleculeStructureSpecification(MoleculeStructureSpecification *str)
{
     return(str->ID);
}

extern MoleculeStructureSpecification *CreateMoleculeStructureSpecification(MoleculeStructureSpecification *newstruct,
INT id,
CHAR *name,
INT  NumberOfElements,
StructuralElement *StructuralElements)
{
StructuralElement *oldStructuralElements,*newStructuralElements;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfElements = NumberOfElements;

     newstruct->StructuralElements = AllocArrayStructuralElement(newstruct->NumberOfElements);
     if(StructuralElements != 0)
          {
          oldStructuralElements = StructuralElements;
          newStructuralElements = newstruct->StructuralElements;
          LOOPi(newstruct->NumberOfElements)
               CopyFullStructuralElement(newStructuralElements++, oldStructuralElements++);
          }



     return(newstruct);
}


extern void CopyFullMoleculeStructureSpecification(MoleculeStructureSpecification *newstruct, MoleculeStructureSpecification *oldstruct)
{
StructuralElement *oldStructuralElements,*newStructuralElements;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfElements = oldstruct->NumberOfElements;


     newstruct->StructuralElements = AllocArrayStructuralElement(newstruct->NumberOfElements);
     if(oldstruct->StructuralElements != 0)
          {
          oldStructuralElements = oldstruct->StructuralElements;
          newStructuralElements = newstruct->StructuralElements;
          LOOPi(newstruct->NumberOfElements)
               CopyFullStructuralElement(newStructuralElements++, oldStructuralElements++);
          }


}
extern void PrintMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr)
{
StructuralElement *ptrStructuralElements;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of structural elements:");
     printf("%d\n",eleptr->NumberOfElements);

     printf("The array of structural elements:\n");
     if(eleptr->StructuralElements != 0)
          {
          ptrStructuralElements = eleptr->StructuralElements;
          LOOPi(eleptr->NumberOfElements)
               PrintStructuralElement(ptrStructuralElements++);
          }


}
extern void FreeMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr)
{
StructuralElement *ptrStructuralElements;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrStructuralElements = eleptr->StructuralElements;
     LOOPi(eleptr->NumberOfElements)
          FreeStructuralElement(ptrStructuralElements++);
     Free(eleptr->StructuralElements);

}
extern void WriteBinMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr, DbaseLinkedList *file)
{
StructuralElement *ptrStructuralElements;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfElements),file);

     if(eleptr->StructuralElements != 0)
          {
          ptrStructuralElements = eleptr->StructuralElements;
          LOOPi(eleptr->NumberOfElements)
               WriteBinStructuralElement(ptrStructuralElements++,file);
          }

}
extern INT ReadBinMoleculeStructureSpecification(MoleculeStructureSpecification *eleptr,DbaseLinkedList *file)
     {
StructuralElement *ptrStructuralElements;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfElements),file);

          eleptr->StructuralElements = AllocArrayStructuralElement(eleptr->NumberOfElements);
          ptrStructuralElements = eleptr->StructuralElements;
          LOOPi(eleptr->NumberOfElements)
               ReadBinStructuralElement(ptrStructuralElements++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_MoleculeStructureSpecification(XDR *stream, char **eleptrp)
{
     MoleculeStructureSpecification *eleptr;
     eleptr = (MoleculeStructureSpecification *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfElements));

     xdr_array(stream,(char **) &(eleptr->StructuralElements),
             (uint *) &(eleptr->NumberOfElements),eleptr->NumberOfElements,
               StructuralElementSize,(xdrproc_t) xdr_StructuralElement);
}

extern void *AllocMoleculeStructureSpecification()
{
     return((void *) AllocateMoleculeStructureSpecification);
}

extern CHAR *GetNameFullStructuralElement(FullStructuralElement *str)
{
     return(str->Name);
}

extern INT GetIDFullStructuralElement(FullStructuralElement *str)
{
     return(str->ID);
}

extern FullStructuralElement *CreateFullStructuralElement(FullStructuralElement *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   StructuralElement *Info,
                                                   MoleculeInfo *Molecule,
                                                   Graph *MoleculeGraph,
                                                   DataSubSet *Connections)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Info != 0)
          {
          newstruct->Info = AllocateStructuralElement;
          CopyFullStructuralElement(newstruct->Info, Info);
          }
     else
          newstruct->Info = 0;
     if(Molecule != 0)
          {
          newstruct->Molecule = AllocateMoleculeInfo;
          CopyFullMoleculeInfo(newstruct->Molecule, Molecule);
          }
     else
          newstruct->Molecule = 0;
     if(MoleculeGraph != 0)
          {
          newstruct->MoleculeGraph = AllocateGraph;
          CopyFullGraph(newstruct->MoleculeGraph, MoleculeGraph);
          }
     else
          newstruct->MoleculeGraph = 0;
     if(Connections != 0)
          {
          newstruct->Connections = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Connections, Connections);
          }
     else
          newstruct->Connections = 0;



     return(newstruct);
}


extern void CopyFullFullStructuralElement(FullStructuralElement *newstruct, FullStructuralElement *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Info != 0)
          {
          newstruct->Info = AllocateStructuralElement;
          CopyFullStructuralElement(newstruct->Info, oldstruct->Info);
          }
     else
          newstruct->Info = 0;
     if(oldstruct->Molecule != 0)
          {
          newstruct->Molecule = AllocateMoleculeInfo;
          CopyFullMoleculeInfo(newstruct->Molecule, oldstruct->Molecule);
          }
     else
          newstruct->Molecule = 0;
     if(oldstruct->MoleculeGraph != 0)
          {
          newstruct->MoleculeGraph = AllocateGraph;
          CopyFullGraph(newstruct->MoleculeGraph, oldstruct->MoleculeGraph);
          }
     else
          newstruct->MoleculeGraph = 0;
     if(oldstruct->Connections != 0)
          {
          newstruct->Connections = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Connections, oldstruct->Connections);
          }
     else
          newstruct->Connections = 0;


}
extern void PrintFullStructuralElement(FullStructuralElement *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Basic Structural information:\n");
     PrintStructuralElement(eleptr->Info);

     printf("The Molecule information:\n");
     PrintMoleculeInfo(eleptr->Molecule);

     printf("The Molecule as Graph:\n");
     PrintGraph(eleptr->MoleculeGraph);

     printf("The connections that can be made (relative to graph):\n");
     PrintDataSubSet(eleptr->Connections);

}
extern void FreeFullStructuralElement(FullStructuralElement *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeStructuralElement(eleptr->Info);
     Free(eleptr->Info);

     FreeMoleculeInfo(eleptr->Molecule);
     Free(eleptr->Molecule);

     FreeGraph(eleptr->MoleculeGraph);
     Free(eleptr->MoleculeGraph);

     FreeDataSubSet(eleptr->Connections);
     Free(eleptr->Connections);

}
extern void WriteBinFullStructuralElement(FullStructuralElement *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinStructuralElement(eleptr->Info,file);

     WriteBinMoleculeInfo(eleptr->Molecule,file);

     WriteBinGraph(eleptr->MoleculeGraph,file);

     WriteBinDataSubSet(eleptr->Connections,file);

}
extern INT ReadBinFullStructuralElement(FullStructuralElement *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Info = AllocateStructuralElement;
     if(ReadBinStructuralElement(eleptr->Info,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Info);
           eleptr->Info = 0;
           }

     eleptr->Molecule = AllocateMoleculeInfo;
     if(ReadBinMoleculeInfo(eleptr->Molecule,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Molecule);
           eleptr->Molecule = 0;
           }

     eleptr->MoleculeGraph = AllocateGraph;
     if(ReadBinGraph(eleptr->MoleculeGraph,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->MoleculeGraph);
           eleptr->MoleculeGraph = 0;
           }

     eleptr->Connections = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Connections,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Connections);
           eleptr->Connections = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_FullStructuralElement(XDR *stream, char **eleptrp)
{
     FullStructuralElement *eleptr;
     eleptr = (FullStructuralElement *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Info),
          StructuralElementSize,
                 (xdrproc_t) xdr_StructuralElement);
     xdr_pointer(stream,
          (char **) &(eleptr->Molecule),
          MoleculeInfoSize,
                 (xdrproc_t) xdr_MoleculeInfo);
     xdr_pointer(stream,
          (char **) &(eleptr->MoleculeGraph),
          GraphSize,
                 (xdrproc_t) xdr_Graph);
     xdr_pointer(stream,
          (char **) &(eleptr->Connections),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
}

extern void *AllocFullStructuralElement()
{
     return((void *) AllocateFullStructuralElement);
}

extern CHAR *GetNameFullMoleculeSpecification(FullMoleculeSpecification *str)
{
     return(str->Name);
}

extern INT GetIDFullMoleculeSpecification(FullMoleculeSpecification *str)
{
     return(str->ID);
}

extern FullMoleculeSpecification *CreateFullMoleculeSpecification(FullMoleculeSpecification *newstruct,
INT id,
CHAR *name,
INT  NumberOfElements,
FullStructuralElement *FullStructuralElements,
DataSubSet *PrioritySets)
{
FullStructuralElement *oldFullStructuralElements,*newFullStructuralElements;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfElements = NumberOfElements;
     if(PrioritySets != 0)
          {
          newstruct->PrioritySets = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->PrioritySets, PrioritySets);
          }
     else
          newstruct->PrioritySets = 0;

     newstruct->FullStructuralElements = AllocArrayFullStructuralElement(newstruct->NumberOfElements);
     if(FullStructuralElements != 0)
          {
          oldFullStructuralElements = FullStructuralElements;
          newFullStructuralElements = newstruct->FullStructuralElements;
          LOOPi(newstruct->NumberOfElements)
               CopyFullFullStructuralElement(newFullStructuralElements++, oldFullStructuralElements++);
          }



     return(newstruct);
}


extern void CopyFullFullMoleculeSpecification(FullMoleculeSpecification *newstruct, FullMoleculeSpecification *oldstruct)
{
FullStructuralElement *oldFullStructuralElements,*newFullStructuralElements;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfElements = oldstruct->NumberOfElements;

     if(oldstruct->PrioritySets != 0)
          {
          newstruct->PrioritySets = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->PrioritySets, oldstruct->PrioritySets);
          }
     else
          newstruct->PrioritySets = 0;

     newstruct->FullStructuralElements = AllocArrayFullStructuralElement(newstruct->NumberOfElements);
     if(oldstruct->FullStructuralElements != 0)
          {
          oldFullStructuralElements = oldstruct->FullStructuralElements;
          newFullStructuralElements = newstruct->FullStructuralElements;
          LOOPi(newstruct->NumberOfElements)
               CopyFullFullStructuralElement(newFullStructuralElements++, oldFullStructuralElements++);
          }


}
extern void PrintFullMoleculeSpecification(FullMoleculeSpecification *eleptr)
{
FullStructuralElement *ptrFullStructuralElements;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of structural elements:");
     printf("%d\n",eleptr->NumberOfElements);

     printf("The Priority Set Values:\n");
     PrintDataSubSet(eleptr->PrioritySets);

     printf("The array of structural elements:\n");
     if(eleptr->FullStructuralElements != 0)
          {
          ptrFullStructuralElements = eleptr->FullStructuralElements;
          LOOPi(eleptr->NumberOfElements)
               PrintFullStructuralElement(ptrFullStructuralElements++);
          }


}
extern void FreeFullMoleculeSpecification(FullMoleculeSpecification *eleptr)
{
FullStructuralElement *ptrFullStructuralElements;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrFullStructuralElements = eleptr->FullStructuralElements;
     LOOPi(eleptr->NumberOfElements)
          FreeFullStructuralElement(ptrFullStructuralElements++);
     Free(eleptr->FullStructuralElements);

     FreeDataSubSet(eleptr->PrioritySets);
     Free(eleptr->PrioritySets);

}
extern void WriteBinFullMoleculeSpecification(FullMoleculeSpecification *eleptr, DbaseLinkedList *file)
{
FullStructuralElement *ptrFullStructuralElements;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfElements),file);

     WriteBinDataSubSet(eleptr->PrioritySets,file);

     if(eleptr->FullStructuralElements != 0)
          {
          ptrFullStructuralElements = eleptr->FullStructuralElements;
          LOOPi(eleptr->NumberOfElements)
               WriteBinFullStructuralElement(ptrFullStructuralElements++,file);
          }

}
extern INT ReadBinFullMoleculeSpecification(FullMoleculeSpecification *eleptr,DbaseLinkedList *file)
     {
FullStructuralElement *ptrFullStructuralElements;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfElements),file);

     eleptr->PrioritySets = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->PrioritySets,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->PrioritySets);
           eleptr->PrioritySets = 0;
           }

          eleptr->FullStructuralElements = AllocArrayFullStructuralElement(eleptr->NumberOfElements);
          ptrFullStructuralElements = eleptr->FullStructuralElements;
          LOOPi(eleptr->NumberOfElements)
               ReadBinFullStructuralElement(ptrFullStructuralElements++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_FullMoleculeSpecification(XDR *stream, char **eleptrp)
{
     FullMoleculeSpecification *eleptr;
     eleptr = (FullMoleculeSpecification *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfElements));

     xdr_pointer(stream,
          (char **) &(eleptr->PrioritySets),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_array(stream,(char **) &(eleptr->FullStructuralElements),
             (uint *) &(eleptr->NumberOfElements),eleptr->NumberOfElements,
               FullStructuralElementSize,(xdrproc_t) xdr_FullStructuralElement);
}

extern void *AllocFullMoleculeSpecification()
{
     return((void *) AllocateFullMoleculeSpecification);
}

extern CHAR *GetNameGenerateStructureMaster(GenerateStructureMaster *str)
{
     return(str->Name);
}

extern INT GetIDGenerateStructureMaster(GenerateStructureMaster *str)
{
     return(str->ID);
}

extern GenerateStructureMaster *CreateGenerateStructureMaster(GenerateStructureMaster *newstruct,
INT id,
CHAR *name,
MoleculeStructureSpecification *BasicSpecification,
FullMoleculeSpecification *FullSpecification)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(BasicSpecification != 0)
          {
          newstruct->BasicSpecification = AllocateMoleculeStructureSpecification;
          CopyFullMoleculeStructureSpecification(newstruct->BasicSpecification, BasicSpecification);
          }
     else
          newstruct->BasicSpecification = 0;
     if(FullSpecification != 0)
          {
          newstruct->FullSpecification = AllocateFullMoleculeSpecification;
          CopyFullFullMoleculeSpecification(newstruct->FullSpecification, FullSpecification);
          }
     else
          newstruct->FullSpecification = 0;



     return(newstruct);
}


extern void CopyFullGenerateStructureMaster(GenerateStructureMaster *newstruct, GenerateStructureMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->BasicSpecification != 0)
          {
          newstruct->BasicSpecification = AllocateMoleculeStructureSpecification;
          CopyFullMoleculeStructureSpecification(newstruct->BasicSpecification, oldstruct->BasicSpecification);
          }
     else
          newstruct->BasicSpecification = 0;
     if(oldstruct->FullSpecification != 0)
          {
          newstruct->FullSpecification = AllocateFullMoleculeSpecification;
          CopyFullFullMoleculeSpecification(newstruct->FullSpecification, oldstruct->FullSpecification);
          }
     else
          newstruct->FullSpecification = 0;


}
extern void PrintGenerateStructureMaster(GenerateStructureMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Basic Structure Specification:\n");
     PrintMoleculeStructureSpecification(eleptr->BasicSpecification);

     printf("The Full Filled Specification for molecule generation:\n");
     PrintFullMoleculeSpecification(eleptr->FullSpecification);

}
extern void FreeGenerateStructureMaster(GenerateStructureMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeMoleculeStructureSpecification(eleptr->BasicSpecification);
     Free(eleptr->BasicSpecification);

     FreeFullMoleculeSpecification(eleptr->FullSpecification);
     Free(eleptr->FullSpecification);

}
extern void WriteBinGenerateStructureMaster(GenerateStructureMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinMoleculeStructureSpecification(eleptr->BasicSpecification,file);

     WriteBinFullMoleculeSpecification(eleptr->FullSpecification,file);

}
extern INT ReadBinGenerateStructureMaster(GenerateStructureMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->BasicSpecification = AllocateMoleculeStructureSpecification;
     if(ReadBinMoleculeStructureSpecification(eleptr->BasicSpecification,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->BasicSpecification);
           eleptr->BasicSpecification = 0;
           }

     eleptr->FullSpecification = AllocateFullMoleculeSpecification;
     if(ReadBinFullMoleculeSpecification(eleptr->FullSpecification,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->FullSpecification);
           eleptr->FullSpecification = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_GenerateStructureMaster(XDR *stream, char **eleptrp)
{
     GenerateStructureMaster *eleptr;
     eleptr = (GenerateStructureMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->BasicSpecification),
          MoleculeStructureSpecificationSize,
                 (xdrproc_t) xdr_MoleculeStructureSpecification);
     xdr_pointer(stream,
          (char **) &(eleptr->FullSpecification),
          FullMoleculeSpecificationSize,
                 (xdrproc_t) xdr_FullMoleculeSpecification);
}

extern void *AllocGenerateStructureMaster()
{
     return((void *) AllocateGenerateStructureMaster);
}

extern CHAR *GetNameCurrentStructure(CurrentStructure *str)
{
     return(str->Name);
}

extern INT GetIDCurrentStructure(CurrentStructure *str)
{
     return(str->ID);
}

extern CurrentStructure *CreateCurrentStructure(CurrentStructure *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  Completed,
                                         Graph *Structure,
                                         DataSubSet *Attachments)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Completed = Completed;
     if(Structure != 0)
          {
          newstruct->Structure = AllocateGraph;
          CopyFullGraph(newstruct->Structure, Structure);
          }
     else
          newstruct->Structure = 0;
     if(Attachments != 0)
          {
          newstruct->Attachments = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Attachments, Attachments);
          }
     else
          newstruct->Attachments = 0;



     return(newstruct);
}


extern void CopyFullCurrentStructure(CurrentStructure *newstruct, CurrentStructure *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Completed = oldstruct->Completed;

     if(oldstruct->Structure != 0)
          {
          newstruct->Structure = AllocateGraph;
          CopyFullGraph(newstruct->Structure, oldstruct->Structure);
          }
     else
          newstruct->Structure = 0;
     if(oldstruct->Attachments != 0)
          {
          newstruct->Attachments = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Attachments, oldstruct->Attachments);
          }
     else
          newstruct->Attachments = 0;


}
extern void PrintCurrentStructure(CurrentStructure *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("1 if the structure is completed, 0 otherwise:");
     printf("%d\n",eleptr->Completed);

     printf("The structure as a Graph:\n");
     PrintGraph(eleptr->Structure);

     printf("The list of nodes that are open for attachments:\n");
     PrintDataSubSet(eleptr->Attachments);

}
extern void FreeCurrentStructure(CurrentStructure *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeGraph(eleptr->Structure);
     Free(eleptr->Structure);

     FreeDataSubSet(eleptr->Attachments);
     Free(eleptr->Attachments);

}
extern void WriteBinCurrentStructure(CurrentStructure *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Completed),file);

     WriteBinGraph(eleptr->Structure,file);

     WriteBinDataSubSet(eleptr->Attachments,file);

}
extern INT ReadBinCurrentStructure(CurrentStructure *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Completed),file);

     eleptr->Structure = AllocateGraph;
     if(ReadBinGraph(eleptr->Structure,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Structure);
           eleptr->Structure = 0;
           }

     eleptr->Attachments = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Attachments,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Attachments);
           eleptr->Attachments = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_CurrentStructure(XDR *stream, char **eleptrp)
{
     CurrentStructure *eleptr;
     eleptr = (CurrentStructure *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Completed));

     xdr_pointer(stream,
          (char **) &(eleptr->Structure),
          GraphSize,
                 (xdrproc_t) xdr_Graph);
     xdr_pointer(stream,
          (char **) &(eleptr->Attachments),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
}

extern void *AllocCurrentStructure()
{
     return((void *) AllocateCurrentStructure);
}

extern CHAR *GetNameAttachmentRemoved(AttachmentRemoved *str)
{
     return(str->Name);
}

extern INT GetIDAttachmentRemoved(AttachmentRemoved *str)
{
     return(str->ID);
}

extern AttachmentRemoved *CreateAttachmentRemoved(AttachmentRemoved *newstruct,
                                           INT id,
                                           CHAR *name,
                                           Graph *Structure,
                                           INT  Attachment)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Attachment = Attachment;
     if(Structure != 0)
          {
          newstruct->Structure = AllocateGraph;
          CopyFullGraph(newstruct->Structure, Structure);
          }
     else
          newstruct->Structure = 0;



     return(newstruct);
}


extern void CopyFullAttachmentRemoved(AttachmentRemoved *newstruct, AttachmentRemoved *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Attachment = oldstruct->Attachment;

     if(oldstruct->Structure != 0)
          {
          newstruct->Structure = AllocateGraph;
          CopyFullGraph(newstruct->Structure, oldstruct->Structure);
          }
     else
          newstruct->Structure = 0;


}
extern void PrintAttachmentRemoved(AttachmentRemoved *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The new point of attachment:");
     printf("%d\n",eleptr->Attachment);

     printf("The new graph with no attachment:\n");
     PrintGraph(eleptr->Structure);

}
extern void FreeAttachmentRemoved(AttachmentRemoved *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeGraph(eleptr->Structure);
     Free(eleptr->Structure);

}
extern void WriteBinAttachmentRemoved(AttachmentRemoved *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Attachment),file);

     WriteBinGraph(eleptr->Structure,file);

}
extern INT ReadBinAttachmentRemoved(AttachmentRemoved *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Attachment),file);

     eleptr->Structure = AllocateGraph;
     if(ReadBinGraph(eleptr->Structure,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Structure);
           eleptr->Structure = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_AttachmentRemoved(XDR *stream, char **eleptrp)
{
     AttachmentRemoved *eleptr;
     eleptr = (AttachmentRemoved *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Attachment));

     xdr_pointer(stream,
          (char **) &(eleptr->Structure),
          GraphSize,
                 (xdrproc_t) xdr_Graph);
}

extern void *AllocAttachmentRemoved()
{
     return((void *) AllocateAttachmentRemoved);
}
