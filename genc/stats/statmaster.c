
extern CHAR *GetNameStatisticsConstants(StatisticsConstants *str)
{
     return(str->Name);
}

extern INT GetIDStatisticsConstants(StatisticsConstants *str)
{
     return(str->ID);
}

extern StatisticsConstants *CreateStatisticsConstants(StatisticsConstants *newstruct,
                                               INT id,
                                               CHAR *name,
                                               ClusterConstants *Cluster)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Cluster != 0)
          {
          newstruct->Cluster = AllocateClusterConstants;
          CopyFullClusterConstants(newstruct->Cluster, Cluster);
          }
     else
          newstruct->Cluster = 0;



     return(newstruct);
}


extern void CopyFullStatisticsConstants(StatisticsConstants *newstruct, StatisticsConstants *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Cluster != 0)
          {
          newstruct->Cluster = AllocateClusterConstants;
          CopyFullClusterConstants(newstruct->Cluster, oldstruct->Cluster);
          }
     else
          newstruct->Cluster = 0;


}
extern void PrintStatisticsConstants(StatisticsConstants *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The set of Cluster Constants:\n");
     PrintClusterConstants(eleptr->Cluster);

}
extern void FreeStatisticsConstants(StatisticsConstants *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeClusterConstants(eleptr->Cluster);
     Free(eleptr->Cluster);

}
extern void WriteBinStatisticsConstants(StatisticsConstants *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinClusterConstants(eleptr->Cluster,file);

}
extern INT ReadBinStatisticsConstants(StatisticsConstants *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Cluster = AllocateClusterConstants;
     if(ReadBinClusterConstants(eleptr->Cluster,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Cluster);
           eleptr->Cluster = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_StatisticsConstants(XDR *stream, char **eleptrp)
{
     StatisticsConstants *eleptr;
     eleptr = (StatisticsConstants *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Cluster),
          ClusterConstantsSize,
                 (xdrproc_t) xdr_ClusterConstants);
}

extern void *AllocStatisticsConstants()
{
     return((void *) AllocateStatisticsConstants);
}

extern CHAR *GetNameStatisticsMaster(StatisticsMaster *str)
{
     return(str->Name);
}

extern INT GetIDStatisticsMaster(StatisticsMaster *str)
{
     return(str->ID);
}

extern StatisticsMaster *CreateStatisticsMaster(StatisticsMaster *newstruct,
                                         INT id,
                                         CHAR *name,
                                         SetOfSysSamData *Simple,
                                         FactorAnalysis *FactorRun,
                                         RegressionSet *RegressionRun,
                                         StatisticsConstants *Constants,
                                         UniVariateClusterSet *UniClusters)
{

     newstruct->Name = CopyNAME(name);
     newstruct->ID   = id;
     if(Simple != 0)
          {
          newstruct->Simple = AllocateSetOfSysSamData;
          CopyFullSetOfSysSamData(newstruct->Simple, Simple);
          }
     else
          newstruct->Simple = 0;
     if(FactorRun != 0)
          {
          newstruct->FactorRun = AllocateFactorAnalysis;
          CopyFullFactorAnalysis(newstruct->FactorRun, FactorRun);
          }
     else
          newstruct->FactorRun = 0;
     if(RegressionRun != 0)
          {
          newstruct->RegressionRun = AllocateRegressionSet;
          CopyFullRegressionSet(newstruct->RegressionRun, RegressionRun);
          }
     else
          newstruct->RegressionRun = 0;
     if(Constants != 0)
          {
          newstruct->Constants = AllocateStatisticsConstants;
          CopyFullStatisticsConstants(newstruct->Constants, Constants);
          }
     else
          newstruct->Constants = 0;
     if(UniClusters != 0)
          {
          newstruct->UniClusters = AllocateUniVariateClusterSet;
          CopyFullUniVariateClusterSet(newstruct->UniClusters, UniClusters);
          }
     else
          newstruct->UniClusters = 0;



     return(newstruct);
}


extern void CopyFullStatisticsMaster(StatisticsMaster *newstruct, StatisticsMaster *oldstruct)
{

     newstruct->ID = oldstruct->ID;
     newstruct->Name = CopyNAME(oldstruct->Name);

     if(oldstruct->Simple != 0)
          {
          newstruct->Simple = AllocateSetOfSysSamData;
          CopyFullSetOfSysSamData(newstruct->Simple, oldstruct->Simple);
          }
     else
          newstruct->Simple = 0;
     if(oldstruct->FactorRun != 0)
          {
          newstruct->FactorRun = AllocateFactorAnalysis;
          CopyFullFactorAnalysis(newstruct->FactorRun, oldstruct->FactorRun);
          }
     else
          newstruct->FactorRun = 0;
     if(oldstruct->RegressionRun != 0)
          {
          newstruct->RegressionRun = AllocateRegressionSet;
          CopyFullRegressionSet(newstruct->RegressionRun, oldstruct->RegressionRun);
          }
     else
          newstruct->RegressionRun = 0;
     if(oldstruct->Constants != 0)
          {
          newstruct->Constants = AllocateStatisticsConstants;
          CopyFullStatisticsConstants(newstruct->Constants, oldstruct->Constants);
          }
     else
          newstruct->Constants = 0;
     if(oldstruct->UniClusters != 0)
          {
          newstruct->UniClusters = AllocateUniVariateClusterSet;
          CopyFullUniVariateClusterSet(newstruct->UniClusters, oldstruct->UniClusters);
          }
     else
          newstruct->UniClusters = 0;


}
extern void PrintStatisticsMaster(StatisticsMaster *eleptr)
{

     if(eleptr == 0) return;
     printf("ID  :%20d\n",eleptr->ID);
     printf("Name:%20s\n",eleptr->Name);

     printf("The Simple Statistics:\n");
     PrintSetOfSysSamData(eleptr->Simple);

     printf("The factor analysis data:\n");
     PrintFactorAnalysis(eleptr->FactorRun);

     printf("The Data for Regression Analysis:\n");
     PrintRegressionSet(eleptr->RegressionRun);

     printf("The set of needed constants:\n");
     PrintStatisticsConstants(eleptr->Constants);

     printf("The Univariate Clusters:\n");
     PrintUniVariateClusterSet(eleptr->UniClusters);

}
extern void FreeStatisticsMaster(StatisticsMaster *eleptr)
{

     if(eleptr == 0) return;
     Free(eleptr->Name);
     FreeSetOfSysSamData(eleptr->Simple);
     Free(eleptr->Simple);

     FreeFactorAnalysis(eleptr->FactorRun);
     Free(eleptr->FactorRun);

     FreeRegressionSet(eleptr->RegressionRun);
     Free(eleptr->RegressionRun);

     FreeStatisticsConstants(eleptr->Constants);
     Free(eleptr->Constants);

     FreeUniVariateClusterSet(eleptr->UniClusters);
     Free(eleptr->UniClusters);

}
extern void WriteBinStatisticsMaster(StatisticsMaster *eleptr, DbaseLinkedList *file)
{

     if(eleptr == 0)
           {
           WriteBinINT(&(NoStructureCode),file);
           return;
           }
     WriteBinINT(&(eleptr->ID),file);
     WriteBinNAME(&(eleptr->Name),file);

     WriteBinSetOfSysSamData(eleptr->Simple,file);

     WriteBinFactorAnalysis(eleptr->FactorRun,file);

     WriteBinRegressionSet(eleptr->RegressionRun,file);

     WriteBinStatisticsConstants(eleptr->Constants,file);

     WriteBinUniVariateClusterSet(eleptr->UniClusters,file);

}
extern INT ReadBinStatisticsMaster(StatisticsMaster *eleptr,DbaseLinkedList *file)
     {

     ReadBinINT(&(eleptr->ID),file);
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             return(NO_STRUCTURE_CODE);
            }
     ReadBinNAME(&(eleptr->Name),file);

     eleptr->Simple = AllocateSetOfSysSamData;
     if(ReadBinSetOfSysSamData(eleptr->Simple,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Simple);
           eleptr->Simple = 0;
           }

     eleptr->FactorRun = AllocateFactorAnalysis;
     if(ReadBinFactorAnalysis(eleptr->FactorRun,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->FactorRun);
           eleptr->FactorRun = 0;
           }

     eleptr->RegressionRun = AllocateRegressionSet;
     if(ReadBinRegressionSet(eleptr->RegressionRun,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->RegressionRun);
           eleptr->RegressionRun = 0;
           }

     eleptr->Constants = AllocateStatisticsConstants;
     if(ReadBinStatisticsConstants(eleptr->Constants,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->Constants);
           eleptr->Constants = 0;
           }

     eleptr->UniClusters = AllocateUniVariateClusterSet;
     if(ReadBinUniVariateClusterSet(eleptr->UniClusters,file) == NO_STRUCTURE_CODE)
           {
           Free(eleptr->UniClusters);
           eleptr->UniClusters = 0;
           }

     return(STRUCTURE_READ);
     }
extern void xdr_StatisticsMaster(XDR *stream, char **eleptrp)
{
     StatisticsMaster *eleptr;
     eleptr = (StatisticsMaster *) eleptrp;
     xdr_INT(stream,(char **) &(eleptr->ID));
     if(eleptr->ID == NO_STRUCTURE_CODE)
            {
             eleptr = 0;
             return;
            }
     xdr_NAME(stream,(char **) &(eleptr->Name));

     xdr_pointer(stream,
          (char **) &(eleptr->Simple),
          SetOfSysSamDataSize,
                 (xdrproc_t) xdr_SetOfSysSamData);
     xdr_pointer(stream,
          (char **) &(eleptr->FactorRun),
          FactorAnalysisSize,
                 (xdrproc_t) xdr_FactorAnalysis);
     xdr_pointer(stream,
          (char **) &(eleptr->RegressionRun),
          RegressionSetSize,
                 (xdrproc_t) xdr_RegressionSet);
     xdr_pointer(stream,
          (char **) &(eleptr->Constants),
          StatisticsConstantsSize,
                 (xdrproc_t) xdr_StatisticsConstants);
     xdr_pointer(stream,
          (char **) &(eleptr->UniClusters),
          UniVariateClusterSetSize,
                 (xdrproc_t) xdr_UniVariateClusterSet);
}

extern void *AllocStatisticsMaster()
{
     return((void *) AllocateStatisticsMaster);
}
