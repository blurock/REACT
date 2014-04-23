
extern CHAR *GetNameDataSubSet(DataSubSet *str)
{
     return(str->Name);
}

extern INT GetIDDataSubSet(DataSubSet *str)
{
     return(str->ID);
}

extern DataSubSet *CreateDataSubSet(DataSubSet *newstruct,
                             INT id,
                             CHAR *name,
                             INT  MaximumPoint,
                             INT  NumberOfPoints,
                             INT *Points)
{
INT *oldPoints,*newPoints;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->MaximumPoint = MaximumPoint;
     newstruct->NumberOfPoints = NumberOfPoints;

     newstruct->Points = AllocArrayINT(newstruct->NumberOfPoints);
     if(Points != 0)
          {
          oldPoints = Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfPoints)
               CopyFullINT(newPoints++, oldPoints++);
          }



     return(newstruct);
}


extern void CopyFullDataSubSet(DataSubSet *newstruct, DataSubSet *oldstruct)
{
INT *oldPoints,*newPoints;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->MaximumPoint = oldstruct->MaximumPoint;
     newstruct->NumberOfPoints = oldstruct->NumberOfPoints;


     newstruct->Points = AllocArrayINT(newstruct->NumberOfPoints);
     if(oldstruct->Points != 0)
          {
          oldPoints = oldstruct->Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfPoints)
               CopyFullINT(newPoints++, oldPoints++);
          }


}
extern void PrintDataSubSet(DataSubSet *eleptr)
{
INT *ptrPoints;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The Highest data point number in the Points:");
     printf("%d\n",eleptr->MaximumPoint);
     printf(" The number of points in the subset:");
     printf("%d\n",eleptr->NumberOfPoints);

     printf(" The Array of integers (ID's) in subset:\n");
     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               PrintINT(ptrPoints++);
          }


}
extern void FreeDataSubSet(DataSubSet *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Points);

}
extern void WriteBinDataSubSet(DataSubSet *eleptr, DbaseLinkedList *file)
{
INT *ptrPoints;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->MaximumPoint),file);
     WriteBinINT(&(eleptr->NumberOfPoints),file);

     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               WriteBinINT(ptrPoints++,file);
          }

}
extern INT ReadBinDataSubSet(DataSubSet *eleptr,DbaseLinkedList *file)
     {
INT *ptrPoints;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->MaximumPoint),file);
     ReadBinINT(&(eleptr->NumberOfPoints),file);

          eleptr->Points = AllocArrayINT(eleptr->NumberOfPoints);
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               ReadBinINT(ptrPoints++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataSubSet(XDR *stream, char **eleptrp)
{
     DataSubSet *eleptr;
     eleptr = (DataSubSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->MaximumPoint));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPoints));

     xdr_array(stream,(char **) &(eleptr->Points),
             (uint *) &(eleptr->NumberOfPoints),eleptr->NumberOfPoints,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocDataSubSet()
{
     return((void *) AllocateDataSubSet);
}

extern CHAR *GetNameDataSubSetVector(DataSubSetVector *str)
{
     return(str->Name);
}

extern INT GetIDDataSubSetVector(DataSubSetVector *str)
{
     return(str->ID);
}

extern DataSubSetVector *CreateDataSubSetVector(DataSubSetVector *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfVectors,
                                         DataSubSet *Vector)
{
DataSubSet *oldVector,*newVector;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfVectors = NumberOfVectors;

     newstruct->Vector = AllocArrayDataSubSet(newstruct->NumberOfVectors);
     if(Vector != 0)
          {
          oldVector = Vector;
          newVector = newstruct->Vector;
          LOOPi(newstruct->NumberOfVectors)
               CopyFullDataSubSet(newVector++, oldVector++);
          }



     return(newstruct);
}


extern void CopyFullDataSubSetVector(DataSubSetVector *newstruct, DataSubSetVector *oldstruct)
{
DataSubSet *oldVector,*newVector;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfVectors = oldstruct->NumberOfVectors;


     newstruct->Vector = AllocArrayDataSubSet(newstruct->NumberOfVectors);
     if(oldstruct->Vector != 0)
          {
          oldVector = oldstruct->Vector;
          newVector = newstruct->Vector;
          LOOPi(newstruct->NumberOfVectors)
               CopyFullDataSubSet(newVector++, oldVector++);
          }


}
extern void PrintDataSubSetVector(DataSubSetVector *eleptr)
{
DataSubSet *ptrVector;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of data subsets:");
     printf("%d\n",eleptr->NumberOfVectors);

     printf(" The set of datasubsets:\n");
     if(eleptr->Vector != 0)
          {
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->NumberOfVectors)
               PrintDataSubSet(ptrVector++);
          }


}
extern void FreeDataSubSetVector(DataSubSetVector *eleptr)
{
DataSubSet *ptrVector;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrVector = eleptr->Vector;
     LOOPi(eleptr->NumberOfVectors)
          FreeDataSubSet(ptrVector++);
     Free(eleptr->Vector);

}
extern void WriteBinDataSubSetVector(DataSubSetVector *eleptr, DbaseLinkedList *file)
{
DataSubSet *ptrVector;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfVectors),file);

     if(eleptr->Vector != 0)
          {
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->NumberOfVectors)
               WriteBinDataSubSet(ptrVector++,file);
          }

}
extern INT ReadBinDataSubSetVector(DataSubSetVector *eleptr,DbaseLinkedList *file)
     {
DataSubSet *ptrVector;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfVectors),file);

          eleptr->Vector = AllocArrayDataSubSet(eleptr->NumberOfVectors);
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->NumberOfVectors)
               ReadBinDataSubSet(ptrVector++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DataSubSetVector(XDR *stream, char **eleptrp)
{
     DataSubSetVector *eleptr;
     eleptr = (DataSubSetVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVectors));

     xdr_array(stream,(char **) &(eleptr->Vector),
             (uint *) &(eleptr->NumberOfVectors),eleptr->NumberOfVectors,
               DataSubSetSize,(xdrproc_t) xdr_DataSubSet);
}

extern void *AllocDataSubSetVector()
{
     return((void *) AllocateDataSubSetVector);
}

extern CHAR *GetNameDataTestBlock(DataTestBlock *str)
{
     return(str->Name);
}

extern INT GetIDDataTestBlock(DataTestBlock *str)
{
     return(str->ID);
}

extern DataTestBlock *CreateDataTestBlock(DataTestBlock *newstruct,
                                   INT id,
                                   CHAR *name,
                                   DataSubSet *Build,
                                   DataSubSet *Test)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Build != 0)
          {
          newstruct->Build = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Build, Build);
          }
     else
          newstruct->Build = 0;
     if(Test != 0)
          {
          newstruct->Test = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Test, Test);
          }
     else
          newstruct->Test = 0;



     return(newstruct);
}


extern void CopyFullDataTestBlock(DataTestBlock *newstruct, DataTestBlock *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Build != 0)
          {
          newstruct->Build = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Build, oldstruct->Build);
          }
     else
          newstruct->Build = 0;
     if(oldstruct->Test != 0)
          {
          newstruct->Test = AllocateDataSubSet;
          CopyFullDataSubSet(newstruct->Test, oldstruct->Test);
          }
     else
          newstruct->Test = 0;


}
extern void PrintDataTestBlock(DataTestBlock *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf(" The Build data subset (used for creating structure:\n");
     PrintDataSubSet(eleptr->Build);

     printf(" The Test data subset (independent set used for testing):\n");
     PrintDataSubSet(eleptr->Test);

}
extern void FreeDataTestBlock(DataTestBlock *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeDataSubSet(eleptr->Build);
     Free(eleptr->Build);

     FreeDataSubSet(eleptr->Test);
     Free(eleptr->Test);

}
extern void WriteBinDataTestBlock(DataTestBlock *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinDataSubSet(eleptr->Build,file);

     WriteBinDataSubSet(eleptr->Test,file);

}
extern INT ReadBinDataTestBlock(DataTestBlock *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Build = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Build,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Build);
           eleptr->Build = 0;
           }

     eleptr->Test = AllocateDataSubSet;
     if(ReadBinDataSubSet(eleptr->Test,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Test);
           eleptr->Test = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_DataTestBlock(XDR *stream, char **eleptrp)
{
     DataTestBlock *eleptr;
     eleptr = (DataTestBlock *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Build),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Test),
          DataSubSetSize,
                 (xdrproc_t) xdr_DataSubSet);
}

extern void *AllocDataTestBlock()
{
     return((void *) AllocateDataTestBlock);
}
