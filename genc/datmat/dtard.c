
extern CHAR *GetNameCharRange(CharRange *str)
{
     return(str->Name);
}

extern INT GetIDCharRange(CharRange *str)
{
     return(str->ID);
}

extern CharRange *CreateCharRange(CharRange *newstruct,
                           INT id,
                           CHAR *name,
                           INT  BeginChar,
                           INT  Size)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->BeginChar = BeginChar;
     newstruct->Size = Size;



     return(newstruct);
}


extern void CopyFullCharRange(CharRange *newstruct, CharRange *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->BeginChar = oldstruct->BeginChar;
     newstruct->Size = oldstruct->Size;



}
extern void PrintCharRange(CharRange *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The First Character (begining character position - starting with zero):");
     printf("%d\n",eleptr->BeginChar);
     printf("The Size of the range (in characters):");
     printf("%d\n",eleptr->Size);

}
extern void FreeCharRange(CharRange *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinCharRange(CharRange *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->BeginChar),file);
     WriteBinINT(&(eleptr->Size),file);

}
extern INT ReadBinCharRange(CharRange *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->BeginChar),file);
     ReadBinINT(&(eleptr->Size),file);

     return(STRUCTURE_READ);
     }
extern void xdr_CharRange(XDR *stream, char **eleptrp)
{
     CharRange *eleptr;
     eleptr = (CharRange *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->BeginChar));
     xdr_INT(stream,(char **) &(eleptr->Size));

}

extern void *AllocCharRange()
{
     return((void *) AllocateCharRange);
}

extern CHAR *GetNameBasisType(BasisType *str)
{
     return(str->Name);
}

extern INT GetIDBasisType(BasisType *str)
{
     return(str->ID);
}

extern BasisType *CreateBasisType(BasisType *newstruct,
                           INT id,
                           CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullBasisType(BasisType *newstruct, BasisType *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Integer != 0)
          {
          newstruct->Integer = AllocateINT;
          CopyFullINT(newstruct->Integer, oldstruct->Integer);
          }
     else
          newstruct->Integer = 0;
     if(oldstruct->Float != 0)
          {
          newstruct->Float = AllocateFLOAT;
          CopyFullFLOAT(newstruct->Float, oldstruct->Float);
          }
     else
          newstruct->Float = 0;


}
extern void PrintBasisType(BasisType *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf(" A pointer to an integer:\n");
     PrintINT(eleptr->Integer);

     printf(" A pointer to a Floating Point Number:\n");
     PrintFLOAT(eleptr->Float);

}
extern void FreeBasisType(BasisType *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Integer);

     Free(eleptr->Float);

}
extern void WriteBinBasisType(BasisType *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinINT(eleptr->Integer,file);

     WriteBinFLOAT(eleptr->Float,file);

}
extern INT ReadBinBasisType(BasisType *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Integer = AllocateINT;
     if(ReadBinINT(eleptr->Integer,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Integer);
           eleptr->Integer = 0;
           }

     eleptr->Float = AllocateFLOAT;
     if(ReadBinFLOAT(eleptr->Float,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Float);
           eleptr->Float = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BasisType(XDR *stream, char **eleptrp)
{
     BasisType *eleptr;
     eleptr = (BasisType *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Integer),
          INTSize,
                 (xdrproc_t) xdr_INT);
     xdr_pointer(stream,
          (char **) &(eleptr->Float),
          FLOATSize,
                 (xdrproc_t) xdr_FLOAT);
}

extern void *AllocBasisType()
{
     return((void *) AllocateBasisType);
}

extern CHAR *GetNameDataPoint(DataPoint *str)
{
     return(str->Name);
}

extern INT GetIDDataPoint(DataPoint *str)
{
     return(str->ID);
}

extern DataPoint *CreateDataPoint(DataPoint *newstruct,
                           INT id,
                           CHAR *name,
                           INT  Type,
                           INT  NumberOfPoints)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Type = Type;
     newstruct->NumberOfPoints = NumberOfPoints;



     return(newstruct);
}


extern void CopyFullDataPoint(DataPoint *newstruct, DataPoint *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Range = oldstruct->Range;
     newstruct->Type = oldstruct->Type;
     newstruct->NumberOfPoints = oldstruct->NumberOfPoints;
     newstruct->Vector = oldstruct->Vector;



}
extern void PrintDataPoint(DataPoint *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The type of element (i.e. the basis type):");
     printf("%d\n",eleptr->Type);
     printf(" The number of points read in of this type:");
     printf("%d\n",eleptr->NumberOfPoints);

}
extern void FreeDataPoint(DataPoint *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinDataPoint(DataPoint *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Type),file);
     WriteBinINT(&(eleptr->NumberOfPoints),file);

}
extern INT ReadBinDataPoint(DataPoint *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Type),file);
     ReadBinINT(&(eleptr->NumberOfPoints),file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataPoint(XDR *stream, char **eleptrp)
{
     DataPoint *eleptr;
     eleptr = (DataPoint *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Type));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPoints));

}

extern void *AllocDataPoint()
{
     return((void *) AllocateDataPoint);
}

extern CHAR *GetNameDataBlock(DataBlock *str)
{
     return(str->Name);
}

extern INT GetIDDataBlock(DataBlock *str)
{
     return(str->ID);
}

extern DataBlock *CreateDataBlock(DataBlock *newstruct,
                           INT id,
                           CHAR *name,
                           INT  NumberOfColumns,
                           INT  NumberOfPoints,
                           DataPoint *Columns)
{
DataPoint *oldColumns,*newColumns;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfColumns = NumberOfColumns;
     newstruct->NumberOfPoints = NumberOfPoints;

     newstruct->Columns = AllocArrayDataPoint(newstruct->NumberOfColumns);
     if(Columns != 0)
          {
          oldColumns = Columns;
          newColumns = newstruct->Columns;
          LOOPi(newstruct->NumberOfColumns)
               CopyFullDataPoint(newColumns++, oldColumns++);
          }



     return(newstruct);
}


extern void CopyFullDataBlock(DataBlock *newstruct, DataBlock *oldstruct)
{
DataPoint *oldColumns,*newColumns;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfColumns = oldstruct->NumberOfColumns;
     newstruct->NumberOfPoints = oldstruct->NumberOfPoints;


     newstruct->Columns = AllocArrayDataPoint(newstruct->NumberOfColumns);
     if(oldstruct->Columns != 0)
          {
          oldColumns = oldstruct->Columns;
          newColumns = newstruct->Columns;
          LOOPi(newstruct->NumberOfColumns)
               CopyFullDataPoint(newColumns++, oldColumns++);
          }


}
extern void PrintDataBlock(DataBlock *eleptr)
{
DataPoint *ptrColumns;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of variables:");
     printf("%d\n",eleptr->NumberOfColumns);
     printf(" The number of points in each column:");
     printf("%d\n",eleptr->NumberOfPoints);

     printf(" The vector of variable information:\n");
     if(eleptr->Columns != 0)
          {
          ptrColumns = eleptr->Columns;
          LOOPi(eleptr->NumberOfColumns)
               PrintDataPoint(ptrColumns++);
          }


}
extern void FreeDataBlock(DataBlock *eleptr)
{
DataPoint *ptrColumns;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrColumns = eleptr->Columns;
     LOOPi(eleptr->NumberOfColumns)
          FreeDataPoint(ptrColumns++);
     Free(eleptr->Columns);

}
extern void WriteBinDataBlock(DataBlock *eleptr, DbaseLinkedList *file)
{
DataPoint *ptrColumns;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfColumns),file);
     WriteBinINT(&(eleptr->NumberOfPoints),file);

     if(eleptr->Columns != 0)
          {
          ptrColumns = eleptr->Columns;
          LOOPi(eleptr->NumberOfColumns)
               WriteBinDataPoint(ptrColumns++,file);
          }

}
extern INT ReadBinDataBlock(DataBlock *eleptr,DbaseLinkedList *file)
     {
DataPoint *ptrColumns;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfColumns),file);
     ReadBinINT(&(eleptr->NumberOfPoints),file);

          eleptr->Columns = AllocArrayDataPoint(eleptr->NumberOfColumns);
          ptrColumns = eleptr->Columns;
          LOOPi(eleptr->NumberOfColumns)
               ReadBinDataPoint(ptrColumns++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataBlock(XDR *stream, char **eleptrp)
{
     DataBlock *eleptr;
     eleptr = (DataBlock *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfColumns));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPoints));

     xdr_array(stream,(char **) &(eleptr->Columns),
             (uint *) &(eleptr->NumberOfColumns),eleptr->NumberOfColumns,
               DataPointSize,(xdrproc_t) xdr_DataPoint);
}

extern void *AllocDataBlock()
{
     return((void *) AllocateDataBlock);
}

extern CHAR *GetNameDataPointName(DataPointName *str)
{
     return(str->Name);
}

extern INT GetIDDataPointName(DataPointName *str)
{
     return(str->ID);
}

extern DataPointName *CreateDataPointName(DataPointName *newstruct,
                                   INT id,
                                   CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullDataPointName(DataPointName *newstruct, DataPointName *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintDataPointName(DataPointName *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeDataPointName(DataPointName *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinDataPointName(DataPointName *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinDataPointName(DataPointName *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataPointName(XDR *stream, char **eleptrp)
{
     DataPointName *eleptr;
     eleptr = (DataPointName *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocDataPointName()
{
     return((void *) AllocateDataPointName);
}

extern CHAR *GetNameDataPointNameSet(DataPointNameSet *str)
{
     return(str->Name);
}

extern INT GetIDDataPointNameSet(DataPointNameSet *str)
{
     return(str->ID);
}

extern DataPointNameSet *CreateDataPointNameSet(DataPointNameSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfNames,
                                         DataPointName *Names)
{
DataPointName *oldNames,*newNames;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNames = NumberOfNames;

     newstruct->Names = AllocArrayDataPointName(newstruct->NumberOfNames);
     if(Names != 0)
          {
          oldNames = Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfNames)
               CopyFullDataPointName(newNames++, oldNames++);
          }



     return(newstruct);
}


extern void CopyFullDataPointNameSet(DataPointNameSet *newstruct, DataPointNameSet *oldstruct)
{
DataPointName *oldNames,*newNames;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNames = oldstruct->NumberOfNames;


     newstruct->Names = AllocArrayDataPointName(newstruct->NumberOfNames);
     if(oldstruct->Names != 0)
          {
          oldNames = oldstruct->Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfNames)
               CopyFullDataPointName(newNames++, oldNames++);
          }


}
extern void PrintDataPointNameSet(DataPointNameSet *eleptr)
{
DataPointName *ptrNames;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("     Number Of Names:");
     printf("%d\n",eleptr->NumberOfNames);

     printf(" The vector of names:\n");
     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               PrintDataPointName(ptrNames++);
          }


}
extern void FreeDataPointNameSet(DataPointNameSet *eleptr)
{
DataPointName *ptrNames;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrNames = eleptr->Names;
     LOOPi(eleptr->NumberOfNames)
          FreeDataPointName(ptrNames++);
     Free(eleptr->Names);

}
extern void WriteBinDataPointNameSet(DataPointNameSet *eleptr, DbaseLinkedList *file)
{
DataPointName *ptrNames;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfNames),file);

     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               WriteBinDataPointName(ptrNames++,file);
          }

}
extern INT ReadBinDataPointNameSet(DataPointNameSet *eleptr,DbaseLinkedList *file)
     {
DataPointName *ptrNames;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNames),file);

          eleptr->Names = AllocArrayDataPointName(eleptr->NumberOfNames);
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               ReadBinDataPointName(ptrNames++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataPointNameSet(XDR *stream, char **eleptrp)
{
     DataPointNameSet *eleptr;
     eleptr = (DataPointNameSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfNames));

     xdr_array(stream,(char **) &(eleptr->Names),
             (uint *) &(eleptr->NumberOfNames),eleptr->NumberOfNames,
               DataPointNameSize,(xdrproc_t) xdr_DataPointName);
}

extern void *AllocDataPointNameSet()
{
     return((void *) AllocateDataPointNameSet);
}

extern CHAR *GetNameDataBlockSet(DataBlockSet *str)
{
     return(str->Name);
}

extern INT GetIDDataBlockSet(DataBlockSet *str)
{
     return(str->ID);
}

extern DataBlockSet *CreateDataBlockSet(DataBlockSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumDataBlocks,
                                 DataBlock *Blocks,
                                 DataPointNameSet *NameSet)
{
DataBlock *oldBlocks,*newBlocks;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumDataBlocks = NumDataBlocks;
     if(NameSet != 0)
          {
          newstruct->NameSet = AllocateDataPointNameSet;
          CopyFullDataPointNameSet(newstruct->NameSet, NameSet);
          }
     else
          newstruct->NameSet = 0;

     newstruct->Blocks = AllocArrayDataBlock(newstruct->NumDataBlocks);
     if(Blocks != 0)
          {
          oldBlocks = Blocks;
          newBlocks = newstruct->Blocks;
          LOOPi(newstruct->NumDataBlocks)
               CopyFullDataBlock(newBlocks++, oldBlocks++);
          }



     return(newstruct);
}


extern void CopyFullDataBlockSet(DataBlockSet *newstruct, DataBlockSet *oldstruct)
{
DataBlock *oldBlocks,*newBlocks;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumDataBlocks = oldstruct->NumDataBlocks;

     if(oldstruct->NameSet != 0)
          {
          newstruct->NameSet = AllocateDataPointNameSet;
          CopyFullDataPointNameSet(newstruct->NameSet, oldstruct->NameSet);
          }
     else
          newstruct->NameSet = 0;

     newstruct->Blocks = AllocArrayDataBlock(newstruct->NumDataBlocks);
     if(oldstruct->Blocks != 0)
          {
          oldBlocks = oldstruct->Blocks;
          newBlocks = newstruct->Blocks;
          LOOPi(newstruct->NumDataBlocks)
               CopyFullDataBlock(newBlocks++, oldBlocks++);
          }


}
extern void PrintDataBlockSet(DataBlockSet *eleptr)
{
DataBlock *ptrBlocks;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of blocks:");
     printf("%d\n",eleptr->NumDataBlocks);

     printf("The names of the elements:\n");
     PrintDataPointNameSet(eleptr->NameSet);

     printf("  The blocks of data:\n");
     if(eleptr->Blocks != 0)
          {
          ptrBlocks = eleptr->Blocks;
          LOOPi(eleptr->NumDataBlocks)
               PrintDataBlock(ptrBlocks++);
          }


}
extern void FreeDataBlockSet(DataBlockSet *eleptr)
{
DataBlock *ptrBlocks;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrBlocks = eleptr->Blocks;
     LOOPi(eleptr->NumDataBlocks)
          FreeDataBlock(ptrBlocks++);
     Free(eleptr->Blocks);

     FreeDataPointNameSet(eleptr->NameSet);
     Free(eleptr->NameSet);

}
extern void WriteBinDataBlockSet(DataBlockSet *eleptr, DbaseLinkedList *file)
{
DataBlock *ptrBlocks;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumDataBlocks),file);

     WriteBinDataPointNameSet(eleptr->NameSet,file);

     if(eleptr->Blocks != 0)
          {
          ptrBlocks = eleptr->Blocks;
          LOOPi(eleptr->NumDataBlocks)
               WriteBinDataBlock(ptrBlocks++,file);
          }

}
extern INT ReadBinDataBlockSet(DataBlockSet *eleptr,DbaseLinkedList *file)
     {
DataBlock *ptrBlocks;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumDataBlocks),file);

     eleptr->NameSet = AllocateDataPointNameSet;
     if(ReadBinDataPointNameSet(eleptr->NameSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->NameSet);
           eleptr->NameSet = 0;
           }

          eleptr->Blocks = AllocArrayDataBlock(eleptr->NumDataBlocks);
          ptrBlocks = eleptr->Blocks;
          LOOPi(eleptr->NumDataBlocks)
               ReadBinDataBlock(ptrBlocks++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataBlockSet(XDR *stream, char **eleptrp)
{
     DataBlockSet *eleptr;
     eleptr = (DataBlockSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumDataBlocks));

     xdr_pointer(stream,
          (char **) &(eleptr->NameSet),
          DataPointNameSetSize,
                 (xdrproc_t) xdr_DataPointNameSet);
     xdr_array(stream,(char **) &(eleptr->Blocks),
             (uint *) &(eleptr->NumDataBlocks),eleptr->NumDataBlocks,
               DataBlockSize,(xdrproc_t) xdr_DataBlock);
}

extern void *AllocDataBlockSet()
{
     return((void *) AllocateDataBlockSet);
}
