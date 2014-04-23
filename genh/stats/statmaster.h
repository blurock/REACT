/*------------------------------------------*/
/*   Structures For statistic   */
/* Structure:1:StatisticsConstants

                  Cluster --(ClusterConstants) The set of Cluster Constants
*/
typedef struct statisticsconstants StatisticsConstants;
struct statisticsconstants {
     INT ID;
     CHAR *Name;
     ClusterConstants *Cluster;
     };
#define StatisticsConstantsSize sizeof(StatisticsConstants)
#define AllocateStatisticsConstants (StatisticsConstants *) Malloc(StatisticsConstantsSize)
#define AllocArrayStatisticsConstants(n) (StatisticsConstants *) Calloc(n,StatisticsConstantsSize)
#define StatisticsConstantsPntrSize sizeof(StatisticsConstants **)
#define AllocPntrArrayStatisticsConstants(n) (StatisticsConstants **) Calloc(n,StatisticsConstantsPntrSize)
#define SingCopyStatisticsConstants(out,in) memcpy(out,in,StatisticsConstantsSize)
extern StatisticsConstants *CreateStatisticsConstants(StatisticsConstants *newstruct,
                                               INT id,
                                               CHAR *name,
                                               ClusterConstants *Cluster);

extern CHAR *GetNameStatisticsConstants(StatisticsConstants *str);
extern INT  GetIDStatisticsConstants(StatisticsConstants *str);
extern void PrintStatisticsConstants(StatisticsConstants *eleptr);
extern void FreeStatisticsConstants(StatisticsConstants *eleptr);
extern void *AllocStatisticsConstants();
extern void WriteBinStatisticsConstants(StatisticsConstants *eleptr, DbaseLinkedList *file);
extern INT ReadBinStatisticsConstants(StatisticsConstants *eleptr, DbaseLinkedList *file);
extern void xdr_StatisticsConstants(XDR *stream, char **eleptr);
extern void CopyFullStatisticsConstants(StatisticsConstants *newstruct, StatisticsConstants *oldstruct);
/*------------------------------------------*/
/*   Structures For statistic   */
/* Structure:0:StatisticsMaster

                   Simple --(SetOfSysSamData) The Simple Statistics
                FactorRun --(FactorAnalysis) The factor analysis data
            RegressionRun --(RegressionSet) The Data for Regression Analysis
                Constants --(StatisticsConstants) The set of needed constants
              UniClusters --(UniVariateClusterSet) The Univariate Clusters
*/
typedef struct statisticsmaster StatisticsMaster;
struct statisticsmaster {
     INT ID;
     CHAR *Name;
     SetOfSysSamData *Simple;
     FactorAnalysis *FactorRun;
     RegressionSet *RegressionRun;
     StatisticsConstants *Constants;
     UniVariateClusterSet *UniClusters;
     };
#define StatisticsMasterSize sizeof(StatisticsMaster)
#define AllocateStatisticsMaster (StatisticsMaster *) Malloc(StatisticsMasterSize)
#define AllocArrayStatisticsMaster(n) (StatisticsMaster *) Calloc(n,StatisticsMasterSize)
#define StatisticsMasterPntrSize sizeof(StatisticsMaster **)
#define AllocPntrArrayStatisticsMaster(n) (StatisticsMaster **) Calloc(n,StatisticsMasterPntrSize)
#define SingCopyStatisticsMaster(out,in) memcpy(out,in,StatisticsMasterSize)
extern StatisticsMaster *CreateStatisticsMaster(StatisticsMaster *newstruct,
                                         INT id,
                                         CHAR *name,
                                         SetOfSysSamData *Simple,
                                         FactorAnalysis *FactorRun,
                                         RegressionSet *RegressionRun,
                                         StatisticsConstants *Constants,
                                         UniVariateClusterSet *UniClusters);

extern CHAR *GetNameStatisticsMaster(StatisticsMaster *str);
extern INT  GetIDStatisticsMaster(StatisticsMaster *str);
extern void PrintStatisticsMaster(StatisticsMaster *eleptr);
extern void FreeStatisticsMaster(StatisticsMaster *eleptr);
extern void *AllocStatisticsMaster();
extern void WriteBinStatisticsMaster(StatisticsMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinStatisticsMaster(StatisticsMaster *eleptr, DbaseLinkedList *file);
extern void xdr_StatisticsMaster(XDR *stream, char **eleptr);
extern void CopyFullStatisticsMaster(StatisticsMaster *newstruct, StatisticsMaster *oldstruct);
