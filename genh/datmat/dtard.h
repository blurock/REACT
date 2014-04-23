/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:0:CharRange

                BeginChar --(INT) The First Character (begining character position - starting with zero)
                     Size --(INT) The Size of the range (in characters)
*/
typedef struct chrrng CharRange;
struct chrrng {
     INT ID;
     CHAR *Name;
     INT  BeginChar;
     INT  Size;
     };
#define CharRangeSize sizeof(CharRange)
#define AllocateCharRange (CharRange *) Malloc(CharRangeSize)
#define AllocArrayCharRange(n) (CharRange *) Calloc(n,CharRangeSize)
#define CharRangePntrSize sizeof(CharRange **)
#define AllocPntrArrayCharRange(n) (CharRange **) Calloc(n,CharRangePntrSize)
#define SingCopyCharRange(out,in) memcpy(out,in,CharRangeSize)
extern CharRange *CreateCharRange(CharRange *newstruct,
                           INT id,
                           CHAR *name,
                           INT  BeginChar,
                           INT  Size);

extern CHAR *GetNameCharRange(CharRange *str);
extern INT  GetIDCharRange(CharRange *str);
extern void PrintCharRange(CharRange *eleptr);
extern void FreeCharRange(CharRange *eleptr);
extern void *AllocCharRange();
extern void WriteBinCharRange(CharRange *eleptr, DbaseLinkedList *file);
extern INT ReadBinCharRange(CharRange *eleptr, DbaseLinkedList *file);
extern void xdr_CharRange(XDR *stream, char **eleptr);
extern void CopyFullCharRange(CharRange *newstruct, CharRange *oldstruct);
/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:1:BasisType

                  Integer --(INT)  A pointer to an integer
                    Float --(FLOAT)  A pointer to a Floating Point Number
*/
typedef struct basistyp BasisType;
struct basistyp {
     INT ID;
     CHAR *Name;
     INT *Integer;
     FLOAT *Float;
     };
#define BasisTypeSize sizeof(BasisType)
#define AllocateBasisType (BasisType *) Malloc(BasisTypeSize)
#define AllocArrayBasisType(n) (BasisType *) Calloc(n,BasisTypeSize)
#define BasisTypePntrSize sizeof(BasisType **)
#define AllocPntrArrayBasisType(n) (BasisType **) Calloc(n,BasisTypePntrSize)
#define SingCopyBasisType(out,in) memcpy(out,in,BasisTypeSize)
extern BasisType *CreateBasisType(BasisType *newstruct,
                           INT id,
                           CHAR *name);

extern CHAR *GetNameBasisType(BasisType *str);
extern INT  GetIDBasisType(BasisType *str);
extern void PrintBasisType(BasisType *eleptr);
extern void FreeBasisType(BasisType *eleptr);
extern void *AllocBasisType();
extern void WriteBinBasisType(BasisType *eleptr, DbaseLinkedList *file);
extern INT ReadBinBasisType(BasisType *eleptr, DbaseLinkedList *file);
extern void xdr_BasisType(XDR *stream, char **eleptr);
extern void CopyFullBasisType(BasisType *newstruct, BasisType *oldstruct);
/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:2:DataPoint

                    Range --(CharRange)  Position in line of element
                     Type --(INT)  The type of element (i.e. the basis type)
           NumberOfPoints --(INT)  The number of points read in of this type
                   Vector --(BasisType)  The vector of points
*/
typedef struct dtapnt DataPoint;
struct dtapnt {
     INT ID;
     CHAR *Name;
     CharRange  Range;
     INT  Type;
     INT  NumberOfPoints;
     BasisType  Vector;
     };
#define DataPointSize sizeof(DataPoint)
#define AllocateDataPoint (DataPoint *) Malloc(DataPointSize)
#define AllocArrayDataPoint(n) (DataPoint *) Calloc(n,DataPointSize)
#define DataPointPntrSize sizeof(DataPoint **)
#define AllocPntrArrayDataPoint(n) (DataPoint **) Calloc(n,DataPointPntrSize)
#define SingCopyDataPoint(out,in) memcpy(out,in,DataPointSize)
extern DataPoint *CreateDataPoint(DataPoint *newstruct,
                           INT id,
                           CHAR *name,
                           INT  Type,
                           INT  NumberOfPoints);

extern CHAR *GetNameDataPoint(DataPoint *str);
extern INT  GetIDDataPoint(DataPoint *str);
extern void PrintDataPoint(DataPoint *eleptr);
extern void FreeDataPoint(DataPoint *eleptr);
extern void *AllocDataPoint();
extern void WriteBinDataPoint(DataPoint *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataPoint(DataPoint *eleptr, DbaseLinkedList *file);
extern void xdr_DataPoint(XDR *stream, char **eleptr);
extern void CopyFullDataPoint(DataPoint *newstruct, DataPoint *oldstruct);
/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:3:DataBlock

          NumberOfColumns --(INT)  The number of variables
           NumberOfPoints --(INT)  The number of points in each column
                  Columns --(DataPoint)  The vector of variable information
*/
typedef struct dtablk DataBlock;
struct dtablk {
     INT ID;
     CHAR *Name;
     INT  NumberOfColumns;
     INT  NumberOfPoints;
     DataPoint *Columns;
     };
#define DataBlockSize sizeof(DataBlock)
#define AllocateDataBlock (DataBlock *) Malloc(DataBlockSize)
#define AllocArrayDataBlock(n) (DataBlock *) Calloc(n,DataBlockSize)
#define DataBlockPntrSize sizeof(DataBlock **)
#define AllocPntrArrayDataBlock(n) (DataBlock **) Calloc(n,DataBlockPntrSize)
#define SingCopyDataBlock(out,in) memcpy(out,in,DataBlockSize)
extern DataBlock *CreateDataBlock(DataBlock *newstruct,
                           INT id,
                           CHAR *name,
                           INT  NumberOfColumns,
                           INT  NumberOfPoints,
                           DataPoint *Columns);

extern CHAR *GetNameDataBlock(DataBlock *str);
extern INT  GetIDDataBlock(DataBlock *str);
extern void PrintDataBlock(DataBlock *eleptr);
extern void FreeDataBlock(DataBlock *eleptr);
extern void *AllocDataBlock();
extern void WriteBinDataBlock(DataBlock *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataBlock(DataBlock *eleptr, DbaseLinkedList *file);
extern void xdr_DataBlock(XDR *stream, char **eleptr);
extern void CopyFullDataBlock(DataBlock *newstruct, DataBlock *oldstruct);
/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:4:DataPointName

*/
typedef struct dtapntname DataPointName;
struct dtapntname {
     INT ID;
     CHAR *Name;
     };
#define DataPointNameSize sizeof(DataPointName)
#define AllocateDataPointName (DataPointName *) Malloc(DataPointNameSize)
#define AllocArrayDataPointName(n) (DataPointName *) Calloc(n,DataPointNameSize)
#define DataPointNamePntrSize sizeof(DataPointName **)
#define AllocPntrArrayDataPointName(n) (DataPointName **) Calloc(n,DataPointNamePntrSize)
#define SingCopyDataPointName(out,in) memcpy(out,in,DataPointNameSize)
extern DataPointName *CreateDataPointName(DataPointName *newstruct,
                                   INT id,
                                   CHAR *name);

extern CHAR *GetNameDataPointName(DataPointName *str);
extern INT  GetIDDataPointName(DataPointName *str);
extern void PrintDataPointName(DataPointName *eleptr);
extern void FreeDataPointName(DataPointName *eleptr);
extern void *AllocDataPointName();
extern void WriteBinDataPointName(DataPointName *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataPointName(DataPointName *eleptr, DbaseLinkedList *file);
extern void xdr_DataPointName(XDR *stream, char **eleptr);
extern void CopyFullDataPointName(DataPointName *newstruct, DataPointName *oldstruct);
/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:4:DataPointNameSet

            NumberOfNames --(INT)  Number Of Names
                    Names --(DataPointName)  The vector of names
*/
typedef struct dtapntnameset DataPointNameSet;
struct dtapntnameset {
     INT ID;
     CHAR *Name;
     INT  NumberOfNames;
     DataPointName *Names;
     };
#define DataPointNameSetSize sizeof(DataPointNameSet)
#define AllocateDataPointNameSet (DataPointNameSet *) Malloc(DataPointNameSetSize)
#define AllocArrayDataPointNameSet(n) (DataPointNameSet *) Calloc(n,DataPointNameSetSize)
#define DataPointNameSetPntrSize sizeof(DataPointNameSet **)
#define AllocPntrArrayDataPointNameSet(n) (DataPointNameSet **) Calloc(n,DataPointNameSetPntrSize)
#define SingCopyDataPointNameSet(out,in) memcpy(out,in,DataPointNameSetSize)
extern DataPointNameSet *CreateDataPointNameSet(DataPointNameSet *newstruct,
                                         INT id,
                                         CHAR *name,
                                         INT  NumberOfNames,
                                         DataPointName *Names);

extern CHAR *GetNameDataPointNameSet(DataPointNameSet *str);
extern INT  GetIDDataPointNameSet(DataPointNameSet *str);
extern void PrintDataPointNameSet(DataPointNameSet *eleptr);
extern void FreeDataPointNameSet(DataPointNameSet *eleptr);
extern void *AllocDataPointNameSet();
extern void WriteBinDataPointNameSet(DataPointNameSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataPointNameSet(DataPointNameSet *eleptr, DbaseLinkedList *file);
extern void xdr_DataPointNameSet(XDR *stream, char **eleptr);
extern void CopyFullDataPointNameSet(DataPointNameSet *newstruct, DataPointNameSet *oldstruct);
/*------------------------------------------*/
/*   Structures for dtard.c     */
/* Structure:4:DataBlockSet

            NumDataBlocks --(INT) The number of blocks
                   Blocks --(DataBlock) The blocks of data
                  NameSet --(DataPointNameSet) The names of the elements
*/
typedef struct dtablkset DataBlockSet;
struct dtablkset {
     INT ID;
     CHAR *Name;
     INT  NumDataBlocks;
     DataBlock *Blocks;
     DataPointNameSet *NameSet;
     };
#define DataBlockSetSize sizeof(DataBlockSet)
#define AllocateDataBlockSet (DataBlockSet *) Malloc(DataBlockSetSize)
#define AllocArrayDataBlockSet(n) (DataBlockSet *) Calloc(n,DataBlockSetSize)
#define DataBlockSetPntrSize sizeof(DataBlockSet **)
#define AllocPntrArrayDataBlockSet(n) (DataBlockSet **) Calloc(n,DataBlockSetPntrSize)
#define SingCopyDataBlockSet(out,in) memcpy(out,in,DataBlockSetSize)
extern DataBlockSet *CreateDataBlockSet(DataBlockSet *newstruct,
                                 INT id,
                                 CHAR *name,
                                 INT  NumDataBlocks,
                                 DataBlock *Blocks,
                                 DataPointNameSet *NameSet);

extern CHAR *GetNameDataBlockSet(DataBlockSet *str);
extern INT  GetIDDataBlockSet(DataBlockSet *str);
extern void PrintDataBlockSet(DataBlockSet *eleptr);
extern void FreeDataBlockSet(DataBlockSet *eleptr);
extern void *AllocDataBlockSet();
extern void WriteBinDataBlockSet(DataBlockSet *eleptr, DbaseLinkedList *file);
extern INT ReadBinDataBlockSet(DataBlockSet *eleptr, DbaseLinkedList *file);
extern void xdr_DataBlockSet(XDR *stream, char **eleptr);
extern void CopyFullDataBlockSet(DataBlockSet *newstruct, DataBlockSet *oldstruct);
