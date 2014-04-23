
extern CHAR *GetNameTreeLevelDescription(TreeLevelDescription *str)
{
     return(str->Name);
}

extern INT GetIDTreeLevelDescription(TreeLevelDescription *str)
{
     return(str->ID);
}

extern TreeLevelDescription *CreateTreeLevelDescription(TreeLevelDescription *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  IDMultFactor,
                                                 INT  MaxSize)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->IDMultFactor = IDMultFactor;
     newstruct->MaxSize = MaxSize;



     return(newstruct);
}


extern void CopyFullTreeLevelDescription(TreeLevelDescription *newstruct, TreeLevelDescription *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->IDMultFactor = oldstruct->IDMultFactor;
     newstruct->MaxSize = oldstruct->MaxSize;
     newstruct->LevelIDFunc = oldstruct->LevelIDFunc;



}
extern void PrintTreeLevelDescription(TreeLevelDescription *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The ID Multiplication Factor:");
     printf("%d\n",eleptr->IDMultFactor);
     printf("The Maximum Size of the id:");
     printf("%d\n",eleptr->MaxSize);

}
extern void FreeTreeLevelDescription(TreeLevelDescription *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinTreeLevelDescription(TreeLevelDescription *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->IDMultFactor),file);
     WriteBinINT(&(eleptr->MaxSize),file);

}
extern INT ReadBinTreeLevelDescription(TreeLevelDescription *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->IDMultFactor),file);
     ReadBinINT(&(eleptr->MaxSize),file);

     return(STRUCTURE_READ);
     }
extern void xdr_TreeLevelDescription(XDR *stream, char **eleptrp)
{
     TreeLevelDescription *eleptr;
     eleptr = (TreeLevelDescription *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->IDMultFactor));
     xdr_INT(stream,(char **) &(eleptr->MaxSize));

}

extern void *AllocTreeLevelDescription()
{
     return((void *) AllocateTreeLevelDescription);
}

extern CHAR *GetNameListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *str)
{
     return(str->Name);
}

extern INT GetIDListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *str)
{
     return(str->ID);
}

extern ListOfTreeLevelDescriptions *CreateListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *newstruct,
INT id,
CHAR *name,
INT  NumberOfLevels,
TreeLevelDescription *Levels,
INT  BindStruct,
INT  Database,
INT  KeyType)
{
TreeLevelDescription *oldLevels,*newLevels;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfLevels = NumberOfLevels;
     newstruct->BindStruct = BindStruct;
     newstruct->Database = Database;
     newstruct->KeyType = KeyType;

     newstruct->Levels = AllocArrayTreeLevelDescription(newstruct->NumberOfLevels);
     if(Levels != 0)
          {
          oldLevels = Levels;
          newLevels = newstruct->Levels;
          LOOPi(newstruct->NumberOfLevels)
               CopyFullTreeLevelDescription(newLevels++, oldLevels++);
          }



     return(newstruct);
}


extern void CopyFullListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *newstruct, ListOfTreeLevelDescriptions *oldstruct)
{
TreeLevelDescription *oldLevels,*newLevels;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfLevels = oldstruct->NumberOfLevels;
     newstruct->BindStruct = oldstruct->BindStruct;
     newstruct->Database = oldstruct->Database;
     newstruct->KeyType = oldstruct->KeyType;


     newstruct->Levels = AllocArrayTreeLevelDescription(newstruct->NumberOfLevels);
     if(oldstruct->Levels != 0)
          {
          oldLevels = oldstruct->Levels;
          newLevels = newstruct->Levels;
          LOOPi(newstruct->NumberOfLevels)
               CopyFullTreeLevelDescription(newLevels++, oldLevels++);
          }


}
extern void PrintListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr)
{
TreeLevelDescription *ptrLevels;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of tree levels:");
     printf("%d\n",eleptr->NumberOfLevels);
     printf("The id of the bind structure (to get local list):");
     printf("%d\n",eleptr->BindStruct);
     printf("The id of the database of structures :");
     printf("%d\n",eleptr->Database);
     printf("The id of the keyword type:");
     printf("%d\n",eleptr->KeyType);

     printf("   The set of levels:\n");
     if(eleptr->Levels != 0)
          {
          ptrLevels = eleptr->Levels;
          LOOPi(eleptr->NumberOfLevels)
               PrintTreeLevelDescription(ptrLevels++);
          }


}
extern void FreeListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr)
{
TreeLevelDescription *ptrLevels;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrLevels = eleptr->Levels;
     LOOPi(eleptr->NumberOfLevels)
          FreeTreeLevelDescription(ptrLevels++);
     Free(eleptr->Levels);

}
extern void WriteBinListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr, DbaseLinkedList *file)
{
TreeLevelDescription *ptrLevels;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfLevels),file);
     WriteBinINT(&(eleptr->BindStruct),file);
     WriteBinINT(&(eleptr->Database),file);
     WriteBinINT(&(eleptr->KeyType),file);

     if(eleptr->Levels != 0)
          {
          ptrLevels = eleptr->Levels;
          LOOPi(eleptr->NumberOfLevels)
               WriteBinTreeLevelDescription(ptrLevels++,file);
          }

}
extern INT ReadBinListOfTreeLevelDescriptions(ListOfTreeLevelDescriptions *eleptr,DbaseLinkedList *file)
     {
TreeLevelDescription *ptrLevels;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfLevels),file);
     ReadBinINT(&(eleptr->BindStruct),file);
     ReadBinINT(&(eleptr->Database),file);
     ReadBinINT(&(eleptr->KeyType),file);

          eleptr->Levels = AllocArrayTreeLevelDescription(eleptr->NumberOfLevels);
          ptrLevels = eleptr->Levels;
          LOOPi(eleptr->NumberOfLevels)
               ReadBinTreeLevelDescription(ptrLevels++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ListOfTreeLevelDescriptions(XDR *stream, char **eleptrp)
{
     ListOfTreeLevelDescriptions *eleptr;
     eleptr = (ListOfTreeLevelDescriptions *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfLevels));
     xdr_INT(stream,(char **) &(eleptr->BindStruct));
     xdr_INT(stream,(char **) &(eleptr->Database));
     xdr_INT(stream,(char **) &(eleptr->KeyType));

     xdr_array(stream,(char **) &(eleptr->Levels),
             (uint *) &(eleptr->NumberOfLevels),eleptr->NumberOfLevels,
               TreeLevelDescriptionSize,(xdrproc_t) xdr_TreeLevelDescription);
}

extern void *AllocListOfTreeLevelDescriptions()
{
     return((void *) AllocateListOfTreeLevelDescriptions);
}

extern CHAR *GetNameObjectIDInfo(ObjectIDInfo *str)
{
     return(str->Name);
}

extern INT GetIDObjectIDInfo(ObjectIDInfo *str)
{
     return(str->ID);
}

extern ObjectIDInfo *CreateObjectIDInfo(ObjectIDInfo *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumberOfObjectIDs,
                                 INT *ObjectIDs)
{
INT *oldObjectIDs,*newObjectIDs;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfObjectIDs = NumberOfObjectIDs;

     newstruct->ObjectIDs = AllocArrayINT(newstruct->NumberOfObjectIDs);
     if(ObjectIDs != 0)
          {
          oldObjectIDs = ObjectIDs;
          newObjectIDs = newstruct->ObjectIDs;
          LOOPi(newstruct->NumberOfObjectIDs)
               CopyFullINT(newObjectIDs++, oldObjectIDs++);
          }



     return(newstruct);
}


extern void CopyFullObjectIDInfo(ObjectIDInfo *newstruct, ObjectIDInfo *oldstruct)
{
INT *oldObjectIDs,*newObjectIDs;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfObjectIDs = oldstruct->NumberOfObjectIDs;


     newstruct->ObjectIDs = AllocArrayINT(newstruct->NumberOfObjectIDs);
     if(oldstruct->ObjectIDs != 0)
          {
          oldObjectIDs = oldstruct->ObjectIDs;
          newObjectIDs = newstruct->ObjectIDs;
          LOOPi(newstruct->NumberOfObjectIDs)
               CopyFullINT(newObjectIDs++, oldObjectIDs++);
          }


}
extern void PrintObjectIDInfo(ObjectIDInfo *eleptr)
{
INT *ptrObjectIDs;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of object id's:");
     printf("%d\n",eleptr->NumberOfObjectIDs);

     printf("The list of object id's:\n");
     if(eleptr->ObjectIDs != 0)
          {
          ptrObjectIDs = eleptr->ObjectIDs;
          LOOPi(eleptr->NumberOfObjectIDs)
               PrintINT(ptrObjectIDs++);
          }


}
extern void FreeObjectIDInfo(ObjectIDInfo *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->ObjectIDs);

}
extern void WriteBinObjectIDInfo(ObjectIDInfo *eleptr, DbaseLinkedList *file)
{
INT *ptrObjectIDs;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfObjectIDs),file);

     if(eleptr->ObjectIDs != 0)
          {
          ptrObjectIDs = eleptr->ObjectIDs;
          LOOPi(eleptr->NumberOfObjectIDs)
               WriteBinINT(ptrObjectIDs++,file);
          }

}
extern INT ReadBinObjectIDInfo(ObjectIDInfo *eleptr,DbaseLinkedList *file)
     {
INT *ptrObjectIDs;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfObjectIDs),file);

          eleptr->ObjectIDs = AllocArrayINT(eleptr->NumberOfObjectIDs);
          ptrObjectIDs = eleptr->ObjectIDs;
          LOOPi(eleptr->NumberOfObjectIDs)
               ReadBinINT(ptrObjectIDs++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ObjectIDInfo(XDR *stream, char **eleptrp)
{
     ObjectIDInfo *eleptr;
     eleptr = (ObjectIDInfo *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfObjectIDs));

     xdr_array(stream,(char **) &(eleptr->ObjectIDs),
             (uint *) &(eleptr->NumberOfObjectIDs),eleptr->NumberOfObjectIDs,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocObjectIDInfo()
{
     return((void *) AllocateObjectIDInfo);
}

extern CHAR *GetNameObjectIDClass(ObjectIDClass *str)
{
     return(str->Name);
}

extern INT GetIDObjectIDClass(ObjectIDClass *str)
{
     return(str->ID);
}

extern ObjectIDClass *CreateObjectIDClass(ObjectIDClass *newstruct,
                                   INT id,
                                   CHAR *name,
                                   ObjectIDInfo *Info,
                                   INT  NumberOfKeys,
                                   DbaseKeyword *Keys)
{
DbaseKeyword *oldKeys,*newKeys;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfKeys = NumberOfKeys;
     if(Info != 0)
          {
          newstruct->Info = AllocateObjectIDInfo;
          CopyFullObjectIDInfo(newstruct->Info, Info);
          }
     else
          newstruct->Info = 0;

     newstruct->Keys = AllocArrayDbaseKeyword(newstruct->NumberOfKeys);
     if(Keys != 0)
          {
          oldKeys = Keys;
          newKeys = newstruct->Keys;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullDbaseKeyword(newKeys++, oldKeys++);
          }



     return(newstruct);
}


extern void CopyFullObjectIDClass(ObjectIDClass *newstruct, ObjectIDClass *oldstruct)
{
DbaseKeyword *oldKeys,*newKeys;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfKeys = oldstruct->NumberOfKeys;

     if(oldstruct->Info != 0)
          {
          newstruct->Info = AllocateObjectIDInfo;
          CopyFullObjectIDInfo(newstruct->Info, oldstruct->Info);
          }
     else
          newstruct->Info = 0;

     newstruct->Keys = AllocArrayDbaseKeyword(newstruct->NumberOfKeys);
     if(oldstruct->Keys != 0)
          {
          oldKeys = oldstruct->Keys;
          newKeys = newstruct->Keys;
          LOOPi(newstruct->NumberOfKeys)
               CopyFullDbaseKeyword(newKeys++, oldKeys++);
          }


}
extern void PrintObjectIDClass(ObjectIDClass *eleptr)
{
DbaseKeyword *ptrKeys;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The number of Keys:");
     printf("%d\n",eleptr->NumberOfKeys);

     printf("The Object Information of this group:\n");
     PrintObjectIDInfo(eleptr->Info);

     printf("     The set of Keys:\n");
     if(eleptr->Keys != 0)
          {
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               PrintDbaseKeyword(ptrKeys++);
          }


}
extern void FreeObjectIDClass(ObjectIDClass *eleptr)
{
DbaseKeyword *ptrKeys;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrKeys = eleptr->Keys;
     LOOPi(eleptr->NumberOfKeys)
          FreeDbaseKeyword(ptrKeys++);
     Free(eleptr->Keys);

     FreeObjectIDInfo(eleptr->Info);
     Free(eleptr->Info);

}
extern void WriteBinObjectIDClass(ObjectIDClass *eleptr, DbaseLinkedList *file)
{
DbaseKeyword *ptrKeys;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfKeys),file);

     WriteBinObjectIDInfo(eleptr->Info,file);

     if(eleptr->Keys != 0)
          {
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               WriteBinDbaseKeyword(ptrKeys++,file);
          }

}
extern INT ReadBinObjectIDClass(ObjectIDClass *eleptr,DbaseLinkedList *file)
     {
DbaseKeyword *ptrKeys;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfKeys),file);

     eleptr->Info = AllocateObjectIDInfo;
     if(ReadBinObjectIDInfo(eleptr->Info,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Info);
           eleptr->Info = 0;
           }

          eleptr->Keys = AllocArrayDbaseKeyword(eleptr->NumberOfKeys);
          ptrKeys = eleptr->Keys;
          LOOPi(eleptr->NumberOfKeys)
               ReadBinDbaseKeyword(ptrKeys++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ObjectIDClass(XDR *stream, char **eleptrp)
{
     ObjectIDClass *eleptr;
     eleptr = (ObjectIDClass *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfKeys));

     xdr_pointer(stream,
          (char **) &(eleptr->Info),
          ObjectIDInfoSize,
                 (xdrproc_t) xdr_ObjectIDInfo);
     xdr_array(stream,(char **) &(eleptr->Keys),
             (uint *) &(eleptr->NumberOfKeys),eleptr->NumberOfKeys,
               DbaseKeywordSize,(xdrproc_t) xdr_DbaseKeyword);
}

extern void *AllocObjectIDClass()
{
     return((void *) AllocateObjectIDClass);
}

extern CHAR *GetNameObjectIDTreeNode(ObjectIDTreeNode *str)
{
     return(str->Name);
}

extern INT GetIDObjectIDTreeNode(ObjectIDTreeNode *str)
{
     return(str->ID);
}

extern ObjectIDTreeNode *CreateObjectIDTreeNode(ObjectIDTreeNode *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfSubTrees,
                                         ObjectIDTreeNode *SubTrees,
                                         ObjectIDClass *Info)
{
ObjectIDTreeNode *oldSubTrees,*newSubTrees;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfSubTrees = NumberOfSubTrees;
     if(Info != 0)
          {
          newstruct->Info = AllocateObjectIDClass;
          CopyFullObjectIDClass(newstruct->Info, Info);
          }
     else
          newstruct->Info = 0;

     newstruct->SubTrees = AllocArrayObjectIDTreeNode(newstruct->NumberOfSubTrees);
     if(SubTrees != 0)
          {
          oldSubTrees = SubTrees;
          newSubTrees = newstruct->SubTrees;
          LOOPi(newstruct->NumberOfSubTrees)
               CopyFullObjectIDTreeNode(newSubTrees++, oldSubTrees++);
          }



     return(newstruct);
}


extern void CopyFullObjectIDTreeNode(ObjectIDTreeNode *newstruct, ObjectIDTreeNode *oldstruct)
{
ObjectIDTreeNode *oldSubTrees,*newSubTrees;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfSubTrees = oldstruct->NumberOfSubTrees;

     if(oldstruct->Info != 0)
          {
          newstruct->Info = AllocateObjectIDClass;
          CopyFullObjectIDClass(newstruct->Info, oldstruct->Info);
          }
     else
          newstruct->Info = 0;

     newstruct->SubTrees = AllocArrayObjectIDTreeNode(newstruct->NumberOfSubTrees);
     if(oldstruct->SubTrees != 0)
          {
          oldSubTrees = oldstruct->SubTrees;
          newSubTrees = newstruct->SubTrees;
          LOOPi(newstruct->NumberOfSubTrees)
               CopyFullObjectIDTreeNode(newSubTrees++, oldSubTrees++);
          }


}
extern void PrintObjectIDTreeNode(ObjectIDTreeNode *eleptr)
{
ObjectIDTreeNode *ptrSubTrees;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of subtrees:");
     printf("%d\n",eleptr->NumberOfSubTrees);

     printf("The Node Information (if a terminal node):\n");
     PrintObjectIDClass(eleptr->Info);

     printf(" The set of subtrees:\n");
     if(eleptr->SubTrees != 0)
          {
          ptrSubTrees = eleptr->SubTrees;
          LOOPi(eleptr->NumberOfSubTrees)
               PrintObjectIDTreeNode(ptrSubTrees++);
          }


}
extern void FreeObjectIDTreeNode(ObjectIDTreeNode *eleptr)
{
ObjectIDTreeNode *ptrSubTrees;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSubTrees = eleptr->SubTrees;
     LOOPi(eleptr->NumberOfSubTrees)
          FreeObjectIDTreeNode(ptrSubTrees++);
     Free(eleptr->SubTrees);

     FreeObjectIDClass(eleptr->Info);
     Free(eleptr->Info);

}
extern void WriteBinObjectIDTreeNode(ObjectIDTreeNode *eleptr, DbaseLinkedList *file)
{
ObjectIDTreeNode *ptrSubTrees;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfSubTrees),file);

     WriteBinObjectIDClass(eleptr->Info,file);

     if(eleptr->SubTrees != 0)
          {
          ptrSubTrees = eleptr->SubTrees;
          LOOPi(eleptr->NumberOfSubTrees)
               WriteBinObjectIDTreeNode(ptrSubTrees++,file);
          }

}
extern INT ReadBinObjectIDTreeNode(ObjectIDTreeNode *eleptr,DbaseLinkedList *file)
     {
ObjectIDTreeNode *ptrSubTrees;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfSubTrees),file);

     eleptr->Info = AllocateObjectIDClass;
     if(ReadBinObjectIDClass(eleptr->Info,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Info);
           eleptr->Info = 0;
           }

          eleptr->SubTrees = AllocArrayObjectIDTreeNode(eleptr->NumberOfSubTrees);
          ptrSubTrees = eleptr->SubTrees;
          LOOPi(eleptr->NumberOfSubTrees)
               ReadBinObjectIDTreeNode(ptrSubTrees++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ObjectIDTreeNode(XDR *stream, char **eleptrp)
{
     ObjectIDTreeNode *eleptr;
     eleptr = (ObjectIDTreeNode *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfSubTrees));

     xdr_pointer(stream,
          (char **) &(eleptr->Info),
          ObjectIDClassSize,
                 (xdrproc_t) xdr_ObjectIDClass);
     xdr_array(stream,(char **) &(eleptr->SubTrees),
             (uint *) &(eleptr->NumberOfSubTrees),eleptr->NumberOfSubTrees,
               ObjectIDTreeNodeSize,(xdrproc_t) xdr_ObjectIDTreeNode);
}

extern void *AllocObjectIDTreeNode()
{
     return((void *) AllocateObjectIDTreeNode);
}

extern CHAR *GetNameObjectClassification(ObjectClassification *str)
{
     return(str->Name);
}

extern INT GetIDObjectClassification(ObjectClassification *str)
{
     return(str->ID);
}

extern ObjectClassification *CreateObjectClassification(ObjectClassification *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 ObjectIDTreeNode *TreeOfObjects,
                                                 ListOfTreeLevelDescriptions *Description,
                                                 INT  (*Equivalence)(),
                                                 VOID  (*FindElementInSet)())
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Equivalence = Equivalence;
     newstruct->FindElementInSet = FindElementInSet;
     if(TreeOfObjects != 0)
          {
          newstruct->TreeOfObjects = AllocateObjectIDTreeNode;
          CopyFullObjectIDTreeNode(newstruct->TreeOfObjects, TreeOfObjects);
          }
     else
          newstruct->TreeOfObjects = 0;
     if(Description != 0)
          {
          newstruct->Description = AllocateListOfTreeLevelDescriptions;
          CopyFullListOfTreeLevelDescriptions(newstruct->Description, Description);
          }
     else
          newstruct->Description = 0;



     return(newstruct);
}


extern void CopyFullObjectClassification(ObjectClassification *newstruct, ObjectClassification *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Equivalence = oldstruct->Equivalence;
     newstruct->FindElementInSet = oldstruct->FindElementInSet;

     if(oldstruct->TreeOfObjects != 0)
          {
          newstruct->TreeOfObjects = AllocateObjectIDTreeNode;
          CopyFullObjectIDTreeNode(newstruct->TreeOfObjects, oldstruct->TreeOfObjects);
          }
     else
          newstruct->TreeOfObjects = 0;
     if(oldstruct->Description != 0)
          {
          newstruct->Description = AllocateListOfTreeLevelDescriptions;
          CopyFullListOfTreeLevelDescriptions(newstruct->Description, oldstruct->Description);
          }
     else
          newstruct->Description = 0;


}
extern void PrintObjectClassification(ObjectClassification *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("     The object tree:\n");
     PrintObjectIDTreeNode(eleptr->TreeOfObjects);

     printf("The tree descriptions:\n");
     PrintListOfTreeLevelDescriptions(eleptr->Description);

}
extern void FreeObjectClassification(ObjectClassification *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeObjectIDTreeNode(eleptr->TreeOfObjects);
     Free(eleptr->TreeOfObjects);

     FreeListOfTreeLevelDescriptions(eleptr->Description);
     Free(eleptr->Description);

}
extern void WriteBinObjectClassification(ObjectClassification *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinObjectIDTreeNode(eleptr->TreeOfObjects,file);

     WriteBinListOfTreeLevelDescriptions(eleptr->Description,file);

}
extern INT ReadBinObjectClassification(ObjectClassification *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->TreeOfObjects = AllocateObjectIDTreeNode;
     if(ReadBinObjectIDTreeNode(eleptr->TreeOfObjects,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->TreeOfObjects);
           eleptr->TreeOfObjects = 0;
           }

     eleptr->Description = AllocateListOfTreeLevelDescriptions;
     if(ReadBinListOfTreeLevelDescriptions(eleptr->Description,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Description);
           eleptr->Description = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ObjectClassification(XDR *stream, char **eleptrp)
{
     ObjectClassification *eleptr;
     eleptr = (ObjectClassification *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->TreeOfObjects),
          ObjectIDTreeNodeSize,
                 (xdrproc_t) xdr_ObjectIDTreeNode);
     xdr_pointer(stream,
          (char **) &(eleptr->Description),
          ListOfTreeLevelDescriptionsSize,
                 (xdrproc_t) xdr_ListOfTreeLevelDescriptions);
}

extern void *AllocObjectClassification()
{
     return((void *) AllocateObjectClassification);
}

extern CHAR *GetNameSetOfObjectClassifications(SetOfObjectClassifications *str)
{
     return(str->Name);
}

extern INT GetIDSetOfObjectClassifications(SetOfObjectClassifications *str)
{
     return(str->ID);
}

extern SetOfObjectClassifications *CreateSetOfObjectClassifications(SetOfObjectClassifications *newstruct,
INT id,
CHAR *name,
INT  NumberOfClassifications,
ObjectClassification *Classifications)
{
ObjectClassification *oldClassifications,*newClassifications;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfClassifications = NumberOfClassifications;

     newstruct->Classifications = AllocArrayObjectClassification(newstruct->NumberOfClassifications);
     if(Classifications != 0)
          {
          oldClassifications = Classifications;
          newClassifications = newstruct->Classifications;
          LOOPi(newstruct->NumberOfClassifications)
               CopyFullObjectClassification(newClassifications++, oldClassifications++);
          }



     return(newstruct);
}


extern void CopyFullSetOfObjectClassifications(SetOfObjectClassifications *newstruct, SetOfObjectClassifications *oldstruct)
{
ObjectClassification *oldClassifications,*newClassifications;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfClassifications = oldstruct->NumberOfClassifications;


     newstruct->Classifications = AllocArrayObjectClassification(newstruct->NumberOfClassifications);
     if(oldstruct->Classifications != 0)
          {
          oldClassifications = oldstruct->Classifications;
          newClassifications = newstruct->Classifications;
          LOOPi(newstruct->NumberOfClassifications)
               CopyFullObjectClassification(newClassifications++, oldClassifications++);
          }


}
extern void PrintSetOfObjectClassifications(SetOfObjectClassifications *eleptr)
{
ObjectClassification *ptrClassifications;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of classifications:");
     printf("%d\n",eleptr->NumberOfClassifications);

     printf("The object classifications:\n");
     if(eleptr->Classifications != 0)
          {
          ptrClassifications = eleptr->Classifications;
          LOOPi(eleptr->NumberOfClassifications)
               PrintObjectClassification(ptrClassifications++);
          }


}
extern void FreeSetOfObjectClassifications(SetOfObjectClassifications *eleptr)
{
ObjectClassification *ptrClassifications;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrClassifications = eleptr->Classifications;
     LOOPi(eleptr->NumberOfClassifications)
          FreeObjectClassification(ptrClassifications++);
     Free(eleptr->Classifications);

}
extern void WriteBinSetOfObjectClassifications(SetOfObjectClassifications *eleptr, DbaseLinkedList *file)
{
ObjectClassification *ptrClassifications;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfClassifications),file);

     if(eleptr->Classifications != 0)
          {
          ptrClassifications = eleptr->Classifications;
          LOOPi(eleptr->NumberOfClassifications)
               WriteBinObjectClassification(ptrClassifications++,file);
          }

}
extern INT ReadBinSetOfObjectClassifications(SetOfObjectClassifications *eleptr,DbaseLinkedList *file)
     {
ObjectClassification *ptrClassifications;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfClassifications),file);

          eleptr->Classifications = AllocArrayObjectClassification(eleptr->NumberOfClassifications);
          ptrClassifications = eleptr->Classifications;
          LOOPi(eleptr->NumberOfClassifications)
               ReadBinObjectClassification(ptrClassifications++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfObjectClassifications(XDR *stream, char **eleptrp)
{
     SetOfObjectClassifications *eleptr;
     eleptr = (SetOfObjectClassifications *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfClassifications));

     xdr_array(stream,(char **) &(eleptr->Classifications),
             (uint *) &(eleptr->NumberOfClassifications),eleptr->NumberOfClassifications,
               ObjectClassificationSize,(xdrproc_t) xdr_ObjectClassification);
}

extern void *AllocSetOfObjectClassifications()
{
     return((void *) AllocateSetOfObjectClassifications);
}

extern CHAR *GetNameLocDbaseClassifications(LocDbaseClassifications *str)
{
     return(str->Name);
}

extern INT GetIDLocDbaseClassifications(LocDbaseClassifications *str)
{
     return(str->ID);
}

extern LocDbaseClassifications *CreateLocDbaseClassifications(LocDbaseClassifications *newstruct,
INT id,
CHAR *name,
SetOfObjectClassifications *Local,
SetOfObjectClassifications *Database)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Local != 0)
          {
          newstruct->Local = AllocateSetOfObjectClassifications;
          CopyFullSetOfObjectClassifications(newstruct->Local, Local);
          }
     else
          newstruct->Local = 0;
     if(Database != 0)
          {
          newstruct->Database = AllocateSetOfObjectClassifications;
          CopyFullSetOfObjectClassifications(newstruct->Database, Database);
          }
     else
          newstruct->Database = 0;



     return(newstruct);
}


extern void CopyFullLocDbaseClassifications(LocDbaseClassifications *newstruct, LocDbaseClassifications *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Local != 0)
          {
          newstruct->Local = AllocateSetOfObjectClassifications;
          CopyFullSetOfObjectClassifications(newstruct->Local, oldstruct->Local);
          }
     else
          newstruct->Local = 0;
     if(oldstruct->Database != 0)
          {
          newstruct->Database = AllocateSetOfObjectClassifications;
          CopyFullSetOfObjectClassifications(newstruct->Database, oldstruct->Database);
          }
     else
          newstruct->Database = 0;


}
extern void PrintLocDbaseClassifications(LocDbaseClassifications *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The local classifications:\n");
     PrintSetOfObjectClassifications(eleptr->Local);

     printf("The database classifications:\n");
     PrintSetOfObjectClassifications(eleptr->Database);

}
extern void FreeLocDbaseClassifications(LocDbaseClassifications *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSetOfObjectClassifications(eleptr->Local);
     Free(eleptr->Local);

     FreeSetOfObjectClassifications(eleptr->Database);
     Free(eleptr->Database);

}
extern void WriteBinLocDbaseClassifications(LocDbaseClassifications *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSetOfObjectClassifications(eleptr->Local,file);

     WriteBinSetOfObjectClassifications(eleptr->Database,file);

}
extern INT ReadBinLocDbaseClassifications(LocDbaseClassifications *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Local = AllocateSetOfObjectClassifications;
     if(ReadBinSetOfObjectClassifications(eleptr->Local,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Local);
           eleptr->Local = 0;
           }

     eleptr->Database = AllocateSetOfObjectClassifications;
     if(ReadBinSetOfObjectClassifications(eleptr->Database,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Database);
           eleptr->Database = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_LocDbaseClassifications(XDR *stream, char **eleptrp)
{
     LocDbaseClassifications *eleptr;
     eleptr = (LocDbaseClassifications *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Local),
          SetOfObjectClassificationsSize,
                 (xdrproc_t) xdr_SetOfObjectClassifications);
     xdr_pointer(stream,
          (char **) &(eleptr->Database),
          SetOfObjectClassificationsSize,
                 (xdrproc_t) xdr_SetOfObjectClassifications);
}

extern void *AllocLocDbaseClassifications()
{
     return((void *) AllocateLocDbaseClassifications);
}
