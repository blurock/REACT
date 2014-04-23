
extern CHAR *GetNameNeighbor(Neighbor *str)
{
     return(str->Name);
}

extern INT GetIDNeighbor(Neighbor *str)
{
     return(str->ID);
}

extern Neighbor *CreateNeighbor(Neighbor *newstruct,
                         INT id,
                         CHAR *name,
                         INT  NumberOfNeighbors,
                         INT *List)
{
INT *oldList,*newList;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNeighbors = NumberOfNeighbors;

     newstruct->List = AllocArrayINT(newstruct->NumberOfNeighbors);
     if(List != 0)
          {
          oldList = List;
          newList = newstruct->List;
          LOOPi(newstruct->NumberOfNeighbors)
               CopyFullINT(newList++, oldList++);
          }



     return(newstruct);
}


extern void CopyFullNeighbor(Neighbor *newstruct, Neighbor *oldstruct)
{
INT *oldList,*newList;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNeighbors = oldstruct->NumberOfNeighbors;


     newstruct->List = AllocArrayINT(newstruct->NumberOfNeighbors);
     if(oldstruct->List != 0)
          {
          oldList = oldstruct->List;
          newList = newstruct->List;
          LOOPi(newstruct->NumberOfNeighbors)
               CopyFullINT(newList++, oldList++);
          }


}
extern void PrintNeighbor(Neighbor *eleptr)
{
INT *ptrList;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" Number Of Neighbors:");
     printf("%d\n",eleptr->NumberOfNeighbors);

     printf("The list of Neighbor ID's:\n");
     if(eleptr->List != 0)
          {
          ptrList = eleptr->List;
          LOOPi(eleptr->NumberOfNeighbors)
               PrintINT(ptrList++);
          }


}
extern void FreeNeighbor(Neighbor *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->List);

}
extern void WriteBinNeighbor(Neighbor *eleptr, DbaseLinkedList *file)
{
INT *ptrList;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfNeighbors),file);

     if(eleptr->List != 0)
          {
          ptrList = eleptr->List;
          LOOPi(eleptr->NumberOfNeighbors)
               WriteBinINT(ptrList++,file);
          }

}
extern INT ReadBinNeighbor(Neighbor *eleptr,DbaseLinkedList *file)
     {
INT *ptrList;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNeighbors),file);

          eleptr->List = AllocArrayINT(eleptr->NumberOfNeighbors);
          ptrList = eleptr->List;
          LOOPi(eleptr->NumberOfNeighbors)
               ReadBinINT(ptrList++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_Neighbor(XDR *stream, char **eleptrp)
{
     Neighbor *eleptr;
     eleptr = (Neighbor *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfNeighbors));

     xdr_array(stream,(char **) &(eleptr->List),
             (uint *) &(eleptr->NumberOfNeighbors),eleptr->NumberOfNeighbors,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocNeighbor()
{
     return((void *) AllocateNeighbor);
}

extern CHAR *GetNameGraphMetaAtom(GraphMetaAtom *str)
{
     return(str->Name);
}

extern INT GetIDGraphMetaAtom(GraphMetaAtom *str)
{
     return(str->ID);
}

extern GraphMetaAtom *CreateGraphMetaAtom(GraphMetaAtom *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfAliased,
                                   INT *AtomicTypes)
{
INT *oldAtomicTypes,*newAtomicTypes;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfAliased = NumberOfAliased;

     newstruct->AtomicTypes = AllocArrayINT(newstruct->NumberOfAliased);
     if(AtomicTypes != 0)
          {
          oldAtomicTypes = AtomicTypes;
          newAtomicTypes = newstruct->AtomicTypes;
          LOOPi(newstruct->NumberOfAliased)
               CopyFullINT(newAtomicTypes++, oldAtomicTypes++);
          }



     return(newstruct);
}


extern void CopyFullGraphMetaAtom(GraphMetaAtom *newstruct, GraphMetaAtom *oldstruct)
{
INT *oldAtomicTypes,*newAtomicTypes;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfAliased = oldstruct->NumberOfAliased;


     newstruct->AtomicTypes = AllocArrayINT(newstruct->NumberOfAliased);
     if(oldstruct->AtomicTypes != 0)
          {
          oldAtomicTypes = oldstruct->AtomicTypes;
          newAtomicTypes = newstruct->AtomicTypes;
          LOOPi(newstruct->NumberOfAliased)
               CopyFullINT(newAtomicTypes++, oldAtomicTypes++);
          }


}
extern void PrintGraphMetaAtom(GraphMetaAtom *eleptr)
{
INT *ptrAtomicTypes;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Possibilities:");
     printf("%d\n",eleptr->NumberOfAliased);

     printf("    The Atomic Types:\n");
     if(eleptr->AtomicTypes != 0)
          {
          ptrAtomicTypes = eleptr->AtomicTypes;
          LOOPi(eleptr->NumberOfAliased)
               PrintINT(ptrAtomicTypes++);
          }


}
extern void FreeGraphMetaAtom(GraphMetaAtom *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->AtomicTypes);

}
extern void WriteBinGraphMetaAtom(GraphMetaAtom *eleptr, DbaseLinkedList *file)
{
INT *ptrAtomicTypes;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfAliased),file);

     if(eleptr->AtomicTypes != 0)
          {
          ptrAtomicTypes = eleptr->AtomicTypes;
          LOOPi(eleptr->NumberOfAliased)
               WriteBinINT(ptrAtomicTypes++,file);
          }

}
extern INT ReadBinGraphMetaAtom(GraphMetaAtom *eleptr,DbaseLinkedList *file)
     {
INT *ptrAtomicTypes;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfAliased),file);

          eleptr->AtomicTypes = AllocArrayINT(eleptr->NumberOfAliased);
          ptrAtomicTypes = eleptr->AtomicTypes;
          LOOPi(eleptr->NumberOfAliased)
               ReadBinINT(ptrAtomicTypes++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_GraphMetaAtom(XDR *stream, char **eleptrp)
{
     GraphMetaAtom *eleptr;
     eleptr = (GraphMetaAtom *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfAliased));

     xdr_array(stream,(char **) &(eleptr->AtomicTypes),
             (uint *) &(eleptr->NumberOfAliased),eleptr->NumberOfAliased,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocGraphMetaAtom()
{
     return((void *) AllocateGraphMetaAtom);
}

extern CHAR *GetNameSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *str)
{
     return(str->Name);
}

extern INT GetIDSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *str)
{
     return(str->ID);
}

extern SetOfGraphMetaAtoms *CreateSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfMetaAtoms,
                                               GraphMetaAtom *MetaAtoms)
{
GraphMetaAtom *oldMetaAtoms,*newMetaAtoms;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfMetaAtoms = NumberOfMetaAtoms;

     newstruct->MetaAtoms = AllocArrayGraphMetaAtom(newstruct->NumberOfMetaAtoms);
     if(MetaAtoms != 0)
          {
          oldMetaAtoms = MetaAtoms;
          newMetaAtoms = newstruct->MetaAtoms;
          LOOPi(newstruct->NumberOfMetaAtoms)
               CopyFullGraphMetaAtom(newMetaAtoms++, oldMetaAtoms++);
          }



     return(newstruct);
}


extern void CopyFullSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *newstruct, SetOfGraphMetaAtoms *oldstruct)
{
GraphMetaAtom *oldMetaAtoms,*newMetaAtoms;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfMetaAtoms = oldstruct->NumberOfMetaAtoms;


     newstruct->MetaAtoms = AllocArrayGraphMetaAtom(newstruct->NumberOfMetaAtoms);
     if(oldstruct->MetaAtoms != 0)
          {
          oldMetaAtoms = oldstruct->MetaAtoms;
          newMetaAtoms = newstruct->MetaAtoms;
          LOOPi(newstruct->NumberOfMetaAtoms)
               CopyFullGraphMetaAtom(newMetaAtoms++, oldMetaAtoms++);
          }


}
extern void PrintSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr)
{
GraphMetaAtom *ptrMetaAtoms;
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
               PrintGraphMetaAtom(ptrMetaAtoms++);
          }


}
extern void FreeSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr)
{
GraphMetaAtom *ptrMetaAtoms;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrMetaAtoms = eleptr->MetaAtoms;
     LOOPi(eleptr->NumberOfMetaAtoms)
          FreeGraphMetaAtom(ptrMetaAtoms++);
     Free(eleptr->MetaAtoms);

}
extern void WriteBinSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr, DbaseLinkedList *file)
{
GraphMetaAtom *ptrMetaAtoms;
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
               WriteBinGraphMetaAtom(ptrMetaAtoms++,file);
          }

}
extern INT ReadBinSetOfGraphMetaAtoms(SetOfGraphMetaAtoms *eleptr,DbaseLinkedList *file)
     {
GraphMetaAtom *ptrMetaAtoms;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfMetaAtoms),file);

          eleptr->MetaAtoms = AllocArrayGraphMetaAtom(eleptr->NumberOfMetaAtoms);
          ptrMetaAtoms = eleptr->MetaAtoms;
          LOOPi(eleptr->NumberOfMetaAtoms)
               ReadBinGraphMetaAtom(ptrMetaAtoms++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfGraphMetaAtoms(XDR *stream, char **eleptrp)
{
     SetOfGraphMetaAtoms *eleptr;
     eleptr = (SetOfGraphMetaAtoms *) eleptrp;
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
               GraphMetaAtomSize,(xdrproc_t) xdr_GraphMetaAtom);
}

extern void *AllocSetOfGraphMetaAtoms()
{
     return((void *) AllocateSetOfGraphMetaAtoms);
}

extern CHAR *GetNameGraph(Graph *str)
{
     return(str->Name);
}

extern INT GetIDGraph(Graph *str)
{
     return(str->ID);
}

extern Graph *CreateGraph(Graph *newstruct,
                   INT id,
                   CHAR *name,
                   INT  NumberOfNodes,
                   INT *NodeTypes,
                   Neighbor *Neighbors,
                   SetOfGraphMetaAtoms *MetaAtoms)
{
INT *oldNodeTypes,*newNodeTypes;
Neighbor *oldNeighbors,*newNeighbors;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNodes = NumberOfNodes;
     if(MetaAtoms != 0)
          {
          newstruct->MetaAtoms = AllocateSetOfGraphMetaAtoms;
          CopyFullSetOfGraphMetaAtoms(newstruct->MetaAtoms, MetaAtoms);
          }
     else
          newstruct->MetaAtoms = 0;

     newstruct->NodeTypes = AllocArrayINT(newstruct->NumberOfNodes);
     if(NodeTypes != 0)
          {
          oldNodeTypes = NodeTypes;
          newNodeTypes = newstruct->NodeTypes;
          LOOPi(newstruct->NumberOfNodes)
               CopyFullINT(newNodeTypes++, oldNodeTypes++);
          }

     newstruct->Neighbors = AllocArrayNeighbor(newstruct->NumberOfNodes);
     if(Neighbors != 0)
          {
          oldNeighbors = Neighbors;
          newNeighbors = newstruct->Neighbors;
          LOOPi(newstruct->NumberOfNodes)
               CopyFullNeighbor(newNeighbors++, oldNeighbors++);
          }



     return(newstruct);
}


extern void CopyFullGraph(Graph *newstruct, Graph *oldstruct)
{
INT *oldNodeTypes,*newNodeTypes;
Neighbor *oldNeighbors,*newNeighbors;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNodes = oldstruct->NumberOfNodes;

     if(oldstruct->MetaAtoms != 0)
          {
          newstruct->MetaAtoms = AllocateSetOfGraphMetaAtoms;
          CopyFullSetOfGraphMetaAtoms(newstruct->MetaAtoms, oldstruct->MetaAtoms);
          }
     else
          newstruct->MetaAtoms = 0;

     newstruct->NodeTypes = AllocArrayINT(newstruct->NumberOfNodes);
     if(oldstruct->NodeTypes != 0)
          {
          oldNodeTypes = oldstruct->NodeTypes;
          newNodeTypes = newstruct->NodeTypes;
          LOOPi(newstruct->NumberOfNodes)
               CopyFullINT(newNodeTypes++, oldNodeTypes++);
          }

     newstruct->Neighbors = AllocArrayNeighbor(newstruct->NumberOfNodes);
     if(oldstruct->Neighbors != 0)
          {
          oldNeighbors = oldstruct->Neighbors;
          newNeighbors = newstruct->Neighbors;
          LOOPi(newstruct->NumberOfNodes)
               CopyFullNeighbor(newNeighbors++, oldNeighbors++);
          }


}
extern void PrintGraph(Graph *eleptr)
{
INT *ptrNodeTypes;
Neighbor *ptrNeighbors;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number of Nodes in Graph:");
     printf("%d\n",eleptr->NumberOfNodes);

     printf("The set of MetaAtoms:\n");
     PrintSetOfGraphMetaAtoms(eleptr->MetaAtoms);

     printf("Types (Colors) of the Nodes:\n");
     if(eleptr->NodeTypes != 0)
          {
          ptrNodeTypes = eleptr->NodeTypes;
          LOOPi(eleptr->NumberOfNodes)
               PrintINT(ptrNodeTypes++);
          }


     printf("The set of Neighbors:\n");
     if(eleptr->Neighbors != 0)
          {
          ptrNeighbors = eleptr->Neighbors;
          LOOPi(eleptr->NumberOfNodes)
               PrintNeighbor(ptrNeighbors++);
          }


}
extern void FreeGraph(Graph *eleptr)
{
Neighbor *ptrNeighbors;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->NodeTypes);

     ptrNeighbors = eleptr->Neighbors;
     LOOPi(eleptr->NumberOfNodes)
          FreeNeighbor(ptrNeighbors++);
     Free(eleptr->Neighbors);

     FreeSetOfGraphMetaAtoms(eleptr->MetaAtoms);
     Free(eleptr->MetaAtoms);

}
extern void WriteBinGraph(Graph *eleptr, DbaseLinkedList *file)
{
INT *ptrNodeTypes;
Neighbor *ptrNeighbors;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfNodes),file);

     WriteBinSetOfGraphMetaAtoms(eleptr->MetaAtoms,file);

     if(eleptr->NodeTypes != 0)
          {
          ptrNodeTypes = eleptr->NodeTypes;
          LOOPi(eleptr->NumberOfNodes)
               WriteBinINT(ptrNodeTypes++,file);
          }

     if(eleptr->Neighbors != 0)
          {
          ptrNeighbors = eleptr->Neighbors;
          LOOPi(eleptr->NumberOfNodes)
               WriteBinNeighbor(ptrNeighbors++,file);
          }

}
extern INT ReadBinGraph(Graph *eleptr,DbaseLinkedList *file)
     {
INT *ptrNodeTypes;
Neighbor *ptrNeighbors;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNodes),file);

     eleptr->MetaAtoms = AllocateSetOfGraphMetaAtoms;
     if(ReadBinSetOfGraphMetaAtoms(eleptr->MetaAtoms,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->MetaAtoms);
           eleptr->MetaAtoms = 0;
           }

          eleptr->NodeTypes = AllocArrayINT(eleptr->NumberOfNodes);
          ptrNodeTypes = eleptr->NodeTypes;
          LOOPi(eleptr->NumberOfNodes)
               ReadBinINT(ptrNodeTypes++,file);

          eleptr->Neighbors = AllocArrayNeighbor(eleptr->NumberOfNodes);
          ptrNeighbors = eleptr->Neighbors;
          LOOPi(eleptr->NumberOfNodes)
               ReadBinNeighbor(ptrNeighbors++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_Graph(XDR *stream, char **eleptrp)
{
     Graph *eleptr;
     eleptr = (Graph *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfNodes));

     xdr_pointer(stream,
          (char **) &(eleptr->MetaAtoms),
          SetOfGraphMetaAtomsSize,
                 (xdrproc_t) xdr_SetOfGraphMetaAtoms);
     xdr_array(stream,(char **) &(eleptr->NodeTypes),
             (uint *) &(eleptr->NumberOfNodes),eleptr->NumberOfNodes,
               INTSize,(xdrproc_t) xdr_INT);
     xdr_array(stream,(char **) &(eleptr->Neighbors),
             (uint *) &(eleptr->NumberOfNodes),eleptr->NumberOfNodes,
               NeighborSize,(xdrproc_t) xdr_Neighbor);
}

extern void *AllocGraph()
{
     return((void *) AllocateGraph);
}

extern CHAR *GetNameSetOfGraphs(SetOfGraphs *str)
{
     return(str->Name);
}

extern INT GetIDSetOfGraphs(SetOfGraphs *str)
{
     return(str->ID);
}

extern SetOfGraphs *CreateSetOfGraphs(SetOfGraphs *newstruct,
                               INT id,
                               CHAR *name,
                               INT  NumberOfGraphs,
                               Graph *Graphs)
{
Graph *oldGraphs,*newGraphs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfGraphs = NumberOfGraphs;

     newstruct->Graphs = AllocArrayGraph(newstruct->NumberOfGraphs);
     if(Graphs != 0)
          {
          oldGraphs = Graphs;
          newGraphs = newstruct->Graphs;
          LOOPi(newstruct->NumberOfGraphs)
               CopyFullGraph(newGraphs++, oldGraphs++);
          }



     return(newstruct);
}


extern void CopyFullSetOfGraphs(SetOfGraphs *newstruct, SetOfGraphs *oldstruct)
{
Graph *oldGraphs,*newGraphs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfGraphs = oldstruct->NumberOfGraphs;


     newstruct->Graphs = AllocArrayGraph(newstruct->NumberOfGraphs);
     if(oldstruct->Graphs != 0)
          {
          oldGraphs = oldstruct->Graphs;
          newGraphs = newstruct->Graphs;
          LOOPi(newstruct->NumberOfGraphs)
               CopyFullGraph(newGraphs++, oldGraphs++);
          }


}
extern void PrintSetOfGraphs(SetOfGraphs *eleptr)
{
Graph *ptrGraphs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of graphs:");
     printf("%d\n",eleptr->NumberOfGraphs);

     printf("   The set of graphs:\n");
     if(eleptr->Graphs != 0)
          {
          ptrGraphs = eleptr->Graphs;
          LOOPi(eleptr->NumberOfGraphs)
               PrintGraph(ptrGraphs++);
          }


}
extern void FreeSetOfGraphs(SetOfGraphs *eleptr)
{
Graph *ptrGraphs;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrGraphs = eleptr->Graphs;
     LOOPi(eleptr->NumberOfGraphs)
          FreeGraph(ptrGraphs++);
     Free(eleptr->Graphs);

}
extern void WriteBinSetOfGraphs(SetOfGraphs *eleptr, DbaseLinkedList *file)
{
Graph *ptrGraphs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfGraphs),file);

     if(eleptr->Graphs != 0)
          {
          ptrGraphs = eleptr->Graphs;
          LOOPi(eleptr->NumberOfGraphs)
               WriteBinGraph(ptrGraphs++,file);
          }

}
extern INT ReadBinSetOfGraphs(SetOfGraphs *eleptr,DbaseLinkedList *file)
     {
Graph *ptrGraphs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfGraphs),file);

          eleptr->Graphs = AllocArrayGraph(eleptr->NumberOfGraphs);
          ptrGraphs = eleptr->Graphs;
          LOOPi(eleptr->NumberOfGraphs)
               ReadBinGraph(ptrGraphs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfGraphs(XDR *stream, char **eleptrp)
{
     SetOfGraphs *eleptr;
     eleptr = (SetOfGraphs *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfGraphs));

     xdr_array(stream,(char **) &(eleptr->Graphs),
             (uint *) &(eleptr->NumberOfGraphs),eleptr->NumberOfGraphs,
               GraphSize,(xdrproc_t) xdr_Graph);
}

extern void *AllocSetOfGraphs()
{
     return((void *) AllocateSetOfGraphs);
}

extern CHAR *GetNameGraphReaction(GraphReaction *str)
{
     return(str->Name);
}

extern INT GetIDGraphReaction(GraphReaction *str)
{
     return(str->ID);
}

extern GraphReaction *CreateGraphReaction(GraphReaction *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberLHS,
                                   Graph *GraphLHS,
                                   INT  NumberRHS,
                                   Graph *GraphRHS)
{
Graph *oldGraphLHS,*newGraphLHS;
Graph *oldGraphRHS,*newGraphRHS;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberLHS = NumberLHS;
     newstruct->NumberRHS = NumberRHS;

     newstruct->GraphLHS = AllocArrayGraph(newstruct->NumberLHS);
     if(GraphLHS != 0)
          {
          oldGraphLHS = GraphLHS;
          newGraphLHS = newstruct->GraphLHS;
          LOOPi(newstruct->NumberLHS)
               CopyFullGraph(newGraphLHS++, oldGraphLHS++);
          }

     newstruct->GraphRHS = AllocArrayGraph(newstruct->NumberRHS);
     if(GraphRHS != 0)
          {
          oldGraphRHS = GraphRHS;
          newGraphRHS = newstruct->GraphRHS;
          LOOPi(newstruct->NumberRHS)
               CopyFullGraph(newGraphRHS++, oldGraphRHS++);
          }



     return(newstruct);
}


extern void CopyFullGraphReaction(GraphReaction *newstruct, GraphReaction *oldstruct)
{
Graph *oldGraphLHS,*newGraphLHS;
Graph *oldGraphRHS,*newGraphRHS;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberLHS = oldstruct->NumberLHS;
     newstruct->NumberRHS = oldstruct->NumberRHS;


     newstruct->GraphLHS = AllocArrayGraph(newstruct->NumberLHS);
     if(oldstruct->GraphLHS != 0)
          {
          oldGraphLHS = oldstruct->GraphLHS;
          newGraphLHS = newstruct->GraphLHS;
          LOOPi(newstruct->NumberLHS)
               CopyFullGraph(newGraphLHS++, oldGraphLHS++);
          }

     newstruct->GraphRHS = AllocArrayGraph(newstruct->NumberRHS);
     if(oldstruct->GraphRHS != 0)
          {
          oldGraphRHS = oldstruct->GraphRHS;
          newGraphRHS = newstruct->GraphRHS;
          LOOPi(newstruct->NumberRHS)
               CopyFullGraph(newGraphRHS++, oldGraphRHS++);
          }


}
extern void PrintGraphReaction(GraphReaction *eleptr)
{
Graph *ptrGraphLHS;
Graph *ptrGraphRHS;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of graphs on left hand side:");
     printf("%d\n",eleptr->NumberLHS);
     printf("The number of graphs on the right hand side:");
     printf("%d\n",eleptr->NumberRHS);

     printf("The set of graph on the left hand side:\n");
     if(eleptr->GraphLHS != 0)
          {
          ptrGraphLHS = eleptr->GraphLHS;
          LOOPi(eleptr->NumberLHS)
               PrintGraph(ptrGraphLHS++);
          }


     printf("The set of graphs on the RHS:\n");
     if(eleptr->GraphRHS != 0)
          {
          ptrGraphRHS = eleptr->GraphRHS;
          LOOPi(eleptr->NumberRHS)
               PrintGraph(ptrGraphRHS++);
          }


}
extern void FreeGraphReaction(GraphReaction *eleptr)
{
Graph *ptrGraphLHS;
Graph *ptrGraphRHS;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrGraphLHS = eleptr->GraphLHS;
     LOOPi(eleptr->NumberLHS)
          FreeGraph(ptrGraphLHS++);
     Free(eleptr->GraphLHS);

     ptrGraphRHS = eleptr->GraphRHS;
     LOOPi(eleptr->NumberRHS)
          FreeGraph(ptrGraphRHS++);
     Free(eleptr->GraphRHS);

}
extern void WriteBinGraphReaction(GraphReaction *eleptr, DbaseLinkedList *file)
{
Graph *ptrGraphLHS;
Graph *ptrGraphRHS;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberLHS),file);
     WriteBinINT(&(eleptr->NumberRHS),file);

     if(eleptr->GraphLHS != 0)
          {
          ptrGraphLHS = eleptr->GraphLHS;
          LOOPi(eleptr->NumberLHS)
               WriteBinGraph(ptrGraphLHS++,file);
          }

     if(eleptr->GraphRHS != 0)
          {
          ptrGraphRHS = eleptr->GraphRHS;
          LOOPi(eleptr->NumberRHS)
               WriteBinGraph(ptrGraphRHS++,file);
          }

}
extern INT ReadBinGraphReaction(GraphReaction *eleptr,DbaseLinkedList *file)
     {
Graph *ptrGraphLHS;
Graph *ptrGraphRHS;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberLHS),file);
     ReadBinINT(&(eleptr->NumberRHS),file);

          eleptr->GraphLHS = AllocArrayGraph(eleptr->NumberLHS);
          ptrGraphLHS = eleptr->GraphLHS;
          LOOPi(eleptr->NumberLHS)
               ReadBinGraph(ptrGraphLHS++,file);

          eleptr->GraphRHS = AllocArrayGraph(eleptr->NumberRHS);
          ptrGraphRHS = eleptr->GraphRHS;
          LOOPi(eleptr->NumberRHS)
               ReadBinGraph(ptrGraphRHS++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_GraphReaction(XDR *stream, char **eleptrp)
{
     GraphReaction *eleptr;
     eleptr = (GraphReaction *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberLHS));
     xdr_INT(stream,(char **) &(eleptr->NumberRHS));

     xdr_array(stream,(char **) &(eleptr->GraphLHS),
             (uint *) &(eleptr->NumberLHS),eleptr->NumberLHS,
               GraphSize,(xdrproc_t) xdr_Graph);
     xdr_array(stream,(char **) &(eleptr->GraphRHS),
             (uint *) &(eleptr->NumberRHS),eleptr->NumberRHS,
               GraphSize,(xdrproc_t) xdr_Graph);
}

extern void *AllocGraphReaction()
{
     return((void *) AllocateGraphReaction);
}

extern CHAR *GetNameSetOfGraphReactions(SetOfGraphReactions *str)
{
     return(str->Name);
}

extern INT GetIDSetOfGraphReactions(SetOfGraphReactions *str)
{
     return(str->ID);
}

extern SetOfGraphReactions *CreateSetOfGraphReactions(SetOfGraphReactions *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfGraphReactions,
                                               GraphReaction *Reactions)
{
GraphReaction *oldReactions,*newReactions;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfGraphReactions = NumberOfGraphReactions;

     newstruct->Reactions = AllocArrayGraphReaction(newstruct->NumberOfGraphReactions);
     if(Reactions != 0)
          {
          oldReactions = Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfGraphReactions)
               CopyFullGraphReaction(newReactions++, oldReactions++);
          }



     return(newstruct);
}


extern void CopyFullSetOfGraphReactions(SetOfGraphReactions *newstruct, SetOfGraphReactions *oldstruct)
{
GraphReaction *oldReactions,*newReactions;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfGraphReactions = oldstruct->NumberOfGraphReactions;


     newstruct->Reactions = AllocArrayGraphReaction(newstruct->NumberOfGraphReactions);
     if(oldstruct->Reactions != 0)
          {
          oldReactions = oldstruct->Reactions;
          newReactions = newstruct->Reactions;
          LOOPi(newstruct->NumberOfGraphReactions)
               CopyFullGraphReaction(newReactions++, oldReactions++);
          }


}
extern void PrintSetOfGraphReactions(SetOfGraphReactions *eleptr)
{
GraphReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of graph reactions:");
     printf("%d\n",eleptr->NumberOfGraphReactions);

     printf("The set of graph reactions:\n");
     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfGraphReactions)
               PrintGraphReaction(ptrReactions++);
          }


}
extern void FreeSetOfGraphReactions(SetOfGraphReactions *eleptr)
{
GraphReaction *ptrReactions;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrReactions = eleptr->Reactions;
     LOOPi(eleptr->NumberOfGraphReactions)
          FreeGraphReaction(ptrReactions++);
     Free(eleptr->Reactions);

}
extern void WriteBinSetOfGraphReactions(SetOfGraphReactions *eleptr, DbaseLinkedList *file)
{
GraphReaction *ptrReactions;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfGraphReactions),file);

     if(eleptr->Reactions != 0)
          {
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfGraphReactions)
               WriteBinGraphReaction(ptrReactions++,file);
          }

}
extern INT ReadBinSetOfGraphReactions(SetOfGraphReactions *eleptr,DbaseLinkedList *file)
     {
GraphReaction *ptrReactions;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfGraphReactions),file);

          eleptr->Reactions = AllocArrayGraphReaction(eleptr->NumberOfGraphReactions);
          ptrReactions = eleptr->Reactions;
          LOOPi(eleptr->NumberOfGraphReactions)
               ReadBinGraphReaction(ptrReactions++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfGraphReactions(XDR *stream, char **eleptrp)
{
     SetOfGraphReactions *eleptr;
     eleptr = (SetOfGraphReactions *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfGraphReactions));

     xdr_array(stream,(char **) &(eleptr->Reactions),
             (uint *) &(eleptr->NumberOfGraphReactions),eleptr->NumberOfGraphReactions,
               GraphReactionSize,(xdrproc_t) xdr_GraphReaction);
}

extern void *AllocSetOfGraphReactions()
{
     return((void *) AllocateSetOfGraphReactions);
}

extern CHAR *GetNameCombinedGraph(CombinedGraph *str)
{
     return(str->Name);
}

extern INT GetIDCombinedGraph(CombinedGraph *str)
{
     return(str->ID);
}

extern CombinedGraph *CreateCombinedGraph(CombinedGraph *newstruct,
                                   INT id,
                                   CHAR *name,
                                   Graph *Combined,
                                   INT  NumberOfBegins,
                                   INT *Begins)
{
INT *oldBegins,*newBegins;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfBegins = NumberOfBegins;
     if(Combined != 0)
          {
          newstruct->Combined = AllocateGraph;
          CopyFullGraph(newstruct->Combined, Combined);
          }
     else
          newstruct->Combined = 0;

     newstruct->Begins = AllocArrayINT(newstruct->NumberOfBegins);
     if(Begins != 0)
          {
          oldBegins = Begins;
          newBegins = newstruct->Begins;
          LOOPi(newstruct->NumberOfBegins)
               CopyFullINT(newBegins++, oldBegins++);
          }



     return(newstruct);
}


extern void CopyFullCombinedGraph(CombinedGraph *newstruct, CombinedGraph *oldstruct)
{
INT *oldBegins,*newBegins;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfBegins = oldstruct->NumberOfBegins;

     if(oldstruct->Combined != 0)
          {
          newstruct->Combined = AllocateGraph;
          CopyFullGraph(newstruct->Combined, oldstruct->Combined);
          }
     else
          newstruct->Combined = 0;

     newstruct->Begins = AllocArrayINT(newstruct->NumberOfBegins);
     if(oldstruct->Begins != 0)
          {
          oldBegins = oldstruct->Begins;
          newBegins = newstruct->Begins;
          LOOPi(newstruct->NumberOfBegins)
               CopyFullINT(newBegins++, oldBegins++);
          }


}
extern void PrintCombinedGraph(CombinedGraph *eleptr)
{
INT *ptrBegins;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of graphs in the one graph:");
     printf("%d\n",eleptr->NumberOfBegins);

     printf("  The combined graph:\n");
     PrintGraph(eleptr->Combined);

     printf("The set of Begin Points of the nodes of the corr. graphs:\n");
     if(eleptr->Begins != 0)
          {
          ptrBegins = eleptr->Begins;
          LOOPi(eleptr->NumberOfBegins)
               PrintINT(ptrBegins++);
          }


}
extern void FreeCombinedGraph(CombinedGraph *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Begins);

     FreeGraph(eleptr->Combined);
     Free(eleptr->Combined);

}
extern void WriteBinCombinedGraph(CombinedGraph *eleptr, DbaseLinkedList *file)
{
INT *ptrBegins;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfBegins),file);

     WriteBinGraph(eleptr->Combined,file);

     if(eleptr->Begins != 0)
          {
          ptrBegins = eleptr->Begins;
          LOOPi(eleptr->NumberOfBegins)
               WriteBinINT(ptrBegins++,file);
          }

}
extern INT ReadBinCombinedGraph(CombinedGraph *eleptr,DbaseLinkedList *file)
     {
INT *ptrBegins;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfBegins),file);

     eleptr->Combined = AllocateGraph;
     if(ReadBinGraph(eleptr->Combined,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Combined);
           eleptr->Combined = 0;
           }

          eleptr->Begins = AllocArrayINT(eleptr->NumberOfBegins);
          ptrBegins = eleptr->Begins;
          LOOPi(eleptr->NumberOfBegins)
               ReadBinINT(ptrBegins++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_CombinedGraph(XDR *stream, char **eleptrp)
{
     CombinedGraph *eleptr;
     eleptr = (CombinedGraph *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfBegins));

     xdr_pointer(stream,
          (char **) &(eleptr->Combined),
          GraphSize,
                 (xdrproc_t) xdr_Graph);
     xdr_array(stream,(char **) &(eleptr->Begins),
             (uint *) &(eleptr->NumberOfBegins),eleptr->NumberOfBegins,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocCombinedGraph()
{
     return((void *) AllocateCombinedGraph);
}

extern CHAR *GetNameSetOfCombinedGraphs(SetOfCombinedGraphs *str)
{
     return(str->Name);
}

extern INT GetIDSetOfCombinedGraphs(SetOfCombinedGraphs *str)
{
     return(str->ID);
}

extern SetOfCombinedGraphs *CreateSetOfCombinedGraphs(SetOfCombinedGraphs *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfCGraphs,
                                               CombinedGraph *CGraphs)
{
CombinedGraph *oldCGraphs,*newCGraphs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfCGraphs = NumberOfCGraphs;

     newstruct->CGraphs = AllocArrayCombinedGraph(newstruct->NumberOfCGraphs);
     if(CGraphs != 0)
          {
          oldCGraphs = CGraphs;
          newCGraphs = newstruct->CGraphs;
          LOOPi(newstruct->NumberOfCGraphs)
               CopyFullCombinedGraph(newCGraphs++, oldCGraphs++);
          }



     return(newstruct);
}


extern void CopyFullSetOfCombinedGraphs(SetOfCombinedGraphs *newstruct, SetOfCombinedGraphs *oldstruct)
{
CombinedGraph *oldCGraphs,*newCGraphs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfCGraphs = oldstruct->NumberOfCGraphs;


     newstruct->CGraphs = AllocArrayCombinedGraph(newstruct->NumberOfCGraphs);
     if(oldstruct->CGraphs != 0)
          {
          oldCGraphs = oldstruct->CGraphs;
          newCGraphs = newstruct->CGraphs;
          LOOPi(newstruct->NumberOfCGraphs)
               CopyFullCombinedGraph(newCGraphs++, oldCGraphs++);
          }


}
extern void PrintSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr)
{
CombinedGraph *ptrCGraphs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of graphs:");
     printf("%d\n",eleptr->NumberOfCGraphs);

     printf("   The set of graphs:\n");
     if(eleptr->CGraphs != 0)
          {
          ptrCGraphs = eleptr->CGraphs;
          LOOPi(eleptr->NumberOfCGraphs)
               PrintCombinedGraph(ptrCGraphs++);
          }


}
extern void FreeSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr)
{
CombinedGraph *ptrCGraphs;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrCGraphs = eleptr->CGraphs;
     LOOPi(eleptr->NumberOfCGraphs)
          FreeCombinedGraph(ptrCGraphs++);
     Free(eleptr->CGraphs);

}
extern void WriteBinSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr, DbaseLinkedList *file)
{
CombinedGraph *ptrCGraphs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfCGraphs),file);

     if(eleptr->CGraphs != 0)
          {
          ptrCGraphs = eleptr->CGraphs;
          LOOPi(eleptr->NumberOfCGraphs)
               WriteBinCombinedGraph(ptrCGraphs++,file);
          }

}
extern INT ReadBinSetOfCombinedGraphs(SetOfCombinedGraphs *eleptr,DbaseLinkedList *file)
     {
CombinedGraph *ptrCGraphs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfCGraphs),file);

          eleptr->CGraphs = AllocArrayCombinedGraph(eleptr->NumberOfCGraphs);
          ptrCGraphs = eleptr->CGraphs;
          LOOPi(eleptr->NumberOfCGraphs)
               ReadBinCombinedGraph(ptrCGraphs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfCombinedGraphs(XDR *stream, char **eleptrp)
{
     SetOfCombinedGraphs *eleptr;
     eleptr = (SetOfCombinedGraphs *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfCGraphs));

     xdr_array(stream,(char **) &(eleptr->CGraphs),
             (uint *) &(eleptr->NumberOfCGraphs),eleptr->NumberOfCGraphs,
               CombinedGraphSize,(xdrproc_t) xdr_CombinedGraph);
}

extern void *AllocSetOfCombinedGraphs()
{
     return((void *) AllocateSetOfCombinedGraphs);
}
