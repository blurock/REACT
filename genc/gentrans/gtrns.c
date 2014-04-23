
extern CHAR *GetNameGraphNode(GraphNode *str)
{
     return(str->Name);
}

extern INT GetIDGraphNode(GraphNode *str)
{
     return(str->ID);
}

extern GraphNode *CreateGraphNode(GraphNode *newstruct,
                           INT id,
                           CHAR *name,
                           INT  Molecule,
                           INT  GNode)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Molecule = Molecule;
     newstruct->GNode = GNode;



     return(newstruct);
}


extern void CopyFullGraphNode(GraphNode *newstruct, GraphNode *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Molecule = oldstruct->Molecule;
     newstruct->GNode = oldstruct->GNode;



}
extern void PrintGraphNode(GraphNode *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Position of Molecule Within List:");
     printf("%d\n",eleptr->Molecule);
     printf("Position of node within Molecule:");
     printf("%d\n",eleptr->GNode);

}
extern void FreeGraphNode(GraphNode *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinGraphNode(GraphNode *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Molecule),file);
     WriteBinINT(&(eleptr->GNode),file);

}
extern INT ReadBinGraphNode(GraphNode *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Molecule),file);
     ReadBinINT(&(eleptr->GNode),file);

     return(STRUCTURE_READ);
     }
extern void xdr_GraphNode(XDR *stream, char **eleptrp)
{
     GraphNode *eleptr;
     eleptr = (GraphNode *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Molecule));
     xdr_INT(stream,(char **) &(eleptr->GNode));

}

extern void *AllocGraphNode()
{
     return((void *) AllocateGraphNode);
}

extern CHAR *GetNameGraphNodePair(GraphNodePair *str)
{
     return(str->Name);
}

extern INT GetIDGraphNodePair(GraphNodePair *str)
{
     return(str->ID);
}

extern GraphNodePair *CreateGraphNodePair(GraphNodePair *newstruct,
                                   INT id,
                                   CHAR *name,
                                   GraphNode *TransformN,
                                   GraphNode *GraphN)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(TransformN != 0)
          {
          newstruct->TransformN = AllocateGraphNode;
          CopyFullGraphNode(newstruct->TransformN, TransformN);
          }
     else
          newstruct->TransformN = 0;
     if(GraphN != 0)
          {
          newstruct->GraphN = AllocateGraphNode;
          CopyFullGraphNode(newstruct->GraphN, GraphN);
          }
     else
          newstruct->GraphN = 0;



     return(newstruct);
}


extern void CopyFullGraphNodePair(GraphNodePair *newstruct, GraphNodePair *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->TransformN != 0)
          {
          newstruct->TransformN = AllocateGraphNode;
          CopyFullGraphNode(newstruct->TransformN, oldstruct->TransformN);
          }
     else
          newstruct->TransformN = 0;
     if(oldstruct->GraphN != 0)
          {
          newstruct->GraphN = AllocateGraphNode;
          CopyFullGraphNode(newstruct->GraphN, oldstruct->GraphN);
          }
     else
          newstruct->GraphN = 0;


}
extern void PrintGraphNodePair(GraphNodePair *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("      Transform Node:\n");
     PrintGraphNode(eleptr->TransformN);

     printf("          Graph Node:\n");
     PrintGraphNode(eleptr->GraphN);

}
extern void FreeGraphNodePair(GraphNodePair *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeGraphNode(eleptr->TransformN);
     Free(eleptr->TransformN);

     FreeGraphNode(eleptr->GraphN);
     Free(eleptr->GraphN);

}
extern void WriteBinGraphNodePair(GraphNodePair *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinGraphNode(eleptr->TransformN,file);

     WriteBinGraphNode(eleptr->GraphN,file);

}
extern INT ReadBinGraphNodePair(GraphNodePair *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->TransformN = AllocateGraphNode;
     if(ReadBinGraphNode(eleptr->TransformN,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->TransformN);
           eleptr->TransformN = 0;
           }

     eleptr->GraphN = AllocateGraphNode;
     if(ReadBinGraphNode(eleptr->GraphN,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->GraphN);
           eleptr->GraphN = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_GraphNodePair(XDR *stream, char **eleptrp)
{
     GraphNodePair *eleptr;
     eleptr = (GraphNodePair *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->TransformN),
          GraphNodeSize,
                 (xdrproc_t) xdr_GraphNode);
     xdr_pointer(stream,
          (char **) &(eleptr->GraphN),
          GraphNodeSize,
                 (xdrproc_t) xdr_GraphNode);
}

extern void *AllocGraphNodePair()
{
     return((void *) AllocateGraphNodePair);
}

extern CHAR *GetNameGraphBond(GraphBond *str)
{
     return(str->Name);
}

extern INT GetIDGraphBond(GraphBond *str)
{
     return(str->ID);
}

extern GraphBond *CreateGraphBond(GraphBond *newstruct,
                           INT id,
                           CHAR *name,
                           INT  MoleculeI,
                           INT  GNodeI,
                           INT  MoleculeJ,
                           INT  GNodeJ,
                           INT  Type)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->MoleculeI = MoleculeI;
     newstruct->GNodeI = GNodeI;
     newstruct->MoleculeJ = MoleculeJ;
     newstruct->GNodeJ = GNodeJ;
     newstruct->Type = Type;



     return(newstruct);
}


extern void CopyFullGraphBond(GraphBond *newstruct, GraphBond *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->MoleculeI = oldstruct->MoleculeI;
     newstruct->GNodeI = oldstruct->GNodeI;
     newstruct->MoleculeJ = oldstruct->MoleculeJ;
     newstruct->GNodeJ = oldstruct->GNodeJ;
     newstruct->Type = oldstruct->Type;



}
extern void PrintGraphBond(GraphBond *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Position of Molecule Within List:");
     printf("%d\n",eleptr->MoleculeI);
     printf("Position of first node within Molecule:");
     printf("%d\n",eleptr->GNodeI);
     printf("Position of Molecule Within List:");
     printf("%d\n",eleptr->MoleculeJ);
     printf("Position of second node within molecule:");
     printf("%d\n",eleptr->GNodeJ);
     printf("The Type of Bond change:");
     printf("%d\n",eleptr->Type);

}
extern void FreeGraphBond(GraphBond *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinGraphBond(GraphBond *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->MoleculeI),file);
     WriteBinINT(&(eleptr->GNodeI),file);
     WriteBinINT(&(eleptr->MoleculeJ),file);
     WriteBinINT(&(eleptr->GNodeJ),file);
     WriteBinINT(&(eleptr->Type),file);

}
extern INT ReadBinGraphBond(GraphBond *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->MoleculeI),file);
     ReadBinINT(&(eleptr->GNodeI),file);
     ReadBinINT(&(eleptr->MoleculeJ),file);
     ReadBinINT(&(eleptr->GNodeJ),file);
     ReadBinINT(&(eleptr->Type),file);

     return(STRUCTURE_READ);
     }
extern void xdr_GraphBond(XDR *stream, char **eleptrp)
{
     GraphBond *eleptr;
     eleptr = (GraphBond *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->MoleculeI));
     xdr_INT(stream,(char **) &(eleptr->GNodeI));
     xdr_INT(stream,(char **) &(eleptr->MoleculeJ));
     xdr_INT(stream,(char **) &(eleptr->GNodeJ));
     xdr_INT(stream,(char **) &(eleptr->Type));

}

extern void *AllocGraphBond()
{
     return((void *) AllocateGraphBond);
}

extern CHAR *GetNameNodeTransform(NodeTransform *str)
{
     return(str->Name);
}

extern INT GetIDNodeTransform(NodeTransform *str)
{
     return(str->ID);
}

extern NodeTransform *CreateNodeTransform(NodeTransform *newstruct,
                                   INT id,
                                   CHAR *name,
                                   GraphNode *LHSnode,
                                   GraphNode *RHSnode)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(LHSnode != 0)
          {
          newstruct->LHSnode = AllocateGraphNode;
          CopyFullGraphNode(newstruct->LHSnode, LHSnode);
          }
     else
          newstruct->LHSnode = 0;
     if(RHSnode != 0)
          {
          newstruct->RHSnode = AllocateGraphNode;
          CopyFullGraphNode(newstruct->RHSnode, RHSnode);
          }
     else
          newstruct->RHSnode = 0;



     return(newstruct);
}


extern void CopyFullNodeTransform(NodeTransform *newstruct, NodeTransform *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->LHSnode != 0)
          {
          newstruct->LHSnode = AllocateGraphNode;
          CopyFullGraphNode(newstruct->LHSnode, oldstruct->LHSnode);
          }
     else
          newstruct->LHSnode = 0;
     if(oldstruct->RHSnode != 0)
          {
          newstruct->RHSnode = AllocateGraphNode;
          CopyFullGraphNode(newstruct->RHSnode, oldstruct->RHSnode);
          }
     else
          newstruct->RHSnode = 0;


}
extern void PrintNodeTransform(NodeTransform *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The node on the Left Hand Side:\n");
     PrintGraphNode(eleptr->LHSnode);

     printf("The node on the Right Hand Side:\n");
     PrintGraphNode(eleptr->RHSnode);

}
extern void FreeNodeTransform(NodeTransform *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeGraphNode(eleptr->LHSnode);
     Free(eleptr->LHSnode);

     FreeGraphNode(eleptr->RHSnode);
     Free(eleptr->RHSnode);

}
extern void WriteBinNodeTransform(NodeTransform *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinGraphNode(eleptr->LHSnode,file);

     WriteBinGraphNode(eleptr->RHSnode,file);

}
extern INT ReadBinNodeTransform(NodeTransform *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->LHSnode = AllocateGraphNode;
     if(ReadBinGraphNode(eleptr->LHSnode,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->LHSnode);
           eleptr->LHSnode = 0;
           }

     eleptr->RHSnode = AllocateGraphNode;
     if(ReadBinGraphNode(eleptr->RHSnode,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->RHSnode);
           eleptr->RHSnode = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_NodeTransform(XDR *stream, char **eleptrp)
{
     NodeTransform *eleptr;
     eleptr = (NodeTransform *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->LHSnode),
          GraphNodeSize,
                 (xdrproc_t) xdr_GraphNode);
     xdr_pointer(stream,
          (char **) &(eleptr->RHSnode),
          GraphNodeSize,
                 (xdrproc_t) xdr_GraphNode);
}

extern void *AllocNodeTransform()
{
     return((void *) AllocateNodeTransform);
}

extern CHAR *GetNameSetOfNodeTransforms(SetOfNodeTransforms *str)
{
     return(str->Name);
}

extern INT GetIDSetOfNodeTransforms(SetOfNodeTransforms *str)
{
     return(str->ID);
}

extern SetOfNodeTransforms *CreateSetOfNodeTransforms(SetOfNodeTransforms *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfNodeTransforms,
                                               NodeTransform *Transforms,
                                               INT  NumberRUnmatched,
                                               GraphNode *RUnmatched,
                                               INT  NumberPUnmatched,
                                               GraphNode *PUnmatched)
{
NodeTransform *oldTransforms,*newTransforms;
GraphNode *oldRUnmatched,*newRUnmatched;
GraphNode *oldPUnmatched,*newPUnmatched;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNodeTransforms = NumberOfNodeTransforms;
     newstruct->NumberRUnmatched = NumberRUnmatched;
     newstruct->NumberPUnmatched = NumberPUnmatched;

     newstruct->Transforms = AllocArrayNodeTransform(newstruct->NumberOfNodeTransforms);
     if(Transforms != 0)
          {
          oldTransforms = Transforms;
          newTransforms = newstruct->Transforms;
          LOOPi(newstruct->NumberOfNodeTransforms)
               CopyFullNodeTransform(newTransforms++, oldTransforms++);
          }

     newstruct->RUnmatched = AllocArrayGraphNode(newstruct->NumberRUnmatched);
     if(RUnmatched != 0)
          {
          oldRUnmatched = RUnmatched;
          newRUnmatched = newstruct->RUnmatched;
          LOOPi(newstruct->NumberRUnmatched)
               CopyFullGraphNode(newRUnmatched++, oldRUnmatched++);
          }

     newstruct->PUnmatched = AllocArrayGraphNode(newstruct->NumberPUnmatched);
     if(PUnmatched != 0)
          {
          oldPUnmatched = PUnmatched;
          newPUnmatched = newstruct->PUnmatched;
          LOOPi(newstruct->NumberPUnmatched)
               CopyFullGraphNode(newPUnmatched++, oldPUnmatched++);
          }



     return(newstruct);
}


extern void CopyFullSetOfNodeTransforms(SetOfNodeTransforms *newstruct, SetOfNodeTransforms *oldstruct)
{
NodeTransform *oldTransforms,*newTransforms;
GraphNode *oldRUnmatched,*newRUnmatched;
GraphNode *oldPUnmatched,*newPUnmatched;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNodeTransforms = oldstruct->NumberOfNodeTransforms;
     newstruct->NumberRUnmatched = oldstruct->NumberRUnmatched;
     newstruct->NumberPUnmatched = oldstruct->NumberPUnmatched;


     newstruct->Transforms = AllocArrayNodeTransform(newstruct->NumberOfNodeTransforms);
     if(oldstruct->Transforms != 0)
          {
          oldTransforms = oldstruct->Transforms;
          newTransforms = newstruct->Transforms;
          LOOPi(newstruct->NumberOfNodeTransforms)
               CopyFullNodeTransform(newTransforms++, oldTransforms++);
          }

     newstruct->RUnmatched = AllocArrayGraphNode(newstruct->NumberRUnmatched);
     if(oldstruct->RUnmatched != 0)
          {
          oldRUnmatched = oldstruct->RUnmatched;
          newRUnmatched = newstruct->RUnmatched;
          LOOPi(newstruct->NumberRUnmatched)
               CopyFullGraphNode(newRUnmatched++, oldRUnmatched++);
          }

     newstruct->PUnmatched = AllocArrayGraphNode(newstruct->NumberPUnmatched);
     if(oldstruct->PUnmatched != 0)
          {
          oldPUnmatched = oldstruct->PUnmatched;
          newPUnmatched = newstruct->PUnmatched;
          LOOPi(newstruct->NumberPUnmatched)
               CopyFullGraphNode(newPUnmatched++, oldPUnmatched++);
          }


}
extern void PrintSetOfNodeTransforms(SetOfNodeTransforms *eleptr)
{
NodeTransform *ptrTransforms;
GraphNode *ptrRUnmatched;
GraphNode *ptrPUnmatched;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("Number Of Nodes that are transformed:");
     printf("%d\n",eleptr->NumberOfNodeTransforms);
     printf("The number of unmatched atoms:");
     printf("%d\n",eleptr->NumberRUnmatched);
     printf("The number of unmatched atoms:");
     printf("%d\n",eleptr->NumberPUnmatched);

     printf("The Set of transforms:\n");
     if(eleptr->Transforms != 0)
          {
          ptrTransforms = eleptr->Transforms;
          LOOPi(eleptr->NumberOfNodeTransforms)
               PrintNodeTransform(ptrTransforms++);
          }


     printf("The set of Unmatched Reactant Atoms:\n");
     if(eleptr->RUnmatched != 0)
          {
          ptrRUnmatched = eleptr->RUnmatched;
          LOOPi(eleptr->NumberRUnmatched)
               PrintGraphNode(ptrRUnmatched++);
          }


     printf("The set of Unmatched Product Atoms:\n");
     if(eleptr->PUnmatched != 0)
          {
          ptrPUnmatched = eleptr->PUnmatched;
          LOOPi(eleptr->NumberPUnmatched)
               PrintGraphNode(ptrPUnmatched++);
          }


}
extern void FreeSetOfNodeTransforms(SetOfNodeTransforms *eleptr)
{
NodeTransform *ptrTransforms;
GraphNode *ptrRUnmatched;
GraphNode *ptrPUnmatched;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrTransforms = eleptr->Transforms;
     LOOPi(eleptr->NumberOfNodeTransforms)
          FreeNodeTransform(ptrTransforms++);
     Free(eleptr->Transforms);

     ptrRUnmatched = eleptr->RUnmatched;
     LOOPi(eleptr->NumberRUnmatched)
          FreeGraphNode(ptrRUnmatched++);
     Free(eleptr->RUnmatched);

     ptrPUnmatched = eleptr->PUnmatched;
     LOOPi(eleptr->NumberPUnmatched)
          FreeGraphNode(ptrPUnmatched++);
     Free(eleptr->PUnmatched);

}
extern void WriteBinSetOfNodeTransforms(SetOfNodeTransforms *eleptr, DbaseLinkedList *file)
{
NodeTransform *ptrTransforms;
GraphNode *ptrRUnmatched;
GraphNode *ptrPUnmatched;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfNodeTransforms),file);
     WriteBinINT(&(eleptr->NumberRUnmatched),file);
     WriteBinINT(&(eleptr->NumberPUnmatched),file);

     if(eleptr->Transforms != 0)
          {
          ptrTransforms = eleptr->Transforms;
          LOOPi(eleptr->NumberOfNodeTransforms)
               WriteBinNodeTransform(ptrTransforms++,file);
          }

     if(eleptr->RUnmatched != 0)
          {
          ptrRUnmatched = eleptr->RUnmatched;
          LOOPi(eleptr->NumberRUnmatched)
               WriteBinGraphNode(ptrRUnmatched++,file);
          }

     if(eleptr->PUnmatched != 0)
          {
          ptrPUnmatched = eleptr->PUnmatched;
          LOOPi(eleptr->NumberPUnmatched)
               WriteBinGraphNode(ptrPUnmatched++,file);
          }

}
extern INT ReadBinSetOfNodeTransforms(SetOfNodeTransforms *eleptr,DbaseLinkedList *file)
     {
NodeTransform *ptrTransforms;
GraphNode *ptrRUnmatched;
GraphNode *ptrPUnmatched;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNodeTransforms),file);
     ReadBinINT(&(eleptr->NumberRUnmatched),file);
     ReadBinINT(&(eleptr->NumberPUnmatched),file);

          eleptr->Transforms = AllocArrayNodeTransform(eleptr->NumberOfNodeTransforms);
          ptrTransforms = eleptr->Transforms;
          LOOPi(eleptr->NumberOfNodeTransforms)
               ReadBinNodeTransform(ptrTransforms++,file);

          eleptr->RUnmatched = AllocArrayGraphNode(eleptr->NumberRUnmatched);
          ptrRUnmatched = eleptr->RUnmatched;
          LOOPi(eleptr->NumberRUnmatched)
               ReadBinGraphNode(ptrRUnmatched++,file);

          eleptr->PUnmatched = AllocArrayGraphNode(eleptr->NumberPUnmatched);
          ptrPUnmatched = eleptr->PUnmatched;
          LOOPi(eleptr->NumberPUnmatched)
               ReadBinGraphNode(ptrPUnmatched++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfNodeTransforms(XDR *stream, char **eleptrp)
{
     SetOfNodeTransforms *eleptr;
     eleptr = (SetOfNodeTransforms *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfNodeTransforms));
     xdr_INT(stream,(char **) &(eleptr->NumberRUnmatched));
     xdr_INT(stream,(char **) &(eleptr->NumberPUnmatched));

     xdr_array(stream,(char **) &(eleptr->Transforms),
             (uint *) &(eleptr->NumberOfNodeTransforms),eleptr->NumberOfNodeTransforms,
               NodeTransformSize,(xdrproc_t) xdr_NodeTransform);
     xdr_array(stream,(char **) &(eleptr->RUnmatched),
             (uint *) &(eleptr->NumberRUnmatched),eleptr->NumberRUnmatched,
               GraphNodeSize,(xdrproc_t) xdr_GraphNode);
     xdr_array(stream,(char **) &(eleptr->PUnmatched),
             (uint *) &(eleptr->NumberPUnmatched),eleptr->NumberPUnmatched,
               GraphNodeSize,(xdrproc_t) xdr_GraphNode);
}

extern void *AllocSetOfNodeTransforms()
{
     return((void *) AllocateSetOfNodeTransforms);
}

extern CHAR *GetNameBondTransforms(BondTransforms *str)
{
     return(str->Name);
}

extern INT GetIDBondTransforms(BondTransforms *str)
{
     return(str->ID);
}

extern BondTransforms *CreateBondTransforms(BondTransforms *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfBondsMade,
                                     GraphBond *BondsMade,
                                     INT  NumberOfBondsBroken,
                                     GraphBond *BondsBroken)
{
GraphBond *oldBondsMade,*newBondsMade;
GraphBond *oldBondsBroken,*newBondsBroken;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfBondsMade = NumberOfBondsMade;
     newstruct->NumberOfBondsBroken = NumberOfBondsBroken;

     newstruct->BondsMade = AllocArrayGraphBond(newstruct->NumberOfBondsMade);
     if(BondsMade != 0)
          {
          oldBondsMade = BondsMade;
          newBondsMade = newstruct->BondsMade;
          LOOPi(newstruct->NumberOfBondsMade)
               CopyFullGraphBond(newBondsMade++, oldBondsMade++);
          }

     newstruct->BondsBroken = AllocArrayGraphBond(newstruct->NumberOfBondsBroken);
     if(BondsBroken != 0)
          {
          oldBondsBroken = BondsBroken;
          newBondsBroken = newstruct->BondsBroken;
          LOOPi(newstruct->NumberOfBondsBroken)
               CopyFullGraphBond(newBondsBroken++, oldBondsBroken++);
          }



     return(newstruct);
}


extern void CopyFullBondTransforms(BondTransforms *newstruct, BondTransforms *oldstruct)
{
GraphBond *oldBondsMade,*newBondsMade;
GraphBond *oldBondsBroken,*newBondsBroken;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfBondsMade = oldstruct->NumberOfBondsMade;
     newstruct->NumberOfBondsBroken = oldstruct->NumberOfBondsBroken;


     newstruct->BondsMade = AllocArrayGraphBond(newstruct->NumberOfBondsMade);
     if(oldstruct->BondsMade != 0)
          {
          oldBondsMade = oldstruct->BondsMade;
          newBondsMade = newstruct->BondsMade;
          LOOPi(newstruct->NumberOfBondsMade)
               CopyFullGraphBond(newBondsMade++, oldBondsMade++);
          }

     newstruct->BondsBroken = AllocArrayGraphBond(newstruct->NumberOfBondsBroken);
     if(oldstruct->BondsBroken != 0)
          {
          oldBondsBroken = oldstruct->BondsBroken;
          newBondsBroken = newstruct->BondsBroken;
          LOOPi(newstruct->NumberOfBondsBroken)
               CopyFullGraphBond(newBondsBroken++, oldBondsBroken++);
          }


}
extern void PrintBondTransforms(BondTransforms *eleptr)
{
GraphBond *ptrBondsMade;
GraphBond *ptrBondsBroken;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of bonds bonds made:");
     printf("%d\n",eleptr->NumberOfBondsMade);
     printf("The number of bond broken:");
     printf("%d\n",eleptr->NumberOfBondsBroken);

     printf("      The Made Bonds:\n");
     if(eleptr->BondsMade != 0)
          {
          ptrBondsMade = eleptr->BondsMade;
          LOOPi(eleptr->NumberOfBondsMade)
               PrintGraphBond(ptrBondsMade++);
          }


     printf("    The Broken Bonds:\n");
     if(eleptr->BondsBroken != 0)
          {
          ptrBondsBroken = eleptr->BondsBroken;
          LOOPi(eleptr->NumberOfBondsBroken)
               PrintGraphBond(ptrBondsBroken++);
          }


}
extern void FreeBondTransforms(BondTransforms *eleptr)
{
GraphBond *ptrBondsMade;
GraphBond *ptrBondsBroken;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrBondsMade = eleptr->BondsMade;
     LOOPi(eleptr->NumberOfBondsMade)
          FreeGraphBond(ptrBondsMade++);
     Free(eleptr->BondsMade);

     ptrBondsBroken = eleptr->BondsBroken;
     LOOPi(eleptr->NumberOfBondsBroken)
          FreeGraphBond(ptrBondsBroken++);
     Free(eleptr->BondsBroken);

}
extern void WriteBinBondTransforms(BondTransforms *eleptr, DbaseLinkedList *file)
{
GraphBond *ptrBondsMade;
GraphBond *ptrBondsBroken;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfBondsMade),file);
     WriteBinINT(&(eleptr->NumberOfBondsBroken),file);

     if(eleptr->BondsMade != 0)
          {
          ptrBondsMade = eleptr->BondsMade;
          LOOPi(eleptr->NumberOfBondsMade)
               WriteBinGraphBond(ptrBondsMade++,file);
          }

     if(eleptr->BondsBroken != 0)
          {
          ptrBondsBroken = eleptr->BondsBroken;
          LOOPi(eleptr->NumberOfBondsBroken)
               WriteBinGraphBond(ptrBondsBroken++,file);
          }

}
extern INT ReadBinBondTransforms(BondTransforms *eleptr,DbaseLinkedList *file)
     {
GraphBond *ptrBondsMade;
GraphBond *ptrBondsBroken;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfBondsMade),file);
     ReadBinINT(&(eleptr->NumberOfBondsBroken),file);

          eleptr->BondsMade = AllocArrayGraphBond(eleptr->NumberOfBondsMade);
          ptrBondsMade = eleptr->BondsMade;
          LOOPi(eleptr->NumberOfBondsMade)
               ReadBinGraphBond(ptrBondsMade++,file);

          eleptr->BondsBroken = AllocArrayGraphBond(eleptr->NumberOfBondsBroken);
          ptrBondsBroken = eleptr->BondsBroken;
          LOOPi(eleptr->NumberOfBondsBroken)
               ReadBinGraphBond(ptrBondsBroken++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BondTransforms(XDR *stream, char **eleptrp)
{
     BondTransforms *eleptr;
     eleptr = (BondTransforms *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfBondsMade));
     xdr_INT(stream,(char **) &(eleptr->NumberOfBondsBroken));

     xdr_array(stream,(char **) &(eleptr->BondsMade),
             (uint *) &(eleptr->NumberOfBondsMade),eleptr->NumberOfBondsMade,
               GraphBondSize,(xdrproc_t) xdr_GraphBond);
     xdr_array(stream,(char **) &(eleptr->BondsBroken),
             (uint *) &(eleptr->NumberOfBondsBroken),eleptr->NumberOfBondsBroken,
               GraphBondSize,(xdrproc_t) xdr_GraphBond);
}

extern void *AllocBondTransforms()
{
     return((void *) AllocateBondTransforms);
}

extern CHAR *GetNameBondTransformSet(BondTransformSet *str)
{
     return(str->Name);
}

extern INT GetIDBondTransformSet(BondTransformSet *str)
{
     return(str->ID);
}

extern BondTransformSet *CreateBondTransformSet(BondTransformSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         BondTransforms *LHStransform,
                                         BondTransforms *RHStransform)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(LHStransform != 0)
          {
          newstruct->LHStransform = AllocateBondTransforms;
          CopyFullBondTransforms(newstruct->LHStransform, LHStransform);
          }
     else
          newstruct->LHStransform = 0;
     if(RHStransform != 0)
          {
          newstruct->RHStransform = AllocateBondTransforms;
          CopyFullBondTransforms(newstruct->RHStransform, RHStransform);
          }
     else
          newstruct->RHStransform = 0;



     return(newstruct);
}


extern void CopyFullBondTransformSet(BondTransformSet *newstruct, BondTransformSet *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->LHStransform != 0)
          {
          newstruct->LHStransform = AllocateBondTransforms;
          CopyFullBondTransforms(newstruct->LHStransform, oldstruct->LHStransform);
          }
     else
          newstruct->LHStransform = 0;
     if(oldstruct->RHStransform != 0)
          {
          newstruct->RHStransform = AllocateBondTransforms;
          CopyFullBondTransforms(newstruct->RHStransform, oldstruct->RHStransform);
          }
     else
          newstruct->RHStransform = 0;


}
extern void PrintBondTransformSet(BondTransformSet *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The bonds on the LHS that are present but not on RHS:\n");
     PrintBondTransforms(eleptr->LHStransform);

     printf("The bonds on the RHS that are present but not on LHS:\n");
     PrintBondTransforms(eleptr->RHStransform);

}
extern void FreeBondTransformSet(BondTransformSet *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeBondTransforms(eleptr->LHStransform);
     Free(eleptr->LHStransform);

     FreeBondTransforms(eleptr->RHStransform);
     Free(eleptr->RHStransform);

}
extern void WriteBinBondTransformSet(BondTransformSet *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinBondTransforms(eleptr->LHStransform,file);

     WriteBinBondTransforms(eleptr->RHStransform,file);

}
extern INT ReadBinBondTransformSet(BondTransformSet *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->LHStransform = AllocateBondTransforms;
     if(ReadBinBondTransforms(eleptr->LHStransform,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->LHStransform);
           eleptr->LHStransform = 0;
           }

     eleptr->RHStransform = AllocateBondTransforms;
     if(ReadBinBondTransforms(eleptr->RHStransform,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->RHStransform);
           eleptr->RHStransform = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BondTransformSet(XDR *stream, char **eleptrp)
{
     BondTransformSet *eleptr;
     eleptr = (BondTransformSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->LHStransform),
          BondTransformsSize,
                 (xdrproc_t) xdr_BondTransforms);
     xdr_pointer(stream,
          (char **) &(eleptr->RHStransform),
          BondTransformsSize,
                 (xdrproc_t) xdr_BondTransforms);
}

extern void *AllocBondTransformSet()
{
     return((void *) AllocateBondTransformSet);
}

extern CHAR *GetNameGraphTransform(GraphTransform *str)
{
     return(str->Name);
}

extern INT GetIDGraphTransform(GraphTransform *str)
{
     return(str->ID);
}

extern GraphTransform *CreateGraphTransform(GraphTransform *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberLHS,
                                     INT  NumberRHS,
                                     Graph *GraphLHS,
                                     Graph *GraphRHS,
                                     SetOfNodeTransforms *Nodes,
                                     BondTransformSet *Bonds)
{
Graph *oldGraphLHS,*newGraphLHS;
Graph *oldGraphRHS,*newGraphRHS;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberLHS = NumberLHS;
     newstruct->NumberRHS = NumberRHS;
     if(Nodes != 0)
          {
          newstruct->Nodes = AllocateSetOfNodeTransforms;
          CopyFullSetOfNodeTransforms(newstruct->Nodes, Nodes);
          }
     else
          newstruct->Nodes = 0;
     if(Bonds != 0)
          {
          newstruct->Bonds = AllocateBondTransformSet;
          CopyFullBondTransformSet(newstruct->Bonds, Bonds);
          }
     else
          newstruct->Bonds = 0;

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


extern void CopyFullGraphTransform(GraphTransform *newstruct, GraphTransform *oldstruct)
{
Graph *oldGraphLHS,*newGraphLHS;
Graph *oldGraphRHS,*newGraphRHS;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberLHS = oldstruct->NumberLHS;
     newstruct->NumberRHS = oldstruct->NumberRHS;

     if(oldstruct->Nodes != 0)
          {
          newstruct->Nodes = AllocateSetOfNodeTransforms;
          CopyFullSetOfNodeTransforms(newstruct->Nodes, oldstruct->Nodes);
          }
     else
          newstruct->Nodes = 0;
     if(oldstruct->Bonds != 0)
          {
          newstruct->Bonds = AllocateBondTransformSet;
          CopyFullBondTransformSet(newstruct->Bonds, oldstruct->Bonds);
          }
     else
          newstruct->Bonds = 0;

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
extern void PrintGraphTransform(GraphTransform *eleptr)
{
Graph *ptrGraphLHS;
Graph *ptrGraphRHS;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Graphs on the LHS:");
     printf("%d\n",eleptr->NumberLHS);
     printf("The number of Graphs on the RHS:");
     printf("%d\n",eleptr->NumberRHS);

     printf(" The Node Transforms:\n");
     PrintSetOfNodeTransforms(eleptr->Nodes);

     printf(" The Bond Transforms:\n");
     PrintBondTransformSet(eleptr->Bonds);

     printf("The set of graphs on the LHS:\n");
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
extern void FreeGraphTransform(GraphTransform *eleptr)
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

     FreeSetOfNodeTransforms(eleptr->Nodes);
     Free(eleptr->Nodes);

     FreeBondTransformSet(eleptr->Bonds);
     Free(eleptr->Bonds);

}
extern void WriteBinGraphTransform(GraphTransform *eleptr, DbaseLinkedList *file)
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

     WriteBinSetOfNodeTransforms(eleptr->Nodes,file);

     WriteBinBondTransformSet(eleptr->Bonds,file);

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
extern INT ReadBinGraphTransform(GraphTransform *eleptr,DbaseLinkedList *file)
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

     eleptr->Nodes = AllocateSetOfNodeTransforms;
     if(ReadBinSetOfNodeTransforms(eleptr->Nodes,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Nodes);
           eleptr->Nodes = 0;
           }

     eleptr->Bonds = AllocateBondTransformSet;
     if(ReadBinBondTransformSet(eleptr->Bonds,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Bonds);
           eleptr->Bonds = 0;
           }

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
extern void xdr_GraphTransform(XDR *stream, char **eleptrp)
{
     GraphTransform *eleptr;
     eleptr = (GraphTransform *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberLHS));
     xdr_INT(stream,(char **) &(eleptr->NumberRHS));

     xdr_pointer(stream,
          (char **) &(eleptr->Nodes),
          SetOfNodeTransformsSize,
                 (xdrproc_t) xdr_SetOfNodeTransforms);
     xdr_pointer(stream,
          (char **) &(eleptr->Bonds),
          BondTransformSetSize,
                 (xdrproc_t) xdr_BondTransformSet);
     xdr_array(stream,(char **) &(eleptr->GraphLHS),
             (uint *) &(eleptr->NumberLHS),eleptr->NumberLHS,
               GraphSize,(xdrproc_t) xdr_Graph);
     xdr_array(stream,(char **) &(eleptr->GraphRHS),
             (uint *) &(eleptr->NumberRHS),eleptr->NumberRHS,
               GraphSize,(xdrproc_t) xdr_Graph);
}

extern void *AllocGraphTransform()
{
     return((void *) AllocateGraphTransform);
}

extern CHAR *GetNameTransformGraphCorrSet(TransformGraphCorrSet *str)
{
     return(str->Name);
}

extern INT GetIDTransformGraphCorrSet(TransformGraphCorrSet *str)
{
     return(str->ID);
}

extern TransformGraphCorrSet *CreateTransformGraphCorrSet(TransformGraphCorrSet *newstruct,
                                                   INT id,
                                                   CHAR *name,
                                                   INT  NumberOfGraphs,
                                                   SetOfPairSets *TransformPairSet)
{
SetOfPairSets *oldTransformPairSet,*newTransformPairSet;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfGraphs = NumberOfGraphs;

     newstruct->TransformPairSet = AllocArraySetOfPairSets(newstruct->NumberOfGraphs);
     if(TransformPairSet != 0)
          {
          oldTransformPairSet = TransformPairSet;
          newTransformPairSet = newstruct->TransformPairSet;
          LOOPi(newstruct->NumberOfGraphs)
               CopyFullSetOfPairSets(newTransformPairSet++, oldTransformPairSet++);
          }



     return(newstruct);
}


extern void CopyFullTransformGraphCorrSet(TransformGraphCorrSet *newstruct, TransformGraphCorrSet *oldstruct)
{
SetOfPairSets *oldTransformPairSet,*newTransformPairSet;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfGraphs = oldstruct->NumberOfGraphs;


     newstruct->TransformPairSet = AllocArraySetOfPairSets(newstruct->NumberOfGraphs);
     if(oldstruct->TransformPairSet != 0)
          {
          oldTransformPairSet = oldstruct->TransformPairSet;
          newTransformPairSet = newstruct->TransformPairSet;
          LOOPi(newstruct->NumberOfGraphs)
               CopyFullSetOfPairSets(newTransformPairSet++, oldTransformPairSet++);
          }


}
extern void PrintTransformGraphCorrSet(TransformGraphCorrSet *eleptr)
{
SetOfPairSets *ptrTransformPairSet;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of graphs in the transform:");
     printf("%d\n",eleptr->NumberOfGraphs);

     printf("The SetOfPairSets for each transform graph:\n");
     if(eleptr->TransformPairSet != 0)
          {
          ptrTransformPairSet = eleptr->TransformPairSet;
          LOOPi(eleptr->NumberOfGraphs)
               PrintSetOfPairSets(ptrTransformPairSet++);
          }


}
extern void FreeTransformGraphCorrSet(TransformGraphCorrSet *eleptr)
{
SetOfPairSets *ptrTransformPairSet;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrTransformPairSet = eleptr->TransformPairSet;
     LOOPi(eleptr->NumberOfGraphs)
          FreeSetOfPairSets(ptrTransformPairSet++);
     Free(eleptr->TransformPairSet);

}
extern void WriteBinTransformGraphCorrSet(TransformGraphCorrSet *eleptr, DbaseLinkedList *file)
{
SetOfPairSets *ptrTransformPairSet;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfGraphs),file);

     if(eleptr->TransformPairSet != 0)
          {
          ptrTransformPairSet = eleptr->TransformPairSet;
          LOOPi(eleptr->NumberOfGraphs)
               WriteBinSetOfPairSets(ptrTransformPairSet++,file);
          }

}
extern INT ReadBinTransformGraphCorrSet(TransformGraphCorrSet *eleptr,DbaseLinkedList *file)
     {
SetOfPairSets *ptrTransformPairSet;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfGraphs),file);

          eleptr->TransformPairSet = AllocArraySetOfPairSets(eleptr->NumberOfGraphs);
          ptrTransformPairSet = eleptr->TransformPairSet;
          LOOPi(eleptr->NumberOfGraphs)
               ReadBinSetOfPairSets(ptrTransformPairSet++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_TransformGraphCorrSet(XDR *stream, char **eleptrp)
{
     TransformGraphCorrSet *eleptr;
     eleptr = (TransformGraphCorrSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfGraphs));

     xdr_array(stream,(char **) &(eleptr->TransformPairSet),
             (uint *) &(eleptr->NumberOfGraphs),eleptr->NumberOfGraphs,
               SetOfPairSetsSize,(xdrproc_t) xdr_SetOfPairSets);
}

extern void *AllocTransformGraphCorrSet()
{
     return((void *) AllocateTransformGraphCorrSet);
}

extern CHAR *GetNameGraphTransformGraphTree(GraphTransformGraphTree *str)
{
     return(str->Name);
}

extern INT GetIDGraphTransformGraphTree(GraphTransformGraphTree *str)
{
     return(str->ID);
}

extern GraphTransformGraphTree *CreateGraphTransformGraphTree(GraphTransformGraphTree *newstruct,
INT id,
CHAR *name,
TransformGraphCorrSet *CorrSets,
INT  NumberOfSubTrees,
GraphTransformGraphTree *SubTree)
{
GraphTransformGraphTree *oldSubTree,*newSubTree;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSubTrees = NumberOfSubTrees;
     if(CorrSets != 0)
          {
          newstruct->CorrSets = AllocateTransformGraphCorrSet;
          CopyFullTransformGraphCorrSet(newstruct->CorrSets, CorrSets);
          }
     else
          newstruct->CorrSets = 0;

     newstruct->SubTree = AllocArrayGraphTransformGraphTree(newstruct->NumberOfSubTrees);
     if(SubTree != 0)
          {
          oldSubTree = SubTree;
          newSubTree = newstruct->SubTree;
          LOOPi(newstruct->NumberOfSubTrees)
               CopyFullGraphTransformGraphTree(newSubTree++, oldSubTree++);
          }



     return(newstruct);
}


extern void CopyFullGraphTransformGraphTree(GraphTransformGraphTree *newstruct, GraphTransformGraphTree *oldstruct)
{
GraphTransformGraphTree *oldSubTree,*newSubTree;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSubTrees = oldstruct->NumberOfSubTrees;

     if(oldstruct->CorrSets != 0)
          {
          newstruct->CorrSets = AllocateTransformGraphCorrSet;
          CopyFullTransformGraphCorrSet(newstruct->CorrSets, oldstruct->CorrSets);
          }
     else
          newstruct->CorrSets = 0;

     newstruct->SubTree = AllocArrayGraphTransformGraphTree(newstruct->NumberOfSubTrees);
     if(oldstruct->SubTree != 0)
          {
          oldSubTree = oldstruct->SubTree;
          newSubTree = newstruct->SubTree;
          LOOPi(newstruct->NumberOfSubTrees)
               CopyFullGraphTransformGraphTree(newSubTree++, oldSubTree++);
          }


}
extern void PrintGraphTransformGraphTree(GraphTransformGraphTree *eleptr)
{
GraphTransformGraphTree *ptrSubTree;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of subtrees (total combinations of graphs and corrs):");
     printf("%d\n",eleptr->NumberOfSubTrees);

     printf("The set of graph reaction correspondences:\n");
     PrintTransformGraphCorrSet(eleptr->CorrSets);

     printf("The correspondence subtree:\n");
     if(eleptr->SubTree != 0)
          {
          ptrSubTree = eleptr->SubTree;
          LOOPi(eleptr->NumberOfSubTrees)
               PrintGraphTransformGraphTree(ptrSubTree++);
          }


}
extern void FreeGraphTransformGraphTree(GraphTransformGraphTree *eleptr)
{
GraphTransformGraphTree *ptrSubTree;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSubTree = eleptr->SubTree;
     LOOPi(eleptr->NumberOfSubTrees)
          FreeGraphTransformGraphTree(ptrSubTree++);
     Free(eleptr->SubTree);

     FreeTransformGraphCorrSet(eleptr->CorrSets);
     Free(eleptr->CorrSets);

}
extern void WriteBinGraphTransformGraphTree(GraphTransformGraphTree *eleptr, DbaseLinkedList *file)
{
GraphTransformGraphTree *ptrSubTree;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSubTrees),file);

     WriteBinTransformGraphCorrSet(eleptr->CorrSets,file);

     if(eleptr->SubTree != 0)
          {
          ptrSubTree = eleptr->SubTree;
          LOOPi(eleptr->NumberOfSubTrees)
               WriteBinGraphTransformGraphTree(ptrSubTree++,file);
          }

}
extern INT ReadBinGraphTransformGraphTree(GraphTransformGraphTree *eleptr,DbaseLinkedList *file)
     {
GraphTransformGraphTree *ptrSubTree;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSubTrees),file);

     eleptr->CorrSets = AllocateTransformGraphCorrSet;
     if(ReadBinTransformGraphCorrSet(eleptr->CorrSets,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->CorrSets);
           eleptr->CorrSets = 0;
           }

          eleptr->SubTree = AllocArrayGraphTransformGraphTree(eleptr->NumberOfSubTrees);
          ptrSubTree = eleptr->SubTree;
          LOOPi(eleptr->NumberOfSubTrees)
               ReadBinGraphTransformGraphTree(ptrSubTree++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_GraphTransformGraphTree(XDR *stream, char **eleptrp)
{
     GraphTransformGraphTree *eleptr;
     eleptr = (GraphTransformGraphTree *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSubTrees));

     xdr_pointer(stream,
          (char **) &(eleptr->CorrSets),
          TransformGraphCorrSetSize,
                 (xdrproc_t) xdr_TransformGraphCorrSet);
     xdr_array(stream,(char **) &(eleptr->SubTree),
             (uint *) &(eleptr->NumberOfSubTrees),eleptr->NumberOfSubTrees,
               GraphTransformGraphTreeSize,(xdrproc_t) xdr_GraphTransformGraphTree);
}

extern void *AllocGraphTransformGraphTree()
{
     return((void *) AllocateGraphTransformGraphTree);
}

extern CHAR *GetNameTransformSet(TransformSet *str)
{
     return(str->Name);
}

extern INT GetIDTransformSet(TransformSet *str)
{
     return(str->ID);
}

extern TransformSet *CreateTransformSet(TransformSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfTransforms,
                                 GraphTransform *Set)
{
GraphTransform *oldSet,*newSet;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfTransforms = NumberOfTransforms;

     newstruct->Set = AllocArrayGraphTransform(newstruct->NumberOfTransforms);
     if(Set != 0)
          {
          oldSet = Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfTransforms)
               CopyFullGraphTransform(newSet++, oldSet++);
          }



     return(newstruct);
}


extern void CopyFullTransformSet(TransformSet *newstruct, TransformSet *oldstruct)
{
GraphTransform *oldSet,*newSet;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfTransforms = oldstruct->NumberOfTransforms;


     newstruct->Set = AllocArrayGraphTransform(newstruct->NumberOfTransforms);
     if(oldstruct->Set != 0)
          {
          oldSet = oldstruct->Set;
          newSet = newstruct->Set;
          LOOPi(newstruct->NumberOfTransforms)
               CopyFullGraphTransform(newSet++, oldSet++);
          }


}
extern void PrintTransformSet(TransformSet *eleptr)
{
GraphTransform *ptrSet;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Transforms:");
     printf("%d\n",eleptr->NumberOfTransforms);

     printf("The set of Transforms:\n");
     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfTransforms)
               PrintGraphTransform(ptrSet++);
          }


}
extern void FreeTransformSet(TransformSet *eleptr)
{
GraphTransform *ptrSet;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSet = eleptr->Set;
     LOOPi(eleptr->NumberOfTransforms)
          FreeGraphTransform(ptrSet++);
     Free(eleptr->Set);

}
extern void WriteBinTransformSet(TransformSet *eleptr, DbaseLinkedList *file)
{
GraphTransform *ptrSet;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfTransforms),file);

     if(eleptr->Set != 0)
          {
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfTransforms)
               WriteBinGraphTransform(ptrSet++,file);
          }

}
extern INT ReadBinTransformSet(TransformSet *eleptr,DbaseLinkedList *file)
     {
GraphTransform *ptrSet;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfTransforms),file);

          eleptr->Set = AllocArrayGraphTransform(eleptr->NumberOfTransforms);
          ptrSet = eleptr->Set;
          LOOPi(eleptr->NumberOfTransforms)
               ReadBinGraphTransform(ptrSet++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_TransformSet(XDR *stream, char **eleptrp)
{
     TransformSet *eleptr;
     eleptr = (TransformSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfTransforms));

     xdr_array(stream,(char **) &(eleptr->Set),
             (uint *) &(eleptr->NumberOfTransforms),eleptr->NumberOfTransforms,
               GraphTransformSize,(xdrproc_t) xdr_GraphTransform);
}

extern void *AllocTransformSet()
{
     return((void *) AllocateTransformSet);
}

extern CHAR *GetNameSetOfGraphNodePairs(SetOfGraphNodePairs *str)
{
     return(str->Name);
}

extern INT GetIDSetOfGraphNodePairs(SetOfGraphNodePairs *str)
{
     return(str->ID);
}

extern SetOfGraphNodePairs *CreateSetOfGraphNodePairs(SetOfGraphNodePairs *newstruct,
                                               INT id,
                                               CHAR *name,
                                               INT  NumberOfPairs,
                                               GraphNodePair *Pairs)
{
GraphNodePair *oldPairs,*newPairs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPairs = NumberOfPairs;

     newstruct->Pairs = AllocArrayGraphNodePair(newstruct->NumberOfPairs);
     if(Pairs != 0)
          {
          oldPairs = Pairs;
          newPairs = newstruct->Pairs;
          LOOPi(newstruct->NumberOfPairs)
               CopyFullGraphNodePair(newPairs++, oldPairs++);
          }



     return(newstruct);
}


extern void CopyFullSetOfGraphNodePairs(SetOfGraphNodePairs *newstruct, SetOfGraphNodePairs *oldstruct)
{
GraphNodePair *oldPairs,*newPairs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPairs = oldstruct->NumberOfPairs;


     newstruct->Pairs = AllocArrayGraphNodePair(newstruct->NumberOfPairs);
     if(oldstruct->Pairs != 0)
          {
          oldPairs = oldstruct->Pairs;
          newPairs = newstruct->Pairs;
          LOOPi(newstruct->NumberOfPairs)
               CopyFullGraphNodePair(newPairs++, oldPairs++);
          }


}
extern void PrintSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr)
{
GraphNodePair *ptrPairs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number Of GraphNodePairs:");
     printf("%d\n",eleptr->NumberOfPairs);

     printf("The Set of GraphNOdePairs:\n");
     if(eleptr->Pairs != 0)
          {
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               PrintGraphNodePair(ptrPairs++);
          }


}
extern void FreeSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr)
{
GraphNodePair *ptrPairs;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrPairs = eleptr->Pairs;
     LOOPi(eleptr->NumberOfPairs)
          FreeGraphNodePair(ptrPairs++);
     Free(eleptr->Pairs);

}
extern void WriteBinSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr, DbaseLinkedList *file)
{
GraphNodePair *ptrPairs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPairs),file);

     if(eleptr->Pairs != 0)
          {
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               WriteBinGraphNodePair(ptrPairs++,file);
          }

}
extern INT ReadBinSetOfGraphNodePairs(SetOfGraphNodePairs *eleptr,DbaseLinkedList *file)
     {
GraphNodePair *ptrPairs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPairs),file);

          eleptr->Pairs = AllocArrayGraphNodePair(eleptr->NumberOfPairs);
          ptrPairs = eleptr->Pairs;
          LOOPi(eleptr->NumberOfPairs)
               ReadBinGraphNodePair(ptrPairs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfGraphNodePairs(XDR *stream, char **eleptrp)
{
     SetOfGraphNodePairs *eleptr;
     eleptr = (SetOfGraphNodePairs *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPairs));

     xdr_array(stream,(char **) &(eleptr->Pairs),
             (uint *) &(eleptr->NumberOfPairs),eleptr->NumberOfPairs,
               GraphNodePairSize,(xdrproc_t) xdr_GraphNodePair);
}

extern void *AllocSetOfGraphNodePairs()
{
     return((void *) AllocateSetOfGraphNodePairs);
}

extern CHAR *GetNameTotalSetOfTransformPairs(TotalSetOfTransformPairs *str)
{
     return(str->Name);
}

extern INT GetIDTotalSetOfTransformPairs(TotalSetOfTransformPairs *str)
{
     return(str->ID);
}

extern TotalSetOfTransformPairs *CreateTotalSetOfTransformPairs(TotalSetOfTransformPairs *newstruct,
INT id,
CHAR *name,
INT  NumberOfPairSets,
SetOfGraphNodePairs *PairSets)
{
SetOfGraphNodePairs *oldPairSets,*newPairSets;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPairSets = NumberOfPairSets;

     newstruct->PairSets = AllocArraySetOfGraphNodePairs(newstruct->NumberOfPairSets);
     if(PairSets != 0)
          {
          oldPairSets = PairSets;
          newPairSets = newstruct->PairSets;
          LOOPi(newstruct->NumberOfPairSets)
               CopyFullSetOfGraphNodePairs(newPairSets++, oldPairSets++);
          }



     return(newstruct);
}


extern void CopyFullTotalSetOfTransformPairs(TotalSetOfTransformPairs *newstruct, TotalSetOfTransformPairs *oldstruct)
{
SetOfGraphNodePairs *oldPairSets,*newPairSets;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPairSets = oldstruct->NumberOfPairSets;


     newstruct->PairSets = AllocArraySetOfGraphNodePairs(newstruct->NumberOfPairSets);
     if(oldstruct->PairSets != 0)
          {
          oldPairSets = oldstruct->PairSets;
          newPairSets = newstruct->PairSets;
          LOOPi(newstruct->NumberOfPairSets)
               CopyFullSetOfGraphNodePairs(newPairSets++, oldPairSets++);
          }


}
extern void PrintTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr)
{
SetOfGraphNodePairs *ptrPairSets;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The Number Of Sets:");
     printf("%d\n",eleptr->NumberOfPairSets);

     printf("       The Pair Sets:\n");
     if(eleptr->PairSets != 0)
          {
          ptrPairSets = eleptr->PairSets;
          LOOPi(eleptr->NumberOfPairSets)
               PrintSetOfGraphNodePairs(ptrPairSets++);
          }


}
extern void FreeTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr)
{
SetOfGraphNodePairs *ptrPairSets;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrPairSets = eleptr->PairSets;
     LOOPi(eleptr->NumberOfPairSets)
          FreeSetOfGraphNodePairs(ptrPairSets++);
     Free(eleptr->PairSets);

}
extern void WriteBinTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr, DbaseLinkedList *file)
{
SetOfGraphNodePairs *ptrPairSets;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPairSets),file);

     if(eleptr->PairSets != 0)
          {
          ptrPairSets = eleptr->PairSets;
          LOOPi(eleptr->NumberOfPairSets)
               WriteBinSetOfGraphNodePairs(ptrPairSets++,file);
          }

}
extern INT ReadBinTotalSetOfTransformPairs(TotalSetOfTransformPairs *eleptr,DbaseLinkedList *file)
     {
SetOfGraphNodePairs *ptrPairSets;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPairSets),file);

          eleptr->PairSets = AllocArraySetOfGraphNodePairs(eleptr->NumberOfPairSets);
          ptrPairSets = eleptr->PairSets;
          LOOPi(eleptr->NumberOfPairSets)
               ReadBinSetOfGraphNodePairs(ptrPairSets++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_TotalSetOfTransformPairs(XDR *stream, char **eleptrp)
{
     TotalSetOfTransformPairs *eleptr;
     eleptr = (TotalSetOfTransformPairs *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPairSets));

     xdr_array(stream,(char **) &(eleptr->PairSets),
             (uint *) &(eleptr->NumberOfPairSets),eleptr->NumberOfPairSets,
               SetOfGraphNodePairsSize,(xdrproc_t) xdr_SetOfGraphNodePairs);
}

extern void *AllocTotalSetOfTransformPairs()
{
     return((void *) AllocateTotalSetOfTransformPairs);
}
