
extern CHAR *GetNameClusterConstants(ClusterConstants *str)
{
     return(str->Name);
}

extern INT GetIDClusterConstants(ClusterConstants *str)
{
     return(str->ID);
}

extern ClusterConstants *CreateClusterConstants(ClusterConstants *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumClusters,
                                         INT  MaxCycles,
                                         FLOAT  Optimized,
                                         INT  Debug,
                                         INT  Tiny)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumClusters = NumClusters;
     newstruct->MaxCycles = MaxCycles;
     newstruct->Optimized = Optimized;
     newstruct->Debug = Debug;
     newstruct->Tiny = Tiny;



     return(newstruct);
}


extern void CopyFullClusterConstants(ClusterConstants *newstruct, ClusterConstants *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumClusters = oldstruct->NumClusters;
     newstruct->MaxCycles = oldstruct->MaxCycles;
     newstruct->Optimized = oldstruct->Optimized;
     newstruct->Debug = oldstruct->Debug;
     newstruct->Tiny = oldstruct->Tiny;



}
extern void PrintClusterConstants(ClusterConstants *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf("The Number of Clusters:");
     printf("%d\n",eleptr->NumClusters);
     printf("The Maximum Number of Cycles :");
     printf("%d\n",eleptr->MaxCycles);
     printf("The Definition of Optimized:");
     printf("%f\n",eleptr->Optimized);
     printf("      The Debug Flag:");
     printf("%d\n",eleptr->Debug);
     printf("The power of a very small number:");
     printf("%d\n",eleptr->Tiny);

}
extern void FreeClusterConstants(ClusterConstants *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinClusterConstants(ClusterConstants *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumClusters),file);
     WriteBinINT(&(eleptr->MaxCycles),file);
     WriteBinFLOAT(&(eleptr->Optimized),file);
     WriteBinINT(&(eleptr->Debug),file);
     WriteBinINT(&(eleptr->Tiny),file);

}
extern INT ReadBinClusterConstants(ClusterConstants *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumClusters),file);
     ReadBinINT(&(eleptr->MaxCycles),file);
     ReadBinFLOAT(&(eleptr->Optimized),file);
     ReadBinINT(&(eleptr->Debug),file);
     ReadBinINT(&(eleptr->Tiny),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ClusterConstants(XDR *stream, char **eleptrp)
{
     ClusterConstants *eleptr;
     eleptr = (ClusterConstants *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumClusters));
     xdr_INT(stream,(char **) &(eleptr->MaxCycles));
     xdr_FLOAT(stream,(char **) &(eleptr->Optimized));
     xdr_INT(stream,(char **) &(eleptr->Debug));
     xdr_INT(stream,(char **) &(eleptr->Tiny));

}

extern void *AllocClusterConstants()
{
     return((void *) AllocateClusterConstants);
}

extern CHAR *GetNameSubVector(SubVector *str)
{
     return(str->Name);
}

extern INT GetIDSubVector(SubVector *str)
{
     return(str->ID);
}

extern SubVector *CreateSubVector(SubVector *newstruct,
                           INT id,
                           CHAR *name,
                           INT  NumberOfClusters,
                           FLOAT *Centers)
{
FLOAT *oldCenters,*newCenters;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfClusters = NumberOfClusters;

     newstruct->Centers = AllocArrayFLOAT(newstruct->NumberOfClusters);
     if(Centers != 0)
          {
          oldCenters = Centers;
          newCenters = newstruct->Centers;
          LOOPi(newstruct->NumberOfClusters)
               CopyFullFLOAT(newCenters++, oldCenters++);
          }



     return(newstruct);
}


extern void CopyFullSubVector(SubVector *newstruct, SubVector *oldstruct)
{
FLOAT *oldCenters,*newCenters;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfClusters = oldstruct->NumberOfClusters;


     newstruct->Centers = AllocArrayFLOAT(newstruct->NumberOfClusters);
     if(oldstruct->Centers != 0)
          {
          oldCenters = oldstruct->Centers;
          newCenters = newstruct->Centers;
          LOOPi(newstruct->NumberOfClusters)
               CopyFullFLOAT(newCenters++, oldCenters++);
          }


}
extern void PrintSubVector(SubVector *eleptr)
{
FLOAT *ptrCenters;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The Number of Clusters:");
     printf("%d\n",eleptr->NumberOfClusters);

     printf(" The Vector of Cluster Centers (Integer):\n");
     if(eleptr->Centers != 0)
          {
          ptrCenters = eleptr->Centers;
          LOOPi(eleptr->NumberOfClusters)
               PrintFLOAT(ptrCenters++);
          }


}
extern void FreeSubVector(SubVector *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     Free(eleptr->Centers);

}
extern void WriteBinSubVector(SubVector *eleptr, DbaseLinkedList *file)
{
FLOAT *ptrCenters;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfClusters),file);

     if(eleptr->Centers != 0)
          {
          ptrCenters = eleptr->Centers;
          LOOPi(eleptr->NumberOfClusters)
               WriteBinFLOAT(ptrCenters++,file);
          }

}
extern INT ReadBinSubVector(SubVector *eleptr,DbaseLinkedList *file)
     {
FLOAT *ptrCenters;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfClusters),file);

          eleptr->Centers = AllocArrayFLOAT(eleptr->NumberOfClusters);
          ptrCenters = eleptr->Centers;
          LOOPi(eleptr->NumberOfClusters)
               ReadBinFLOAT(ptrCenters++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_SubVector(XDR *stream, char **eleptrp)
{
     SubVector *eleptr;
     eleptr = (SubVector *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfClusters));

     xdr_array(stream,(char **) &(eleptr->Centers),
             (uint *) &(eleptr->NumberOfClusters),eleptr->NumberOfClusters,
               FLOATSize,(xdrproc_t) xdr_FLOAT);
}

extern void *AllocSubVector()
{
     return((void *) AllocateSubVector);
}

extern CHAR *GetNameDistanceMatrix(DistanceMatrix *str)
{
     return(str->Name);
}

extern INT GetIDDistanceMatrix(DistanceMatrix *str)
{
     return(str->ID);
}

extern DistanceMatrix *CreateDistanceMatrix(DistanceMatrix *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfPoints,
                                     SubVector *Points)
{
SubVector *oldPoints,*newPoints;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfPoints = NumberOfPoints;

     newstruct->Points = AllocArraySubVector(newstruct->NumberOfPoints);
     if(Points != 0)
          {
          oldPoints = Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfPoints)
               CopyFullSubVector(newPoints++, oldPoints++);
          }



     return(newstruct);
}


extern void CopyFullDistanceMatrix(DistanceMatrix *newstruct, DistanceMatrix *oldstruct)
{
SubVector *oldPoints,*newPoints;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfPoints = oldstruct->NumberOfPoints;


     newstruct->Points = AllocArraySubVector(newstruct->NumberOfPoints);
     if(oldstruct->Points != 0)
          {
          oldPoints = oldstruct->Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfPoints)
               CopyFullSubVector(newPoints++, oldPoints++);
          }


}
extern void PrintDistanceMatrix(DistanceMatrix *eleptr)
{
SubVector *ptrPoints;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of Points:");
     printf("%d\n",eleptr->NumberOfPoints);

     printf(" The set of Points (the distances from the respective points):\n");
     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               PrintSubVector(ptrPoints++);
          }


}
extern void FreeDistanceMatrix(DistanceMatrix *eleptr)
{
SubVector *ptrPoints;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrPoints = eleptr->Points;
     LOOPi(eleptr->NumberOfPoints)
          FreeSubVector(ptrPoints++);
     Free(eleptr->Points);

}
extern void WriteBinDistanceMatrix(DistanceMatrix *eleptr, DbaseLinkedList *file)
{
SubVector *ptrPoints;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfPoints),file);

     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               WriteBinSubVector(ptrPoints++,file);
          }

}
extern INT ReadBinDistanceMatrix(DistanceMatrix *eleptr,DbaseLinkedList *file)
     {
SubVector *ptrPoints;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfPoints),file);

          eleptr->Points = AllocArraySubVector(eleptr->NumberOfPoints);
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfPoints)
               ReadBinSubVector(ptrPoints++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_DistanceMatrix(XDR *stream, char **eleptrp)
{
     DistanceMatrix *eleptr;
     eleptr = (DistanceMatrix *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfPoints));

     xdr_array(stream,(char **) &(eleptr->Points),
             (uint *) &(eleptr->NumberOfPoints),eleptr->NumberOfPoints,
               SubVectorSize,(xdrproc_t) xdr_SubVector);
}

extern void *AllocDistanceMatrix()
{
     return((void *) AllocateDistanceMatrix);
}

extern CHAR *GetNameClusterCenters(ClusterCenters *str)
{
     return(str->Name);
}

extern INT GetIDClusterCenters(ClusterCenters *str)
{
     return(str->ID);
}

extern ClusterCenters *CreateClusterCenters(ClusterCenters *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfClusters,
                                     INT  NumberOfVariables,
                                     DataSubSetVector *Sets,
                                     SysSamVector *Clusters,
                                     SysSamVector *Points,
                                     INT  SysSamID,
                                     INT  SubSetID,
                                     INT  VarLstID)
{
SysSamVector *oldClusters,*newClusters;
SysSamVector *oldPoints,*newPoints;
INT i;

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     newstruct->NumberOfClusters = NumberOfClusters;
     newstruct->NumberOfVariables = NumberOfVariables;
     newstruct->SysSamID = SysSamID;
     newstruct->SubSetID = SubSetID;
     newstruct->VarLstID = VarLstID;
     if(Sets != 0)
          {
          newstruct->Sets = AllocateDataSubSetVector;
          CopyFullDataSubSetVector(newstruct->Sets, Sets);
          }
     else
          newstruct->Sets = 0;

     newstruct->Clusters = AllocArraySysSamVector(newstruct->NumberOfVariables);
     if(Clusters != 0)
          {
          oldClusters = Clusters;
          newClusters = newstruct->Clusters;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullSysSamVector(newClusters++, oldClusters++);
          }

     newstruct->Points = AllocArraySysSamVector(newstruct->NumberOfVariables);
     if(Points != 0)
          {
          oldPoints = Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullSysSamVector(newPoints++, oldPoints++);
          }



     return(newstruct);
}


extern void CopyFullClusterCenters(ClusterCenters *newstruct, ClusterCenters *oldstruct)
{
SysSamVector *oldClusters,*newClusters;
SysSamVector *oldPoints,*newPoints;
INT i;

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);
     newstruct->NumberOfClusters = oldstruct->NumberOfClusters;
     newstruct->NumberOfVariables = oldstruct->NumberOfVariables;
     newstruct->SysSamID = oldstruct->SysSamID;
     newstruct->SubSetID = oldstruct->SubSetID;
     newstruct->VarLstID = oldstruct->VarLstID;

     if(oldstruct->Sets != 0)
          {
          newstruct->Sets = AllocateDataSubSetVector;
          CopyFullDataSubSetVector(newstruct->Sets, oldstruct->Sets);
          }
     else
          newstruct->Sets = 0;

     newstruct->Clusters = AllocArraySysSamVector(newstruct->NumberOfVariables);
     if(oldstruct->Clusters != 0)
          {
          oldClusters = oldstruct->Clusters;
          newClusters = newstruct->Clusters;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullSysSamVector(newClusters++, oldClusters++);
          }

     newstruct->Points = AllocArraySysSamVector(newstruct->NumberOfVariables);
     if(oldstruct->Points != 0)
          {
          oldPoints = oldstruct->Points;
          newPoints = newstruct->Points;
          LOOPi(newstruct->NumberOfVariables)
               CopyFullSysSamVector(newPoints++, oldPoints++);
          }


}
extern void PrintClusterCenters(ClusterCenters *eleptr)
{
SysSamVector *ptrClusters;
SysSamVector *ptrPoints;
INT i;

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);
     printf(" The number of Clusters:");
     printf("%d\n",eleptr->NumberOfClusters);
     printf(" The Number Of Variables:");
     printf("%d\n",eleptr->NumberOfVariables);
     printf(" The ID of the SysSamVector Used:");
     printf("%d\n",eleptr->SysSamID);
     printf(" The ID of the DataSubSet Used:");
     printf("%d\n",eleptr->SubSetID);
     printf(" The ID of the Variable List:");
     printf("%d\n",eleptr->VarLstID);

     printf(" The set of points (numbers) belonging to the set:\n");
     PrintDataSubSetVector(eleptr->Sets);

     printf(" The set of cluster center information for each variable:\n");
     if(eleptr->Clusters != 0)
          {
          ptrClusters = eleptr->Clusters;
          LOOPi(eleptr->NumberOfVariables)
               PrintSysSamVector(ptrClusters++);
          }


     printf(" The set of point information for each variable:\n");
     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfVariables)
               PrintSysSamVector(ptrPoints++);
          }


}
extern void FreeClusterCenters(ClusterCenters *eleptr)
{
SysSamVector *ptrClusters;
SysSamVector *ptrPoints;
INT i;

     if(eleptr == 0) return;
     Free(eleptr->Name);
     ptrClusters = eleptr->Clusters;
     LOOPi(eleptr->NumberOfVariables)
          FreeSysSamVector(ptrClusters++);
     Free(eleptr->Clusters);

     ptrPoints = eleptr->Points;
     LOOPi(eleptr->NumberOfVariables)
          FreeSysSamVector(ptrPoints++);
     Free(eleptr->Points);

     FreeDataSubSetVector(eleptr->Sets);
     Free(eleptr->Sets);

}
extern void WriteBinClusterCenters(ClusterCenters *eleptr, DbaseLinkedList *file)
{
SysSamVector *ptrClusters;
SysSamVector *ptrPoints;
INT i;

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);
     WriteBinINT(&(eleptr->NumberOfClusters),file);
     WriteBinINT(&(eleptr->NumberOfVariables),file);
     WriteBinINT(&(eleptr->SysSamID),file);
     WriteBinINT(&(eleptr->SubSetID),file);
     WriteBinINT(&(eleptr->VarLstID),file);

     WriteBinDataSubSetVector(eleptr->Sets,file);

     if(eleptr->Clusters != 0)
          {
          ptrClusters = eleptr->Clusters;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinSysSamVector(ptrClusters++,file);
          }

     if(eleptr->Points != 0)
          {
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfVariables)
               WriteBinSysSamVector(ptrPoints++,file);
          }

}
extern INT ReadBinClusterCenters(ClusterCenters *eleptr,DbaseLinkedList *file)
     {
SysSamVector *ptrClusters;
SysSamVector *ptrPoints;
INT i;

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);
     ReadBinINT(&(eleptr->NumberOfClusters),file);
     ReadBinINT(&(eleptr->NumberOfVariables),file);
     ReadBinINT(&(eleptr->SysSamID),file);
     ReadBinINT(&(eleptr->SubSetID),file);
     ReadBinINT(&(eleptr->VarLstID),file);

     eleptr->Sets = AllocateDataSubSetVector;
     if(ReadBinDataSubSetVector(eleptr->Sets,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Sets);
           eleptr->Sets = 0;
           }

          eleptr->Clusters = AllocArraySysSamVector(eleptr->NumberOfVariables);
          ptrClusters = eleptr->Clusters;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinSysSamVector(ptrClusters++,file);

          eleptr->Points = AllocArraySysSamVector(eleptr->NumberOfVariables);
          ptrPoints = eleptr->Points;
          LOOPi(eleptr->NumberOfVariables)
               ReadBinSysSamVector(ptrPoints++,file);

     return(STRUCTURE_READ);
     }
extern void xdr_ClusterCenters(XDR *stream, char **eleptrp)
{
     ClusterCenters *eleptr;
     eleptr = (ClusterCenters *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));
     xdr_INT(stream,(char **) &(eleptr->NumberOfClusters));
     xdr_INT(stream,(char **) &(eleptr->NumberOfVariables));
     xdr_INT(stream,(char **) &(eleptr->SysSamID));
     xdr_INT(stream,(char **) &(eleptr->SubSetID));
     xdr_INT(stream,(char **) &(eleptr->VarLstID));

     xdr_pointer(stream,
          (char **) &(eleptr->Sets),
          DataSubSetVectorSize,
                 (xdrproc_t) xdr_DataSubSetVector);
     xdr_array(stream,(char **) &(eleptr->Clusters),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               SysSamVectorSize,(xdrproc_t) xdr_SysSamVector);
     xdr_array(stream,(char **) &(eleptr->Points),
             (uint *) &(eleptr->NumberOfVariables),eleptr->NumberOfVariables,
               SysSamVectorSize,(xdrproc_t) xdr_SysSamVector);
}

extern void *AllocClusterCenters()
{
     return((void *) AllocateClusterCenters);
}

extern CHAR *GetNameClusterDefinitions(ClusterDefinitions *str)
{
     return(str->Name);
}

extern INT GetIDClusterDefinitions(ClusterDefinitions *str)
{
     return(str->ID);
}

extern ClusterDefinitions *CreateClusterDefinitions(ClusterDefinitions *newstruct,
                                             INT id,
                                             CHAR *name)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;



     return(newstruct);
}


extern void CopyFullClusterDefinitions(ClusterDefinitions *newstruct, ClusterDefinitions *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);



}
extern void PrintClusterDefinitions(ClusterDefinitions *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

}
extern void FreeClusterDefinitions(ClusterDefinitions *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
}
extern void WriteBinClusterDefinitions(ClusterDefinitions *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

}
extern INT ReadBinClusterDefinitions(ClusterDefinitions *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     return(STRUCTURE_READ);
     }
extern void xdr_ClusterDefinitions(XDR *stream, char **eleptrp)
{
     ClusterDefinitions *eleptr;
     eleptr = (ClusterDefinitions *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

}

extern void *AllocClusterDefinitions()
{
     return((void *) AllocateClusterDefinitions);
}

extern CHAR *GetNameClusterMaster(ClusterMaster *str)
{
     return(str->Name);
}

extern INT GetIDClusterMaster(ClusterMaster *str)
{
     return(str->ID);
}

extern ClusterMaster *CreateClusterMaster(ClusterMaster *newstruct,
                                   INT id,
                                   CHAR *name,
                                   ClusterCenters *Centers,
                                   ClusterConstants *Constants,
                                   ClusterDefinitions *Definitions)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Centers != 0)
          {
          newstruct->Centers = AllocateClusterCenters;
          CopyFullClusterCenters(newstruct->Centers, Centers);
          }
     else
          newstruct->Centers = 0;
     if(Constants != 0)
          {
          newstruct->Constants = AllocateClusterConstants;
          CopyFullClusterConstants(newstruct->Constants, Constants);
          }
     else
          newstruct->Constants = 0;
     if(Definitions != 0)
          {
          newstruct->Definitions = AllocateClusterDefinitions;
          CopyFullClusterDefinitions(newstruct->Definitions, Definitions);
          }
     else
          newstruct->Definitions = 0;



     return(newstruct);
}


extern void CopyFullClusterMaster(ClusterMaster *newstruct, ClusterMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Centers != 0)
          {
          newstruct->Centers = AllocateClusterCenters;
          CopyFullClusterCenters(newstruct->Centers, oldstruct->Centers);
          }
     else
          newstruct->Centers = 0;
     if(oldstruct->Constants != 0)
          {
          newstruct->Constants = AllocateClusterConstants;
          CopyFullClusterConstants(newstruct->Constants, oldstruct->Constants);
          }
     else
          newstruct->Constants = 0;
     if(oldstruct->Definitions != 0)
          {
          newstruct->Definitions = AllocateClusterDefinitions;
          CopyFullClusterDefinitions(newstruct->Definitions, oldstruct->Definitions);
          }
     else
          newstruct->Definitions = 0;


}
extern void PrintClusterMaster(ClusterMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Cluster Center Information:\n");
     PrintClusterCenters(eleptr->Centers);

     printf("The Constants For Clustering:\n");
     PrintClusterConstants(eleptr->Constants);

     printf("The definition of the cluster functions:\n");
     PrintClusterDefinitions(eleptr->Definitions);

}
extern void FreeClusterMaster(ClusterMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeClusterCenters(eleptr->Centers);
     Free(eleptr->Centers);

     FreeClusterConstants(eleptr->Constants);
     Free(eleptr->Constants);

     FreeClusterDefinitions(eleptr->Definitions);
     Free(eleptr->Definitions);

}
extern void WriteBinClusterMaster(ClusterMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinClusterCenters(eleptr->Centers,file);

     WriteBinClusterConstants(eleptr->Constants,file);

     WriteBinClusterDefinitions(eleptr->Definitions,file);

}
extern INT ReadBinClusterMaster(ClusterMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Centers = AllocateClusterCenters;
     if(ReadBinClusterCenters(eleptr->Centers,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Centers);
           eleptr->Centers = 0;
           }

     eleptr->Constants = AllocateClusterConstants;
     if(ReadBinClusterConstants(eleptr->Constants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Constants);
           eleptr->Constants = 0;
           }

     eleptr->Definitions = AllocateClusterDefinitions;
     if(ReadBinClusterDefinitions(eleptr->Definitions,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Definitions);
           eleptr->Definitions = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_ClusterMaster(XDR *stream, char **eleptrp)
{
     ClusterMaster *eleptr;
     eleptr = (ClusterMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Centers),
          ClusterCentersSize,
                 (xdrproc_t) xdr_ClusterCenters);
     xdr_pointer(stream,
          (char **) &(eleptr->Constants),
          ClusterConstantsSize,
                 (xdrproc_t) xdr_ClusterConstants);
     xdr_pointer(stream,
          (char **) &(eleptr->Definitions),
          ClusterDefinitionsSize,
                 (xdrproc_t) xdr_ClusterDefinitions);
}

extern void *AllocClusterMaster()
{
     return((void *) AllocateClusterMaster);
}
