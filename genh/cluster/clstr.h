/*------------------------------------------*/
/*   Structures for Clustering Data   */
/* Structure:40:ClusterConstants

              NumClusters --(INT) The Number of Clusters
                MaxCycles --(INT) The Maximum Number of Cycles 
                Optimized --(FLOAT) The Definition of Optimized
                    Debug --(INT) The Debug Flag
                     Tiny --(INT) The power of a very small number
*/
typedef struct clusterconstants ClusterConstants;
struct clusterconstants {
     INT ID;
     CHAR *Name;
     INT  NumClusters;
     INT  MaxCycles;
     FLOAT  Optimized;
     INT  Debug;
     INT  Tiny;
     };
#define ClusterConstantsSize sizeof(ClusterConstants)
#define AllocateClusterConstants (ClusterConstants *) Malloc(ClusterConstantsSize)
#define AllocArrayClusterConstants(n) (ClusterConstants *) Calloc(n,ClusterConstantsSize)
#define ClusterConstantsPntrSize sizeof(ClusterConstants **)
#define AllocPntrArrayClusterConstants(n) (ClusterConstants **) Calloc(n,ClusterConstantsPntrSize)
#define SingCopyClusterConstants(out,in) memcpy(out,in,ClusterConstantsSize)
extern ClusterConstants *CreateClusterConstants(ClusterConstants *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumClusters,
                                         INT  MaxCycles,
                                         FLOAT  Optimized,
                                         INT  Debug,
                                         INT  Tiny);

extern CHAR *GetNameClusterConstants(ClusterConstants *str);
extern INT  GetIDClusterConstants(ClusterConstants *str);
extern void PrintClusterConstants(ClusterConstants *eleptr);
extern void FreeClusterConstants(ClusterConstants *eleptr);
extern void *AllocClusterConstants();
extern void WriteBinClusterConstants(ClusterConstants *eleptr, DbaseLinkedList *file);
extern INT ReadBinClusterConstants(ClusterConstants *eleptr, DbaseLinkedList *file);
extern void xdr_ClusterConstants(XDR *stream, char **eleptr);
extern void CopyFullClusterConstants(ClusterConstants *newstruct, ClusterConstants *oldstruct);
/*------------------------------------------*/
/*   Structures for Clustering Data   */
/* Structure:40:SubVector

         NumberOfClusters --(INT)  The Number of Clusters
                  Centers --(FLOAT)  The Vector of Cluster Centers (Integer)
*/
typedef struct subvec SubVector;
struct subvec {
     INT ID;
     CHAR *Name;
     INT  NumberOfClusters;
     FLOAT *Centers;
     };
#define SubVectorSize sizeof(SubVector)
#define AllocateSubVector (SubVector *) Malloc(SubVectorSize)
#define AllocArraySubVector(n) (SubVector *) Calloc(n,SubVectorSize)
#define SubVectorPntrSize sizeof(SubVector **)
#define AllocPntrArraySubVector(n) (SubVector **) Calloc(n,SubVectorPntrSize)
#define SingCopySubVector(out,in) memcpy(out,in,SubVectorSize)
extern SubVector *CreateSubVector(SubVector *newstruct,
                           INT id,
                           CHAR *name,
                           INT  NumberOfClusters,
                           FLOAT *Centers);

extern CHAR *GetNameSubVector(SubVector *str);
extern INT  GetIDSubVector(SubVector *str);
extern void PrintSubVector(SubVector *eleptr);
extern void FreeSubVector(SubVector *eleptr);
extern void *AllocSubVector();
extern void WriteBinSubVector(SubVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinSubVector(SubVector *eleptr, DbaseLinkedList *file);
extern void xdr_SubVector(XDR *stream, char **eleptr);
extern void CopyFullSubVector(SubVector *newstruct, SubVector *oldstruct);
/*------------------------------------------*/
/*   Structures for Clustering Data   */
/* Structure:40:DistanceMatrix

           NumberOfPoints --(INT)  The number of Points
                   Points --(SubVector)  The set of Points (the distances from the respective points)
*/
typedef struct distmat DistanceMatrix;
struct distmat {
     INT ID;
     CHAR *Name;
     INT  NumberOfPoints;
     SubVector *Points;
     };
#define DistanceMatrixSize sizeof(DistanceMatrix)
#define AllocateDistanceMatrix (DistanceMatrix *) Malloc(DistanceMatrixSize)
#define AllocArrayDistanceMatrix(n) (DistanceMatrix *) Calloc(n,DistanceMatrixSize)
#define DistanceMatrixPntrSize sizeof(DistanceMatrix **)
#define AllocPntrArrayDistanceMatrix(n) (DistanceMatrix **) Calloc(n,DistanceMatrixPntrSize)
#define SingCopyDistanceMatrix(out,in) memcpy(out,in,DistanceMatrixSize)
extern DistanceMatrix *CreateDistanceMatrix(DistanceMatrix *newstruct,
                                     INT id,
                                     CHAR *name,
                                     INT  NumberOfPoints,
                                     SubVector *Points);

extern CHAR *GetNameDistanceMatrix(DistanceMatrix *str);
extern INT  GetIDDistanceMatrix(DistanceMatrix *str);
extern void PrintDistanceMatrix(DistanceMatrix *eleptr);
extern void FreeDistanceMatrix(DistanceMatrix *eleptr);
extern void *AllocDistanceMatrix();
extern void WriteBinDistanceMatrix(DistanceMatrix *eleptr, DbaseLinkedList *file);
extern INT ReadBinDistanceMatrix(DistanceMatrix *eleptr, DbaseLinkedList *file);
extern void xdr_DistanceMatrix(XDR *stream, char **eleptr);
extern void CopyFullDistanceMatrix(DistanceMatrix *newstruct, DistanceMatrix *oldstruct);
/*------------------------------------------*/
/*   Structures for Clustering Data   */
/* Structure:41:ClusterCenters

         NumberOfClusters --(INT)  The number of Clusters
        NumberOfVariables --(INT)  The Number Of Variables
                     Sets --(DataSubSetVector)  The set of points (numbers) belonging to the set
                 Clusters --(SysSamVector)  The set of cluster center information for each variable
                   Points --(SysSamVector)  The set of point information for each variable
                 SysSamID --(INT)  The ID of the SysSamVector Used
                 SubSetID --(INT)  The ID of the DataSubSet Used
                 VarLstID --(INT)  The ID of the Variable List
*/
typedef struct cluscenter ClusterCenters;
struct cluscenter {
     INT ID;
     CHAR *Name;
     INT  NumberOfClusters;
     INT  NumberOfVariables;
     DataSubSetVector *Sets;
     SysSamVector *Clusters;
     SysSamVector *Points;
     INT  SysSamID;
     INT  SubSetID;
     INT  VarLstID;
     };
#define ClusterCentersSize sizeof(ClusterCenters)
#define AllocateClusterCenters (ClusterCenters *) Malloc(ClusterCentersSize)
#define AllocArrayClusterCenters(n) (ClusterCenters *) Calloc(n,ClusterCentersSize)
#define ClusterCentersPntrSize sizeof(ClusterCenters **)
#define AllocPntrArrayClusterCenters(n) (ClusterCenters **) Calloc(n,ClusterCentersPntrSize)
#define SingCopyClusterCenters(out,in) memcpy(out,in,ClusterCentersSize)
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
                                     INT  VarLstID);

extern CHAR *GetNameClusterCenters(ClusterCenters *str);
extern INT  GetIDClusterCenters(ClusterCenters *str);
extern void PrintClusterCenters(ClusterCenters *eleptr);
extern void FreeClusterCenters(ClusterCenters *eleptr);
extern void *AllocClusterCenters();
extern void WriteBinClusterCenters(ClusterCenters *eleptr, DbaseLinkedList *file);
extern INT ReadBinClusterCenters(ClusterCenters *eleptr, DbaseLinkedList *file);
extern void xdr_ClusterCenters(XDR *stream, char **eleptr);
extern void CopyFullClusterCenters(ClusterCenters *newstruct, ClusterCenters *oldstruct);
/*------------------------------------------*/
/*   Structures for Clustering Data   */
/* Structure:42:ClusterDefinitions

                 Distance --(FUNCTION)  The Distance Contribution of Element
                  Average --(FUNCTION)  The Average Contribution
*/
typedef struct clusdef ClusterDefinitions;
struct clusdef {
     INT ID;
     CHAR *Name;
     INT *(*Distance)();
     void *(*Average)();
     };
#define ClusterDefinitionsSize sizeof(ClusterDefinitions)
#define AllocateClusterDefinitions (ClusterDefinitions *) Malloc(ClusterDefinitionsSize)
#define AllocArrayClusterDefinitions(n) (ClusterDefinitions *) Calloc(n,ClusterDefinitionsSize)
#define ClusterDefinitionsPntrSize sizeof(ClusterDefinitions **)
#define AllocPntrArrayClusterDefinitions(n) (ClusterDefinitions **) Calloc(n,ClusterDefinitionsPntrSize)
#define SingCopyClusterDefinitions(out,in) memcpy(out,in,ClusterDefinitionsSize)
extern ClusterDefinitions *CreateClusterDefinitions(ClusterDefinitions *newstruct,
                                             INT id,
                                             CHAR *name);

extern CHAR *GetNameClusterDefinitions(ClusterDefinitions *str);
extern INT  GetIDClusterDefinitions(ClusterDefinitions *str);
extern void PrintClusterDefinitions(ClusterDefinitions *eleptr);
extern void FreeClusterDefinitions(ClusterDefinitions *eleptr);
extern void *AllocClusterDefinitions();
extern void WriteBinClusterDefinitions(ClusterDefinitions *eleptr, DbaseLinkedList *file);
extern INT ReadBinClusterDefinitions(ClusterDefinitions *eleptr, DbaseLinkedList *file);
extern void xdr_ClusterDefinitions(XDR *stream, char **eleptr);
extern void CopyFullClusterDefinitions(ClusterDefinitions *newstruct, ClusterDefinitions *oldstruct);
/*------------------------------------------*/
/*   Structures for Clustering Data   */
/* Structure:45:ClusterMaster

                  Centers --(ClusterCenters) The Cluster Center Information
                Constants --(ClusterConstants) The Constants For Clustering
              Definitions --(ClusterDefinitions) The definition of the cluster functions
*/
typedef struct clustercentermaster ClusterMaster;
struct clustercentermaster {
     INT ID;
     CHAR *Name;
     ClusterCenters *Centers;
     ClusterConstants *Constants;
     ClusterDefinitions *Definitions;
     };
#define ClusterMasterSize sizeof(ClusterMaster)
#define AllocateClusterMaster (ClusterMaster *) Malloc(ClusterMasterSize)
#define AllocArrayClusterMaster(n) (ClusterMaster *) Calloc(n,ClusterMasterSize)
#define ClusterMasterPntrSize sizeof(ClusterMaster **)
#define AllocPntrArrayClusterMaster(n) (ClusterMaster **) Calloc(n,ClusterMasterPntrSize)
#define SingCopyClusterMaster(out,in) memcpy(out,in,ClusterMasterSize)
extern ClusterMaster *CreateClusterMaster(ClusterMaster *newstruct,
                                   INT id,
                                   CHAR *name,
                                   ClusterCenters *Centers,
                                   ClusterConstants *Constants,
                                   ClusterDefinitions *Definitions);

extern CHAR *GetNameClusterMaster(ClusterMaster *str);
extern INT  GetIDClusterMaster(ClusterMaster *str);
extern void PrintClusterMaster(ClusterMaster *eleptr);
extern void FreeClusterMaster(ClusterMaster *eleptr);
extern void *AllocClusterMaster();
extern void WriteBinClusterMaster(ClusterMaster *eleptr, DbaseLinkedList *file);
extern INT ReadBinClusterMaster(ClusterMaster *eleptr, DbaseLinkedList *file);
extern void xdr_ClusterMaster(XDR *stream, char **eleptr);
extern void CopyFullClusterMaster(ClusterMaster *newstruct, ClusterMaster *oldstruct);
