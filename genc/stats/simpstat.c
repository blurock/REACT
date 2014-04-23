
extern CHAR *GetNameStatDivisionChoice(StatDivisionChoice *str)
{
     return(str->Name);
}

extern INT GetIDStatDivisionChoice(StatDivisionChoice *str)
{
     return(str->ID);
}

extern StatDivisionChoice *CreateStatDivisionChoice(StatDivisionChoice *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  BoundarySet,
                                             FLOAT  Division)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->BoundarySet = BoundarySet;
     newstruct->Division = Division;



     return(newstruct);
}


extern void CopyFullStatDivisionChoice(StatDivisionChoice *newstruct, StatDivisionChoice *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->BoundarySet = oldstruct->BoundarySet;
     newstruct->Division = oldstruct->Division;



}
extern void PrintStatDivisionChoice(StatDivisionChoice *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Flag whether the boundary is set or not:");
     printf("%d\n",eleptr->BoundarySet);
     printf("The division as a Float:");
     printf("%f\n",eleptr->Division);

}
extern void FreeStatDivisionChoice(StatDivisionChoice *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinStatDivisionChoice(StatDivisionChoice *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->BoundarySet),file);
     WriteBinFLOAT(&(eleptr->Division),file);

}
extern INT ReadBinStatDivisionChoice(StatDivisionChoice *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->BoundarySet),file);
     ReadBinFLOAT(&(eleptr->Division),file);

     return(STRUCTURE_READ);
     }
extern void xdr_StatDivisionChoice(XDR *stream, char **eleptrp)
{
     StatDivisionChoice *eleptr;
     eleptr = (StatDivisionChoice *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->BoundarySet));
     xdr_FLOAT(stream,(char **) &(eleptr->Division));

}

extern void *AllocStatDivisionChoice()
{
     return((void *) AllocateStatDivisionChoice);
}

extern CHAR *GetNameSimpleVarDivisions(SimpleVarDivisions *str)
{
     return(str->Name);
}

extern INT GetIDSimpleVarDivisions(SimpleVarDivisions *str)
{
     return(str->ID);
}

extern SimpleVarDivisions *CreateSimpleVarDivisions(SimpleVarDivisions *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfDivisions,
                                             StatDivisionChoice *DivInfo)
{
StatDivisionChoice *oldDivInfo,*newDivInfo;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfDivisions = NumberOfDivisions;

     newstruct->DivInfo = AllocArrayStatDivisionChoice(newstruct->NumberOfDivisions);
     if(DivInfo != 0)
          {
          oldDivInfo = DivInfo;
          newDivInfo = newstruct->DivInfo;
          LOOPi(newstruct->NumberOfDivisions)
               CopyFullStatDivisionChoice(newDivInfo++, oldDivInfo++);
          }



     return(newstruct);
}


extern void CopyFullSimpleVarDivisions(SimpleVarDivisions *newstruct, SimpleVarDivisions *oldstruct)
{
StatDivisionChoice *oldDivInfo,*newDivInfo;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfDivisions = oldstruct->NumberOfDivisions;


     newstruct->DivInfo = AllocArrayStatDivisionChoice(newstruct->NumberOfDivisions);
     if(oldstruct->DivInfo != 0)
          {
          oldDivInfo = oldstruct->DivInfo;
          newDivInfo = newstruct->DivInfo;
          LOOPi(newstruct->NumberOfDivisions)
               CopyFullStatDivisionChoice(newDivInfo++, oldDivInfo++);
          }


}
extern void PrintSimpleVarDivisions(SimpleVarDivisions *eleptr)
{
StatDivisionChoice *ptrDivInfo;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of divisions:");
     printf("%d\n",eleptr->NumberOfDivisions);

     printf("The Values of the division as floats:\n");
     if(eleptr->DivInfo != 0)
          {
          ptrDivInfo = eleptr->DivInfo;
          LOOPi(eleptr->NumberOfDivisions)
               PrintStatDivisionChoice(ptrDivInfo++);
          }


}
extern void FreeSimpleVarDivisions(SimpleVarDivisions *eleptr)
{
StatDivisionChoice *ptrDivInfo;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrDivInfo = eleptr->DivInfo;
     LOOPi(eleptr->NumberOfDivisions)
          FreeStatDivisionChoice(ptrDivInfo++);
     Free(eleptr->DivInfo);

}
extern void WriteBinSimpleVarDivisions(SimpleVarDivisions *eleptr, DbaseLinkedList *file)
{
StatDivisionChoice *ptrDivInfo;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfDivisions),file);

     if(eleptr->DivInfo != 0)
          {
          ptrDivInfo = eleptr->DivInfo;
          LOOPi(eleptr->NumberOfDivisions)
               WriteBinStatDivisionChoice(ptrDivInfo++,file);
          }

}
extern INT ReadBinSimpleVarDivisions(SimpleVarDivisions *eleptr,DbaseLinkedList *file)
     {
StatDivisionChoice *ptrDivInfo;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfDivisions),file);

          eleptr->DivInfo = AllocArrayStatDivisionChoice(eleptr->NumberOfDivisions);
          ptrDivInfo = eleptr->DivInfo;
          LOOPi(eleptr->NumberOfDivisions)
               ReadBinStatDivisionChoice(ptrDivInfo++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SimpleVarDivisions(XDR *stream, char **eleptrp)
{
     SimpleVarDivisions *eleptr;
     eleptr = (SimpleVarDivisions *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfDivisions));

     xdr_array(stream,(char **) &(eleptr->DivInfo),
             (uint *) &(eleptr->NumberOfDivisions),eleptr->NumberOfDivisions,
               StatDivisionChoiceSize,(xdrproc_t) xdr_StatDivisionChoice);
}

extern void *AllocSimpleVarDivisions()
{
     return((void *) AllocateSimpleVarDivisions);
}

extern CHAR *GetNameSysSamStats(SysSamStats *str)
{
     return(str->Name);
}

extern INT GetIDSysSamStats(SysSamStats *str)
{
     return(str->ID);
}

extern SysSamStats *CreateSysSamStats(SysSamStats *newstruct,
                               INT id,
                               CHAR *name,
                               FLOAT  Average,
                               FLOAT  StdDeviation)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->Average = Average;
     newstruct->StdDeviation = StdDeviation;



     return(newstruct);
}


extern void CopyFullSysSamStats(SysSamStats *newstruct, SysSamStats *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->Average = oldstruct->Average;
     newstruct->StdDeviation = oldstruct->StdDeviation;



}
extern void PrintSysSamStats(SysSamStats *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The average or Sample Mean:");
     printf("%f\n",eleptr->Average);
     printf("The Standard Sample Deviation:");
     printf("%f\n",eleptr->StdDeviation);

}
extern void FreeSysSamStats(SysSamStats *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinSysSamStats(SysSamStats *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinFLOAT(&(eleptr->Average),file);
     WriteBinFLOAT(&(eleptr->StdDeviation),file);

}
extern INT ReadBinSysSamStats(SysSamStats *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinFLOAT(&(eleptr->Average),file);
     ReadBinFLOAT(&(eleptr->StdDeviation),file);

     return(STRUCTURE_READ);
     }
extern void xdr_SysSamStats(XDR *stream, char **eleptrp)
{
     SysSamStats *eleptr;
     eleptr = (SysSamStats *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_FLOAT(stream,(char **) &(eleptr->Average));
     xdr_FLOAT(stream,(char **) &(eleptr->StdDeviation));

}

extern void *AllocSysSamStats()
{
     return((void *) AllocateSysSamStats);
}

extern CHAR *GetNameSysSamVectorData(SysSamVectorData *str)
{
     return(str->Name);
}

extern INT GetIDSysSamVectorData(SysSamVectorData *str)
{
     return(str->ID);
}

extern SysSamVectorData *CreateSysSamVectorData(SysSamVectorData *newstruct,
                                         INT id,
                                         CHAR *name,
                                         BaseType *Highest,
                                         BaseType *Lowest,
                                         BaseType *Average,
                                         BaseVector *DistinctValues,
                                         INT  NumberDistinctValues,
                                         INT *Counts,
                                         SimpleVarDivisions *Divisions)
{
INT *oldCounts,*newCounts;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberDistinctValues = NumberDistinctValues;
     if(Highest != 0)
          {
          newstruct->Highest = AllocateBaseType;
          CopyFullBaseType(newstruct->Highest, Highest);
          }
     else
          newstruct->Highest = 0;
     if(Lowest != 0)
          {
          newstruct->Lowest = AllocateBaseType;
          CopyFullBaseType(newstruct->Lowest, Lowest);
          }
     else
          newstruct->Lowest = 0;
     if(Average != 0)
          {
          newstruct->Average = AllocateBaseType;
          CopyFullBaseType(newstruct->Average, Average);
          }
     else
          newstruct->Average = 0;
     if(DistinctValues != 0)
          {
          newstruct->DistinctValues = AllocateBaseVector;
          CopyFullBaseVector(newstruct->DistinctValues, DistinctValues);
          }
     else
          newstruct->DistinctValues = 0;
     if(Divisions != 0)
          {
          newstruct->Divisions = AllocateSimpleVarDivisions;
          CopyFullSimpleVarDivisions(newstruct->Divisions, Divisions);
          }
     else
          newstruct->Divisions = 0;

     newstruct->Counts = AllocArrayINT(newstruct->NumberDistinctValues);
     if(Counts != 0)
          {
          oldCounts = Counts;
          newCounts = newstruct->Counts;
          LOOPi(newstruct->NumberDistinctValues)
               CopyFullINT(newCounts++, oldCounts++);
          }



     return(newstruct);
}


extern void CopyFullSysSamVectorData(SysSamVectorData *newstruct, SysSamVectorData *oldstruct)
{
INT *oldCounts,*newCounts;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberDistinctValues = oldstruct->NumberDistinctValues;

     if(oldstruct->Highest != 0)
          {
          newstruct->Highest = AllocateBaseType;
          CopyFullBaseType(newstruct->Highest, oldstruct->Highest);
          }
     else
          newstruct->Highest = 0;
     if(oldstruct->Lowest != 0)
          {
          newstruct->Lowest = AllocateBaseType;
          CopyFullBaseType(newstruct->Lowest, oldstruct->Lowest);
          }
     else
          newstruct->Lowest = 0;
     if(oldstruct->Average != 0)
          {
          newstruct->Average = AllocateBaseType;
          CopyFullBaseType(newstruct->Average, oldstruct->Average);
          }
     else
          newstruct->Average = 0;
     if(oldstruct->DistinctValues != 0)
          {
          newstruct->DistinctValues = AllocateBaseVector;
          CopyFullBaseVector(newstruct->DistinctValues, oldstruct->DistinctValues);
          }
     else
          newstruct->DistinctValues = 0;
     if(oldstruct->Divisions != 0)
          {
          newstruct->Divisions = AllocateSimpleVarDivisions;
          CopyFullSimpleVarDivisions(newstruct->Divisions, oldstruct->Divisions);
          }
     else
          newstruct->Divisions = 0;

     newstruct->Counts = AllocArrayINT(newstruct->NumberDistinctValues);
     if(oldstruct->Counts != 0)
          {
          oldCounts = oldstruct->Counts;
          newCounts = newstruct->Counts;
          LOOPi(newstruct->NumberDistinctValues)
               CopyFullINT(newCounts++, oldCounts++);
          }


}
extern void PrintSysSamVectorData(SysSamVectorData *eleptr)
{
INT *ptrCounts;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Distinct Values:");
     printf("%d\n",eleptr->NumberDistinctValues);

     printf("   The Highest Value:\n");
     PrintBaseType(eleptr->Highest);

     printf("    The Lowest Value:\n");
     PrintBaseType(eleptr->Lowest);

     printf("   The Average Value:\n");
     PrintBaseType(eleptr->Average);

     printf("The Set of Distinct Values:\n");
     PrintBaseVector(eleptr->DistinctValues);

     printf("The Cluster Divisions of the Variable:\n");
     PrintSimpleVarDivisions(eleptr->Divisions);

     printf("The Number of each distinct value:\n");
     if(eleptr->Counts != 0)
          {
          ptrCounts = eleptr->Counts;
          LOOPi(eleptr->NumberDistinctValues)
               PrintINT(ptrCounts++);
          }


}
extern void FreeSysSamVectorData(SysSamVectorData *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Counts);

     FreeBaseType(eleptr->Highest);
     Free(eleptr->Highest);

     FreeBaseType(eleptr->Lowest);
     Free(eleptr->Lowest);

     FreeBaseType(eleptr->Average);
     Free(eleptr->Average);

     FreeBaseVector(eleptr->DistinctValues);
     Free(eleptr->DistinctValues);

     FreeSimpleVarDivisions(eleptr->Divisions);
     Free(eleptr->Divisions);

}
extern void WriteBinSysSamVectorData(SysSamVectorData *eleptr, DbaseLinkedList *file)
{
INT *ptrCounts;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberDistinctValues),file);

     WriteBinBaseType(eleptr->Highest,file);

     WriteBinBaseType(eleptr->Lowest,file);

     WriteBinBaseType(eleptr->Average,file);

     WriteBinBaseVector(eleptr->DistinctValues,file);

     WriteBinSimpleVarDivisions(eleptr->Divisions,file);

     if(eleptr->Counts != 0)
          {
          ptrCounts = eleptr->Counts;
          LOOPi(eleptr->NumberDistinctValues)
               WriteBinINT(ptrCounts++,file);
          }

}
extern INT ReadBinSysSamVectorData(SysSamVectorData *eleptr,DbaseLinkedList *file)
     {
INT *ptrCounts;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberDistinctValues),file);

     eleptr->Highest = AllocateBaseType;
     if(ReadBinBaseType(eleptr->Highest,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Highest);
           eleptr->Highest = 0;
           }

     eleptr->Lowest = AllocateBaseType;
     if(ReadBinBaseType(eleptr->Lowest,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Lowest);
           eleptr->Lowest = 0;
           }

     eleptr->Average = AllocateBaseType;
     if(ReadBinBaseType(eleptr->Average,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Average);
           eleptr->Average = 0;
           }

     eleptr->DistinctValues = AllocateBaseVector;
     if(ReadBinBaseVector(eleptr->DistinctValues,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->DistinctValues);
           eleptr->DistinctValues = 0;
           }

     eleptr->Divisions = AllocateSimpleVarDivisions;
     if(ReadBinSimpleVarDivisions(eleptr->Divisions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Divisions);
           eleptr->Divisions = 0;
           }

          eleptr->Counts = AllocArrayINT(eleptr->NumberDistinctValues);
          ptrCounts = eleptr->Counts;
          LOOPi(eleptr->NumberDistinctValues)
               ReadBinINT(ptrCounts++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SysSamVectorData(XDR *stream, char **eleptrp)
{
     SysSamVectorData *eleptr;
     eleptr = (SysSamVectorData *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberDistinctValues));

     xdr_pointer(stream,
          (char **) &(eleptr->Highest),
          BaseTypeSize,
                 (xdrproc_t) xdr_BaseType);
     xdr_pointer(stream,
          (char **) &(eleptr->Lowest),
          BaseTypeSize,
                 (xdrproc_t) xdr_BaseType);
     xdr_pointer(stream,
          (char **) &(eleptr->Average),
          BaseTypeSize,
                 (xdrproc_t) xdr_BaseType);
     xdr_pointer(stream,
          (char **) &(eleptr->DistinctValues),
          BaseVectorSize,
                 (xdrproc_t) xdr_BaseVector);
     xdr_pointer(stream,
          (char **) &(eleptr->Divisions),
          SimpleVarDivisionsSize,
                 (xdrproc_t) xdr_SimpleVarDivisions);
     xdr_array(stream,(char **) &(eleptr->Counts),
             (uint *) &(eleptr->NumberDistinctValues),eleptr->NumberDistinctValues,
               INTSize,(xdrproc_t) xdr_INT);
}

extern void *AllocSysSamVectorData()
{
     return((void *) AllocateSysSamVectorData);
}

extern CHAR *GetNameSetOfSysSamData(SetOfSysSamData *str)
{
     return(str->Name);
}

extern INT GetIDSetOfSysSamData(SetOfSysSamData *str)
{
     return(str->ID);
}

extern SetOfSysSamData *CreateSetOfSysSamData(SetOfSysSamData *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfVariables,
                                       SysSamVectorData *Stats)
{
SysSamVectorData *oldStats,*newStats;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfVariables = NumberOfVariables;

     newstruct->Stats = AllocArraySysSamVectorData(newstruct->NumberOfVariables);
     if(Stats != 0)
          {
          oldStats = Stats;
          newStats = newstruct->Stats;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullSysSamVectorData(newStats++, oldStats++);
          }



     return(newstruct);
}


extern void CopyFullSetOfSysSamData(SetOfSysSamData *newstruct, SetOfSysSamData *oldstruct)
{
SysSamVectorData *oldStats,*newStats;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfVariables = oldstruct->NumberOfVariables;


     newstruct->Stats = AllocArraySysSamVectorData(newstruct->NumberOfVariables);
     if(oldstruct->Stats != 0)
          {
          oldStats = oldstruct->Stats;
          newStats = newstruct->Stats;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullSysSamVectorData(newStats++, oldStats++);
          }


}
extern void PrintSetOfSysSamData(SetOfSysSamData *eleptr)
{
SysSamVectorData *ptrStats;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number Of Variables:");
     printf("%d\n",eleptr->NumberOfVariables);

     printf("    The set of stats:\n");
     if(eleptr->Stats != 0)
          {
          ptrStats = eleptr->Stats;
          LOOPi(eleptr->NumberOfVariables)
               PrintSysSamVectorData(ptrStats++);
          }


}
extern void FreeSetOfSysSamData(SetOfSysSamData *eleptr)
{
SysSamVectorData *ptrStats;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrStats = eleptr->Stats;
     LOOPi(eleptr->NumberOfVariables)
          FreeSysSamVectorData(ptrStats++);
     Free(eleptr->Stats);

}
extern void WriteBinSetOfSysSamData(SetOfSysSamData *eleptr, DbaseLinkedList *file)
{
SysSamVectorData *ptrStats;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfVariables),file);

     if(eleptr->Stats != 0)
          {
          ptrStats = eleptr->Stats;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinSysSamVectorData(ptrStats++,file);
          }

}
extern INT ReadBinSetOfSysSamData(SetOfSysSamData *eleptr,DbaseLinkedList *file)
     {
SysSamVectorData *ptrStats;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfVariables),file);

          eleptr->Stats = AllocArraySysSamVectorData(eleptr->NumberOfVariables);
          ptrStats = eleptr->Stats;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinSysSamVectorData(ptrStats++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SetOfSysSamData(XDR *stream, char **eleptrp)
{
     SetOfSysSamData *eleptr;
     eleptr = (SetOfSysSamData *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVariables));

     xdr_array(stream,(char **) &(eleptr->Stats),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               SysSamVectorDataSize,(xdrproc_t) xdr_SysSamVectorData);
}

extern void *AllocSetOfSysSamData()
{
     return((void *) AllocateSetOfSysSamData);
}

extern CHAR *GetNameUniVariateCluster(UniVariateCluster *str)
{
     return(str->Name);
}

extern INT GetIDUniVariateCluster(UniVariateCluster *str)
{
     return(str->ID);
}

extern UniVariateCluster *CreateUniVariateCluster(UniVariateCluster *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfClusters,
                                           DataSubSetVector *Sets,
                                           SysSamVectorData *Statistics)
{
SysSamVectorData *oldStatistics,*newStatistics;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfClusters = NumberOfClusters;
     if(Sets != 0)
          {
          newstruct->Sets = AllocateDataSubSetVector;
          CopyFullDataSubSetVector(newstruct->Sets, Sets);
          }
     else
          newstruct->Sets = 0;

     newstruct->Statistics = AllocArraySysSamVectorData(newstruct->NumberOfClusters);
     if(Statistics != 0)
          {
          oldStatistics = Statistics;
          newStatistics = newstruct->Statistics;
          LOOPi(newstruct->NumberOfClusters)
               CopyFullSysSamVectorData(newStatistics++, oldStatistics++);
          }



     return(newstruct);
}


extern void CopyFullUniVariateCluster(UniVariateCluster *newstruct, UniVariateCluster *oldstruct)
{
SysSamVectorData *oldStatistics,*newStatistics;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfClusters = oldstruct->NumberOfClusters;

     if(oldstruct->Sets != 0)
          {
          newstruct->Sets = AllocateDataSubSetVector;
          CopyFullDataSubSetVector(newstruct->Sets, oldstruct->Sets);
          }
     else
          newstruct->Sets = 0;

     newstruct->Statistics = AllocArraySysSamVectorData(newstruct->NumberOfClusters);
     if(oldstruct->Statistics != 0)
          {
          oldStatistics = oldstruct->Statistics;
          newStatistics = newstruct->Statistics;
          LOOPi(newstruct->NumberOfClusters)
               CopyFullSysSamVectorData(newStatistics++, oldStatistics++);
          }


}
extern void PrintUniVariateCluster(UniVariateCluster *eleptr)
{
SysSamVectorData *ptrStatistics;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of Clusters:");
     printf("%d\n",eleptr->NumberOfClusters);

     printf(" The set of points (numbers) belonging to the set:\n");
     PrintDataSubSetVector(eleptr->Sets);

     printf(" The Set of statistics for each cluster:\n");
     if(eleptr->Statistics != 0)
          {
          ptrStatistics = eleptr->Statistics;
          LOOPi(eleptr->NumberOfClusters)
               PrintSysSamVectorData(ptrStatistics++);
          }


}
extern void FreeUniVariateCluster(UniVariateCluster *eleptr)
{
SysSamVectorData *ptrStatistics;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrStatistics = eleptr->Statistics;
     LOOPi(eleptr->NumberOfClusters)
          FreeSysSamVectorData(ptrStatistics++);
     Free(eleptr->Statistics);

     FreeDataSubSetVector(eleptr->Sets);
     Free(eleptr->Sets);

}
extern void WriteBinUniVariateCluster(UniVariateCluster *eleptr, DbaseLinkedList *file)
{
SysSamVectorData *ptrStatistics;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfClusters),file);

     WriteBinDataSubSetVector(eleptr->Sets,file);

     if(eleptr->Statistics != 0)
          {
          ptrStatistics = eleptr->Statistics;
          LOOPi(eleptr->NumberOfClusters)
               WriteBinSysSamVectorData(ptrStatistics++,file);
          }

}
extern INT ReadBinUniVariateCluster(UniVariateCluster *eleptr,DbaseLinkedList *file)
     {
SysSamVectorData *ptrStatistics;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfClusters),file);

     eleptr->Sets = AllocateDataSubSetVector;
     if(ReadBinDataSubSetVector(eleptr->Sets,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Sets);
           eleptr->Sets = 0;
           }

          eleptr->Statistics = AllocArraySysSamVectorData(eleptr->NumberOfClusters);
          ptrStatistics = eleptr->Statistics;
          LOOPi(eleptr->NumberOfClusters)
               ReadBinSysSamVectorData(ptrStatistics++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_UniVariateCluster(XDR *stream, char **eleptrp)
{
     UniVariateCluster *eleptr;
     eleptr = (UniVariateCluster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfClusters));

     xdr_pointer(stream,
          (char **) &(eleptr->Sets),
          DataSubSetVectorSize,
                 (xdrproc_t) xdr_DataSubSetVector);
     xdr_array(stream,(char **) &(eleptr->Statistics),
             (uint *) &(eleptr->NumberOfClusters),eleptr->NumberOfClusters,
               SysSamVectorDataSize,(xdrproc_t) xdr_SysSamVectorData);
}

extern void *AllocUniVariateCluster()
{
     return((void *) AllocateUniVariateCluster);
}

extern CHAR *GetNameUniVariateClusterSet(UniVariateClusterSet *str)
{
     return(str->Name);
}

extern INT GetIDUniVariateClusterSet(UniVariateClusterSet *str)
{
     return(str->ID);
}

extern UniVariateClusterSet *CreateUniVariateClusterSet(UniVariateClusterSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfVariables,
                                                 UniVariateCluster *VarClusters)
{
UniVariateCluster *oldVarClusters,*newVarClusters;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfVariables = NumberOfVariables;

     newstruct->VarClusters = AllocArrayUniVariateCluster(newstruct->NumberOfVariables);
     if(VarClusters != 0)
          {
          oldVarClusters = VarClusters;
          newVarClusters = newstruct->VarClusters;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullUniVariateCluster(newVarClusters++, oldVarClusters++);
          }



     return(newstruct);
}


extern void CopyFullUniVariateClusterSet(UniVariateClusterSet *newstruct, UniVariateClusterSet *oldstruct)
{
UniVariateCluster *oldVarClusters,*newVarClusters;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfVariables = oldstruct->NumberOfVariables;


     newstruct->VarClusters = AllocArrayUniVariateCluster(newstruct->NumberOfVariables);
     if(oldstruct->VarClusters != 0)
          {
          oldVarClusters = oldstruct->VarClusters;
          newVarClusters = newstruct->VarClusters;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullUniVariateCluster(newVarClusters++, oldVarClusters++);
          }


}
extern void PrintUniVariateClusterSet(UniVariateClusterSet *eleptr)
{
UniVariateCluster *ptrVarClusters;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The number of Variables:");
     printf("%d\n",eleptr->NumberOfVariables);

     printf("The Set of Clusters for each variable:\n");
     if(eleptr->VarClusters != 0)
          {
          ptrVarClusters = eleptr->VarClusters;
          LOOPi(eleptr->NumberOfVariables)
               PrintUniVariateCluster(ptrVarClusters++);
          }


}
extern void FreeUniVariateClusterSet(UniVariateClusterSet *eleptr)
{
UniVariateCluster *ptrVarClusters;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrVarClusters = eleptr->VarClusters;
     LOOPi(eleptr->NumberOfVariables)
          FreeUniVariateCluster(ptrVarClusters++);
     Free(eleptr->VarClusters);

}
extern void WriteBinUniVariateClusterSet(UniVariateClusterSet *eleptr, DbaseLinkedList *file)
{
UniVariateCluster *ptrVarClusters;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfVariables),file);

     if(eleptr->VarClusters != 0)
          {
          ptrVarClusters = eleptr->VarClusters;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinUniVariateCluster(ptrVarClusters++,file);
          }

}
extern INT ReadBinUniVariateClusterSet(UniVariateClusterSet *eleptr,DbaseLinkedList *file)
     {
UniVariateCluster *ptrVarClusters;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfVariables),file);

          eleptr->VarClusters = AllocArrayUniVariateCluster(eleptr->NumberOfVariables);
          ptrVarClusters = eleptr->VarClusters;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinUniVariateCluster(ptrVarClusters++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_UniVariateClusterSet(XDR *stream, char **eleptrp)
{
     UniVariateClusterSet *eleptr;
     eleptr = (UniVariateClusterSet *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVariables));

     xdr_array(stream,(char **) &(eleptr->VarClusters),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               UniVariateClusterSize,(xdrproc_t) xdr_UniVariateCluster);
}

extern void *AllocUniVariateClusterSet()
{
     return((void *) AllocateUniVariateClusterSet);
}
