/*------------------------------------------*/
/*   Structures For building Subsets   */
/* Structure:21:DataSubSet

             MaximumPoint --(INT)  The Highest data point number in the Points
           NumberOfPoints --(INT)  The number of points in the subset
                   Points --(INT)  The Array of integers (ID's) in subset
*/
typedef struct dtasubset DataSubSet;
struct dtasubset {
     INT ID;
     CHAR *Name;
     INT  MaximumPoint;
     INT  NumberOfPoints;
     INT *Points;
     };
#define DataSubSetSize sizeof(DataSubSet)
#define AllocateDataSubSet (DataSubSet *) Malloc(DataSubSetSize)
#define AllocArrayDataSubSet(n) (DataSubSet *) Calloc(n,DataSubSetSize)
#define DataSubSetPntrSize sizeof(DataSubSet **)
#define AllocPntrArrayDataSubSet(n) (DataSubSet **) Calloc(n,DataSubSetPntrSize)
#define SingCopyDataSubSet(out,in) memcpy(out,in,DataSubSetSize)
extern DataSubSet *CreateDataSubSet(DataSubSet *newstruct,
                             INT id,
                             CHAR *name,
                             INT  MaximumPoint,
                             INT  NumberOfPoints,
                             INT *Points);

extern CHAR *GetNameDataSubSet(DataSubSet *str);
extern INT  GetIDDataSubSet(DataSubSet *str);
extern void PrintDataSubSet(DataSubSet *eleptr);
extern void FreeDataSubSet(DataSubSet *eleptr);
extern void *AllocDataSubSet();
extern void WriteBinDataSubSet(DataSubSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataSubSet(DataSubSet *eleptr, DbaseLinkedList *file);
extern void xdr_DataSubSet(XDR *stream, char **eleptr);
extern void CopyFullDataSubSet(DataSubSet *newstruct, DataSubSet *oldstruct);
/*------------------------------------------*/
/*   Structures For building Subsets   */
/* Structure:22:DataSubSetVector

          NumberOfVectors --(INT)  The number of data subsets
                   Vector --(DataSubSet)  The set of datasubsets
*/
typedef struct dtasubsetvec DataSubSetVector;
struct dtasubsetvec {
     INT ID;
     CHAR *Name;
     INT  NumberOfVectors;
     DataSubSet *Vector;
     };
#define DataSubSetVectorSize sizeof(DataSubSetVector)
#define AllocateDataSubSetVector (DataSubSetVector *) Malloc(DataSubSetVectorSize)
#define AllocArrayDataSubSetVector(n) (DataSubSetVector *) Calloc(n,DataSubSetVectorSize)
#define DataSubSetVectorPntrSize sizeof(DataSubSetVector **)
#define AllocPntrArrayDataSubSetVector(n) (DataSubSetVector **) Calloc(n,DataSubSetVectorPntrSize)
#define SingCopyDataSubSetVector(out,in) memcpy(out,in,DataSubSetVectorSize)
extern DataSubSetVector *CreateDataSubSetVector(DataSubSetVector *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfVectors,
                                         DataSubSet *Vector);

extern CHAR *GetNameDataSubSetVector(DataSubSetVector *str);
extern INT  GetIDDataSubSetVector(DataSubSetVector *str);
extern void PrintDataSubSetVector(DataSubSetVector *eleptr);
extern void FreeDataSubSetVector(DataSubSetVector *eleptr);
extern void *AllocDataSubSetVector();
extern void WriteBinDataSubSetVector(DataSubSetVector *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataSubSetVector(DataSubSetVector *eleptr, DbaseLinkedList *file);
extern void xdr_DataSubSetVector(XDR *stream, char **eleptr);
extern void CopyFullDataSubSetVector(DataSubSetVector *newstruct, DataSubSetVector *oldstruct);
/*------------------------------------------*/
/*   Structures For building Subsets   */
/* Structure:23:DataTestBlock

                    Build --(DataSubSet)  The Build data subset (used for creating structure
                     Test --(DataSubSet)  The Test data subset (independent set used for testing)
*/
typedef struct dtatestblk DataTestBlock;
struct dtatestblk {
     INT ID;
     CHAR *Name;
     DataSubSet *Build;
     DataSubSet *Test;
     };
#define DataTestBlockSize sizeof(DataTestBlock)
#define AllocateDataTestBlock (DataTestBlock *) Malloc(DataTestBlockSize)
#define AllocArrayDataTestBlock(n) (DataTestBlock *) Calloc(n,DataTestBlockSize)
#define DataTestBlockPntrSize sizeof(DataTestBlock **)
#define AllocPntrArrayDataTestBlock(n) (DataTestBlock **) Calloc(n,DataTestBlockPntrSize)
#define SingCopyDataTestBlock(out,in) memcpy(out,in,DataTestBlockSize)
extern DataTestBlock *CreateDataTestBlock(DataTestBlock *newstruct,
                                   INT id,
                                   CHAR *name,
                                   DataSubSet *Build,
                                   DataSubSet *Test);

extern CHAR *GetNameDataTestBlock(DataTestBlock *str);
extern INT  GetIDDataTestBlock(DataTestBlock *str);
extern void PrintDataTestBlock(DataTestBlock *eleptr);
extern void FreeDataTestBlock(DataTestBlock *eleptr);
extern void *AllocDataTestBlock();
extern void WriteBinDataTestBlock(DataTestBlock *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataTestBlock(DataTestBlock *eleptr, DbaseLinkedList *file);
extern void xdr_DataTestBlock(XDR *stream, char **eleptr);
extern void CopyFullDataTestBlock(DataTestBlock *newstruct, DataTestBlock *oldstruct);
