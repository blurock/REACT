/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:10:StatDivisionChoice

              BoundarySet --(INT) The Flag whether the boundary is set or not
                 Division --(FLOAT) The division as a Float
*/
typedef struct statdivisionchoice StatDivisionChoice;
struct statdivisionchoice {
     INT ID;
     CHAR *Name;
     INT  BoundarySet;
     FLOAT  Division;
     };
#define StatDivisionChoiceSize sizeof(StatDivisionChoice)
#define AllocateStatDivisionChoice (StatDivisionChoice *) Malloc(StatDivisionChoiceSize)
#define AllocArrayStatDivisionChoice(n) (StatDivisionChoice *) Calloc(n,StatDivisionChoiceSize)
#define StatDivisionChoicePntrSize sizeof(StatDivisionChoice **)
#define AllocPntrArrayStatDivisionChoice(n) (StatDivisionChoice **) Calloc(n,StatDivisionChoicePntrSize)
#define SingCopyStatDivisionChoice(out,in) memcpy(out,in,StatDivisionChoiceSize)
extern StatDivisionChoice *CreateStatDivisionChoice(StatDivisionChoice *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  BoundarySet,
                                             FLOAT  Division);

extern CHAR *GetNameStatDivisionChoice(StatDivisionChoice *str);
extern INT  GetIDStatDivisionChoice(StatDivisionChoice *str);
extern void PrintStatDivisionChoice(StatDivisionChoice *eleptr);
extern void FreeStatDivisionChoice(StatDivisionChoice *eleptr);
extern void *AllocStatDivisionChoice();
extern void WriteBinStatDivisionChoice(StatDivisionChoice *eleptr, DbaseLinkedList *file);
extern INT ReadBinStatDivisionChoice(StatDivisionChoice *eleptr, DbaseLinkedList *file);
extern void xdr_StatDivisionChoice(XDR *stream, char **eleptr);
extern void CopyFullStatDivisionChoice(StatDivisionChoice *newstruct, StatDivisionChoice *oldstruct);
/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:10:SimpleVarDivisions

        NumberOfDivisions --(INT) The number of divisions
                  DivInfo --(StatDivisionChoice) The Values of the division as floats
*/
typedef struct simplevardivisions SimpleVarDivisions;
struct simplevardivisions {
     INT ID;
     CHAR *Name;
     INT  NumberOfDivisions;
     StatDivisionChoice *DivInfo;
     };
#define SimpleVarDivisionsSize sizeof(SimpleVarDivisions)
#define AllocateSimpleVarDivisions (SimpleVarDivisions *) Malloc(SimpleVarDivisionsSize)
#define AllocArraySimpleVarDivisions(n) (SimpleVarDivisions *) Calloc(n,SimpleVarDivisionsSize)
#define SimpleVarDivisionsPntrSize sizeof(SimpleVarDivisions **)
#define AllocPntrArraySimpleVarDivisions(n) (SimpleVarDivisions **) Calloc(n,SimpleVarDivisionsPntrSize)
#define SingCopySimpleVarDivisions(out,in) memcpy(out,in,SimpleVarDivisionsSize)
extern SimpleVarDivisions *CreateSimpleVarDivisions(SimpleVarDivisions *newstruct,
                                             INT id,
                                             CHAR *name,
                                             INT  NumberOfDivisions,
                                             StatDivisionChoice *DivInfo);

extern CHAR *GetNameSimpleVarDivisions(SimpleVarDivisions *str);
extern INT  GetIDSimpleVarDivisions(SimpleVarDivisions *str);
extern void PrintSimpleVarDivisions(SimpleVarDivisions *eleptr);
extern void FreeSimpleVarDivisions(SimpleVarDivisions *eleptr);
extern void *AllocSimpleVarDivisions();
extern void WriteBinSimpleVarDivisions(SimpleVarDivisions *eleptr, DbaseLinkedList *file);
extern INT ReadBinSimpleVarDivisions(SimpleVarDivisions *eleptr, DbaseLinkedList *file);
extern void xdr_SimpleVarDivisions(XDR *stream, char **eleptr);
extern void CopyFullSimpleVarDivisions(SimpleVarDivisions *newstruct, SimpleVarDivisions *oldstruct);
/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:14:SysSamStats

                  Average --(FLOAT) The average or Sample Mean
             StdDeviation --(FLOAT) The Standard Sample Deviation
*/
typedef struct syssamstats SysSamStats;
struct syssamstats {
     INT ID;
     CHAR *Name;
     FLOAT  Average;
     FLOAT  StdDeviation;
     };
#define SysSamStatsSize sizeof(SysSamStats)
#define AllocateSysSamStats (SysSamStats *) Malloc(SysSamStatsSize)
#define AllocArraySysSamStats(n) (SysSamStats *) Calloc(n,SysSamStatsSize)
#define SysSamStatsPntrSize sizeof(SysSamStats **)
#define AllocPntrArraySysSamStats(n) (SysSamStats **) Calloc(n,SysSamStatsPntrSize)
#define SingCopySysSamStats(out,in) memcpy(out,in,SysSamStatsSize)
extern SysSamStats *CreateSysSamStats(SysSamStats *newstruct,
                               INT id,
                               CHAR *name,
                               FLOAT  Average,
                               FLOAT  StdDeviation);

extern CHAR *GetNameSysSamStats(SysSamStats *str);
extern INT  GetIDSysSamStats(SysSamStats *str);
extern void PrintSysSamStats(SysSamStats *eleptr);
extern void FreeSysSamStats(SysSamStats *eleptr);
extern void *AllocSysSamStats();
extern void WriteBinSysSamStats(SysSamStats *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysSamStats(SysSamStats *eleptr, DbaseLinkedList *file);
extern void xdr_SysSamStats(XDR *stream, char **eleptr);
extern void CopyFullSysSamStats(SysSamStats *newstruct, SysSamStats *oldstruct);
/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:15:SysSamVectorData

                  Highest --(BaseType) The Highest Value
                   Lowest --(BaseType) The Lowest Value
                  Average --(BaseType) The Average Value
           DistinctValues --(BaseVector) The Set of Distinct Values
     NumberDistinctValues --(INT) The Number of Distinct Values
                   Counts --(INT) The Number of each distinct value
                Divisions --(SimpleVarDivisions) The Cluster Divisions of the Variable
*/
typedef struct syssamdata SysSamVectorData;
struct syssamdata {
     INT ID;
     CHAR *Name;
     BaseType *Highest;
     BaseType *Lowest;
     BaseType *Average;
     BaseVector *DistinctValues;
     INT  NumberDistinctValues;
     INT *Counts;
     SimpleVarDivisions *Divisions;
     };
#define SysSamVectorDataSize sizeof(SysSamVectorData)
#define AllocateSysSamVectorData (SysSamVectorData *) Malloc(SysSamVectorDataSize)
#define AllocArraySysSamVectorData(n) (SysSamVectorData *) Calloc(n,SysSamVectorDataSize)
#define SysSamVectorDataPntrSize sizeof(SysSamVectorData **)
#define AllocPntrArraySysSamVectorData(n) (SysSamVectorData **) Calloc(n,SysSamVectorDataPntrSize)
#define SingCopySysSamVectorData(out,in) memcpy(out,in,SysSamVectorDataSize)
extern SysSamVectorData *CreateSysSamVectorData(SysSamVectorData *newstruct,
                                         INT id,
                                         CHAR *name,
                                         BaseType *Highest,
                                         BaseType *Lowest,
                                         BaseType *Average,
                                         BaseVector *DistinctValues,
                                         INT  NumberDistinctValues,
                                         INT *Counts,
                                         SimpleVarDivisions *Divisions);

extern CHAR *GetNameSysSamVectorData(SysSamVectorData *str);
extern INT  GetIDSysSamVectorData(SysSamVectorData *str);
extern void PrintSysSamVectorData(SysSamVectorData *eleptr);
extern void FreeSysSamVectorData(SysSamVectorData *eleptr);
extern void *AllocSysSamVectorData();
extern void WriteBinSysSamVectorData(SysSamVectorData *eleptr, DbaseLinkedList *file);
extern INT ReadBinSysSamVectorData(SysSamVectorData *eleptr, DbaseLinkedList *file);
extern void xdr_SysSamVectorData(XDR *stream, char **eleptr);
extern void CopyFullSysSamVectorData(SysSamVectorData *newstruct, SysSamVectorData *oldstruct);
/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:16:SetOfSysSamData

        NumberOfVariables --(INT) The Number Of Variables
                    Stats --(SysSamVectorData) The set of stats
*/
typedef struct setofsyssamdata SetOfSysSamData;
struct setofsyssamdata {
     INT ID;
     CHAR *Name;
     INT  NumberOfVariables;
     SysSamVectorData *Stats;
     };
#define SetOfSysSamDataSize sizeof(SetOfSysSamData)
#define AllocateSetOfSysSamData (SetOfSysSamData *) Malloc(SetOfSysSamDataSize)
#define AllocArraySetOfSysSamData(n) (SetOfSysSamData *) Calloc(n,SetOfSysSamDataSize)
#define SetOfSysSamDataPntrSize sizeof(SetOfSysSamData **)
#define AllocPntrArraySetOfSysSamData(n) (SetOfSysSamData **) Calloc(n,SetOfSysSamDataPntrSize)
#define SingCopySetOfSysSamData(out,in) memcpy(out,in,SetOfSysSamDataSize)
extern SetOfSysSamData *CreateSetOfSysSamData(SetOfSysSamData *newstruct,
                                       INT id,
                                       CHAR *name,
                                       INT  NumberOfVariables,
                                       SysSamVectorData *Stats);

extern CHAR *GetNameSetOfSysSamData(SetOfSysSamData *str);
extern INT  GetIDSetOfSysSamData(SetOfSysSamData *str);
extern void PrintSetOfSysSamData(SetOfSysSamData *eleptr);
extern void FreeSetOfSysSamData(SetOfSysSamData *eleptr);
extern void *AllocSetOfSysSamData();
extern void WriteBinSetOfSysSamData(SetOfSysSamData *eleptr, DbaseLinkedList *file);
extern INT ReadBinSetOfSysSamData(SetOfSysSamData *eleptr, DbaseLinkedList *file);
extern void xdr_SetOfSysSamData(XDR *stream, char **eleptr);
extern void CopyFullSetOfSysSamData(SetOfSysSamData *newstruct, SetOfSysSamData *oldstruct);
/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:100:UniVariateCluster

         NumberOfClusters --(INT)  The number of Clusters
                     Sets --(DataSubSetVector)  The set of points (numbers) belonging to the set
               Statistics --(SysSamVectorData)  The Set of statistics for each cluster
*/
typedef struct univariatecluster UniVariateCluster;
struct univariatecluster {
     INT ID;
     CHAR *Name;
     INT  NumberOfClusters;
     DataSubSetVector *Sets;
     SysSamVectorData *Statistics;
     };
#define UniVariateClusterSize sizeof(UniVariateCluster)
#define AllocateUniVariateCluster (UniVariateCluster *) Malloc(UniVariateClusterSize)
#define AllocArrayUniVariateCluster(n) (UniVariateCluster *) Calloc(n,UniVariateClusterSize)
#define UniVariateClusterPntrSize sizeof(UniVariateCluster **)
#define AllocPntrArrayUniVariateCluster(n) (UniVariateCluster **) Calloc(n,UniVariateClusterPntrSize)
#define SingCopyUniVariateCluster(out,in) memcpy(out,in,UniVariateClusterSize)
extern UniVariateCluster *CreateUniVariateCluster(UniVariateCluster *newstruct,
                                           INT id,
                                           CHAR *name,
                                           INT  NumberOfClusters,
                                           DataSubSetVector *Sets,
                                           SysSamVectorData *Statistics);

extern CHAR *GetNameUniVariateCluster(UniVariateCluster *str);
extern INT  GetIDUniVariateCluster(UniVariateCluster *str);
extern void PrintUniVariateCluster(UniVariateCluster *eleptr);
extern void FreeUniVariateCluster(UniVariateCluster *eleptr);
extern void *AllocUniVariateCluster();
extern void WriteBinUniVariateCluster(UniVariateCluster *eleptr, DbaseLinkedList *file);
extern INT ReadBinUniVariateCluster(UniVariateCluster *eleptr, DbaseLinkedList *file);
extern void xdr_UniVariateCluster(XDR *stream, char **eleptr);
extern void CopyFullUniVariateCluster(UniVariateCluster *newstruct, UniVariateCluster *oldstruct);
/*------------------------------------------*/
/*   Structures For Statistics and Clustering   */
/* Structure:101:UniVariateClusterSet

        NumberOfVariables --(INT) The number of Variables
              VarClusters --(UniVariateCluster) The Set of Clusters for each variable
*/
typedef struct univariateclusterset UniVariateClusterSet;
struct univariateclusterset {
     INT ID;
     CHAR *Name;
     INT  NumberOfVariables;
     UniVariateCluster *VarClusters;
     };
#define UniVariateClusterSetSize sizeof(UniVariateClusterSet)
#define AllocateUniVariateClusterSet (UniVariateClusterSet *) Malloc(UniVariateClusterSetSize)
#define AllocArrayUniVariateClusterSet(n) (UniVariateClusterSet *) Calloc(n,UniVariateClusterSetSize)
#define UniVariateClusterSetPntrSize sizeof(UniVariateClusterSet **)
#define AllocPntrArrayUniVariateClusterSet(n) (UniVariateClusterSet **) Calloc(n,UniVariateClusterSetPntrSize)
#define SingCopyUniVariateClusterSet(out,in) memcpy(out,in,UniVariateClusterSetSize)
extern UniVariateClusterSet *CreateUniVariateClusterSet(UniVariateClusterSet *newstruct,
                                                 INT id,
                                                 CHAR *name,
                                                 INT  NumberOfVariables,
                                                 UniVariateCluster *VarClusters);

extern CHAR *GetNameUniVariateClusterSet(UniVariateClusterSet *str);
extern INT  GetIDUniVariateClusterSet(UniVariateClusterSet *str);
extern void PrintUniVariateClusterSet(UniVariateClusterSet *eleptr);
extern void FreeUniVariateClusterSet(UniVariateClusterSet *eleptr);
extern void *AllocUniVariateClusterSet();
extern void WriteBinUniVariateClusterSet(UniVariateClusterSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinUniVariateClusterSet(UniVariateClusterSet *eleptr, DbaseLinkedList *file);
extern void xdr_UniVariateClusterSet(XDR *stream, char **eleptr);
extern void CopyFullUniVariateClusterSet(UniVariateClusterSet *newstruct, UniVariateClusterSet *oldstruct);
