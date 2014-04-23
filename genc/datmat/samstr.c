
extern CHAR *GetNameBaseIntVector(BaseIntVector *str)
{
     return(str->Name);
}

extern INT GetIDBaseIntVector(BaseIntVector *str)
{
     return(str->ID);
}

extern BaseIntVector *CreateBaseIntVector(BaseIntVector *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  VectorLength,
                                   INT *Vector)
{
INT *oldVector,*newVector;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->VectorLength = VectorLength;

     newstruct->Vector = AllocArrayINT(newstruct->VectorLength);
     if(Vector != 0)
          {
          oldVector = Vector;
          newVector = newstruct->Vector;
          LOOPi(newstruct->VectorLength)
               CopyFullINT(newVector++, oldVector++);
          }



     return(newstruct);
}


extern void CopyFullBaseIntVector(BaseIntVector *newstruct, BaseIntVector *oldstruct)
{
INT *oldVector,*newVector;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->VectorLength = oldstruct->VectorLength;


     newstruct->Vector = AllocArrayINT(newstruct->VectorLength);
     if(oldstruct->Vector != 0)
          {
          oldVector = oldstruct->Vector;
          newVector = newstruct->Vector;
          LOOPi(newstruct->VectorLength)
               CopyFullINT(newVector++, oldVector++);
          }


}
extern void PrintBaseIntVector(BaseIntVector *eleptr)
{
INT *ptrVector;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of points:");
     printf("%d\n",eleptr->VectorLength);

     printf("         The vector :\n");
     if(eleptr->Vector != 0)
          {
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->VectorLength)
               PrintINT(ptrVector++);
          }


}
extern void FreeBaseIntVector(BaseIntVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Vector);

}
extern void WriteBinBaseIntVector(BaseIntVector *eleptr, DbaseLinkedList *file)
{
INT *ptrVector;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->VectorLength),file);

     if(eleptr->Vector != 0)
          {
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->VectorLength)
               WriteBinINT(ptrVector++,file);
          }

}
extern INT ReadBinBaseIntVector(BaseIntVector *eleptr,DbaseLinkedList *file)
     {
INT *ptrVector;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->VectorLength),file);

          eleptr->Vector = AllocArrayINT(eleptr->VectorLength);
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->VectorLength)
               ReadBinINT(ptrVector++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BaseIntVector(XDR *stream, char **eleptrp)
{
     BaseIntVector *eleptr;
     eleptr = (BaseIntVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->VectorLength));

     xdr_array(stream,(char **) &(eleptr->Vector),
             (uint *) &(eleptr->VectorLength),eleptr->VectorLength,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocBaseIntVector()
{
     return((void *) AllocateBaseIntVector);
}

extern CHAR *GetNameBaseFltVector(BaseFltVector *str)
{
     return(str->Name);
}

extern INT GetIDBaseFltVector(BaseFltVector *str)
{
     return(str->ID);
}

extern BaseFltVector *CreateBaseFltVector(BaseFltVector *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  VectorLength,
                                   FLOAT *Vector)
{
FLOAT *oldVector,*newVector;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->VectorLength = VectorLength;

     newstruct->Vector = AllocArrayFLOAT(newstruct->VectorLength);
     if(Vector != 0)
          {
          oldVector = Vector;
          newVector = newstruct->Vector;
          LOOPi(newstruct->VectorLength)
               CopyFullFLOAT(newVector++, oldVector++);
          }



     return(newstruct);
}


extern void CopyFullBaseFltVector(BaseFltVector *newstruct, BaseFltVector *oldstruct)
{
FLOAT *oldVector,*newVector;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->VectorLength = oldstruct->VectorLength;


     newstruct->Vector = AllocArrayFLOAT(newstruct->VectorLength);
     if(oldstruct->Vector != 0)
          {
          oldVector = oldstruct->Vector;
          newVector = newstruct->Vector;
          LOOPi(newstruct->VectorLength)
               CopyFullFLOAT(newVector++, oldVector++);
          }


}
extern void PrintBaseFltVector(BaseFltVector *eleptr)
{
FLOAT *ptrVector;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of points:");
     printf("%d\n",eleptr->VectorLength);

     printf("         The vector :\n");
     if(eleptr->Vector != 0)
          {
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->VectorLength)
               PrintFLOAT(ptrVector++);
          }


}
extern void FreeBaseFltVector(BaseFltVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Vector);

}
extern void WriteBinBaseFltVector(BaseFltVector *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrVector;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->VectorLength),file);

     if(eleptr->Vector != 0)
          {
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->VectorLength)
               WriteBinFLOAT(ptrVector++,file);
          }

}
extern INT ReadBinBaseFltVector(BaseFltVector *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrVector;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->VectorLength),file);

          eleptr->Vector = AllocArrayFLOAT(eleptr->VectorLength);
          ptrVector = eleptr->Vector;
          LOOPi(eleptr->VectorLength)
               ReadBinFLOAT(ptrVector++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_BaseFltVector(XDR *stream, char **eleptrp)
{
     BaseFltVector *eleptr;
     eleptr = (BaseFltVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->VectorLength));

     xdr_array(stream,(char **) &(eleptr->Vector),
             (uint *) &(eleptr->VectorLength),eleptr->VectorLength,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocBaseFltVector()
{
     return((void *) AllocateBaseFltVector);
}

extern CHAR *GetNameBaseVector(BaseVector *str)
{
     return(str->Name);
}

extern INT GetIDBaseVector(BaseVector *str)
{
     return(str->ID);
}

extern BaseVector *CreateBaseVector(BaseVector *newstruct,
                             INT id,
                             CHAR *name,
                             INT  Type,
                             BaseIntVector *Integer,
                             BaseFltVector *Float)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Type = Type;
     if(Integer != 0)
          {
          newstruct->Integer = AllocateBaseIntVector;
          CopyFullBaseIntVector(newstruct->Integer, Integer);
          }
     else
          newstruct->Integer = 0;
     if(Float != 0)
          {
          newstruct->Float = AllocateBaseFltVector;
          CopyFullBaseFltVector(newstruct->Float, Float);
          }
     else
          newstruct->Float = 0;



     return(newstruct);
}


extern void CopyFullBaseVector(BaseVector *newstruct, BaseVector *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Type = oldstruct->Type;

     if(oldstruct->Integer != 0)
          {
          newstruct->Integer = AllocateBaseIntVector;
          CopyFullBaseIntVector(newstruct->Integer, oldstruct->Integer);
          }
     else
          newstruct->Integer = 0;
     if(oldstruct->Float != 0)
          {
          newstruct->Float = AllocateBaseFltVector;
          CopyFullBaseFltVector(newstruct->Float, oldstruct->Float);
          }
     else
          newstruct->Float = 0;


}
extern void PrintBaseVector(BaseVector *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The type of Vector:");
     printf("%d\n",eleptr->Type);

     printf(" The Integer Basis Vector (zero if not used):\n");
     PrintBaseIntVector(eleptr->Integer);

     printf(" The Float Basis Vector (zero if not used):\n");
     PrintBaseFltVector(eleptr->Float);

}
extern void FreeBaseVector(BaseVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeBaseIntVector(eleptr->Integer);
     Free(eleptr->Integer);

     FreeBaseFltVector(eleptr->Float);
     Free(eleptr->Float);

}
extern void WriteBinBaseVector(BaseVector *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Type),file);

     WriteBinBaseIntVector(eleptr->Integer,file);

     WriteBinBaseFltVector(eleptr->Float,file);

}
extern INT ReadBinBaseVector(BaseVector *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Type),file);

     eleptr->Integer = AllocateBaseIntVector;
     if(ReadBinBaseIntVector(eleptr->Integer,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Integer);
           eleptr->Integer = 0;
           }

     eleptr->Float = AllocateBaseFltVector;
     if(ReadBinBaseFltVector(eleptr->Float,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Float);
           eleptr->Float = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_BaseVector(XDR *stream, char **eleptrp)
{
     BaseVector *eleptr;
     eleptr = (BaseVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Type));

     xdr_pointer(stream,
          (char **) &(eleptr->Integer),
          BaseIntVectorSize,
                 (xdrproc_t) xdr_BaseIntVector);
     xdr_pointer(stream,
          (char **) &(eleptr->Float),
          BaseFltVectorSize,
                 (xdrproc_t) xdr_BaseFltVector);
}

extern void *AllocBaseVector()
{
     return((void *) AllocateBaseVector);
}

extern CHAR *GetNameBaseType(BaseType *str)
{
     return(str->Name);
}

extern INT GetIDBaseType(BaseType *str)
{
     return(str->ID);
}

extern BaseType *CreateBaseType(BaseType *newstruct,
                         INT id,
                         CHAR *name,
                         INT  Type,
                         INT  Integer,
                         FLOAT  Float)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Type = Type;
     newstruct->Integer = Integer;
     newstruct->Float = Float;



     return(newstruct);
}


extern void CopyFullBaseType(BaseType *newstruct, BaseType *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Type = oldstruct->Type;
     newstruct->Integer = oldstruct->Integer;
     newstruct->Float = oldstruct->Float;



}
extern void PrintBaseType(BaseType *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("  The type of Vector:");
     printf("%d\n",eleptr->Type);
     printf("      An Integer    :");
     printf("%d\n",eleptr->Integer);
     printf(" A Floating Point Number:");
     printf("%f\n",eleptr->Float);

}
extern void FreeBaseType(BaseType *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinBaseType(BaseType *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->Type),file);
     WriteBinINT(&(eleptr->Integer),file);
     WriteBinFLOAT(&(eleptr->Float),file);

}
extern INT ReadBinBaseType(BaseType *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->Type),file);
     ReadBinINT(&(eleptr->Integer),file);
     ReadBinFLOAT(&(eleptr->Float),file);

     return(STRUCTURE_READ);
     }
extern void xdr_BaseType(XDR *stream, char **eleptrp)
{
     BaseType *eleptr;
     eleptr = (BaseType *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->Type));
     xdr_INT(stream,(char **) &(eleptr->Integer));
     xdr_FLOAT(stream,(char **) &(eleptr->Float));

}

extern void *AllocBaseType()
{
     return((void *) AllocateBaseType);
}

extern CHAR *GetNameSysSamVector(SysSamVector *str)
{
     return(str->Name);
}

extern INT GetIDSysSamVector(SysSamVector *str)
{
     return(str->ID);
}

extern SysSamVector *CreateSysSamVector(SysSamVector *newstruct,
                                 INT id,
                                 CHAR *name,
                                 BaseType *Missing,
                                 INT  NumNotMissing,
                                 BaseVector *Data)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumNotMissing = NumNotMissing;
     if(Missing != 0)
          {
          newstruct->Missing = AllocateBaseType;
          CopyFullBaseType(newstruct->Missing, Missing);
          }
     else
          newstruct->Missing = 0;
     if(Data != 0)
          {
          newstruct->Data = AllocateBaseVector;
          CopyFullBaseVector(newstruct->Data, Data);
          }
     else
          newstruct->Data = 0;



     return(newstruct);
}


extern void CopyFullSysSamVector(SysSamVector *newstruct, SysSamVector *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumNotMissing = oldstruct->NumNotMissing;

     if(oldstruct->Missing != 0)
          {
          newstruct->Missing = AllocateBaseType;
          CopyFullBaseType(newstruct->Missing, oldstruct->Missing);
          }
     else
          newstruct->Missing = 0;
     if(oldstruct->Data != 0)
          {
          newstruct->Data = AllocateBaseVector;
          CopyFullBaseVector(newstruct->Data, oldstruct->Data);
          }
     else
          newstruct->Data = 0;


}
extern void PrintSysSamVector(SysSamVector *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of points that are not missing:");
     printf("%d\n",eleptr->NumNotMissing);

     printf(" The Value of a missing value:\n");
     PrintBaseType(eleptr->Missing);

     printf(" The data vector of type Type:\n");
     PrintBaseVector(eleptr->Data);

}
extern void FreeSysSamVector(SysSamVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeBaseType(eleptr->Missing);
     Free(eleptr->Missing);

     FreeBaseVector(eleptr->Data);
     Free(eleptr->Data);

}
extern void WriteBinSysSamVector(SysSamVector *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumNotMissing),file);

     WriteBinBaseType(eleptr->Missing,file);

     WriteBinBaseVector(eleptr->Data,file);

}
extern INT ReadBinSysSamVector(SysSamVector *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumNotMissing),file);

     eleptr->Missing = AllocateBaseType;
     if(ReadBinBaseType(eleptr->Missing,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Missing);
           eleptr->Missing = 0;
           }

     eleptr->Data = AllocateBaseVector;
     if(ReadBinBaseVector(eleptr->Data,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Data);
           eleptr->Data = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_SysSamVector(XDR *stream, char **eleptrp)
{
     SysSamVector *eleptr;
     eleptr = (SysSamVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumNotMissing));

     xdr_pointer(stream,
          (char **) &(eleptr->Missing),
          BaseTypeSize,
                 (xdrproc_t) xdr_BaseType);
     xdr_pointer(stream,
          (char **) &(eleptr->Data),
          BaseVectorSize,
                 (xdrproc_t) xdr_BaseVector);
}

extern void *AllocSysSamVector()
{
     return((void *) AllocateSysSamVector);
}

extern CHAR *GetNameSysSamName(SysSamName *str)
{
     return(str->Name);
}

extern INT GetIDSysSamName(SysSamName *str)
{
     return(str->ID);
}

extern SysSamName *CreateSysSamName(SysSamName *newstruct,
                             INT id,
                             CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullSysSamName(SysSamName *newstruct, SysSamName *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintSysSamName(SysSamName *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeSysSamName(SysSamName *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinSysSamName(SysSamName *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinSysSamName(SysSamName *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_SysSamName(XDR *stream, char **eleptrp)
{
     SysSamName *eleptr;
     eleptr = (SysSamName *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocSysSamName()
{
     return((void *) AllocateSysSamName);
}

extern CHAR *GetNameSysSamNameSet(SysSamNameSet *str)
{
     return(str->Name);
}

extern INT GetIDSysSamNameSet(SysSamNameSet *str)
{
     return(str->ID);
}

extern SysSamNameSet *CreateSysSamNameSet(SysSamNameSet *newstruct,
                                   INT id,
                                   CHAR *name,
                                   INT  NumberOfNames,
                                   SysSamName *Names)
{
SysSamName *oldNames,*newNames;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfNames = NumberOfNames;

     newstruct->Names = AllocArraySysSamName(newstruct->NumberOfNames);
     if(Names != 0)
          {
          oldNames = Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfNames)
               CopyFullSysSamName(newNames++, oldNames++);
          }



     return(newstruct);
}


extern void CopyFullSysSamNameSet(SysSamNameSet *newstruct, SysSamNameSet *oldstruct)
{
SysSamName *oldNames,*newNames;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfNames = oldstruct->NumberOfNames;


     newstruct->Names = AllocArraySysSamName(newstruct->NumberOfNames);
     if(oldstruct->Names != 0)
          {
          oldNames = oldstruct->Names;
          newNames = newstruct->Names;
          LOOPi(newstruct->NumberOfNames)
               CopyFullSysSamName(newNames++, oldNames++);
          }


}
extern void PrintSysSamNameSet(SysSamNameSet *eleptr)
{
SysSamName *ptrNames;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Data Points:");
     printf("%d\n",eleptr->NumberOfNames);

     printf("The set of Names of the Points:\n");
     if(eleptr->Names != 0)
          {
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               PrintSysSamName(ptrNames++);
          }


}
extern void FreeSysSamNameSet(SysSamNameSet *eleptr)
{
SysSamName *ptrNames;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrNames = eleptr->Names;
     LOOPi(eleptr->NumberOfNames)
          FreeSysSamName(ptrNames++);
     Free(eleptr->Names);

}
extern void WriteBinSysSamNameSet(SysSamNameSet *eleptr, DbaseLinkedList *file)
{
SysSamName *ptrNames;
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
               WriteBinSysSamName(ptrNames++,file);
          }

}
extern INT ReadBinSysSamNameSet(SysSamNameSet *eleptr,DbaseLinkedList *file)
     {
SysSamName *ptrNames;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfNames),file);

          eleptr->Names = AllocArraySysSamName(eleptr->NumberOfNames);
          ptrNames = eleptr->Names;
          LOOPi(eleptr->NumberOfNames)
               ReadBinSysSamName(ptrNames++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SysSamNameSet(XDR *stream, char **eleptrp)
{
     SysSamNameSet *eleptr;
     eleptr = (SysSamNameSet *) eleptrp;
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
               SysSamNameSize,(xdrproc_t) xdr_SysSamName);
}

extern void *AllocSysSamNameSet()
{
     return((void *) AllocateSysSamNameSet);
}

extern CHAR *GetNameSysSamVectorSet(SysSamVectorSet *str)
{
     return(str->Name);
}

extern INT GetIDSysSamVectorSet(SysSamVectorSet *str)
{
     return(str->ID);
}

extern SysSamVectorSet *CreateSysSamVectorSet(SysSamVectorSet *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumSystemSamples,
                                       INT  NumSystemPoints,
                                       SysSamVector *Sets,
                                       SysSamNameSet *NameSet)
{
SysSamVector *oldSets,*newSets;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumSystemSamples = NumSystemSamples;
     newstruct->NumSystemPoints = NumSystemPoints;
     if(NameSet != 0)
          {
          newstruct->NameSet = AllocateSysSamNameSet;
          CopyFullSysSamNameSet(newstruct->NameSet, NameSet);
          }
     else
          newstruct->NameSet = 0;

     newstruct->Sets = AllocArraySysSamVector(newstruct->NumSystemSamples);
     if(Sets != 0)
          {
          oldSets = Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumSystemSamples)
               CopyFullSysSamVector(newSets++, oldSets++);
          }



     return(newstruct);
}


extern void CopyFullSysSamVectorSet(SysSamVectorSet *newstruct, SysSamVectorSet *oldstruct)
{
SysSamVector *oldSets,*newSets;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumSystemSamples = oldstruct->NumSystemSamples;
     newstruct->NumSystemPoints = oldstruct->NumSystemPoints;

     if(oldstruct->NameSet != 0)
          {
          newstruct->NameSet = AllocateSysSamNameSet;
          CopyFullSysSamNameSet(newstruct->NameSet, oldstruct->NameSet);
          }
     else
          newstruct->NameSet = 0;

     newstruct->Sets = AllocArraySysSamVector(newstruct->NumSystemSamples);
     if(oldstruct->Sets != 0)
          {
          oldSets = oldstruct->Sets;
          newSets = newstruct->Sets;
          LOOPi(newstruct->NumSystemSamples)
               CopyFullSysSamVector(newSets++, oldSets++);
          }


}
extern void PrintSysSamVectorSet(SysSamVectorSet *eleptr)
{
SysSamVector *ptrSets;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of samples:");
     printf("%d\n",eleptr->NumSystemSamples);
     printf("The number of Data Points:");
     printf("%d\n",eleptr->NumSystemPoints);

     printf(" The set of Names of each data point:\n");
     PrintSysSamNameSet(eleptr->NameSet);

     printf("The set of SystemSampleVectors:\n");
     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumSystemSamples)
               PrintSysSamVector(ptrSets++);
          }


}
extern void FreeSysSamVectorSet(SysSamVectorSet *eleptr)
{
SysSamVector *ptrSets;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrSets = eleptr->Sets;
     LOOPi(eleptr->NumSystemSamples)
          FreeSysSamVector(ptrSets++);
     Free(eleptr->Sets);

     FreeSysSamNameSet(eleptr->NameSet);
     Free(eleptr->NameSet);

}
extern void WriteBinSysSamVectorSet(SysSamVectorSet *eleptr, DbaseLinkedList *file)
{
SysSamVector *ptrSets;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumSystemSamples),file);
     WriteBinINT(&(eleptr->NumSystemPoints),file);

     WriteBinSysSamNameSet(eleptr->NameSet,file);

     if(eleptr->Sets != 0)
          {
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumSystemSamples)
               WriteBinSysSamVector(ptrSets++,file);
          }

}
extern INT ReadBinSysSamVectorSet(SysSamVectorSet *eleptr,DbaseLinkedList *file)
     {
SysSamVector *ptrSets;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumSystemSamples),file);
     ReadBinINT(&(eleptr->NumSystemPoints),file);

     eleptr->NameSet = AllocateSysSamNameSet;
     if(ReadBinSysSamNameSet(eleptr->NameSet,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->NameSet);
           eleptr->NameSet = 0;
           }

          eleptr->Sets = AllocArraySysSamVector(eleptr->NumSystemSamples);
          ptrSets = eleptr->Sets;
          LOOPi(eleptr->NumSystemSamples)
               ReadBinSysSamVector(ptrSets++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SysSamVectorSet(XDR *stream, char **eleptrp)
{
     SysSamVectorSet *eleptr;
     eleptr = (SysSamVectorSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumSystemSamples));
     xdr_INT(stream,(char **) &(eleptr->NumSystemPoints));

     xdr_pointer(stream,
          (char **) &(eleptr->NameSet),
          SysSamNameSetSize,
                 (xdrproc_t) xdr_SysSamNameSet);
     xdr_array(stream,(char **) &(eleptr->Sets),
             (uint *) &(eleptr->NumSystemSamples),eleptr->NumSystemSamples,
               SysSamVectorSize,(xdrproc_t) xdr_SysSamVector);
}

extern void *AllocSysSamVectorSet()
{
     return((void *) AllocateSysSamVectorSet);
}
